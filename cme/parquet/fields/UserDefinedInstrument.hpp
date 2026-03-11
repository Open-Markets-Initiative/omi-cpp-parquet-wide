#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: User Defined Instrument
struct UserDefinedInstrument {

    static constexpr auto name = "user_defined_instrument";
    static constexpr auto nullable = true;

    UserDefinedInstrument() = default;

    // set user_defined_instrument
    void set(const char* value) {
        data = value;
    }

    // set user_defined_instrument
    void set(const std::string& value) {
        data = value;
    }

    // set user_defined_instrument
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set user_defined_instrument
    void set(const char value) {
        data = {value};
    }

    // reset user_defined_instrument field
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

    // append user_defined_instrument
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // user_defined_instrument schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}