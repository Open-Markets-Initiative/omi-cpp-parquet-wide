#pragma once

#include "../types/RetailLiquidityIndicator.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"

namespace iex::equities::tops::iextp::v1_6_6 {

#pragma pack(push, 1)

// broadcasts a real-time Retail Liquidity Indicator Message each time there is an update to IEX's eligible retail liquidity interest during the trading day
struct RetailLiquidityIndicatorMessage {

    RetailLiquidityIndicator retail_liquidity_indicator;
    Timestamp timestamp;
    Symbol symbol;

    // parse method
    static RetailLiquidityIndicatorMessage* parse(std::byte* buffer) {
        return reinterpret_cast<RetailLiquidityIndicatorMessage*>(buffer);
    }

    // parse method const
    static const RetailLiquidityIndicatorMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const RetailLiquidityIndicatorMessage*>(buffer);
    }
};

#pragma pack(pop)
}
