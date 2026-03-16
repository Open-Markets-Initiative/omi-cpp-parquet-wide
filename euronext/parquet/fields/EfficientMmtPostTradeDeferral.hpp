#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Efficient Mmt Post Trade Deferral
struct EfficientMmtPostTradeDeferral {

    static constexpr auto name = "efficient_mmt_post_trade_deferral";
    static constexpr auto nullable = true;

    EfficientMmtPostTradeDeferral() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "1") { return "Lmtf"; }
        if (value == "2") { return "Datf"; }
        if (value == "3") { return "Volo"; }
        if (value == "4") { return "Fwaf"; }
        if (value == "5") { return "Idaf"; }
        if (value == "6") { return "Volw"; }
        if (value == "7") { return "Fulf"; }
        if (value == "8") { return "Fula"; }
        if (value == "9") { return "Fulv"; }
        if (value == "V") { return "Fulj"; }
        if (value == "W") { return "Coaf"; }
        if (value == "-") { return "Not Applicable"; }
        return sanitize(value);
    }

    // set efficient_mmt_post_trade_deferral
    void set(const char* value) {
        data = translate(value);
    }

    // set efficient_mmt_post_trade_deferral
    void set(const std::string& value) {
        data = translate(value);
    }

    // set efficient_mmt_post_trade_deferral
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset efficient_mmt_post_trade_deferral field
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

    // append efficient_mmt_post_trade_deferral
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // efficient_mmt_post_trade_deferral schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}