#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Etp Flag
struct EtpFlag {

    static constexpr auto name = "etp_flag";
    static constexpr auto nullable = true;

    EtpFlag() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "Y") { return "Etp"; }
        if (value == "N") { return "Not Etp"; }
        if (value == " ") { return "Not Available"; }
        return sanitize(value);
    }

    // set etp_flag
    void set(const char* value) {
        data = translate(value);
    }

    // set etp_flag
    void set(const std::string& value) {
        data = translate(value);
    }

    // set etp_flag
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset etp_flag field
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

    // append etp_flag
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // etp_flag schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}