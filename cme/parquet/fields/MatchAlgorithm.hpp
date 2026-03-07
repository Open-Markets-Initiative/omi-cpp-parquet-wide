#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: Match Algorithm
struct MatchAlgorithm {

    static constexpr auto name = "match_algorithm";
    static constexpr auto nullable = true;

    MatchAlgorithm() = default;

    // set match_algorithm
    void set(const char* value) {
        data = value;
    }

    // set match_algorithm
    void set(const std::string& value) {
        data = value;
    }

    // set match_algorithm
    void set(const char value) {
        data = {value};
    }

    // reset match_algorithm field
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

    // append match_algorithm
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // match_algorithm schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}