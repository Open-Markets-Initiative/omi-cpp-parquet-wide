#pragma once

#include "../types/PriceType.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/Price.hpp"
#include "../types/QuantityOptional.hpp"
#include "../types/ImbalanceQty.hpp"
#include "../types/ImbalanceQtySide.hpp"
#include "../types/PriceQualifier.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct PriceUpdatesGroup {

    PriceType price_type;
    SymbolIndex symbol_index;
    Price price;
    QuantityOptional quantity_optional;
    ImbalanceQty imbalance_qty;
    ImbalanceQtySide imbalance_qty_side;
    PriceQualifier price_qualifier;

    // parse method
    static PriceUpdatesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<PriceUpdatesGroup*>(buffer);
    }

    // parse method const
    static const PriceUpdatesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const PriceUpdatesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
