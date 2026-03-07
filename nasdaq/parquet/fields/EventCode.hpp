#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Event Code
struct EventCode {

    static constexpr auto name = "event_code";
    static constexpr auto nullable = true;

    EventCode() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "O") { return "Start Of Messages"; }
        if (value == "S") { return "Start Of System Hours"; }
        if (value == "Q") { return "Start Of Market Hours"; }
        if (value == "M") { return "End Of Market Hours"; }
        if (value == "E") { return "End Of System Hours"; }
        if (value == "C") { return "End Of Messages"; }
        return sanitize(value);
    }

    // set event_code
    void set(const char* value) {
        data = translate(value);
    }

    // set event_code
    void set(const std::string& value) {
        data = translate(value);
    }

    // set event_code
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset event_code field
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

    // append event_code
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // event_code schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}