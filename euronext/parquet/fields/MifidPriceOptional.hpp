#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Mifid Price Optional
struct MifidPriceOptional {

    static constexpr auto name = "mifid_price_optional";
    static constexpr auto nullable = true;

    MifidPriceOptional() = default;

    // set mifid_price_optional
    void set(const char* value) {
        data = value;
    }

    // set mifid_price_optional
    void set(const std::string& value) {
        data = value;
    }

    // set mifid_price_optional
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set mifid_price_optional
    void set(const char value) {
        data = {value};
    }

    // reset mifid_price_optional field
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

    // append mifid_price_optional
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // mifid_price_optional schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}