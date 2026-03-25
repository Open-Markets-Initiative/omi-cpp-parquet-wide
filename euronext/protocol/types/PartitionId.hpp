#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// partitionID
struct PartitionId {

    static constexpr const char* name = "Partition Id";
    static constexpr std::size_t size =  2;
    using type = std::uint16_t;

    // default constructor
    constexpr PartitionId()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PartitionId(const std::uint16_t value)
     : value{ value } {}

    // get value of PartitionId field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
