#pragma once

#include "../types/MdSeqNumOptional.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/MifidTransactionId.hpp"
#include "../types/EventTime.hpp"
#include "../types/BidOfferDateTime.hpp"
#include "../types/MmtModificationIndicator.hpp"
#include "../types/Price.hpp"
#include "../types/BidPrice.hpp"
#include "../types/OfferPrice.hpp"
#include "../types/Quantity.hpp"
#include "../types/MmtAgencyCrossTradeIndicator.hpp"
#include "../types/MmtBenchmarkIndicator.hpp"
#include "../types/MmtSpecialDividendIndicator.hpp"
#include "../types/MmtTradingMode.hpp"
#include "../types/MifidPriceNotation.hpp"
#include "../types/QuantityNotation.hpp"
#include "../types/NotionalAmountTraded.hpp"
#include "../types/TradingCurrencyOptional.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// BFTradeMessage
struct BfTradeMessage {

    MdSeqNumOptional md_seq_num_optional;
    RebroadcastIndicator rebroadcast_indicator;
    SymbolIndex symbol_index;
    MifidTransactionId mifid_transaction_id;
    EventTime event_time;
    BidOfferDateTime bid_offer_date_time;
    MmtModificationIndicator mmt_modification_indicator;
    Price price;
    BidPrice bid_price;
    OfferPrice offer_price;
    Quantity quantity;
    MmtAgencyCrossTradeIndicator mmt_agency_cross_trade_indicator;
    MmtBenchmarkIndicator mmt_benchmark_indicator;
    MmtSpecialDividendIndicator mmt_special_dividend_indicator;
    MmtTradingMode mmt_trading_mode;
    MifidPriceNotation mifid_price_notation;
    QuantityNotation quantity_notation;
    NotionalAmountTraded notional_amount_traded;
    TradingCurrencyOptional trading_currency_optional;

    // parse method
    static BfTradeMessage* parse(std::byte* buffer) {
        return reinterpret_cast<BfTradeMessage*>(buffer);
    }

    // parse method const
    static const BfTradeMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const BfTradeMessage*>(buffer);
    }
};

#pragma pack(pop)
}
