#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: Settl Currency
struct SettlCurrency {

    static constexpr auto name = "settl_currency";
    static constexpr auto nullable = true;

    SettlCurrency() = default;

    // set settl_currency
    void set(const char* value) {
        data = value;
    }

    // set settl_currency
    void set(const std::string& value) {
        data = value;
    }

    // set settl_currency
    void set(const char value) {
        data = {value};
    }

    // reset settl_currency field
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

    // append settl_currency
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // settl_currency schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}