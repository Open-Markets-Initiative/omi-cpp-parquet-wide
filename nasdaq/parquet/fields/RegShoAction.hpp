#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Reg Sho Action
struct RegShoAction {

    static constexpr auto name = "reg_sho_action";
    static constexpr auto nullable = true;

    RegShoAction() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "0") { return "No Price Test"; }
        if (value == "1") { return "Reg Sho Short Sale Price Test Restriction"; }
        if (value == "2") { return "Test Restriction Remains"; }
        return sanitize(value);
    }

    // set reg_sho_action
    void set(const char* value) {
        data = translate(value);
    }

    // set reg_sho_action
    void set(const std::string& value) {
        data = translate(value);
    }

    // set reg_sho_action
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset reg_sho_action field
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

    // append reg_sho_action
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // reg_sho_action schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}