#pragma once

#include "../types/LegSymbolIndex.hpp"
#include "../types/LegPrice.hpp"
#include "../types/LegRatio.hpp"
#include "../types/LegBuySell.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct StrategyStandingDataGroup {

    LegSymbolIndex leg_symbol_index;
    LegPrice leg_price;
    LegRatio leg_ratio;
    LegBuySell leg_buy_sell;

    // parse method
    static StrategyStandingDataGroup* parse(std::byte* buffer) {
        return reinterpret_cast<StrategyStandingDataGroup*>(buffer);
    }

    // parse method const
    static const StrategyStandingDataGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const StrategyStandingDataGroup*>(buffer);
    }
};

#pragma pack(pop)
}
