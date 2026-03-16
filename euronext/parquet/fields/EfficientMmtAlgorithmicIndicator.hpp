#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Efficient Mmt Algorithmic Indicator
struct EfficientMmtAlgorithmicIndicator {

    static constexpr auto name = "efficient_mmt_algorithmic_indicator";
    static constexpr auto nullable = true;

    EfficientMmtAlgorithmicIndicator() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "H") { return "Algo"; }
        if (value == "-") { return "No Algorithmic Trade"; }
        return sanitize(value);
    }

    // set efficient_mmt_algorithmic_indicator
    void set(const char* value) {
        data = translate(value);
    }

    // set efficient_mmt_algorithmic_indicator
    void set(const std::string& value) {
        data = translate(value);
    }

    // set efficient_mmt_algorithmic_indicator
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset efficient_mmt_algorithmic_indicator field
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

    // append efficient_mmt_algorithmic_indicator
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // efficient_mmt_algorithmic_indicator schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}