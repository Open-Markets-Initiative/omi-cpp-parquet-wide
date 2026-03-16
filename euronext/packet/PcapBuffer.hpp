#pragma once

#include "decompressor/Decompressor.hpp"

#include <cstddef>
#include <cstring>
#include <memory>
#include <vector>

namespace packet {

constexpr std::size_t default_buffer_size = 65536;

// Pcap buffer — decompressed byte buffer with refill/shift
class PcapBuffer {
    std::unique_ptr<Decompressor> source;
    std::vector<std::byte> buf;
    std::size_t pos = 0;
    std::size_t valid = 0;

public:
    explicit PcapBuffer(std::unique_ptr<Decompressor> source,
                         std::size_t buf_size = default_buffer_size)
        : source(std::move(source)), buf(buf_size) {}

    PcapBuffer(const PcapBuffer&) = delete;
    PcapBuffer& operator=(const PcapBuffer&) = delete;
    PcapBuffer(PcapBuffer&&) = default;
    PcapBuffer& operator=(PcapBuffer&&) = default;

    bool ensure(std::size_t n) {
        if (n > buf.size()) return false;
        while (available() < n) {
            if (!refill()) return false;
        }
        return true;
    }

    std::size_t available() const { return valid - pos; }
    const std::byte* data() const { return buf.data() + pos; }
    void consume(std::size_t n) { pos += n; }

private:
    bool refill() {
        std::size_t remaining = valid - pos;
        if (pos > 0) {
            if (remaining > 0)
                std::memmove(buf.data(), buf.data() + pos, remaining);
            pos = 0;
            valid = remaining;
        }
        std::size_t space = buf.size() - valid;
        if (space == 0) return false;
        auto got = source->read(buf.data() + valid, space);
        valid += got;
        return got > 0;
    }
};

} // namespace packet