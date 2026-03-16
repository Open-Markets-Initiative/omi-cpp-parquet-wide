#pragma once

#include "../types/InterestPaymentDate.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct InterestPaymentDateRepGroup {

    InterestPaymentDate interest_payment_date;

    // parse method
    static InterestPaymentDateRepGroup* parse(std::byte* buffer) {
        return reinterpret_cast<InterestPaymentDateRepGroup*>(buffer);
    }

    // parse method const
    static const InterestPaymentDateRepGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const InterestPaymentDateRepGroup*>(buffer);
    }
};

#pragma pack(pop)
}
