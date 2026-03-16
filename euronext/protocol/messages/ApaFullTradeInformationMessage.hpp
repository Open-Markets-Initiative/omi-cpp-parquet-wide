#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/Emm.hpp"
#include "../types/EventTime.hpp"
#include "../types/TradingDateTime.hpp"
#include "../types/PublicationDateTime.hpp"
#include "../types/TradeType.hpp"
#include "../types/MifidInstrumentIdTypeOptional.hpp"
#include "../types/MifidInstrumentIdOptional.hpp"
#include "../types/MifidTransactionId.hpp"
#include "../types/MifidPriceOptional.hpp"
#include "../types/MifidQuantity.hpp"
#include "../types/MifidPriceNotation.hpp"
#include "../types/MifidCurrency.hpp"
#include "../types/MifidQtyInMsrmtUnitNotation.hpp"
#include "../types/MifidQuantityMeasurementUnit.hpp"
#include "../types/MifidNotionalAmount.hpp"
#include "../types/NotionalCurrency.hpp"
#include "../types/MifidClearingFlag.hpp"
#include "../types/EfficientMmtMarketMechanism.hpp"
#include "../types/EfficientMmtTradingMode.hpp"
#include "../types/EfficientMmtTransactionCategory.hpp"
#include "../types/EfficientMmtNegotiationIndicator.hpp"
#include "../types/EfficientMmtAgencyCrossTradeIndicator.hpp"
#include "../types/EfficientMmtModificationIndicator.hpp"
#include "../types/EfficientMmtBenchmarkIndicator.hpp"
#include "../types/EfficientMmtSpecialDividendIndicator.hpp"
#include "../types/EfficientMmtOffBookAutomatedIndicator.hpp"
#include "../types/EfficientMmtContributiontoPrice.hpp"
#include "../types/EfficientMmtAlgorithmicIndicator.hpp"
#include "../types/EfficientMmtPublicationMode.hpp"
#include "../types/EfficientMmtPostTradeDeferral.hpp"
#include "../types/EfficientMmtDuplicativeIndicator.hpp"
#include "../types/TradeReference.hpp"
#include "../types/OriginalReportTimestamp.hpp"
#include "../types/PriceMultiplier.hpp"
#include "../types/PriceMultiplierDecimals.hpp"
#include "../types/Venue.hpp"
#include "../types/MifidEmissionAllowanceType.hpp"
#include "../types/LongTradeReference.hpp"
#include "../types/ApaOrigin.hpp"
#include "../types/TradeUniqueIdentifier.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// APAFullTradeInformationMessage
struct ApaFullTradeInformationMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    Emm emm;
    EventTime event_time;
    TradingDateTime trading_date_time;
    PublicationDateTime publication_date_time;
    TradeType trade_type;
    MifidInstrumentIdTypeOptional mifid_instrument_id_type_optional;
    MifidInstrumentIdOptional mifid_instrument_id_optional;
    MifidTransactionId mifid_transaction_id;
    MifidPriceOptional mifid_price_optional;
    MifidQuantity mifid_quantity;
    MifidPriceNotation mifid_price_notation;
    MifidCurrency mifid_currency;
    MifidQtyInMsrmtUnitNotation mifid_qty_in_msrmt_unit_notation;
    MifidQuantityMeasurementUnit mifid_quantity_measurement_unit;
    MifidNotionalAmount mifid_notional_amount;
    NotionalCurrency notional_currency;
    MifidClearingFlag mifid_clearing_flag;
    EfficientMmtMarketMechanism efficient_mmt_market_mechanism;
    EfficientMmtTradingMode efficient_mmt_trading_mode;
    EfficientMmtTransactionCategory efficient_mmt_transaction_category;
    EfficientMmtNegotiationIndicator efficient_mmt_negotiation_indicator;
    EfficientMmtAgencyCrossTradeIndicator efficient_mmt_agency_cross_trade_indicator;
    EfficientMmtModificationIndicator efficient_mmt_modification_indicator;
    EfficientMmtBenchmarkIndicator efficient_mmt_benchmark_indicator;
    EfficientMmtSpecialDividendIndicator efficient_mmt_special_dividend_indicator;
    EfficientMmtOffBookAutomatedIndicator efficient_mmt_off_book_automated_indicator;
    EfficientMmtContributiontoPrice efficient_mmt_contributionto_price;
    EfficientMmtAlgorithmicIndicator efficient_mmt_algorithmic_indicator;
    EfficientMmtPublicationMode efficient_mmt_publication_mode;
    EfficientMmtPostTradeDeferral efficient_mmt_post_trade_deferral;
    EfficientMmtDuplicativeIndicator efficient_mmt_duplicative_indicator;
    TradeReference trade_reference;
    OriginalReportTimestamp original_report_timestamp;
    PriceMultiplier price_multiplier;
    PriceMultiplierDecimals price_multiplier_decimals;
    Venue venue;
    MifidEmissionAllowanceType mifid_emission_allowance_type;
    LongTradeReference long_trade_reference;
    ApaOrigin apa_origin;
    TradeUniqueIdentifier trade_unique_identifier;

    // parse method
    static ApaFullTradeInformationMessage* parse(std::byte* buffer) {
        return reinterpret_cast<ApaFullTradeInformationMessage*>(buffer);
    }

    // parse method const
    static const ApaFullTradeInformationMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const ApaFullTradeInformationMessage*>(buffer);
    }
};

#pragma pack(pop)
}
