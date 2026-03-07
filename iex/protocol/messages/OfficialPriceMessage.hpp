#pragma once

#include "../types/PriceType.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/OfficialPrice.hpp"

namespace iex::equities::tops::iextp::v1_6_6 {

#pragma pack(push, 1)

// Official Price Messages are sent for each IEX-listed security to indicate the IEX Official Opening Price and IEX Official Closing Price.
struct OfficialPriceMessage {

    PriceType price_type;
    Timestamp timestamp;
    Symbol symbol;
    OfficialPrice official_price;

    // parse method
    static OfficialPriceMessage* parse(std::byte* buffer) {
        return reinterpret_cast<OfficialPriceMessage*>(buffer);
    }

    // parse method const
    static const OfficialPriceMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const OfficialPriceMessage*>(buffer);
    }
};

#pragma pack(pop)
}
