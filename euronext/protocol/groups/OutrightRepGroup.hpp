#pragma once

#include "../types/Emm.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct OutrightRepGroup {

    Emm emm;

    // parse method
    static OutrightRepGroup* parse(std::byte* buffer) {
        return reinterpret_cast<OutrightRepGroup*>(buffer);
    }

    // parse method const
    static const OutrightRepGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const OutrightRepGroup*>(buffer);
    }
};

#pragma pack(pop)
}
