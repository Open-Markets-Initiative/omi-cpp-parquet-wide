#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace iex {

// field: System Event
struct SystemEvent {

    static constexpr auto name = "system_event";
    static constexpr auto nullable = true;

    SystemEvent() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "O") { return "Start Of Messages"; }
        if (value == "S") { return "Start Of System Hours"; }
        if (value == "R") { return "Start Of Regular Market Hours"; }
        if (value == "M") { return "End Of Regular Market Hours"; }
        if (value == "E") { return "End Of System Hours"; }
        if (value == "C") { return "End Of Messages"; }
        return sanitize(value);
    }

    // set system_event
    void set(const char* value) {
        data = translate(value);
    }

    // set system_event
    void set(const std::string& value) {
        data = translate(value);
    }

    // set system_event
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset system_event field
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

    // append system_event
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // system_event schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}