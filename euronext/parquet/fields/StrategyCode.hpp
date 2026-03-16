#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Strategy Code
struct StrategyCode {

    static constexpr auto name = "strategy_code";
    static constexpr auto nullable = true;

    StrategyCode() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "Jelly Roll"; }
        if (value == "B") { return "Butterfly"; }
        if (value == "C") { return "Callor Put Cabinet"; }
        if (value == "D") { return "Spread"; }
        if (value == "E") { return "Calendar Spread"; }
        if (value == "F") { return "Diagonal Calendar Spread"; }
        if (value == "G") { return "Guts"; }
        if (value == "H") { return "Twoby One Ratio Spread"; }
        if (value == "I") { return "Iron Butterfly"; }
        if (value == "J") { return "Combo"; }
        if (value == "K") { return "Strangle"; }
        if (value == "L") { return "Ladder"; }
        if (value == "M") { return "Strip"; }
        if (value == "N") { return "Straddle Calendar Spread"; }
        if (value == "O") { return "Pack"; }
        if (value == "P") { return "Diagonal Straddle Calendar Spread"; }
        if (value == "Q") { return "Simple Inter Commodity Spread"; }
        if (value == "R") { return "Conversion Reversal"; }
        if (value == "S") { return "Straddle"; }
        if (value == "V") { return "Volatility Trade"; }
        if (value == "W") { return "Condor"; }
        if (value == "X") { return "Box"; }
        if (value == "Y") { return "Bundle"; }
        if (value == "Z") { return "Reduced Tick Spread"; }
        if (value == "a") { return "Ladderversus Underlying"; }
        if (value == "b") { return "Butterflyversus Underlying"; }
        if (value == "c") { return "Call Spreadversus Putversus Underlying"; }
        if (value == "d") { return "Callor Put Spreadversus Underlying"; }
        if (value == "e") { return "Callor Put Calendar Spreadversus Underlying"; }
        if (value == "f") { return "Call Put Diagonal Calendar Spreadversus Underlying"; }
        if (value == "g") { return "Gutsversus Underlying"; }
        if (value == "h") { return "Twoby One Callor Put Ratio Spreadversus Underlying"; }
        if (value == "i") { return "Iron Butterflyversus Underlying"; }
        if (value == "j") { return "Comboversus Underlying"; }
        if (value == "k") { return "Strangleversus Underlying"; }
        if (value == "m") { return "Exchangefor Physical"; }
        if (value == "n") { return "Straddle Calendar Spreadversus Underlying"; }
        if (value == "p") { return "Put Spreadversus Callversus Underlying"; }
        if (value == "q") { return "Diagonal Straddle Calendar Spreadversus Underlying"; }
        if (value == "r") { return "Synthetic"; }
        if (value == "s") { return "Straddleversus Underlying"; }
        if (value == "t") { return "Condorversus Underlying"; }
        if (value == "u") { return "Buy Write"; }
        if (value == "v") { return "Iron Condorversus Underlying"; }
        if (value == "w") { return "Iron Condor"; }
        if (value == "x") { return "Call Spreadversus Sella Put"; }
        if (value == "y") { return "Put Spreadversus Sella Call"; }
        if (value == "z") { return "Put Straddleversus Sella Callora Put"; }
        return sanitize(value);
    }

    // set strategy_code
    void set(const char* value) {
        data = translate(value);
    }

    // set strategy_code
    void set(const std::string& value) {
        data = translate(value);
    }

    // set strategy_code
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset strategy_code field
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

    // append strategy_code
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // strategy_code schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}