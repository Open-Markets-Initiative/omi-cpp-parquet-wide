#pragma once

#include "../types/LegSymbolIndex.hpp"
#include "../types/LegRatio.hpp"
#include "../types/LegLastPx.hpp"
#include "../types/LegLastQty.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct PackageComponentsGroup {

    LegSymbolIndex leg_symbol_index;
    LegRatio leg_ratio;
    LegLastPx leg_last_px;
    LegLastQty leg_last_qty;

    // parse method
    static PackageComponentsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<PackageComponentsGroup*>(buffer);
    }

    // parse method const
    static const PackageComponentsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const PackageComponentsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
