#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Type Of Market Admission
struct TypeOfMarketAdmission {

    static constexpr auto name = "type_of_market_admission";
    static constexpr auto nullable = true;

    TypeOfMarketAdmission() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "Instrumentstradedontheprimarymarket"; }
        if (value == "B") { return "Instrumentstradedonthesecondarymarket"; }
        if (value == "C") { return "Instrumentstradedonthe New Market"; }
        if (value == "D") { return "Nonregulatedmarketinstrumentstradedonthefreemarket"; }
        if (value == "E") { return "Nonregulatedmarket Alternext"; }
        if (value == "F") { return "Nonlisted"; }
        if (value == "G") { return "Regulated Market Nonequities"; }
        if (value == "H") { return "Regulated Market Equities Segment A"; }
        if (value == "I") { return "Regulated Market Equities Segment B"; }
        if (value == "J") { return "Regulated Market Equities Segment C"; }
        if (value == "K") { return "Regulated Market Allsecurities Special Segment"; }
        if (value == "L") { return "Regulated Market Equities Otherinstruments"; }
        if (value == "S") { return "Opcvmsicom Inonlisted French Investment Funds"; }
        if (value == "6") { return "Off Market"; }
        if (value == "7") { return "Gold Currenciesand Indices"; }
        if (value == "9") { return "Foreign"; }
        return sanitize(value);
    }

    // set type_of_market_admission
    void set(const char* value) {
        data = translate(value);
    }

    // set type_of_market_admission
    void set(const std::string& value) {
        data = translate(value);
    }

    // set type_of_market_admission
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset type_of_market_admission field
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

    // append type_of_market_admission
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // type_of_market_admission schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}