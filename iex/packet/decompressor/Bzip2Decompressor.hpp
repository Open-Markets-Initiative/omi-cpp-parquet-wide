#pragma once

#ifdef HAS_BZIP2

#include "Decompressor.hpp"

#include <memory>
#include <stdexcept>
#include <vector>
#include <bzlib.h>

namespace packet {

// Bzip2 Decompressor
struct Bzip2Decompressor : Decompressor {
    std::unique_ptr<Decompressor> source;
    bz_stream stream{};
    std::vector<char> inbuf;
    bool finished = false;

    explicit Bzip2Decompressor(std::unique_ptr<Decompressor> source,
                                std::size_t inbuf_size = 32768)
        : source(std::move(source)), inbuf(inbuf_size) {
        stream.bzalloc = nullptr;
        stream.bzfree = nullptr;
        stream.opaque = nullptr;
        if (BZ2_bzDecompressInit(&stream, 0, 0) != BZ_OK)
            throw std::runtime_error("BZ2_bzDecompressInit failed");
    }

    ~Bzip2Decompressor() override { BZ2_bzDecompressEnd(&stream); }

    Bzip2Decompressor(const Bzip2Decompressor&) = delete;
    Bzip2Decompressor& operator=(const Bzip2Decompressor&) = delete;

    std::size_t read(void* buf, std::size_t len) override {
        stream.next_out = static_cast<char*>(buf);
        stream.avail_out = static_cast<unsigned int>(len);
        while (stream.avail_out > 0 && !finished) {
            if (stream.avail_in == 0) {
                auto n = source->read(inbuf.data(), inbuf.size());
                if (n == 0) break;
                stream.next_in = inbuf.data();
                stream.avail_in = static_cast<unsigned int>(n);
            }
            int ret = BZ2_bzDecompress(&stream);
            if (ret == BZ_STREAM_END) { finished = true; break; }
            if (ret != BZ_OK) throw std::runtime_error("BZ2_bzDecompress error");
        }
        return len - stream.avail_out;
    }

    bool eof() const override { return finished; }
};

} // namespace packet

#endif