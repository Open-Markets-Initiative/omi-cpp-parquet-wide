#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Printable
struct Printable {

    static constexpr auto name = "printable";
    static constexpr auto nullable = true;

    Printable() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "N") { return "No"; }
        if (value == "Y") { return "Yes"; }
        return sanitize(value);
    }

    // set printable
    void set(const char* value) {
        data = translate(value);
    }

    // set printable
    void set(const std::string& value) {
        data = translate(value);
    }

    // set printable
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset printable field
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

    // append printable
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // printable schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}