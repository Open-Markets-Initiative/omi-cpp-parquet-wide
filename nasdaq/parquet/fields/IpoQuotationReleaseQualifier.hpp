#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Ipo Quotation Release Qualifier
struct IpoQuotationReleaseQualifier {

    static constexpr auto name = "ipo_quotation_release_qualifier";
    static constexpr auto nullable = true;

    IpoQuotationReleaseQualifier() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "Anticipated Quotation Release Time"; }
        if (value == "C") { return "Ipo Release Canceled Or Postponed"; }
        return sanitize(value);
    }

    // set ipo_quotation_release_qualifier
    void set(const char* value) {
        data = translate(value);
    }

    // set ipo_quotation_release_qualifier
    void set(const std::string& value) {
        data = translate(value);
    }

    // set ipo_quotation_release_qualifier
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset ipo_quotation_release_qualifier field
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

    // append ipo_quotation_release_qualifier
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // ipo_quotation_release_qualifier schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}