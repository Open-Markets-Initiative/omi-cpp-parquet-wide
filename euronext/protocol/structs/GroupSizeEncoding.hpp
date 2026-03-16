#pragma once

#include "../types/BlockLengthShort.hpp"
#include "../types/NumInGroup.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct GroupSizeEncoding {

    BlockLengthShort block_length_short;
    NumInGroup num_in_group;

    // parse method
    static GroupSizeEncoding* parse(std::byte* buffer) {
        return reinterpret_cast<GroupSizeEncoding*>(buffer);
    }

    // parse method const
    static const GroupSizeEncoding* parse(const std::byte* buffer) {
        return reinterpret_cast<const GroupSizeEncoding*>(buffer);
    }
};

#pragma pack(pop)
}
