#pragma once

#include "../types/PhaseTime.hpp"
#include "../types/PhaseId.hpp"
#include "../bitfields/PhaseQualifier.hpp"
#include "../types/TradingPeriod.hpp"
#include "../types/OrderEntryQualifier.hpp"
#include "../types/Session.hpp"
#include "../types/ScheduledEvent.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct TimetablesGroup {

    PhaseTime phase_time;
    PhaseId phase_id;
    PhaseQualifier phase_qualifier;
    TradingPeriod trading_period;
    OrderEntryQualifier order_entry_qualifier;
    Session session;
    ScheduledEvent scheduled_event;

    // parse method
    static TimetablesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<TimetablesGroup*>(buffer);
    }

    // parse method const
    static const TimetablesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const TimetablesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
