#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/Emm.hpp"
#include "../types/EventTime.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/IndexLevel.hpp"
#include "../types/PctgOfCapitalization.hpp"
#include "../types/PrctVarfromPrevClose.hpp"
#include "../types/NumTradedInstruments.hpp"
#include "../types/IndexLevelType.hpp"
#include "../types/IndexPriceCode.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// RealTimeIndexMessage
struct RealTimeIndexMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    Emm emm;
    EventTime event_time;
    SymbolIndex symbol_index;
    IndexLevel index_level;
    PctgOfCapitalization pctg_of_capitalization;
    PrctVarfromPrevClose prct_varfrom_prev_close;
    NumTradedInstruments num_traded_instruments;
    IndexLevelType index_level_type;
    IndexPriceCode index_price_code;

    // parse method
    static RealTimeIndexMessage* parse(std::byte* buffer) {
        return reinterpret_cast<RealTimeIndexMessage*>(buffer);
    }

    // parse method const
    static const RealTimeIndexMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const RealTimeIndexMessage*>(buffer);
    }
};

#pragma pack(pop)
}
