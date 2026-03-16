#pragma once

#include "../types/MdSeqNumOptional.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/BidOfferDateTime.hpp"
#include "../types/MifidTransactionId.hpp"
#include "../types/MmtModificationIndicator.hpp"
#include "../types/NavPrice.hpp"
#include "../types/EventTimeOptional.hpp"
#include "../types/NavBidPrice.hpp"
#include "../types/NavOfferPrice.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// BFNAVMessage
struct BfnavMessage {

    MdSeqNumOptional md_seq_num_optional;
    RebroadcastIndicator rebroadcast_indicator;
    SymbolIndex symbol_index;
    BidOfferDateTime bid_offer_date_time;
    MifidTransactionId mifid_transaction_id;
    MmtModificationIndicator mmt_modification_indicator;
    NavPrice nav_price;
    EventTimeOptional event_time_optional;
    NavBidPrice nav_bid_price;
    NavOfferPrice nav_offer_price;

    // parse method
    static BfnavMessage* parse(std::byte* buffer) {
        return reinterpret_cast<BfnavMessage*>(buffer);
    }

    // parse method const
    static const BfnavMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const BfnavMessage*>(buffer);
    }
};

#pragma pack(pop)
}
