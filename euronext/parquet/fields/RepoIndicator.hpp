#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Repo Indicator
struct RepoIndicator {

    static constexpr auto name = "repo_indicator";
    static constexpr auto nullable = true;

    RepoIndicator() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest repo_indicator record field
    void reset() {
        data.reset();
    }

    // append repo_indicator
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // repo_indicator arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}