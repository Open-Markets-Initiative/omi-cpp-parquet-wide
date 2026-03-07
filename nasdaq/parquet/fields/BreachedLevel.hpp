#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Breached Level
struct BreachedLevel {

    static constexpr auto name = "breached_level";
    static constexpr auto nullable = true;

    BreachedLevel() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "1") { return "Level 1"; }
        if (value == "2") { return "Level 2"; }
        if (value == "3") { return "Level 3"; }
        return sanitize(value);
    }

    // set breached_level
    void set(const char* value) {
        data = translate(value);
    }

    // set breached_level
    void set(const std::string& value) {
        data = translate(value);
    }

    // set breached_level
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset breached_level field
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

    // append breached_level
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // breached_level schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}