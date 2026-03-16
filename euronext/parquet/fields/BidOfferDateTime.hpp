#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Bid Offer Date Time
struct BidOfferDateTime {

    static constexpr auto name = "bid_offer_date_time";
    static constexpr auto nullable = true;

    BidOfferDateTime() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest bid_offer_date_time record field
    void reset() {
        data.reset();
    }

    // append bid_offer_date_time
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // bid_offer_date_time arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}