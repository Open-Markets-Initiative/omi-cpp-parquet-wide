#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: Strike Currency
struct StrikeCurrency {

    static constexpr auto name = "strike_currency";
    static constexpr auto nullable = true;

    StrikeCurrency() = default;

    // set strike_currency
    void set(const char* value) {
        data = value;
    }

    // set strike_currency
    void set(const std::string& value) {
        data = value;
    }

    // set strike_currency
    void set(const char value) {
        data = {value};
    }

    // reset strike_currency field
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

    // append strike_currency
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // strike_currency schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}