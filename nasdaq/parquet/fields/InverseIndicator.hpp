#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Inverse Indicator
struct InverseIndicator {

    static constexpr auto name = "inverse_indicator";
    static constexpr auto nullable = true;

    InverseIndicator() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "Y") { return "Inverse Etp"; }
        if (value == "N") { return "Not Inverse Etp"; }
        return sanitize(value);
    }

    // set inverse_indicator
    void set(const char* value) {
        data = translate(value);
    }

    // set inverse_indicator
    void set(const std::string& value) {
        data = translate(value);
    }

    // set inverse_indicator
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset inverse_indicator field
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

    // append inverse_indicator
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // inverse_indicator schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}