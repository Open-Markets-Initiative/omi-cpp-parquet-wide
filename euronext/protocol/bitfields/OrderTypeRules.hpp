#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// OrderTypeRules_set bit set
struct OrderTypeRules {

    // underlying type
    using type = std::uint16_t;

    static constexpr const char* name = "Order Type Rules";
    static constexpr std::size_t size = 2;

    struct mask {
        static const type Market = 0x0001;
        static const type Limit = 0x0002;
        static const type StopStopLoss = 0x0004;
        static const type StopLimit = 0x0008;
        static const type MarketOnOpenMoo = 0x0010;
        static const type TradeAtSettlement = 0x0020;
        static const type Reserved10 = 0xFFC0;
    };

    // default constructor
    constexpr OrderTypeRules()
     : value{ 0 } {}

    // Market
    [[nodiscard]] constexpr bool Market() const {
        return value & mask::Market;
    }

    // Limit
    [[nodiscard]] constexpr bool Limit() const {
        return value & mask::Limit;
    }

    // StopStopLoss
    [[nodiscard]] constexpr bool StopStopLoss() const {
        return value & mask::StopStopLoss;
    }

    // StopLimit
    [[nodiscard]] constexpr bool StopLimit() const {
        return value & mask::StopLimit;
    }

    // MarketOnOpenMOO
    [[nodiscard]] constexpr bool MarketOnOpenMoo() const {
        return value & mask::MarketOnOpenMoo;
    }

    // TradeAtSettlement
    [[nodiscard]] constexpr bool TradeAtSettlement() const {
        return value & mask::TradeAtSettlement;
    }

    // 10 reserved bits
    [[nodiscard]] constexpr bool Reserved10() const {
        return value & mask::Reserved10;
    }

  protected:
    type value;
};
}
