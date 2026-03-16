#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/Emm.hpp"
#include "../types/EventTime.hpp"
#include "../types/ContractSymbolIndex.hpp"
#include "../types/MifidExecutionId.hpp"
#include "../types/StrategyCode.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// LISPackageStructureMessage
struct LisPackageStructureMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    Emm emm;
    EventTime event_time;
    ContractSymbolIndex contract_symbol_index;
    MifidExecutionId mifid_execution_id;
    StrategyCode strategy_code;

    // parse method
    static LisPackageStructureMessage* parse(std::byte* buffer) {
        return reinterpret_cast<LisPackageStructureMessage*>(buffer);
    }

    // parse method const
    static const LisPackageStructureMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const LisPackageStructureMessage*>(buffer);
    }
};

#pragma pack(pop)
}
