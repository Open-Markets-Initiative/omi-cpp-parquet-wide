#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Market Category
struct MarketCategory {

    static constexpr auto name = "market_category";
    static constexpr auto nullable = true;

    MarketCategory() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "Q") { return "Nasdaq Global Select Market"; }
        if (value == "G") { return "Nasdaq Global Market"; }
        if (value == "S") { return "Nasdaq Capital Market"; }
        if (value == "N") { return "Nyse"; }
        if (value == "A") { return "Nyse American"; }
        if (value == "P") { return "Nyse Arca"; }
        if (value == "M") { return "Nyse Texas"; }
        if (value == "Z") { return "Bats Z"; }
        if (value == "V") { return "Investors Exchange"; }
        if (value == " ") { return "Not Available"; }
        return sanitize(value);
    }

    // set market_category
    void set(const char* value) {
        data = translate(value);
    }

    // set market_category
    void set(const std::string& value) {
        data = translate(value);
    }

    // set market_category
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset market_category field
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

    // append market_category
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // market_category schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}