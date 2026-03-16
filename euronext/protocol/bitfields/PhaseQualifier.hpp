#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// PhaseQualifier_set bit set
struct PhaseQualifier {

    // underlying type
    using type = std::uint16_t;

    static constexpr const char* name = "Phase Qualifier";
    static constexpr std::size_t size = 2;

    struct mask {
        static const type NoQualifier = 0x0001;
        static const type CallBboOnly = 0x0002;
        static const type TradingAtLast = 0x0004;
        static const type RandomUncrossing = 0x0008;
        static const type Suspended = 0x0010;
        static const type WholesaleAllowed = 0x0020;
        static const type StressedMarketConditions = 0x0040;
        static const type ExceptionalMarketConditions = 0x0080;
        static const type UnusedPhaseQualifierset8 = 0x0100;
        static const type QuotingPeriod = 0x0200;
        static const type ExecutionPreventionAcrossAllFirms = 0x0400;
        static const type Reserved5 = 0xF800;
    };

    // default constructor
    constexpr PhaseQualifier()
     : value{ 0 } {}

    // NoQualifier
    [[nodiscard]] constexpr bool NoQualifier() const {
        return value & mask::NoQualifier;
    }

    // CallBBOOnly
    [[nodiscard]] constexpr bool CallBboOnly() const {
        return value & mask::CallBboOnly;
    }

    // TradingAtLast
    [[nodiscard]] constexpr bool TradingAtLast() const {
        return value & mask::TradingAtLast;
    }

    // RandomUncrossing
    [[nodiscard]] constexpr bool RandomUncrossing() const {
        return value & mask::RandomUncrossing;
    }

    // Suspended
    [[nodiscard]] constexpr bool Suspended() const {
        return value & mask::Suspended;
    }

    // WholesaleAllowed
    [[nodiscard]] constexpr bool WholesaleAllowed() const {
        return value & mask::WholesaleAllowed;
    }

    // StressedMarketConditions
    [[nodiscard]] constexpr bool StressedMarketConditions() const {
        return value & mask::StressedMarketConditions;
    }

    // ExceptionalMarketConditions
    [[nodiscard]] constexpr bool ExceptionalMarketConditions() const {
        return value & mask::ExceptionalMarketConditions;
    }

    // Unused PhaseQualifier_set 8
    [[nodiscard]] constexpr bool UnusedPhaseQualifierset8() const {
        return value & mask::UnusedPhaseQualifierset8;
    }

    // QuotingPeriod
    [[nodiscard]] constexpr bool QuotingPeriod() const {
        return value & mask::QuotingPeriod;
    }

    // ExecutionPreventionAcrossAllFirms
    [[nodiscard]] constexpr bool ExecutionPreventionAcrossAllFirms() const {
        return value & mask::ExecutionPreventionAcrossAllFirms;
    }

    // 5 reserved bits
    [[nodiscard]] constexpr bool Reserved5() const {
        return value & mask::Reserved5;
    }

  protected:
    type value;
};
}
