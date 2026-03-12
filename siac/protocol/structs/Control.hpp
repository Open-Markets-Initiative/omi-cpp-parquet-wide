#pragma once

#include "../types/ControlMessageType.hpp"
#include "../types/MessageIndicator.hpp"
#include "../types/TransactionId.hpp"
#include "../types/ParticipantReferenceNumber.hpp"

namespace siac::opra::recipient::obi::v6_2 {

#pragma pack(push, 1)

struct Control {

    ControlMessageType control_message_type;
    MessageIndicator message_indicator;
    TransactionId transaction_id;
    ParticipantReferenceNumber participant_reference_number;

    // parse method
    static Control* parse(std::byte* buffer) {
        return reinterpret_cast<Control*>(buffer);
    }

    // parse method const
    static const Control* parse(const std::byte* buffer) {
        return reinterpret_cast<const Control*>(buffer);
    }
};

#pragma pack(pop)
}
