#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Operational Halt Action
struct OperationalHaltAction {

    static constexpr auto name = "operational_halt_action";
    static constexpr auto nullable = true;

    OperationalHaltAction() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "H") { return "Halted"; }
        if (value == "T") { return "Trading Resumed"; }
        return sanitize(value);
    }

    // set operational_halt_action
    void set(const char* value) {
        data = translate(value);
    }

    // set operational_halt_action
    void set(const std::string& value) {
        data = translate(value);
    }

    // set operational_halt_action
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset operational_halt_action field
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

    // append operational_halt_action
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // operational_halt_action schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}