#pragma once

#include "../types/MdSeqNumOptional.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/EventTime.hpp"
#include "../types/SecurityCondition.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// BFInstrumentSuspensionMessage
struct BfInstrumentSuspensionMessage {

    MdSeqNumOptional md_seq_num_optional;
    RebroadcastIndicator rebroadcast_indicator;
    SymbolIndex symbol_index;
    EventTime event_time;
    SecurityCondition security_condition;

    // parse method
    static BfInstrumentSuspensionMessage* parse(std::byte* buffer) {
        return reinterpret_cast<BfInstrumentSuspensionMessage*>(buffer);
    }

    // parse method const
    static const BfInstrumentSuspensionMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const BfInstrumentSuspensionMessage*>(buffer);
    }
};

#pragma pack(pop)
}
