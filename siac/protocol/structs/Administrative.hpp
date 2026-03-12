#pragma once

#include "../types/AdministrativeMessageType.hpp"
#include "../types/MessageIndicator.hpp"
#include "../types/TransactionId.hpp"
#include "../types/ParticipantReferenceNumber.hpp"
#include "../types/MessageDataLength.hpp"

namespace siac::opra::recipient::obi::v6_2 {

#pragma pack(push, 1)

struct Administrative {

    AdministrativeMessageType administrative_message_type;
    MessageIndicator message_indicator;
    TransactionId transaction_id;
    ParticipantReferenceNumber participant_reference_number;
    MessageDataLength message_data_length;

    // parse method
    static Administrative* parse(std::byte* buffer) {
        return reinterpret_cast<Administrative*>(buffer);
    }

    // parse method const
    static const Administrative* parse(const std::byte* buffer) {
        return reinterpret_cast<const Administrative*>(buffer);
    }
};

#pragma pack(pop)
}
