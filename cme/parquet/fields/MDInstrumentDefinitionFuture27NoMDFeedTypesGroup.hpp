#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: M D Instrument Definition Future 27 No M D Feed Types Group
struct MDInstrumentDefinitionFuture27NoMDFeedTypesGroup {

    static constexpr auto name = "m_d_instrument_definition_future_27_no_m_d_feed_types_group";
    static constexpr auto nullable = true;

    MDInstrumentDefinitionFuture27NoMDFeedTypesGroup() = default;

    // set m_d_instrument_definition_future_27_no_m_d_feed_types_group
    void set(const char* value) {
        data = value;
    }

    // set m_d_instrument_definition_future_27_no_m_d_feed_types_group
    void set(const std::string& value) {
        data = value;
    }

    // set m_d_instrument_definition_future_27_no_m_d_feed_types_group
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set m_d_instrument_definition_future_27_no_m_d_feed_types_group
    void set(const char value) {
        data = {value};
    }

    // reset m_d_instrument_definition_future_27_no_m_d_feed_types_group field
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

    // append m_d_instrument_definition_future_27_no_m_d_feed_types_group
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // m_d_instrument_definition_future_27_no_m_d_feed_types_group schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}