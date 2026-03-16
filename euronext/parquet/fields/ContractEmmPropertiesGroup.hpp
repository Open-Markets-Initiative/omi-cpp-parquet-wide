#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Contract Emm Properties Group
struct ContractEmmPropertiesGroup {

    static constexpr auto name = "contract_emm_properties_group";
    static constexpr auto nullable = true;

    ContractEmmPropertiesGroup() = default;

    // set contract_emm_properties_group
    void set(const char* value) {
        data = value;
    }

    // set contract_emm_properties_group
    void set(const std::string& value) {
        data = value;
    }

    // set contract_emm_properties_group
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set contract_emm_properties_group
    void set(const char value) {
        data = {value};
    }

    // reset contract_emm_properties_group field
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

    // append contract_emm_properties_group
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // contract_emm_properties_group schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}