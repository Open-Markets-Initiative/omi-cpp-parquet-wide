#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// StrategyAuthorized_set bit set
struct StrategyAuthorized {

    // underlying type
    using type = std::uint64_t;

    static constexpr const char* name = "Strategy Authorized";
    static constexpr std::size_t size = 8;
    static const std::uint64_t no_value = 18446744073709551615;

    struct mask {
        static const type JellyRoll = 0x0000000000000001;
        static const type Butterfly = 0x0000000000000002;
        static const type CallOrPutCabinet = 0x0000000000000004;
        static const type Spread = 0x0000000000000008;
        static const type CalendarSpread = 0x0000000000000010;
        static const type DiagonalCalendarSpread = 0x0000000000000020;
        static const type Guts = 0x0000000000000040;
        static const type TwoByOneRatioSpread = 0x0000000000000080;
        static const type IronButterfly = 0x0000000000000100;
        static const type Combo = 0x0000000000000200;
        static const type Strangle = 0x0000000000000400;
        static const type Ladder = 0x0000000000000800;
        static const type Strip = 0x0000000000001000;
        static const type StraddleCalendarSpread = 0x0000000000002000;
        static const type Pack = 0x0000000000004000;
        static const type DiagonalStraddleCalendarSpread = 0x0000000000008000;
        static const type SimpleInterCommoditySpread = 0x0000000000010000;
        static const type ConversionReversal = 0x0000000000020000;
        static const type Straddle = 0x0000000000040000;
        static const type VolatilityTrade = 0x0000000000080000;
        static const type Condor = 0x0000000000100000;
        static const type Box = 0x0000000000200000;
        static const type Bundle = 0x0000000000400000;
        static const type ReducedTickSpread = 0x0000000000800000;
        static const type LadderVersusUnderlying = 0x0000000001000000;
        static const type ButterflyVersusUnderlying = 0x0000000002000000;
        static const type CallSpreadVersusPutVersusUnderlying = 0x0000000004000000;
        static const type CallOrPutSpreadVersusUnderlying = 0x0000000008000000;
        static const type CallOrPutCalendarSpreadVersusUnderlying = 0x0000000010000000;
        static const type CallPutDiagonalCalendarSpreadVersusUnderlying = 0x0000000020000000;
        static const type GutsVersusUnderlying = 0x0000000040000000;
        static const type TwoByOneCallOrPutRatioSpreadVersusUnderlying = 0x0000000080000000;
        static const type IronButterflyVersusUnderlying = 0x0000000000000001;
        static const type ComboVersusUnderlying = 0x0000000000000002;
        static const type StrangleVersusUnderlying = 0x0000000000000004;
        static const type ExchangeForPhysical = 0x0000000000000008;
        static const type StraddleCalendarSpreadVersusUnderlying = 0x0000000000000010;
        static const type PutSpreadVersusCallVersusUnderlying = 0x0000000000000020;
        static const type DiagonalStraddleCalendarSpreadVersusUnderlying = 0x0000000000000040;
        static const type Synthetic = 0x0000000000000080;
        static const type StraddleVersusUnderlying = 0x0000000000000100;
        static const type CondorVersusUnderlying = 0x0000000000000200;
        static const type BuyWrite = 0x0000000000000400;
        static const type IronCondorVersusUnderlying = 0x0000000000000800;
        static const type IronCondor = 0x0000000000001000;
        static const type CallSpreadVersusSellAPut = 0x0000000000002000;
        static const type PutSpreadVersusSellACall = 0x0000000000004000;
        static const type PutStraddleVersusSellACallOrAPut = 0x0000000000008000;
        static const type Reserved16 = 0x00000000FFFF0000;
    };

    // default constructor
    constexpr StrategyAuthorized()
     : value{ 0 } {}

    // JellyRoll
    [[nodiscard]] constexpr bool JellyRoll() const {
        return value & mask::JellyRoll;
    }

    // Butterfly
    [[nodiscard]] constexpr bool Butterfly() const {
        return value & mask::Butterfly;
    }

    // CallOrPutCabinet
    [[nodiscard]] constexpr bool CallOrPutCabinet() const {
        return value & mask::CallOrPutCabinet;
    }

    // Spread
    [[nodiscard]] constexpr bool Spread() const {
        return value & mask::Spread;
    }

    // CalendarSpread
    [[nodiscard]] constexpr bool CalendarSpread() const {
        return value & mask::CalendarSpread;
    }

    // DiagonalCalendarSpread
    [[nodiscard]] constexpr bool DiagonalCalendarSpread() const {
        return value & mask::DiagonalCalendarSpread;
    }

    // Guts
    [[nodiscard]] constexpr bool Guts() const {
        return value & mask::Guts;
    }

    // TwoByOneRatioSpread
    [[nodiscard]] constexpr bool TwoByOneRatioSpread() const {
        return value & mask::TwoByOneRatioSpread;
    }

    // IronButterfly
    [[nodiscard]] constexpr bool IronButterfly() const {
        return value & mask::IronButterfly;
    }

    // Combo
    [[nodiscard]] constexpr bool Combo() const {
        return value & mask::Combo;
    }

    // Strangle
    [[nodiscard]] constexpr bool Strangle() const {
        return value & mask::Strangle;
    }

    // Ladder
    [[nodiscard]] constexpr bool Ladder() const {
        return value & mask::Ladder;
    }

    // Strip
    [[nodiscard]] constexpr bool Strip() const {
        return value & mask::Strip;
    }

    // StraddleCalendarSpread
    [[nodiscard]] constexpr bool StraddleCalendarSpread() const {
        return value & mask::StraddleCalendarSpread;
    }

    // Pack
    [[nodiscard]] constexpr bool Pack() const {
        return value & mask::Pack;
    }

    // DiagonalStraddleCalendarSpread
    [[nodiscard]] constexpr bool DiagonalStraddleCalendarSpread() const {
        return value & mask::DiagonalStraddleCalendarSpread;
    }

    // SimpleInterCommoditySpread
    [[nodiscard]] constexpr bool SimpleInterCommoditySpread() const {
        return value & mask::SimpleInterCommoditySpread;
    }

    // ConversionReversal
    [[nodiscard]] constexpr bool ConversionReversal() const {
        return value & mask::ConversionReversal;
    }

    // Straddle
    [[nodiscard]] constexpr bool Straddle() const {
        return value & mask::Straddle;
    }

    // VolatilityTrade
    [[nodiscard]] constexpr bool VolatilityTrade() const {
        return value & mask::VolatilityTrade;
    }

    // Condor
    [[nodiscard]] constexpr bool Condor() const {
        return value & mask::Condor;
    }

    // Box
    [[nodiscard]] constexpr bool Box() const {
        return value & mask::Box;
    }

    // Bundle
    [[nodiscard]] constexpr bool Bundle() const {
        return value & mask::Bundle;
    }

    // ReducedTickSpread
    [[nodiscard]] constexpr bool ReducedTickSpread() const {
        return value & mask::ReducedTickSpread;
    }

    // LadderVersusUnderlying
    [[nodiscard]] constexpr bool LadderVersusUnderlying() const {
        return value & mask::LadderVersusUnderlying;
    }

    // ButterflyVersusUnderlying
    [[nodiscard]] constexpr bool ButterflyVersusUnderlying() const {
        return value & mask::ButterflyVersusUnderlying;
    }

    // CallSpreadVersusPutVersusUnderlying
    [[nodiscard]] constexpr bool CallSpreadVersusPutVersusUnderlying() const {
        return value & mask::CallSpreadVersusPutVersusUnderlying;
    }

    // CallOrPutSpreadVersusUnderlying
    [[nodiscard]] constexpr bool CallOrPutSpreadVersusUnderlying() const {
        return value & mask::CallOrPutSpreadVersusUnderlying;
    }

    // CallOrPutCalendarSpreadVersusUnderlying
    [[nodiscard]] constexpr bool CallOrPutCalendarSpreadVersusUnderlying() const {
        return value & mask::CallOrPutCalendarSpreadVersusUnderlying;
    }

    // CallPutDiagonalCalendarSpreadVersusUnderlying
    [[nodiscard]] constexpr bool CallPutDiagonalCalendarSpreadVersusUnderlying() const {
        return value & mask::CallPutDiagonalCalendarSpreadVersusUnderlying;
    }

    // GutsVersusUnderlying
    [[nodiscard]] constexpr bool GutsVersusUnderlying() const {
        return value & mask::GutsVersusUnderlying;
    }

    // TwoByOneCallOrPutRatioSpreadVersusUnderlying
    [[nodiscard]] constexpr bool TwoByOneCallOrPutRatioSpreadVersusUnderlying() const {
        return value & mask::TwoByOneCallOrPutRatioSpreadVersusUnderlying;
    }

    // IronButterflyVersusUnderlying
    [[nodiscard]] constexpr bool IronButterflyVersusUnderlying() const {
        return value & mask::IronButterflyVersusUnderlying;
    }

    // ComboVersusUnderlying
    [[nodiscard]] constexpr bool ComboVersusUnderlying() const {
        return value & mask::ComboVersusUnderlying;
    }

    // StrangleVersusUnderlying
    [[nodiscard]] constexpr bool StrangleVersusUnderlying() const {
        return value & mask::StrangleVersusUnderlying;
    }

    // ExchangeForPhysical
    [[nodiscard]] constexpr bool ExchangeForPhysical() const {
        return value & mask::ExchangeForPhysical;
    }

    // StraddleCalendarSpreadVersusUnderlying
    [[nodiscard]] constexpr bool StraddleCalendarSpreadVersusUnderlying() const {
        return value & mask::StraddleCalendarSpreadVersusUnderlying;
    }

    // PutSpreadVersusCallVersusUnderlying
    [[nodiscard]] constexpr bool PutSpreadVersusCallVersusUnderlying() const {
        return value & mask::PutSpreadVersusCallVersusUnderlying;
    }

    // DiagonalStraddleCalendarSpreadVersusUnderlying
    [[nodiscard]] constexpr bool DiagonalStraddleCalendarSpreadVersusUnderlying() const {
        return value & mask::DiagonalStraddleCalendarSpreadVersusUnderlying;
    }

    // Synthetic
    [[nodiscard]] constexpr bool Synthetic() const {
        return value & mask::Synthetic;
    }

    // StraddleVersusUnderlying
    [[nodiscard]] constexpr bool StraddleVersusUnderlying() const {
        return value & mask::StraddleVersusUnderlying;
    }

    // CondorVersusUnderlying
    [[nodiscard]] constexpr bool CondorVersusUnderlying() const {
        return value & mask::CondorVersusUnderlying;
    }

    // BuyWrite
    [[nodiscard]] constexpr bool BuyWrite() const {
        return value & mask::BuyWrite;
    }

    // IronCondorVersusUnderlying
    [[nodiscard]] constexpr bool IronCondorVersusUnderlying() const {
        return value & mask::IronCondorVersusUnderlying;
    }

    // IronCondor
    [[nodiscard]] constexpr bool IronCondor() const {
        return value & mask::IronCondor;
    }

    // CallSpreadVersusSellAPut
    [[nodiscard]] constexpr bool CallSpreadVersusSellAPut() const {
        return value & mask::CallSpreadVersusSellAPut;
    }

    // PutSpreadVersusSellACall
    [[nodiscard]] constexpr bool PutSpreadVersusSellACall() const {
        return value & mask::PutSpreadVersusSellACall;
    }

    // PutStraddleVersusSellACallOrAPut
    [[nodiscard]] constexpr bool PutStraddleVersusSellACallOrAPut() const {
        return value & mask::PutStraddleVersusSellACallOrAPut;
    }

    // 16 reserved bits
    [[nodiscard]] constexpr bool Reserved16() const {
        return value & mask::Reserved16;
    }

  protected:
    type value;
};
}
