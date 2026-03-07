#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: Security Exchange
struct SecurityExchange {

    static constexpr auto name = "security_exchange";
    static constexpr auto nullable = true;

    SecurityExchange() = default;

    // set security_exchange
    void set(const char* value) {
        data = value;
    }

    // set security_exchange
    void set(const std::string& value) {
        data = value;
    }

    // set security_exchange
    void set(const char value) {
        data = {value};
    }

    // reset security_exchange field
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
        // trim trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }

    // append security_exchange
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // security_exchange schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}