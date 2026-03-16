#pragma once

#include "../types/UpdateType.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/NumberOfOrders.hpp"
#include "../types/Price.hpp"
#include "../types/QuantityOptional.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct MarketUpdatesGroup {

    UpdateType update_type;
    SymbolIndex symbol_index;
    NumberOfOrders number_of_orders;
    Price price;
    QuantityOptional quantity_optional;

    // parse method
    static MarketUpdatesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MarketUpdatesGroup*>(buffer);
    }

    // parse method const
    static const MarketUpdatesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MarketUpdatesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
