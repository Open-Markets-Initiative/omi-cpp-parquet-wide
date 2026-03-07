#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Reason Code
struct ReasonCode {

    static constexpr auto name = "reason_code";
    static constexpr auto nullable = true;

    ReasonCode() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "T1") { return "Halt News Pending"; }
        if (value == "T2") { return "Halt News Disseminated"; }
        if (value == "T5") { return "Single Security Trading Pause In Effect"; }
        if (value == "T6") { return "Regulatory Halt Extraordinary Market Activity"; }
        if (value == "T8") { return "Halt Etf"; }
        if (value == "T12") { return "Trading Halted"; }
        if (value == "H4") { return "Halt Non Compliance"; }
        if (value == "H9") { return "Halt Filings Not Current"; }
        if (value == "H10") { return "Halt Sec Trading Suspension"; }
        if (value == "H11") { return "Halt Regulatory Concern"; }
        if (value == "O1") { return "Operations Halt"; }
        if (value == "LUDP") { return "Volatility Trading Pause"; }
        if (value == "LUDS") { return "Straddle Condition Trading Pause"; }
        if (value == "MWC1") { return "Circuit Breaker Halt Level 1"; }
        if (value == "MWC2") { return "Circuit Breaker Halt Level 2"; }
        if (value == "MWC3") { return "Circuit Breaker Halt Level 3"; }
        if (value == "MWC0") { return "Carry Over Circuit Breaker Halt"; }
        if (value == "IPO1") { return "Ipo Issue"; }
        if (value == "M1") { return "Corporate Action"; }
        if (value == "M2") { return "Not Available"; }
        if (value == "T3") { return "News And Resumption Times"; }
        if (value == "T7") { return "Trading Pause Quotation Only Period"; }
        if (value == "R4") { return "Qualifications Issues Resolved"; }
        if (value == "R9") { return "Filing Requirements Satisfied"; }
        if (value == "C3") { return "Issuer News Not Forthcoming"; }
        if (value == "C4") { return "Qualifications Halt Ended"; }
        if (value == "C9") { return "Qualifications Halt Concluded"; }
        if (value == "C11") { return "Trade Halt Concluded By Other Regulatory Authority"; }
        if (value == "MWCQ") { return "Market Wide Circuit Breaker Resumption"; }
        if (value == "R1") { return "New Issue Available"; }
        if (value == "R2") { return "Issue Available"; }
        if (value == "IPOQ") { return "Ipo Security Released"; }
        if (value == "IPOE") { return "Ipo Security Positioning Window Extension"; }
        if (value == " ") { return "Reason Not Available"; }
        return sanitize(value);
    }

    // set reason_code
    void set(const char* value) {
        data = translate(value);
    }

    // set reason_code
    void set(const std::string& value) {
        data = translate(value);
    }

    // set reason_code
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset reason_code field
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

    // append reason_code
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // reason_code schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}