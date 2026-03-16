#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/SymbolIndex.hpp"
#include "../types/OptiqSegment.hpp"
#include "../types/PartitionId.hpp"
#include "../types/FullInstrumentName.hpp"
#include "../types/InstrumentName.hpp"
#include "../types/InstrumentTradingCode.hpp"
#include "../types/InstrumentGroupCode.hpp"
#include "../types/IsinCode.hpp"
#include "../types/PriceDecimals.hpp"
#include "../types/QuantityDecimals.hpp"
#include "../types/AmountDecimals.hpp"
#include "../types/RatioDecimals.hpp"
#include "../types/Cfi.hpp"
#include "../types/InstrumentEventDate.hpp"
#include "../types/StrikePrice.hpp"
#include "../types/DarkEligibility.hpp"
#include "../types/DarkLisThreshold.hpp"
#include "../types/DarkMinQuantity.hpp"
#include "../types/DateOfLastTrade.hpp"
#include "../types/DepositaryList.hpp"
#include "../types/MainDepositary.hpp"
#include "../types/FirstSettlementDate.hpp"
#include "../types/GuaranteeIndicator.hpp"
#include "../types/Icb.hpp"
#include "../types/IssuingCountry.hpp"
#include "../types/LastAdjustedClosingPrice.hpp"
#include "../types/LotSizeOptional.hpp"
#include "../types/MaturityDateOptional.hpp"
#include "../types/MaximumDecimalsInQuantity.hpp"
#include "../types/Mic.hpp"
#include "../types/MicList.hpp"
#include "../types/CountryOfExchangeOptional.hpp"
#include "../types/Mnemonic.hpp"
#include "../types/UnderlyingMic.hpp"
#include "../types/UnderlyingIsinCode.hpp"
#include "../types/TradingCurrencyOptional.hpp"
#include "../types/CurrencyCoefficient.hpp"
#include "../types/TradingCurrencyIndicator.hpp"
#include "../types/StrikeCurrencyIndicator.hpp"
#include "../types/NumberInstrumentCirculating.hpp"
#include "../types/ParValue.hpp"
#include "../types/QuantityNotation.hpp"
#include "../types/InstUnitExp.hpp"
#include "../types/SettlementDelay.hpp"
#include "../types/StrikeCurrency.hpp"
#include "../types/TaxCode.hpp"
#include "../types/TypeOfCorporateEvent.hpp"
#include "../types/TypeOfMarketAdmission.hpp"
#include "../types/RepoIndicator.hpp"
#include "../types/IssuePrice.hpp"
#include "../types/NominalCurrency.hpp"
#include "../types/IssuePriceDecimals.hpp"
#include "../types/StrikePriceDecimals.hpp"
#include "../types/LiquidInstrumentIndicator.hpp"
#include "../types/MarketOfReferenceMic.hpp"
#include "../types/IcbCode.hpp"
#include "../types/ThresholdLisPostTrade60Mn.hpp"
#include "../types/ThresholdLisPostTrade120Mn.hpp"
#include "../types/ThresholdLisPostTradeEod.hpp"
#include "../types/LongMnemonic.hpp"
#include "../types/MaxOrderAmountCall.hpp"
#include "../types/MaxOrderAmountContinuous.hpp"
#include "../types/MaxOrderQuantityCall.hpp"
#include "../types/MaxOrderQuantityContinuous.hpp"
#include "../types/PoolFactor.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// StandingDataMessage
struct StandingDataMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    SymbolIndex symbol_index;
    OptiqSegment optiq_segment;
    PartitionId partition_id;
    FullInstrumentName full_instrument_name;
    InstrumentName instrument_name;
    InstrumentTradingCode instrument_trading_code;
    InstrumentGroupCode instrument_group_code;
    IsinCode isin_code;
    PriceDecimals price_decimals;
    QuantityDecimals quantity_decimals;
    AmountDecimals amount_decimals;
    RatioDecimals ratio_decimals;
    Cfi cfi;
    InstrumentEventDate instrument_event_date;
    StrikePrice strike_price;
    DarkEligibility dark_eligibility;
    DarkLisThreshold dark_lis_threshold;
    DarkMinQuantity dark_min_quantity;
    DateOfLastTrade date_of_last_trade;
    DepositaryList depositary_list;
    MainDepositary main_depositary;
    FirstSettlementDate first_settlement_date;
    GuaranteeIndicator guarantee_indicator;
    Icb icb;
    IssuingCountry issuing_country;
    LastAdjustedClosingPrice last_adjusted_closing_price;
    LotSizeOptional lot_size_optional;
    MaturityDateOptional maturity_date_optional;
    MaximumDecimalsInQuantity maximum_decimals_in_quantity;
    Mic mic;
    MicList mic_list;
    CountryOfExchangeOptional country_of_exchange_optional;
    Mnemonic mnemonic;
    UnderlyingMic underlying_mic;
    UnderlyingIsinCode underlying_isin_code;
    TradingCurrencyOptional trading_currency_optional;
    CurrencyCoefficient currency_coefficient;
    TradingCurrencyIndicator trading_currency_indicator;
    StrikeCurrencyIndicator strike_currency_indicator;
    NumberInstrumentCirculating number_instrument_circulating;
    ParValue par_value;
    QuantityNotation quantity_notation;
    InstUnitExp inst_unit_exp;
    SettlementDelay settlement_delay;
    StrikeCurrency strike_currency;
    TaxCode tax_code;
    TypeOfCorporateEvent type_of_corporate_event;
    TypeOfMarketAdmission type_of_market_admission;
    RepoIndicator repo_indicator;
    IssuePrice issue_price;
    NominalCurrency nominal_currency;
    IssuePriceDecimals issue_price_decimals;
    StrikePriceDecimals strike_price_decimals;
    LiquidInstrumentIndicator liquid_instrument_indicator;
    MarketOfReferenceMic market_of_reference_mic;
    IcbCode icb_code;
    ThresholdLisPostTrade60Mn threshold_lis_post_trade_60mn;
    ThresholdLisPostTrade120Mn threshold_lis_post_trade_120mn;
    ThresholdLisPostTradeEod threshold_lis_post_trade_eod;
    LongMnemonic long_mnemonic;
    MaxOrderAmountCall max_order_amount_call;
    MaxOrderAmountContinuous max_order_amount_continuous;
    MaxOrderQuantityCall max_order_quantity_call;
    MaxOrderQuantityContinuous max_order_quantity_continuous;
    PoolFactor pool_factor;

    // parse method
    static StandingDataMessage* parse(std::byte* buffer) {
        return reinterpret_cast<StandingDataMessage*>(buffer);
    }

    // parse method const
    static const StandingDataMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const StandingDataMessage*>(buffer);
    }
};

#pragma pack(pop)
}
