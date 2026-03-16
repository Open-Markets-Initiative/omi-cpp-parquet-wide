#pragma once

#include "../types/SymbolIndex.hpp"
#include "../types/ActionType.hpp"
#include "../types/OrderPriority.hpp"
#include "../types/PreviousPriority.hpp"
#include "../types/OrderType.hpp"
#include "../types/OrderPx.hpp"
#include "../types/OrderSide.hpp"
#include "../types/OrderQuantity.hpp"
#include "../types/PegOffset.hpp"
#include "../types/FirmId.hpp"
#include "../types/AccountType.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct LongOrderUpdatesGroup {

    SymbolIndex symbol_index;
    ActionType action_type;
    OrderPriority order_priority;
    PreviousPriority previous_priority;
    OrderType order_type;
    OrderPx order_px;
    OrderSide order_side;
    OrderQuantity order_quantity;
    PegOffset peg_offset;
    FirmId firm_id;
    AccountType account_type;

    // parse method
    static LongOrderUpdatesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<LongOrderUpdatesGroup*>(buffer);
    }

    // parse method const
    static const LongOrderUpdatesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const LongOrderUpdatesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
