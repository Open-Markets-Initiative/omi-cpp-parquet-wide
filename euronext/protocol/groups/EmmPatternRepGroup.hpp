#pragma once

#include "../types/Emm.hpp"
#include "../types/PatternId.hpp"
#include "../types/TickSizeIndexId.hpp"
#include "../types/MarketModel.hpp"
#include "../types/LotSizeOptional.hpp"
#include "../types/InstUnitExp.hpp"
#include "../types/Anonymous.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct EmmPatternRepGroup {

    Emm emm;
    PatternId pattern_id;
    TickSizeIndexId tick_size_index_id;
    MarketModel market_model;
    LotSizeOptional lot_size_optional;
    InstUnitExp inst_unit_exp;
    Anonymous anonymous;

    // parse method
    static EmmPatternRepGroup* parse(std::byte* buffer) {
        return reinterpret_cast<EmmPatternRepGroup*>(buffer);
    }

    // parse method const
    static const EmmPatternRepGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const EmmPatternRepGroup*>(buffer);
    }
};

#pragma pack(pop)
}
