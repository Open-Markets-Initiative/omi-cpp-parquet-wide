#pragma once

#ifdef HAS_ZSTD

#include "Decompressor.hpp"

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <vector>
#include <zstd.h>

namespace packet {

// Zstd Decompressor
struct ZstdDecompressor : Decompressor {
    std::unique_ptr<Decompressor> source;
    ZSTD_DStream* dstream = nullptr;
    std::vector<std::byte> inbuf;
    ZSTD_inBuffer input{};
    bool finished = false;

    explicit ZstdDecompressor(std::unique_ptr<Decompressor> source,
                               std::size_t inbuf_size = 32768)
        : source(std::move(source)), inbuf(inbuf_size) {
        dstream = ZSTD_createDStream();
        if (!dstream)
            throw std::runtime_error("ZSTD_createDStream failed");
        ZSTD_initDStream(dstream);
    }

    ~ZstdDecompressor() override {
        if (dstream) ZSTD_freeDStream(dstream);
    }

    ZstdDecompressor(const ZstdDecompressor&) = delete;
    ZstdDecompressor& operator=(const ZstdDecompressor&) = delete;

    std::size_t read(void* buf, std::size_t len) override {
        ZSTD_outBuffer output{buf, len, 0};
        while (output.pos < output.size && !finished) {
            if (input.pos >= input.size) {
                auto n = source->read(inbuf.data(), inbuf.size());
                if (n == 0) { finished = true; break; }
                input = {inbuf.data(), n, 0};
            }
            auto ret = ZSTD_decompressStream(dstream, &output, &input);
            if (ZSTD_isError(ret))
                throw std::runtime_error("ZSTD_decompressStream error");
            if (ret == 0) { finished = true; break; }
        }
        return output.pos;
    }

    bool eof() const override { return finished; }
};

} // namespace packet

#endif