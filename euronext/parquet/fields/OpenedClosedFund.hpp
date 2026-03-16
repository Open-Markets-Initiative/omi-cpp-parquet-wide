#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Opened Closed Fund
struct OpenedClosedFund {

    static constexpr auto name = "opened_closed_fund";
    static constexpr auto nullable = true;

    OpenedClosedFund() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "O") { return "Open"; }
        if (value == "C") { return "Closed"; }
        return sanitize(value);
    }

    // set opened_closed_fund
    void set(const char* value) {
        data = translate(value);
    }

    // set opened_closed_fund
    void set(const std::string& value) {
        data = translate(value);
    }

    // set opened_closed_fund
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset opened_closed_fund field
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

    // append opened_closed_fund
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // opened_closed_fund schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}