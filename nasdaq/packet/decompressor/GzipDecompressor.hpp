#pragma once

#ifdef HAS_ZLIB

#include "Decompressor.hpp"

#include <memory>
#include <stdexcept>
#include <vector>
#include <zlib.h>

namespace packet {

// Gzip Decompressor — reads compressed bytes from any Decompressor source
struct GzipDecompressor : Decompressor {
    std::unique_ptr<Decompressor> source;
    z_stream stream{};
    std::vector<Bytef> inbuf;
    bool finished = false;

    explicit GzipDecompressor(std::unique_ptr<Decompressor> source,
                               std::size_t inbuf_size = 32768)
        : source(std::move(source)), inbuf(inbuf_size) {
        stream.zalloc = Z_NULL;
        stream.zfree = Z_NULL;
        stream.opaque = Z_NULL;
        stream.avail_in = 0;
        stream.next_in = Z_NULL;
        if (inflateInit2(&stream, 15 + 16) != Z_OK)
            throw std::runtime_error("inflateInit2 failed");
    }

    ~GzipDecompressor() override { inflateEnd(&stream); }

    GzipDecompressor(const GzipDecompressor&) = delete;
    GzipDecompressor& operator=(const GzipDecompressor&) = delete;

    std::size_t read(void* buf, std::size_t len) override {
        stream.next_out = static_cast<Bytef*>(buf);
        stream.avail_out = static_cast<uInt>(len);
        while (stream.avail_out > 0 && !finished) {
            if (stream.avail_in == 0) {
                auto n = source->read(inbuf.data(), inbuf.size());
                if (n == 0) break;
                stream.next_in = inbuf.data();
                stream.avail_in = static_cast<uInt>(n);
            }
            int ret = inflate(&stream, Z_NO_FLUSH);
            if (ret == Z_STREAM_END) { finished = true; break; }
            if (ret != Z_OK) throw std::runtime_error("inflate error");
        }
        return len - stream.avail_out;
    }

    bool eof() const override { return finished; }
};

} // namespace packet

#endif