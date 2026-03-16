#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/Emm.hpp"
#include "../types/EventTime.hpp"
#include "../types/SymbolIndexOptional.hpp"
#include "../types/TradingDateTime.hpp"
#include "../types/PublicationDateTime.hpp"
#include "../types/TradeType.hpp"
#include "../types/MifidInstrumentIdTypeOptional.hpp"
#include "../types/MifidInstrumentIdOptional.hpp"
#include "../types/MifidExecutionId.hpp"
#include "../types/MifidPriceOptional.hpp"
#include "../types/MifidQuantity.hpp"
#include "../types/MifidPriceNotation.hpp"
#include "../types/MifidCurrency.hpp"
#include "../types/MifidQtyInMsrmtUnitNotation.hpp"
#include "../types/MifidQuantityMeasurementUnit.hpp"
#include "../types/MifidNotionalAmount.hpp"
#include "../types/NotionalCurrency.hpp"
#include "../types/MifidClearingFlag.hpp"
#include "../types/MmtMarketMechanism.hpp"
#include "../types/MmtTradingMode.hpp"
#include "../types/MmtTransactionCategory.hpp"
#include "../types/MmtNegotiationIndicator.hpp"
#include "../types/MmtAgencyCrossTradeIndicator.hpp"
#include "../types/MmtModificationIndicatorChar4Optional.hpp"
#include "../types/MmtBenchmarkIndicator.hpp"
#include "../types/MmtSpecialDividendIndicator.hpp"
#include "../types/MmtOffBookAutomatedIndicator.hpp"
#include "../types/MmtContributiontoPrice.hpp"
#include "../types/MmtAlgorithmicIndicator.hpp"
#include "../types/MmtPublicationMode.hpp"
#include "../types/MmtPostTradeDeferral.hpp"
#include "../types/MmtDuplicativeIndicator.hpp"
#include "../bitfields/TradeQualifier.hpp"
#include "../types/TransactionType.hpp"
#include "../types/EffectiveDateIndicator.hpp"
#include "../types/BlockTradeCode.hpp"
#include "../types/TradeReference.hpp"
#include "../types/OriginalReportTimestamp.hpp"
#include "../types/TransparencyIndicator.hpp"
#include "../types/CurrencyCoefficient.hpp"
#include "../types/PriceMultiplier.hpp"
#include "../types/PriceMultiplierDecimals.hpp"
#include "../types/Venue.hpp"
#include "../types/StartTimeVwap.hpp"
#include "../types/EndTimeVwap.hpp"
#include "../types/MifidEmissionAllowanceType.hpp"
#include "../types/MarketOfReferenceMic.hpp"
#include "../types/EvaluatedPrice.hpp"
#include "../types/MessagePriceNotation.hpp"
#include "../types/SettlementDate.hpp"
#include "../types/RepoSettlementDate.hpp"
#include "../types/TradeUniqueIdentifier.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// FullTradeInformationMessage
struct FullTradeInformationMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    Emm emm;
    EventTime event_time;
    SymbolIndexOptional symbol_index_optional;
    TradingDateTime trading_date_time;
    PublicationDateTime publication_date_time;
    TradeType trade_type;
    MifidInstrumentIdTypeOptional mifid_instrument_id_type_optional;
    MifidInstrumentIdOptional mifid_instrument_id_optional;
    MifidExecutionId mifid_execution_id;
    MifidPriceOptional mifid_price_optional;
    MifidQuantity mifid_quantity;
    MifidPriceNotation mifid_price_notation;
    MifidCurrency mifid_currency;
    MifidQtyInMsrmtUnitNotation mifid_qty_in_msrmt_unit_notation;
    MifidQuantityMeasurementUnit mifid_quantity_measurement_unit;
    MifidNotionalAmount mifid_notional_amount;
    NotionalCurrency notional_currency;
    MifidClearingFlag mifid_clearing_flag;
    MmtMarketMechanism mmt_market_mechanism;
    MmtTradingMode mmt_trading_mode;
    MmtTransactionCategory mmt_transaction_category;
    MmtNegotiationIndicator mmt_negotiation_indicator;
    MmtAgencyCrossTradeIndicator mmt_agency_cross_trade_indicator;
    MmtModificationIndicatorChar4Optional mmt_modification_indicator_char_4_optional;
    MmtBenchmarkIndicator mmt_benchmark_indicator;
    MmtSpecialDividendIndicator mmt_special_dividend_indicator;
    MmtOffBookAutomatedIndicator mmt_off_book_automated_indicator;
    MmtContributiontoPrice mmt_contributionto_price;
    MmtAlgorithmicIndicator mmt_algorithmic_indicator;
    MmtPublicationMode mmt_publication_mode;
    MmtPostTradeDeferral mmt_post_trade_deferral;
    MmtDuplicativeIndicator mmt_duplicative_indicator;
    TradeQualifier trade_qualifier;
    TransactionType transaction_type;
    EffectiveDateIndicator effective_date_indicator;
    BlockTradeCode block_trade_code;
    TradeReference trade_reference;
    OriginalReportTimestamp original_report_timestamp;
    TransparencyIndicator transparency_indicator;
    CurrencyCoefficient currency_coefficient;
    PriceMultiplier price_multiplier;
    PriceMultiplierDecimals price_multiplier_decimals;
    Venue venue;
    StartTimeVwap start_time_vwap;
    EndTimeVwap end_time_vwap;
    MifidEmissionAllowanceType mifid_emission_allowance_type;
    MarketOfReferenceMic market_of_reference_mic;
    EvaluatedPrice evaluated_price;
    MessagePriceNotation message_price_notation;
    SettlementDate settlement_date;
    RepoSettlementDate repo_settlement_date;
    TradeUniqueIdentifier trade_unique_identifier;

    // parse method
    static FullTradeInformationMessage* parse(std::byte* buffer) {
        return reinterpret_cast<FullTradeInformationMessage*>(buffer);
    }

    // parse method const
    static const FullTradeInformationMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const FullTradeInformationMessage*>(buffer);
    }
};

#pragma pack(pop)
}
