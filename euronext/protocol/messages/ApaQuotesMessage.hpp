#pragma once

#include "../types/MdSeqNumOptional.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/MifidInstrumentIdType.hpp"
#include "../types/MifidInstrumentId.hpp"
#include "../types/Mic.hpp"
#include "../types/Currency.hpp"
#include "../types/LeiCode.hpp"
#include "../types/EventTime.hpp"
#include "../types/QuoteUpdateType.hpp"
#include "../types/MifidPrice.hpp"
#include "../types/MifidQuantity.hpp"
#include "../types/ApaOrigin.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// APAQuotesMessage
struct ApaQuotesMessage {

    MdSeqNumOptional md_seq_num_optional;
    RebroadcastIndicator rebroadcast_indicator;
    MifidInstrumentIdType mifid_instrument_id_type;
    MifidInstrumentId mifid_instrument_id;
    Mic mic;
    Currency currency;
    LeiCode lei_code;
    EventTime event_time;
    QuoteUpdateType quote_update_type;
    MifidPrice mifid_price;
    MifidQuantity mifid_quantity;
    ApaOrigin apa_origin;

    // parse method
    static ApaQuotesMessage* parse(std::byte* buffer) {
        return reinterpret_cast<ApaQuotesMessage*>(buffer);
    }

    // parse method const
    static const ApaQuotesMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const ApaQuotesMessage*>(buffer);
    }
};

#pragma pack(pop)
}
