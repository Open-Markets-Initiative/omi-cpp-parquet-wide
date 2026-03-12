#pragma once

#include "Decompressor.hpp"

#include <cstring>
#include <memory>

namespace packet {

// Prefixed Decompressor — replays a small prefix then delegates to inner source.
// Used after peeking magic bytes for format detection.
struct PrefixedDecompressor : Decompressor {
    std::unique_ptr<Decompressor> inner;
    unsigned char prefix[8];
    std::size_t prefix_len;
    std::size_t prefix_pos = 0;

    PrefixedDecompressor(std::unique_ptr<Decompressor> inner,
                          const void* prefix, std::size_t len)
        : inner(std::move(inner)), prefix_len(len) {
        std::memcpy(this->prefix, prefix, len);
    }

    PrefixedDecompressor(const PrefixedDecompressor&) = delete;
    PrefixedDecompressor& operator=(const PrefixedDecompressor&) = delete;

    std::size_t read(void* buf, std::size_t len) override {
        auto* out = static_cast<unsigned char*>(buf);
        std::size_t total = 0;
        while (total < len && prefix_pos < prefix_len) {
            out[total++] = prefix[prefix_pos++];
        }
        if (total < len) {
            total += inner->read(out + total, len - total);
        }
        return total;
    }

    bool eof() const override {
        return prefix_pos >= prefix_len && inner->eof();
    }
};

} // namespace packet