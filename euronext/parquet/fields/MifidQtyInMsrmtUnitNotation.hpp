#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Mifid Qty In Msrmt Unit Notation
struct MifidQtyInMsrmtUnitNotation {

    static constexpr auto name = "mifid_qty_in_msrmt_unit_notation";
    static constexpr auto nullable = true;

    MifidQtyInMsrmtUnitNotation() = default;

    // set mifid_qty_in_msrmt_unit_notation
    void set(const char* value) {
        data = value;
    }

    // set mifid_qty_in_msrmt_unit_notation
    void set(const std::string& value) {
        data = value;
    }

    // set mifid_qty_in_msrmt_unit_notation
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set mifid_qty_in_msrmt_unit_notation
    void set(const char value) {
        data = {value};
    }

    // reset mifid_qty_in_msrmt_unit_notation field
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

    // append mifid_qty_in_msrmt_unit_notation
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // mifid_qty_in_msrmt_unit_notation schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}