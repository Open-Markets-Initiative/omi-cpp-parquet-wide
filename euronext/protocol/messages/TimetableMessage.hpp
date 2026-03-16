#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/EmmOptional.hpp"
#include "../types/PatternId.hpp"
#include "../types/SymbolIndexOptional.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// TimetableMessage
struct TimetableMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    EmmOptional emm_optional;
    PatternId pattern_id;
    SymbolIndexOptional symbol_index_optional;

    // parse method
    static TimetableMessage* parse(std::byte* buffer) {
        return reinterpret_cast<TimetableMessage*>(buffer);
    }

    // parse method const
    static const TimetableMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const TimetableMessage*>(buffer);
    }
};

#pragma pack(pop)
}
