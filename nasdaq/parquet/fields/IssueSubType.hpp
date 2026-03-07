#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Issue Sub Type
struct IssueSubType {

    static constexpr auto name = "issue_sub_type";
    static constexpr auto nullable = true;

    IssueSubType() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "Preferred Trust Securities"; }
        if (value == "AI") { return "Alpha Index Et Ns"; }
        if (value == "B") { return "Index Based Derivative"; }
        if (value == "C") { return "Common Shares"; }
        if (value == "CB") { return "Commodity Based Trust Shares"; }
        if (value == "CF") { return "Commodity Futures Trust Shares"; }
        if (value == "CL") { return "Commodity Linked Securities"; }
        if (value == "CM") { return "Commodity Index Trust Shares"; }
        if (value == "CO") { return "Collateralized Mortgage Obligation"; }
        if (value == "CT") { return "Currency Trust Shares"; }
        if (value == "CU") { return "Commodity Currency Linked Securities"; }
        if (value == "CW") { return "Currency Warrants"; }
        if (value == "D") { return "Global Depositary Shares"; }
        if (value == "E") { return "Etf Portfolio Depositary Receipt"; }
        if (value == "EG") { return "Equity Gold Shares"; }
        if (value == "EI") { return "Etn Equity Index Linked Securities"; }
        if (value == "EM") { return "Next Shares Exchange Traded Managed Fund"; }
        if (value == "EN") { return "Exchange Traded Notes"; }
        if (value == "EU") { return "Equity Units"; }
        if (value == "F") { return "Holdrs"; }
        if (value == "FI") { return "Etn Fixed Income Linked Securities"; }
        if (value == "FL") { return "Etn Futures Linked Securities"; }
        if (value == "G") { return "Global Shares"; }
        if (value == "I") { return "Etf Index Fund Shares"; }
        if (value == "IR") { return "Interest Rate"; }
        if (value == "IW") { return "Index Warrant"; }
        if (value == "IX") { return "Index Linked Exchangeable Notes"; }
        if (value == "J") { return "Corporate Backed Trust Security"; }
        if (value == "L") { return "Contingent Litigation Right"; }
        if (value == "LL") { return "Limited Liability Company"; }
        if (value == "M") { return "Equity Based Derivative"; }
        if (value == "MF") { return "Managed Fund Shares"; }
        if (value == "ML") { return "Etn Multi Factor Index Linked Securities"; }
        if (value == "MT") { return "Managed Trust Securities"; }
        if (value == "N") { return "Ny Registry Shares"; }
        if (value == "O") { return "Open Ended Mutual Fund"; }
        if (value == "P") { return "Privately Held Security"; }
        if (value == "PP") { return "Poison Pill"; }
        if (value == "PU") { return "Partnership Units"; }
        if (value == "Q") { return "Closed End Funds"; }
        if (value == "R") { return "Reg S"; }
        if (value == "RC") { return "Commodity Redeemable Commodity Linked Securities"; }
        if (value == "RF") { return "Etn Redeemable Futures Linked Securities"; }
        if (value == "RT") { return "Reit"; }
        if (value == "RU") { return "Commodity Redeemable Currency Linked Securities"; }
        if (value == "S") { return "Seed"; }
        if (value == "SC") { return "Spot Rate Closing"; }
        if (value == "SI") { return "Spot Rate Intraday"; }
        if (value == "T") { return "Tracking Stock"; }
        if (value == "TC") { return "Trust Certificates"; }
        if (value == "TU") { return "Trust Units"; }
        if (value == "U") { return "Portal"; }
        if (value == "V") { return "Contingent Value Right"; }
        if (value == "W") { return "Trust Issued Receipts"; }
        if (value == "WC") { return "World Currency Option"; }
        if (value == "X") { return "Trust"; }
        if (value == "Y") { return "Other"; }
        if (value == "Z") { return "Not Applicable"; }
        return sanitize(value);
    }

    // set issue_sub_type
    void set(const char* value) {
        data = translate(value);
    }

    // set issue_sub_type
    void set(const std::string& value) {
        data = translate(value);
    }

    // set issue_sub_type
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset issue_sub_type field
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

    // append issue_sub_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // issue_sub_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}