#pragma once

#include "../types/EquityAndIndexLastSaleMessageType.hpp"
#include "../types/MessageIndicator.hpp"
#include "../types/TransactionId.hpp"
#include "../types/ParticipantReferenceNumber.hpp"
#include "../types/SecuritySymbol.hpp"
#include "../types/Reserved1.hpp"
#include "../structs/ExpirationBlock.hpp"
#include "../types/StrikePriceDenominatorCode.hpp"
#include "../types/StrikePrice.hpp"
#include "../types/Volume.hpp"
#include "../types/PremiumPriceDenominatorCode.hpp"
#include "../types/PremiumPrice.hpp"
#include "../types/TradeIdentifier.hpp"
#include "../types/Reserved4.hpp"

namespace siac::opra::recipient::obi::v6_2 {

#pragma pack(push, 1)

struct EquityAndIndexLastSale {

    EquityAndIndexLastSaleMessageType equity_and_index_last_sale_message_type;
    MessageIndicator message_indicator;
    TransactionId transaction_id;
    ParticipantReferenceNumber participant_reference_number;
    SecuritySymbol security_symbol;
    Reserved1 reserved_1;
    ExpirationBlock expiration_block;
    StrikePriceDenominatorCode strike_price_denominator_code;
    StrikePrice strike_price;
    Volume volume;
    PremiumPriceDenominatorCode premium_price_denominator_code;
    PremiumPrice premium_price;
    TradeIdentifier trade_identifier;
    Reserved4 reserved_4;

    // parse method
    static EquityAndIndexLastSale* parse(std::byte* buffer) {
        return reinterpret_cast<EquityAndIndexLastSale*>(buffer);
    }

    // parse method const
    static const EquityAndIndexLastSale* parse(const std::byte* buffer) {
        return reinterpret_cast<const EquityAndIndexLastSale*>(buffer);
    }
};

#pragma pack(pop)
}
