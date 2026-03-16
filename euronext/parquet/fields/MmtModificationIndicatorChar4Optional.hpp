#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Mmt Modification Indicator char 4 optional
struct MmtModificationIndicatorChar4Optional {

    static constexpr auto name = "mmt_modification_indicator_char_4_optional";
    static constexpr auto nullable = true;

    MmtModificationIndicatorChar4Optional() = default;

    // set mmt_modification_indicator_char_4_optional
    void set(const char* value) {
        data = value;
    }

    // set mmt_modification_indicator_char_4_optional
    void set(const std::string& value) {
        data = value;
    }

    // set mmt_modification_indicator_char_4_optional
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set mmt_modification_indicator_char_4_optional
    void set(const char value) {
        data = {value};
    }

    // reset mmt_modification_indicator_char_4_optional field
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

    // append mmt_modification_indicator_char_4_optional
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // mmt_modification_indicator_char_4_optional schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}