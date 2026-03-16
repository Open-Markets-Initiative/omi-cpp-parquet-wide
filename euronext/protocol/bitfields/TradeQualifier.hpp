#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// TradeQualifier_set bit set
struct TradeQualifier {

    // underlying type
    using type = std::uint8_t;

    static constexpr const char* name = "Trade Qualifier";
    static constexpr std::size_t size = 1;

    struct mask {
        static const type UncrossingTrade = 0x01;
        static const type FirstTradePrice = 0x02;
        static const type PassiveOrder = 0x04;
        static const type AggressiveOrder = 0x08;
        static const type TradeCreationByMarketOperations = 0x10;
        static const type NavTradeExpressedInBps = 0x20;
        static const type NavTradeExpressedInPriceCurrency = 0x40;
        static const type DeferredPublication = 0x80;
    };

    // default constructor
    constexpr TradeQualifier()
     : value{ 0 } {}

    // UncrossingTrade
    [[nodiscard]] constexpr bool UncrossingTrade() const {
        return value & mask::UncrossingTrade;
    }

    // FirstTradePrice
    [[nodiscard]] constexpr bool FirstTradePrice() const {
        return value & mask::FirstTradePrice;
    }

    // PassiveOrder
    [[nodiscard]] constexpr bool PassiveOrder() const {
        return value & mask::PassiveOrder;
    }

    // AggressiveOrder
    [[nodiscard]] constexpr bool AggressiveOrder() const {
        return value & mask::AggressiveOrder;
    }

    // TradeCreationByMarketOperations
    [[nodiscard]] constexpr bool TradeCreationByMarketOperations() const {
        return value & mask::TradeCreationByMarketOperations;
    }

    // NAVTradeExpressedInBps
    [[nodiscard]] constexpr bool NavTradeExpressedInBps() const {
        return value & mask::NavTradeExpressedInBps;
    }

    // NAVTradeExpressedInPriceCurrency
    [[nodiscard]] constexpr bool NavTradeExpressedInPriceCurrency() const {
        return value & mask::NavTradeExpressedInPriceCurrency;
    }

    // DeferredPublication
    [[nodiscard]] constexpr bool DeferredPublication() const {
        return value & mask::DeferredPublication;
    }

  protected:
    type value;
};
}
