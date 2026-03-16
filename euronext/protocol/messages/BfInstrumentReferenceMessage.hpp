#pragma once

#include "../types/MdSeqNumOptional.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/OptiqSegment.hpp"
#include "../types/IsinCodeOptional.hpp"
#include "../types/SedolCode.hpp"
#include "../types/LongIssuerName.hpp"
#include "../types/LongInstrumentName.hpp"
#include "../types/CurrencyOptional.hpp"
#include "../types/DateOfInitialListing.hpp"
#include "../types/ShareAmountInIssue.hpp"
#include "../types/OpenedClosedFund.hpp"
#include "../types/LastNavPrice.hpp"
#include "../types/GrossOfCdscIndicator.hpp"
#include "../types/Coupon.hpp"
#include "../types/MaturityDateOptional.hpp"
#include "../types/ClosingPrice.hpp"
#include "../types/MicOptional.hpp"
#include "../types/GrossDividendPayablePerUnit.hpp"
#include "../types/DividendCurrency.hpp"
#include "../types/DividendRecordDate.hpp"
#include "../types/DividendRate.hpp"
#include "../types/ExDividendDate.hpp"
#include "../types/DividendPaymentDate.hpp"
#include "../types/TaxDescriptionAttachingToADividend.hpp"
#include "../types/NextMeeting.hpp"
#include "../types/GrossDividendInEuros.hpp"
#include "../types/IssueDate.hpp"
#include "../types/IssuingCountry.hpp"
#include "../types/CfiOptional.hpp"
#include "../types/PaymentFrequency.hpp"
#include "../types/MinimumAmount.hpp"
#include "../types/InstrumentCategory.hpp"
#include "../types/SecurityCondition.hpp"
#include "../types/MifidPriceNotation.hpp"
#include "../types/PriceIndexLevelDecimals.hpp"
#include "../types/QuantityDecimals.hpp"
#include "../types/AmountDecimals.hpp"
#include "../types/RatioMultiplierDecimals.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// BFInstrumentReferenceMessage
struct BfInstrumentReferenceMessage {

    MdSeqNumOptional md_seq_num_optional;
    RebroadcastIndicator rebroadcast_indicator;
    SymbolIndex symbol_index;
    OptiqSegment optiq_segment;
    IsinCodeOptional isin_code_optional;
    SedolCode sedol_code;
    LongIssuerName long_issuer_name;
    LongInstrumentName long_instrument_name;
    CurrencyOptional currency_optional;
    DateOfInitialListing date_of_initial_listing;
    ShareAmountInIssue share_amount_in_issue;
    OpenedClosedFund opened_closed_fund;
    LastNavPrice last_nav_price;
    GrossOfCdscIndicator gross_of_cdsc_indicator;
    Coupon coupon;
    MaturityDateOptional maturity_date_optional;
    ClosingPrice closing_price;
    MicOptional mic_optional;
    GrossDividendPayablePerUnit gross_dividend_payable_per_unit;
    DividendCurrency dividend_currency;
    DividendRecordDate dividend_record_date;
    DividendRate dividend_rate;
    ExDividendDate ex_dividend_date;
    DividendPaymentDate dividend_payment_date;
    TaxDescriptionAttachingToADividend tax_description_attaching_to_a_dividend;
    NextMeeting next_meeting;
    GrossDividendInEuros gross_dividend_in_euros;
    IssueDate issue_date;
    IssuingCountry issuing_country;
    CfiOptional cfi_optional;
    PaymentFrequency payment_frequency;
    MinimumAmount minimum_amount;
    InstrumentCategory instrument_category;
    SecurityCondition security_condition;
    MifidPriceNotation mifid_price_notation;
    PriceIndexLevelDecimals price_index_level_decimals;
    QuantityDecimals quantity_decimals;
    AmountDecimals amount_decimals;
    RatioMultiplierDecimals ratio_multiplier_decimals;

    // parse method
    static BfInstrumentReferenceMessage* parse(std::byte* buffer) {
        return reinterpret_cast<BfInstrumentReferenceMessage*>(buffer);
    }

    // parse method const
    static const BfInstrumentReferenceMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const BfInstrumentReferenceMessage*>(buffer);
    }
};

#pragma pack(pop)
}
