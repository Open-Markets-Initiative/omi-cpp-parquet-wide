#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Mother Stock Isin
struct MotherStockIsin {

    static constexpr auto name = "mother_stock_isin";
    static constexpr auto nullable = true;

    MotherStockIsin() = default;

    // set mother_stock_isin
    void set(const char* value) {
        data = value;
    }

    // set mother_stock_isin
    void set(const std::string& value) {
        data = value;
    }

    // set mother_stock_isin
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set mother_stock_isin
    void set(const char value) {
        data = {value};
    }

    // reset mother_stock_isin field
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

    // append mother_stock_isin
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // mother_stock_isin schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}