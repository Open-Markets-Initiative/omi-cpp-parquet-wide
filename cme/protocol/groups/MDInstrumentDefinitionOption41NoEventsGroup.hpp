#pragma once

#include "../types/EventType.hpp"
#include "../types/EventTime.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionOption41NoEventsGroup {

    EventType event_type;
    EventTime event_time;

    // parse method
    static MDInstrumentDefinitionOption41NoEventsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionOption41NoEventsGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionOption41NoEventsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionOption41NoEventsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
