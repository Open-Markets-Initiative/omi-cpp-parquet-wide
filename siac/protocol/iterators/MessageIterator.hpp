#pragma once

#include "../definitions.hpp"

namespace siac::opra::recipient::obi::v6_2 {
// MessageIterator
struct MessageIterator {

    const std::byte* current = nullptr;

    const BlockHeader* block_header = nullptr;

    std::uint8_t version = 0;
    std::uint8_t messages_in_block = 0;
    std::uint8_t entry_index = 0;
    const std::byte* entry = nullptr;

    // initialize group iterator
    void initialize(const std::byte* data) {

        current = data;

        block_header = BlockHeader::parse(current);
        current += sizeof(BlockHeader);

        version = block_header->version.get();
        messages_in_block = block_header->messages_in_block.get();
        entry_index = 0;
        entry = nullptr;
    }

    // next entry
    bool next() {

        if (entry_index >= messages_in_block) {
            return false;
        }

        entry = current;
        entry_index++;
        current += version;

        return true;
    }

    // reset iterator
    void reset() {
        current = nullptr;

        block_header = nullptr;

        version = 0;
        messages_in_block = 0;
        entry_index = 0;
        entry = nullptr;
    }
};
}
