#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Underlying Value Message Type
struct UnderlyingValueMessageType {

    static constexpr auto name = "underlying_value_message_type";
    static constexpr auto nullable = true;

    UnderlyingValueMessageType() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == " ") { return "Index Based On Last Sale"; }
        if (value == "I") { return "Index Based On Bid And Offer"; }
        return sanitize(value);
    }

    // set underlying_value_message_type
    void set(const char* value) {
        data = translate(value);
    }

    // set underlying_value_message_type
    void set(const std::string& value) {
        data = translate(value);
    }

    // set underlying_value_message_type
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset underlying_value_message_type field
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
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }

    // append underlying_value_message_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // underlying_value_message_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}