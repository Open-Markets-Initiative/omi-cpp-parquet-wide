#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/Emm.hpp"
#include "../types/EventTime.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/OpeningLevel.hpp"
#include "../types/OpeningTime.hpp"
#include "../types/ConfirmedReferenceLevel.hpp"
#include "../types/ConfirmedReferenceTime.hpp"
#include "../types/ClosingReferenceLevel.hpp"
#include "../types/ClosingReferenceTime.hpp"
#include "../types/PrctVarfromPrevClose.hpp"
#include "../types/HighLevel.hpp"
#include "../types/HighTime.hpp"
#include "../types/LowLevel.hpp"
#include "../types/LowTime.hpp"
#include "../types/LiquidationLevel.hpp"
#include "../types/LiquidationTime.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// IndexSummaryMessage
struct IndexSummaryMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    Emm emm;
    EventTime event_time;
    SymbolIndex symbol_index;
    OpeningLevel opening_level;
    OpeningTime opening_time;
    ConfirmedReferenceLevel confirmed_reference_level;
    ConfirmedReferenceTime confirmed_reference_time;
    ClosingReferenceLevel closing_reference_level;
    ClosingReferenceTime closing_reference_time;
    PrctVarfromPrevClose prct_varfrom_prev_close;
    HighLevel high_level;
    HighTime high_time;
    LowLevel low_level;
    LowTime low_time;
    LiquidationLevel liquidation_level;
    LiquidationTime liquidation_time;

    // parse method
    static IndexSummaryMessage* parse(std::byte* buffer) {
        return reinterpret_cast<IndexSummaryMessage*>(buffer);
    }

    // parse method const
    static const IndexSummaryMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const IndexSummaryMessage*>(buffer);
    }
};

#pragma pack(pop)
}
