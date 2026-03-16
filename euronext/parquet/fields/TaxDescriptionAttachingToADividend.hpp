#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Tax Description Attaching To A Dividend
struct TaxDescriptionAttachingToADividend {

    static constexpr auto name = "tax_description_attaching_to_a_dividend";
    static constexpr auto nullable = true;

    TaxDescriptionAttachingToADividend() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "D") { return "Deducedat Source"; }
        return sanitize(value);
    }

    // set tax_description_attaching_to_a_dividend
    void set(const char* value) {
        data = translate(value);
    }

    // set tax_description_attaching_to_a_dividend
    void set(const std::string& value) {
        data = translate(value);
    }

    // set tax_description_attaching_to_a_dividend
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset tax_description_attaching_to_a_dividend field
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

    // append tax_description_attaching_to_a_dividend
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // tax_description_attaching_to_a_dividend schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}