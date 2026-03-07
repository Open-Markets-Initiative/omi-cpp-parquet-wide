#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Issue Classification
struct IssueClassification {

    static constexpr auto name = "issue_classification";
    static constexpr auto nullable = true;

    IssueClassification() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "American Depositary Share"; }
        if (value == "B") { return "Bond"; }
        if (value == "C") { return "Common Stock"; }
        if (value == "F") { return "Depository Receipt"; }
        if (value == "I") { return "I 144 A"; }
        if (value == "L") { return "Limited Partnership"; }
        if (value == "N") { return "Notes"; }
        if (value == "O") { return "Ordinary Share"; }
        if (value == "P") { return "Preferred Stock"; }
        if (value == "Q") { return "Other Securities"; }
        if (value == "R") { return "Right"; }
        if (value == "S") { return "Shares Of Beneficial Interest"; }
        if (value == "T") { return "Convertible Debenture"; }
        if (value == "U") { return "Unit"; }
        if (value == "V") { return "Units Of Beneficial Interest"; }
        if (value == "W") { return "Warrant"; }
        return sanitize(value);
    }

    // set issue_classification
    void set(const char* value) {
        data = translate(value);
    }

    // set issue_classification
    void set(const std::string& value) {
        data = translate(value);
    }

    // set issue_classification
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset issue_classification field
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

    // append issue_classification
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // issue_classification schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}