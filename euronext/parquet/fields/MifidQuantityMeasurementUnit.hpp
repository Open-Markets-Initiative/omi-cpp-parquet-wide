#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Mifid Quantity Measurement Unit
struct MifidQuantityMeasurementUnit {

    static constexpr auto name = "mifid_quantity_measurement_unit";
    static constexpr auto nullable = true;

    MifidQuantityMeasurementUnit() = default;

    // set mifid_quantity_measurement_unit
    void set(const char* value) {
        data = value;
    }

    // set mifid_quantity_measurement_unit
    void set(const std::string& value) {
        data = value;
    }

    // set mifid_quantity_measurement_unit
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set mifid_quantity_measurement_unit
    void set(const char value) {
        data = {value};
    }

    // reset mifid_quantity_measurement_unit field
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

    // append mifid_quantity_measurement_unit
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // mifid_quantity_measurement_unit schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}