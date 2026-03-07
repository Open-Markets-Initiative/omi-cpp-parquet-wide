#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: Md Feed Type
struct MdFeedType {

    static constexpr auto name = "md_feed_type";
    static constexpr auto nullable = true;

    MdFeedType() = default;

    // set md_feed_type
    void set(const char* value) {
        data = value;
    }

    // set md_feed_type
    void set(const std::string& value) {
        data = value;
    }

    // set md_feed_type
    void set(const char value) {
        data = {value};
    }

    // reset md_feed_type field
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

    // append md_feed_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // md_feed_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}