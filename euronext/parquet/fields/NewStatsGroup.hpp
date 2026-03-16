#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: New Stats Group
struct NewStatsGroup {

    static constexpr auto name = "new_stats_group";
    static constexpr auto nullable = true;

    NewStatsGroup() = default;

    // set new_stats_group
    void set(const char* value) {
        data = value;
    }

    // set new_stats_group
    void set(const std::string& value) {
        data = value;
    }

    // set new_stats_group
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set new_stats_group
    void set(const char value) {
        data = {value};
    }

    // reset new_stats_group field
    void reset() {
        data.reset();
    }

    // sanitize to valid utf-8 ascii
    static std::string sanitize(const std::string& value) {
        std::string result;
        result.reserve(value.size());
        for (unsigned char c : value) {
            if (c >= 0x20 && c < 0x7F) {
                result.push_back(static_cast<char>(c));
            }
        }
        // trim trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }

    // append new_stats_group
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // new_stats_group schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}