#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// snapshotTime
struct SnapshotTime {

    static constexpr const char* name = "Snapshot Time";
    static constexpr std::size_t size =  8;

    // default constructor
    constexpr SnapshotTime()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit SnapshotTime(const std::uint64_t value)
     : value{ value } {}

    // get value of SnapshotTime field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    std::uint64_t value;
};
}
