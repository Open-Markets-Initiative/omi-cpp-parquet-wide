#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Open Eligibility Status
struct OpenEligibilityStatus {

    static constexpr auto name = "open_eligibility_status";
    static constexpr auto nullable = true;

    OpenEligibilityStatus() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "N") { return "Not Eligible"; }
        if (value == "Y") { return "Eligible"; }
        return sanitize(value);
    }

    // set open_eligibility_status
    void set(const char* value) {
        data = translate(value);
    }

    // set open_eligibility_status
    void set(const std::string& value) {
        data = translate(value);
    }

    // set open_eligibility_status
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset open_eligibility_status field
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

    // append open_eligibility_status
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // open_eligibility_status schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}