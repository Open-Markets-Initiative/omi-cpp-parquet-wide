#pragma once

#include "../types/EmmOptional.hpp"
#include "../types/TickSizeIndexId.hpp"
#include "../types/PatternId.hpp"
#include "../types/LotSizeOptional.hpp"
#include "../bitfields/StrategyAuthorized.hpp"
#include "../types/DynamicCollarLogic.hpp"
#include "../types/CollarMaxUnhaltNb.hpp"
#include "../types/CollarUnhaltDelay.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct ContractEmmPropertiesGroup {

    EmmOptional emm_optional;
    TickSizeIndexId tick_size_index_id;
    PatternId pattern_id;
    LotSizeOptional lot_size_optional;
    StrategyAuthorized strategy_authorized;
    DynamicCollarLogic dynamic_collar_logic;
    CollarMaxUnhaltNb collar_max_unhalt_nb;
    CollarUnhaltDelay collar_unhalt_delay;

    // parse method
    static ContractEmmPropertiesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<ContractEmmPropertiesGroup*>(buffer);
    }

    // parse method const
    static const ContractEmmPropertiesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const ContractEmmPropertiesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
