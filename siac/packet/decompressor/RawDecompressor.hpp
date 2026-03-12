#pragma once

#include "Decompressor.hpp"

#include <cstdio>

namespace packet {

// Raw Decompressor — reads directly from FILE*
// This is the only Decompressor that touches FILE*. All others read from
// a Decompressor source, making the whole stack composable.
struct RawDecompressor : Decompressor {
    FILE* file;
    bool at_eof = false;

    explicit RawDecompressor(FILE* fp) : file(fp) {}

    ~RawDecompressor() override {
        if (file) std::fclose(file);
    }

    RawDecompressor(const RawDecompressor&) = delete;
    RawDecompressor& operator=(const RawDecompressor&) = delete;

    std::size_t read(void* buf, std::size_t len) override {
        auto n = std::fread(buf, 1, len, file);
        if (n == 0) at_eof = true;
        return n;
    }

    bool eof() const override { return at_eof; }
};

} // namespace packet