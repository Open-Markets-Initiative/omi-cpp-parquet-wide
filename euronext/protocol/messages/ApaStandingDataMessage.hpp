#pragma once

#include "../types/MdSeqNumOptional.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/MifidInstrumentIdType.hpp"
#include "../types/MifidInstrumentId.hpp"
#include "../types/FullInstrumentName.hpp"
#include "../types/CfiOptional.hpp"
#include "../types/NotionalCurrency.hpp"
#include "../types/SecondNotionalCurrency.hpp"
#include "../types/PriceMultiplier.hpp"
#include "../types/PriceMultiplierDecimals.hpp"
#include "../types/UnderlyingIsinCode.hpp"
#include "../types/UnderlyingIndexName.hpp"
#include "../types/UnderlyingIndexTerm.hpp"
#include "../types/OptionType.hpp"
#include "../types/StrikePrice.hpp"
#include "../types/StrikePriceDecimals.hpp"
#include "../types/ExerStyle.hpp"
#include "../types/MaturityDateOptional.hpp"
#include "../types/ExpiryDate.hpp"
#include "../types/SettlementMethod.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// APAStandingDataMessage
struct ApaStandingDataMessage {

    MdSeqNumOptional md_seq_num_optional;
    RebroadcastIndicator rebroadcast_indicator;
    MifidInstrumentIdType mifid_instrument_id_type;
    MifidInstrumentId mifid_instrument_id;
    FullInstrumentName full_instrument_name;
    CfiOptional cfi_optional;
    NotionalCurrency notional_currency;
    SecondNotionalCurrency second_notional_currency;
    PriceMultiplier price_multiplier;
    PriceMultiplierDecimals price_multiplier_decimals;
    UnderlyingIsinCode underlying_isin_code;
    UnderlyingIndexName underlying_index_name;
    UnderlyingIndexTerm underlying_index_term;
    OptionType option_type;
    StrikePrice strike_price;
    StrikePriceDecimals strike_price_decimals;
    ExerStyle exer_style;
    MaturityDateOptional maturity_date_optional;
    ExpiryDate expiry_date;
    SettlementMethod settlement_method;

    // parse method
    static ApaStandingDataMessage* parse(std::byte* buffer) {
        return reinterpret_cast<ApaStandingDataMessage*>(buffer);
    }

    // parse method const
    static const ApaStandingDataMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const ApaStandingDataMessage*>(buffer);
    }
};

#pragma pack(pop)
}
