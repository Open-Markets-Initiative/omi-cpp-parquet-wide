#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Contract Type
struct ContractType {

    static constexpr auto name = "contract_type";
    static constexpr auto nullable = true;

    ContractType() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "F") { return "Future"; }
        if (value == "O") { return "Option"; }
        if (value == "U") { return "Underlying"; }
        return sanitize(value);
    }

    // set contract_type
    void set(const char* value) {
        data = translate(value);
    }

    // set contract_type
    void set(const std::string& value) {
        data = translate(value);
    }

    // set contract_type
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset contract_type field
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

    // append contract_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // contract_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}