#pragma once

#include "../types/EventType.hpp"
#include "../types/EventTime.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionFuture27NoEventsGroup {

    EventType event_type;
    EventTime event_time;

    // parse method
    static MDInstrumentDefinitionFuture27NoEventsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionFuture27NoEventsGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionFuture27NoEventsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionFuture27NoEventsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
