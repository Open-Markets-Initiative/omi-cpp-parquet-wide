#pragma once

#include "../types/StatsUpdateType.hpp"
#include "../types/StatsUpdateValue.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct NewStatsGroup {

    StatsUpdateType stats_update_type;
    StatsUpdateValue stats_update_value;

    // parse method
    static NewStatsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<NewStatsGroup*>(buffer);
    }

    // parse method const
    static const NewStatsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const NewStatsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
