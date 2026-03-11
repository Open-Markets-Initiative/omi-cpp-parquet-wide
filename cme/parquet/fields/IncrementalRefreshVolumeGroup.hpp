#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: Incremental Refresh Volume Group
struct IncrementalRefreshVolumeGroup {

    static constexpr auto name = "incremental_refresh_volume_group";
    static constexpr auto nullable = true;

    IncrementalRefreshVolumeGroup() = default;

    // set incremental_refresh_volume_group
    void set(const char* value) {
        data = value;
    }

    // set incremental_refresh_volume_group
    void set(const std::string& value) {
        data = value;
    }

    // set incremental_refresh_volume_group
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set incremental_refresh_volume_group
    void set(const char value) {
        data = {value};
    }

    // reset incremental_refresh_volume_group field
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

    // append incremental_refresh_volume_group
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // incremental_refresh_volume_group schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}