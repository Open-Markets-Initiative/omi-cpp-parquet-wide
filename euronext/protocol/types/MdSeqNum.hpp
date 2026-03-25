#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// mDSeqNum
struct MdSeqNum {

    static constexpr const char* name = "Md Seq Num";
    static constexpr std::size_t size =  8;
    using type = std::uint64_t;

    // default constructor
    constexpr MdSeqNum()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MdSeqNum(const std::uint64_t value)
     : value{ value } {}

    // get value of MdSeqNum field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    std::uint64_t value;
};
}
