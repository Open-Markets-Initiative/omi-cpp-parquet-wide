#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/OptiqSegment.hpp"
#include "../types/PartitionId.hpp"
#include "../types/ContractEventDate.hpp"
#include "../types/ExchangeCode.hpp"
#include "../types/ExerStyle.hpp"
#include "../types/ContractName.hpp"
#include "../types/ContractType.hpp"
#include "../types/UnderlyingType.hpp"
#include "../types/PriceDecimalsOptional.hpp"
#include "../types/QuantityDecimals.hpp"
#include "../types/AmountDecimals.hpp"
#include "../types/RatioDecimalsOptional.hpp"
#include "../types/MainDepositary.hpp"
#include "../types/Mic.hpp"
#include "../types/CountryOfExchange.hpp"
#include "../types/ProductCode.hpp"
#include "../types/UnderlyingMic.hpp"
#include "../types/UnderlyingIsinCode.hpp"
#include "../types/UnderlyingExpiry.hpp"
#include "../bitfields/OrderTypeRules.hpp"
#include "../types/SettlementMethod.hpp"
#include "../types/TradingCurrency.hpp"
#include "../types/StrikePriceDecimalsRatio.hpp"
#include "../bitfields/MmProtections.hpp"
#include "../types/ContractTradingType.hpp"
#include "../types/InstUnitExp.hpp"
#include "../types/UnderlyingSubtype.hpp"
#include "../types/MotherStockIsin.hpp"
#include "../types/SettlementTickSize.hpp"
#include "../types/EdspTickSize.hpp"
#include "../types/UnderlyingSymbolIndex.hpp"
#include "../types/TradingPolicy.hpp"
#include "../types/ReferenceSpreadTableId.hpp"
#include "../types/DerivativesMarketModel.hpp"
#include "../types/TradingUnit.hpp"
#include "../types/ReferencePriceOriginInOpeningCall.hpp"
#include "../types/ReferencePriceOriginInContinuous.hpp"
#include "../types/ReferencePriceOriginInTradingInterruption.hpp"
#include "../types/CollarExpansionFactor.hpp"
#include "../types/MifidiiLiquidFlag.hpp"
#include "../types/PricingAlgorithm.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// ContractStandingDataMessage
struct ContractStandingDataMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    SymbolIndex symbol_index;
    OptiqSegment optiq_segment;
    PartitionId partition_id;
    ContractEventDate contract_event_date;
    ExchangeCode exchange_code;
    ExerStyle exer_style;
    ContractName contract_name;
    ContractType contract_type;
    UnderlyingType underlying_type;
    PriceDecimalsOptional price_decimals_optional;
    QuantityDecimals quantity_decimals;
    AmountDecimals amount_decimals;
    RatioDecimalsOptional ratio_decimals_optional;
    MainDepositary main_depositary;
    Mic mic;
    CountryOfExchange country_of_exchange;
    ProductCode product_code;
    UnderlyingMic underlying_mic;
    UnderlyingIsinCode underlying_isin_code;
    UnderlyingExpiry underlying_expiry;
    OrderTypeRules order_type_rules;
    SettlementMethod settlement_method;
    TradingCurrency trading_currency;
    StrikePriceDecimalsRatio strike_price_decimals_ratio;
    MmProtections mm_protections;
    ContractTradingType contract_trading_type;
    InstUnitExp inst_unit_exp;
    UnderlyingSubtype underlying_subtype;
    MotherStockIsin mother_stock_isin;
    SettlementTickSize settlement_tick_size;
    EdspTickSize edsp_tick_size;
    UnderlyingSymbolIndex underlying_symbol_index;
    TradingPolicy trading_policy;
    ReferenceSpreadTableId reference_spread_table_id;
    DerivativesMarketModel derivatives_market_model;
    TradingUnit trading_unit;
    ReferencePriceOriginInOpeningCall reference_price_origin_in_opening_call;
    ReferencePriceOriginInContinuous reference_price_origin_in_continuous;
    ReferencePriceOriginInTradingInterruption reference_price_origin_in_trading_interruption;
    CollarExpansionFactor collar_expansion_factor;
    MifidiiLiquidFlag mifidii_liquid_flag;
    PricingAlgorithm pricing_algorithm;

    // parse method
    static ContractStandingDataMessage* parse(std::byte* buffer) {
        return reinterpret_cast<ContractStandingDataMessage*>(buffer);
    }

    // parse method const
    static const ContractStandingDataMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const ContractStandingDataMessage*>(buffer);
    }
};

#pragma pack(pop)
}
