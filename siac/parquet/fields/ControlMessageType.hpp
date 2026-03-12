#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Control Message Type
struct ControlMessageType {

    static constexpr auto name = "control_message_type";
    static constexpr auto nullable = true;

    ControlMessageType() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "C") { return "Start Of Day"; }
        if (value == "E") { return "Start Of Summary"; }
        if (value == "F") { return "End Of Summary"; }
        if (value == "J") { return "End Of Day"; }
        if (value == "K") { return "Reset Block Sequence Number"; }
        if (value == "L") { return "Start Of Open Interest"; }
        if (value == "M") { return "End Of Open Interest"; }
        if (value == "N") { return "Line Integrity"; }
        if (value == "P") { return "Disaster Recovery Data Center Activation"; }
        return sanitize(value);
    }

    // set control_message_type
    void set(const char* value) {
        data = translate(value);
    }

    // set control_message_type
    void set(const std::string& value) {
        data = translate(value);
    }

    // set control_message_type
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset control_message_type field
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

    // append control_message_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // control_message_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}