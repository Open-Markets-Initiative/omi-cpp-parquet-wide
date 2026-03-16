#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Mmt Off Book Automated Indicator
struct MmtOffBookAutomatedIndicator {

    static constexpr auto name = "mmt_off_book_automated_indicator";
    static constexpr auto nullable = true;

    MmtOffBookAutomatedIndicator() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "M") { return "Off Book Non Automated"; }
        if (value == "Q") { return "Off Book Automated"; }
        if (value == "-") { return "Unspecifiedordoesnotapply"; }
        return sanitize(value);
    }

    // set mmt_off_book_automated_indicator
    void set(const char* value) {
        data = translate(value);
    }

    // set mmt_off_book_automated_indicator
    void set(const std::string& value) {
        data = translate(value);
    }

    // set mmt_off_book_automated_indicator
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset mmt_off_book_automated_indicator field
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

    // append mmt_off_book_automated_indicator
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // mmt_off_book_automated_indicator schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}