#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Open Interest Message Type
struct OpenInterestMessageType {

    static constexpr auto name = "open_interest_message_type";
    static constexpr auto nullable = true;

    OpenInterestMessageType() = default;

    // set open_interest_message_type
    void set(const char* value) {
        data = value;
    }

    // set open_interest_message_type
    void set(const std::string& value) {
        data = value;
    }

    // set open_interest_message_type
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set open_interest_message_type
    void set(const char value) {
        data = {value};
    }

    // reset open_interest_message_type field
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

    // append open_interest_message_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // open_interest_message_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}