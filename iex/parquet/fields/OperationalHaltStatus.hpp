#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace iex {

// field: Operational Halt Status
struct OperationalHaltStatus {

    static constexpr auto name = "operational_halt_status";
    static constexpr auto nullable = true;

    OperationalHaltStatus() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "O") { return "Iex Specific Operational Trading Halt"; }
        if (value == "N") { return "Not Operationally Halted On Iex"; }
        return sanitize(value);
    }

    // set operational_halt_status
    void set(const char* value) {
        data = translate(value);
    }

    // set operational_halt_status
    void set(const std::string& value) {
        data = translate(value);
    }

    // set operational_halt_status
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset operational_halt_status field
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

    // append operational_halt_status
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // operational_halt_status schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}