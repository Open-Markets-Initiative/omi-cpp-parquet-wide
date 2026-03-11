#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: Snapshot Full Refresh 38 No M D Entries Group
struct SnapshotFullRefresh38NoMDEntriesGroup {

    static constexpr auto name = "snapshot_full_refresh_38_no_m_d_entries_group";
    static constexpr auto nullable = true;

    SnapshotFullRefresh38NoMDEntriesGroup() = default;

    // set snapshot_full_refresh_38_no_m_d_entries_group
    void set(const char* value) {
        data = value;
    }

    // set snapshot_full_refresh_38_no_m_d_entries_group
    void set(const std::string& value) {
        data = value;
    }

    // set snapshot_full_refresh_38_no_m_d_entries_group
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set snapshot_full_refresh_38_no_m_d_entries_group
    void set(const char value) {
        data = {value};
    }

    // reset snapshot_full_refresh_38_no_m_d_entries_group field
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

    // append snapshot_full_refresh_38_no_m_d_entries_group
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // snapshot_full_refresh_38_no_m_d_entries_group schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}