#pragma once

#include "../types/EventType.hpp"
#include "../types/EventTime.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionSpread29NoEventsGroup {

    EventType event_type;
    EventTime event_time;

    // parse method
    static MDInstrumentDefinitionSpread29NoEventsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionSpread29NoEventsGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionSpread29NoEventsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionSpread29NoEventsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
