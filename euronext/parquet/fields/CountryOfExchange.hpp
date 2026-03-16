#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Country Of Exchange
struct CountryOfExchange {

    static constexpr auto name = "country_of_exchange";
    static constexpr auto nullable = true;

    CountryOfExchange() = default;

    // set country_of_exchange
    void set(const char* value) {
        data = value;
    }

    // set country_of_exchange
    void set(const std::string& value) {
        data = value;
    }

    // set country_of_exchange
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set country_of_exchange
    void set(const char value) {
        data = {value};
    }

    // reset country_of_exchange field
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

    // append country_of_exchange
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // country_of_exchange schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}