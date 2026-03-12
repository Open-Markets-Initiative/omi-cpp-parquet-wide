#pragma once

#include "../types/OpenInterestMessageType.hpp"
#include "../types/MessageIndicator.hpp"
#include "../types/TransactionId.hpp"
#include "../types/ParticipantReferenceNumber.hpp"
#include "../types/SecuritySymbol.hpp"
#include "../types/Reserved1.hpp"
#include "../structs/ExpirationBlock.hpp"
#include "../types/StrikePriceDenominatorCode.hpp"
#include "../types/StrikePrice.hpp"
#include "../types/OpenInterestVolume.hpp"

namespace siac::opra::recipient::obi::v6_2 {

#pragma pack(push, 1)

struct OpenInterest {

    OpenInterestMessageType open_interest_message_type;
    MessageIndicator message_indicator;
    TransactionId transaction_id;
    ParticipantReferenceNumber participant_reference_number;
    SecuritySymbol security_symbol;
    Reserved1 reserved_1;
    ExpirationBlock expiration_block;
    StrikePriceDenominatorCode strike_price_denominator_code;
    StrikePrice strike_price;
    OpenInterestVolume open_interest_volume;

    // parse method
    static OpenInterest* parse(std::byte* buffer) {
        return reinterpret_cast<OpenInterest*>(buffer);
    }

    // parse method const
    static const OpenInterest* parse(const std::byte* buffer) {
        return reinterpret_cast<const OpenInterest*>(buffer);
    }
};

#pragma pack(pop)
}
