#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/SymbolIndex.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// StatisticsMessage
struct StatisticsMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    SymbolIndex symbol_index;

    // parse method
    static StatisticsMessage* parse(std::byte* buffer) {
        return reinterpret_cast<StatisticsMessage*>(buffer);
    }

    // parse method const
    static const StatisticsMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const StatisticsMessage*>(buffer);
    }
};

#pragma pack(pop)
}
