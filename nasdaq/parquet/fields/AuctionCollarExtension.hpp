#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Auction Collar Extension
struct AuctionCollarExtension {

    static constexpr auto name = "auction_collar_extension";
    static constexpr auto nullable = true;

    AuctionCollarExtension() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest auction_collar_extension record field
    void reset() {
        data.reset();
    }

    // append auction_collar_extension
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // auction_collar_extension arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}