#pragma once

#include "../types/ChangeType.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/EventTime.hpp"
#include "../types/BookState.hpp"
#include "../types/StatusReason.hpp"
#include "../bitfields/PhaseQualifier.hpp"
#include "../types/TradingPeriodOptional.hpp"
#include "../types/TradingSide.hpp"
#include "../types/PriceLimits.hpp"
#include "../types/QuoteSpreadMultiplier.hpp"
#include "../types/OrderEntryQualifier.hpp"
#include "../types/Session.hpp"
#include "../types/ScheduledEvent.hpp"
#include "../types/ScheduledEventTime.hpp"
#include "../types/InstrumentState.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct MarketStatesGroup {

    ChangeType change_type;
    SymbolIndex symbol_index;
    EventTime event_time;
    BookState book_state;
    StatusReason status_reason;
    PhaseQualifier phase_qualifier;
    TradingPeriodOptional trading_period_optional;
    TradingSide trading_side;
    PriceLimits price_limits;
    QuoteSpreadMultiplier quote_spread_multiplier;
    OrderEntryQualifier order_entry_qualifier;
    Session session;
    ScheduledEvent scheduled_event;
    ScheduledEventTime scheduled_event_time;
    InstrumentState instrument_state;

    // parse method
    static MarketStatesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MarketStatesGroup*>(buffer);
    }

    // parse method const
    static const MarketStatesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MarketStatesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
