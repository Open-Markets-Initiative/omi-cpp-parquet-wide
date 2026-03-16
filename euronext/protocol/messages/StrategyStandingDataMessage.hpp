#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/Emm.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/DerivativesInstrumentTradingCode.hpp"
#include "../types/ExchangeCode.hpp"
#include "../types/MaturityDate.hpp"
#include "../types/StrategyCode.hpp"
#include "../types/ContractSymbolIndex.hpp"
#include "../types/CfiOptional.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// StrategyStandingDataMessage
struct StrategyStandingDataMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    Emm emm;
    SymbolIndex symbol_index;
    DerivativesInstrumentTradingCode derivatives_instrument_trading_code;
    ExchangeCode exchange_code;
    MaturityDate maturity_date;
    StrategyCode strategy_code;
    ContractSymbolIndex contract_symbol_index;
    CfiOptional cfi_optional;

    // parse method
    static StrategyStandingDataMessage* parse(std::byte* buffer) {
        return reinterpret_cast<StrategyStandingDataMessage*>(buffer);
    }

    // parse method const
    static const StrategyStandingDataMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const StrategyStandingDataMessage*>(buffer);
    }
};

#pragma pack(pop)
}
