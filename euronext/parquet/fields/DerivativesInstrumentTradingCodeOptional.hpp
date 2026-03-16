#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Derivatives Instrument Trading Code Optional
struct DerivativesInstrumentTradingCodeOptional {

    static constexpr auto name = "derivatives_instrument_trading_code_optional";
    static constexpr auto nullable = true;

    DerivativesInstrumentTradingCodeOptional() = default;

    // set derivatives_instrument_trading_code_optional
    void set(const char* value) {
        data = value;
    }

    // set derivatives_instrument_trading_code_optional
    void set(const std::string& value) {
        data = value;
    }

    // set derivatives_instrument_trading_code_optional
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set derivatives_instrument_trading_code_optional
    void set(const char value) {
        data = {value};
    }

    // reset derivatives_instrument_trading_code_optional field
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

    // append derivatives_instrument_trading_code_optional
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // derivatives_instrument_trading_code_optional schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}