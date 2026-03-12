#pragma once

#ifdef HAS_LZMA

#include "Decompressor.hpp"

#include <cstdint>
#include <memory>
#include <stdexcept>
#include <vector>
#include <lzma.h>

namespace packet {

// LZMA/XZ Decompressor
struct LzmaDecompressor : Decompressor {
    std::unique_ptr<Decompressor> source;
    lzma_stream stream;
    std::vector<std::uint8_t> inbuf;
    bool finished = false;

    explicit LzmaDecompressor(std::unique_ptr<Decompressor> source,
                               std::size_t inbuf_size = 32768)
        : source(std::move(source)), stream(LZMA_STREAM_INIT), inbuf(inbuf_size) {
        if (lzma_stream_decoder(&stream, UINT64_MAX, 0) != LZMA_OK)
            throw std::runtime_error("lzma_stream_decoder failed");
    }

    ~LzmaDecompressor() override { lzma_end(&stream); }

    LzmaDecompressor(const LzmaDecompressor&) = delete;
    LzmaDecompressor& operator=(const LzmaDecompressor&) = delete;

    std::size_t read(void* buf, std::size_t len) override {
        stream.next_out = static_cast<std::uint8_t*>(buf);
        stream.avail_out = len;
        while (stream.avail_out > 0 && !finished) {
            if (stream.avail_in == 0) {
                auto n = source->read(inbuf.data(), inbuf.size());
                if (n == 0) {
                    auto ret = lzma_code(&stream, LZMA_FINISH);
                    if (ret == LZMA_STREAM_END) finished = true;
                    break;
                }
                stream.next_in = inbuf.data();
                stream.avail_in = n;
            }
            auto ret = lzma_code(&stream, LZMA_RUN);
            if (ret == LZMA_STREAM_END) { finished = true; break; }
            if (ret != LZMA_OK) throw std::runtime_error("lzma_code error");
        }
        return len - stream.avail_out;
    }

    bool eof() const override { return finished; }
};

} // namespace packet

#endif