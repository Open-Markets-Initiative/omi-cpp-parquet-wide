#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// MMProtections_set bit set
struct MmProtections {

    // underlying type
    using type = std::uint8_t;

    static constexpr const char* name = "Mm Protections";
    static constexpr std::size_t size = 1;

    struct mask {
        static const type Delta = 0x01;
        static const type Volume = 0x02;
        static const type Reserved6 = 0xFC;
    };

    // default constructor
    constexpr MmProtections()
     : value{ 0 } {}

    // Delta
    [[nodiscard]] constexpr bool Delta() const {
        return value & mask::Delta;
    }

    // Volume
    [[nodiscard]] constexpr bool Volume() const {
        return value & mask::Volume;
    }

    // 6 reserved bits
    [[nodiscard]] constexpr bool Reserved6() const {
        return value & mask::Reserved6;
    }

  protected:
    type value;
};
}
