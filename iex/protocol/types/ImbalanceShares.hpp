#pragma once

#include <cstddef>
#include <cstdint>

namespace iex::equities::tops::iextp::v1_6_6 {

// Number of unpaired shares at the Reference Price using orders on the Auction Book
struct ImbalanceShares {

    static constexpr const char* name = "Imbalance Shares";
    static constexpr std::size_t size =  4;

    // default constructor
    constexpr ImbalanceShares()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ImbalanceShares(const std::uint32_t value)
     : value{ value } {}

    // get value of ImbalanceShares field
    [[nodiscard]] std::uint32_t get() const {
        return value;
    }

  protected:
    std::uint32_t value;
};
}
