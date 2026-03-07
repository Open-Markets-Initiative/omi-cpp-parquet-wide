#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Ipo Flag
struct IpoFlag {

    static constexpr auto name = "ipo_flag";
    static constexpr auto nullable = true;

    IpoFlag() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "Y") { return "Set Up For Ipo Release"; }
        if (value == "N") { return "Not Set Up For Ipo Release"; }
        if (value == "Z") { return "Non Ipo New Listed Security"; }
        if (value == " ") { return "Not Available"; }
        return sanitize(value);
    }

    // set ipo_flag
    void set(const char* value) {
        data = translate(value);
    }

    // set ipo_flag
    void set(const std::string& value) {
        data = translate(value);
    }

    // set ipo_flag
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset ipo_flag field
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

    // append ipo_flag
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // ipo_flag schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}