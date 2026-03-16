#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/ContractSymbolIndex.hpp"
#include "../types/InstrumentEventDate.hpp"
#include "../types/IsinCode.hpp"
#include "../types/CfiOptional.hpp"
#include "../types/MaturityDate.hpp"
#include "../types/LotSize.hpp"
#include "../types/StrikePrice.hpp"
#include "../types/LastTradingDate.hpp"
#include "../types/DaysToExpiry.hpp"
#include "../types/DerivativesInstrumentTradingCodeOptional.hpp"
#include "../types/DerivativesInstrumentType.hpp"
#include "../types/ExpiryCycleType.hpp"
#include "../types/UnderlyingDerivativesInstrumentTradingCode.hpp"
#include "../types/UnderlyingSymbolIndex.hpp"
#include "../types/TradingUnit.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// OutrightStandingDataMessage
struct OutrightStandingDataMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    SymbolIndex symbol_index;
    ContractSymbolIndex contract_symbol_index;
    InstrumentEventDate instrument_event_date;
    IsinCode isin_code;
    CfiOptional cfi_optional;
    MaturityDate maturity_date;
    LotSize lot_size;
    StrikePrice strike_price;
    LastTradingDate last_trading_date;
    DaysToExpiry days_to_expiry;
    DerivativesInstrumentTradingCodeOptional derivatives_instrument_trading_code_optional;
    DerivativesInstrumentType derivatives_instrument_type;
    ExpiryCycleType expiry_cycle_type;
    UnderlyingDerivativesInstrumentTradingCode underlying_derivatives_instrument_trading_code;
    UnderlyingSymbolIndex underlying_symbol_index;
    TradingUnit trading_unit;

    // parse method
    static OutrightStandingDataMessage* parse(std::byte* buffer) {
        return reinterpret_cast<OutrightStandingDataMessage*>(buffer);
    }

    // parse method const
    static const OutrightStandingDataMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const OutrightStandingDataMessage*>(buffer);
    }
};

#pragma pack(pop)
}
