#pragma once

#include "../types/MdEntryPx.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/OpenCloseSettlFlag.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdEntryTypeStatistics.hpp"
#include "../types/MdEntrySizeOptional.hpp"
#include "../types/Padding1.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDIncrementalRefreshSessionStatistics35NoMDEntriesGroup {

    MdEntryPx md_entry_px;
    SecurityId security_id;
    RptSeq rpt_seq;
    OpenCloseSettlFlag open_close_settl_flag;
    MdUpdateAction md_update_action;
    MdEntryTypeStatistics md_entry_type_statistics;
    MdEntrySizeOptional md_entry_size_optional;
    Padding1 padding_1;

    // parse method
    static MDIncrementalRefreshSessionStatistics35NoMDEntriesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDIncrementalRefreshSessionStatistics35NoMDEntriesGroup*>(buffer);
    }

    // parse method const
    static const MDIncrementalRefreshSessionStatistics35NoMDEntriesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDIncrementalRefreshSessionStatistics35NoMDEntriesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
