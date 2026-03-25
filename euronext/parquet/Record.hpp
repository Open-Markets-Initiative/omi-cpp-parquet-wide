#pragma once

#include <memory>

#include "fields/EventType.hpp"
#include "fields/PacketTime.hpp"
#include "fields/PacketSequenceNumber.hpp"
#include "fields/MdgRestartCount.hpp"
#include "fields/PsnHighWeight.hpp"
#include "fields/ChannelId.hpp"
#include "fields/MdSeqNum.hpp"
#include "fields/SessionTradingDay.hpp"
#include "fields/EventTime.hpp"
#include "fields/MdSeqNumOptional.hpp"
#include "fields/TechnicalNotificationType.hpp"
#include "fields/RebroadcastIndicator.hpp"
#include "fields/RetransmissionStartTime.hpp"
#include "fields/RetransmissionEndTime.hpp"
#include "fields/SymbolIndexOptional.hpp"
#include "fields/Emm.hpp"
#include "fields/BlockLengthShort.hpp"
#include "fields/NumInGroup.hpp"
#include "fields/MarketUpdatesGroup.hpp"
#include "fields/OrderUpdatesGroup.hpp"
#include "fields/PriceUpdatesGroup.hpp"
#include "fields/TradingDateTime.hpp"
#include "fields/PublicationDateTime.hpp"
#include "fields/TradeType.hpp"
#include "fields/MifidInstrumentIdTypeOptional.hpp"
#include "fields/MifidInstrumentIdOptional.hpp"
#include "fields/MifidExecutionId.hpp"
#include "fields/MifidPriceOptional.hpp"
#include "fields/MifidQuantity.hpp"
#include "fields/MifidPriceNotation.hpp"
#include "fields/MifidCurrency.hpp"
#include "fields/MifidQtyInMsrmtUnitNotation.hpp"
#include "fields/MifidQuantityMeasurementUnit.hpp"
#include "fields/MifidNotionalAmount.hpp"
#include "fields/NotionalCurrency.hpp"
#include "fields/MifidClearingFlag.hpp"
#include "fields/MmtMarketMechanism.hpp"
#include "fields/MmtTradingMode.hpp"
#include "fields/MmtTransactionCategory.hpp"
#include "fields/MmtNegotiationIndicator.hpp"
#include "fields/MmtAgencyCrossTradeIndicator.hpp"
#include "fields/MmtModificationIndicatorChar4Optional.hpp"
#include "fields/MmtBenchmarkIndicator.hpp"
#include "fields/MmtSpecialDividendIndicator.hpp"
#include "fields/MmtOffBookAutomatedIndicator.hpp"
#include "fields/MmtContributiontoPrice.hpp"
#include "fields/MmtAlgorithmicIndicator.hpp"
#include "fields/MmtPublicationMode.hpp"
#include "fields/MmtPostTradeDeferral.hpp"
#include "fields/MmtDuplicativeIndicator.hpp"
#include "fields/TransactionType.hpp"
#include "fields/EffectiveDateIndicator.hpp"
#include "fields/BlockTradeCode.hpp"
#include "fields/TradeReference.hpp"
#include "fields/OriginalReportTimestamp.hpp"
#include "fields/TransparencyIndicator.hpp"
#include "fields/CurrencyCoefficient.hpp"
#include "fields/PriceMultiplier.hpp"
#include "fields/PriceMultiplierDecimals.hpp"
#include "fields/Venue.hpp"
#include "fields/StartTimeVwap.hpp"
#include "fields/EndTimeVwap.hpp"
#include "fields/MifidEmissionAllowanceType.hpp"
#include "fields/MarketOfReferenceMic.hpp"
#include "fields/EvaluatedPrice.hpp"
#include "fields/MessagePriceNotation.hpp"
#include "fields/SettlementDate.hpp"
#include "fields/RepoSettlementDate.hpp"
#include "fields/TradeUniqueIdentifier.hpp"
#include "fields/NotUsedGroup.hpp"
#include "fields/MarketStatesGroup.hpp"
#include "fields/EmmOptional.hpp"
#include "fields/PatternId.hpp"
#include "fields/TimetablesGroup.hpp"
#include "fields/SymbolIndex.hpp"
#include "fields/OptiqSegment.hpp"
#include "fields/PartitionId.hpp"
#include "fields/FullInstrumentName.hpp"
#include "fields/InstrumentName.hpp"
#include "fields/InstrumentTradingCode.hpp"
#include "fields/InstrumentGroupCode.hpp"
#include "fields/IsinCode.hpp"
#include "fields/PriceDecimals.hpp"
#include "fields/QuantityDecimals.hpp"
#include "fields/AmountDecimals.hpp"
#include "fields/RatioDecimals.hpp"
#include "fields/Cfi.hpp"
#include "fields/InstrumentEventDate.hpp"
#include "fields/StrikePrice.hpp"
#include "fields/DarkEligibility.hpp"
#include "fields/DarkLisThreshold.hpp"
#include "fields/DarkMinQuantity.hpp"
#include "fields/DateOfLastTrade.hpp"
#include "fields/DepositaryList.hpp"
#include "fields/MainDepositary.hpp"
#include "fields/FirstSettlementDate.hpp"
#include "fields/GuaranteeIndicator.hpp"
#include "fields/Icb.hpp"
#include "fields/IssuingCountry.hpp"
#include "fields/LastAdjustedClosingPrice.hpp"
#include "fields/LotSizeOptional.hpp"
#include "fields/MaturityDateOptional.hpp"
#include "fields/MaximumDecimalsInQuantity.hpp"
#include "fields/Mic.hpp"
#include "fields/MicList.hpp"
#include "fields/CountryOfExchangeOptional.hpp"
#include "fields/Mnemonic.hpp"
#include "fields/UnderlyingMic.hpp"
#include "fields/UnderlyingIsinCode.hpp"
#include "fields/TradingCurrencyOptional.hpp"
#include "fields/TradingCurrencyIndicator.hpp"
#include "fields/StrikeCurrencyIndicator.hpp"
#include "fields/NumberInstrumentCirculating.hpp"
#include "fields/ParValue.hpp"
#include "fields/QuantityNotation.hpp"
#include "fields/InstUnitExp.hpp"
#include "fields/SettlementDelay.hpp"
#include "fields/StrikeCurrency.hpp"
#include "fields/TaxCode.hpp"
#include "fields/TypeOfCorporateEvent.hpp"
#include "fields/TypeOfMarketAdmission.hpp"
#include "fields/RepoIndicator.hpp"
#include "fields/IssuePrice.hpp"
#include "fields/NominalCurrency.hpp"
#include "fields/IssuePriceDecimals.hpp"
#include "fields/StrikePriceDecimals.hpp"
#include "fields/LiquidInstrumentIndicator.hpp"
#include "fields/IcbCode.hpp"
#include "fields/ThresholdLisPostTrade60Mn.hpp"
#include "fields/ThresholdLisPostTrade120Mn.hpp"
#include "fields/ThresholdLisPostTradeEod.hpp"
#include "fields/LongMnemonic.hpp"
#include "fields/MaxOrderAmountCall.hpp"
#include "fields/MaxOrderAmountContinuous.hpp"
#include "fields/MaxOrderQuantityCall.hpp"
#include "fields/MaxOrderQuantityContinuous.hpp"
#include "fields/PoolFactor.hpp"
#include "fields/EmmPatternRepGroup.hpp"
#include "fields/IndexLevel.hpp"
#include "fields/PctgOfCapitalization.hpp"
#include "fields/PrctVarfromPrevClose.hpp"
#include "fields/NumTradedInstruments.hpp"
#include "fields/IndexLevelType.hpp"
#include "fields/IndexPriceCode.hpp"
#include "fields/NewStatsGroup.hpp"
#include "fields/OpeningLevel.hpp"
#include "fields/OpeningTime.hpp"
#include "fields/ConfirmedReferenceLevel.hpp"
#include "fields/ConfirmedReferenceTime.hpp"
#include "fields/ClosingReferenceLevel.hpp"
#include "fields/ClosingReferenceTime.hpp"
#include "fields/HighLevel.hpp"
#include "fields/HighTime.hpp"
#include "fields/LowLevel.hpp"
#include "fields/LowTime.hpp"
#include "fields/LiquidationLevel.hpp"
#include "fields/LiquidationTime.hpp"
#include "fields/DerivativesInstrumentTradingCode.hpp"
#include "fields/ExchangeCode.hpp"
#include "fields/MaturityDate.hpp"
#include "fields/StrategyCode.hpp"
#include "fields/ContractSymbolIndex.hpp"
#include "fields/CfiOptional.hpp"
#include "fields/StrategyStandingDataGroup.hpp"
#include "fields/ContractEventDate.hpp"
#include "fields/ExerStyle.hpp"
#include "fields/ContractName.hpp"
#include "fields/ContractType.hpp"
#include "fields/UnderlyingType.hpp"
#include "fields/PriceDecimalsOptional.hpp"
#include "fields/RatioDecimalsOptional.hpp"
#include "fields/CountryOfExchange.hpp"
#include "fields/ProductCode.hpp"
#include "fields/UnderlyingExpiry.hpp"
#include "fields/SettlementMethod.hpp"
#include "fields/TradingCurrency.hpp"
#include "fields/StrikePriceDecimalsRatio.hpp"
#include "fields/ContractTradingType.hpp"
#include "fields/UnderlyingSubtype.hpp"
#include "fields/MotherStockIsin.hpp"
#include "fields/SettlementTickSize.hpp"
#include "fields/EdspTickSize.hpp"
#include "fields/UnderlyingSymbolIndex.hpp"
#include "fields/TradingPolicy.hpp"
#include "fields/ReferenceSpreadTableId.hpp"
#include "fields/DerivativesMarketModel.hpp"
#include "fields/TradingUnit.hpp"
#include "fields/ReferencePriceOriginInOpeningCall.hpp"
#include "fields/ReferencePriceOriginInContinuous.hpp"
#include "fields/ReferencePriceOriginInTradingInterruption.hpp"
#include "fields/CollarExpansionFactor.hpp"
#include "fields/MifidiiLiquidFlag.hpp"
#include "fields/PricingAlgorithm.hpp"
#include "fields/ContractEmmPropertiesGroup.hpp"
#include "fields/LotSize.hpp"
#include "fields/LastTradingDate.hpp"
#include "fields/DaysToExpiry.hpp"
#include "fields/DerivativesInstrumentTradingCodeOptional.hpp"
#include "fields/DerivativesInstrumentType.hpp"
#include "fields/ExpiryCycleType.hpp"
#include "fields/UnderlyingDerivativesInstrumentTradingCode.hpp"
#include "fields/OutrightRepGroup.hpp"
#include "fields/LongOrderUpdatesGroup.hpp"
#include "fields/PackageComponentsGroup.hpp"
#include "fields/MifidInstrumentIdType.hpp"
#include "fields/MifidInstrumentId.hpp"
#include "fields/Currency.hpp"
#include "fields/LeiCode.hpp"
#include "fields/QuoteUpdateType.hpp"
#include "fields/MifidPrice.hpp"
#include "fields/ApaOrigin.hpp"
#include "fields/SecondNotionalCurrency.hpp"
#include "fields/UnderlyingIndexName.hpp"
#include "fields/UnderlyingIndexTerm.hpp"
#include "fields/OptionType.hpp"
#include "fields/ExpiryDate.hpp"
#include "fields/MifidTransactionId.hpp"
#include "fields/EfficientMmtMarketMechanism.hpp"
#include "fields/EfficientMmtTradingMode.hpp"
#include "fields/EfficientMmtTransactionCategory.hpp"
#include "fields/EfficientMmtNegotiationIndicator.hpp"
#include "fields/EfficientMmtAgencyCrossTradeIndicator.hpp"
#include "fields/EfficientMmtModificationIndicator.hpp"
#include "fields/EfficientMmtBenchmarkIndicator.hpp"
#include "fields/EfficientMmtSpecialDividendIndicator.hpp"
#include "fields/EfficientMmtOffBookAutomatedIndicator.hpp"
#include "fields/EfficientMmtContributiontoPrice.hpp"
#include "fields/EfficientMmtAlgorithmicIndicator.hpp"
#include "fields/EfficientMmtPublicationMode.hpp"
#include "fields/EfficientMmtPostTradeDeferral.hpp"
#include "fields/EfficientMmtDuplicativeIndicator.hpp"
#include "fields/LongTradeReference.hpp"
#include "fields/IsinCodeOptional.hpp"
#include "fields/SedolCode.hpp"
#include "fields/LongIssuerName.hpp"
#include "fields/LongInstrumentName.hpp"
#include "fields/CurrencyOptional.hpp"
#include "fields/DateOfInitialListing.hpp"
#include "fields/ShareAmountInIssue.hpp"
#include "fields/OpenedClosedFund.hpp"
#include "fields/LastNavPrice.hpp"
#include "fields/GrossOfCdscIndicator.hpp"
#include "fields/Coupon.hpp"
#include "fields/ClosingPrice.hpp"
#include "fields/MicOptional.hpp"
#include "fields/GrossDividendPayablePerUnit.hpp"
#include "fields/DividendCurrency.hpp"
#include "fields/DividendRecordDate.hpp"
#include "fields/DividendRate.hpp"
#include "fields/ExDividendDate.hpp"
#include "fields/DividendPaymentDate.hpp"
#include "fields/TaxDescriptionAttachingToADividend.hpp"
#include "fields/NextMeeting.hpp"
#include "fields/GrossDividendInEuros.hpp"
#include "fields/IssueDate.hpp"
#include "fields/PaymentFrequency.hpp"
#include "fields/MinimumAmount.hpp"
#include "fields/InstrumentCategory.hpp"
#include "fields/SecurityCondition.hpp"
#include "fields/PriceIndexLevelDecimals.hpp"
#include "fields/RatioMultiplierDecimals.hpp"
#include "fields/InterestPaymentDateRepGroup.hpp"
#include "fields/BidOfferDateTime.hpp"
#include "fields/MmtModificationIndicator.hpp"
#include "fields/Price.hpp"
#include "fields/BidPrice.hpp"
#include "fields/OfferPrice.hpp"
#include "fields/Quantity.hpp"
#include "fields/NotionalAmountTraded.hpp"
#include "fields/NavPrice.hpp"
#include "fields/EventTimeOptional.hpp"
#include "fields/NavBidPrice.hpp"
#include "fields/NavOfferPrice.hpp"
#include "fields/LastMdSeqNum.hpp"
#include "fields/SnapshotTime.hpp"

namespace euronext {
struct ArrowRecord {

    EventType event_type;
    PacketTime packet_time;
    PacketSequenceNumber packet_sequence_number;
    MdgRestartCount mdg_restart_count;
    PsnHighWeight psn_high_weight;
    ChannelId channel_id;
    MdSeqNum md_seq_num;
    SessionTradingDay session_trading_day;
    EventTime event_time;
    MdSeqNumOptional md_seq_num_optional;
    TechnicalNotificationType technical_notification_type;
    RebroadcastIndicator rebroadcast_indicator;
    RetransmissionStartTime retransmission_start_time;
    RetransmissionEndTime retransmission_end_time;
    SymbolIndexOptional symbol_index_optional;
    Emm emm;
    BlockLengthShort block_length_short;
    NumInGroup num_in_group;
    MarketUpdatesGroup market_updates_group;
    OrderUpdatesGroup order_updates_group;
    PriceUpdatesGroup price_updates_group;
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
    NotUsedGroup not_used_group;
    MarketStatesGroup market_states_group;
    EmmOptional emm_optional;
    PatternId pattern_id;
    TimetablesGroup timetables_group;
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
    EmmPatternRepGroup emm_pattern_rep_group;
    IndexLevel index_level;
    PctgOfCapitalization pctg_of_capitalization;
    PrctVarfromPrevClose prct_varfrom_prev_close;
    NumTradedInstruments num_traded_instruments;
    IndexLevelType index_level_type;
    IndexPriceCode index_price_code;
    NewStatsGroup new_stats_group;
    OpeningLevel opening_level;
    OpeningTime opening_time;
    ConfirmedReferenceLevel confirmed_reference_level;
    ConfirmedReferenceTime confirmed_reference_time;
    ClosingReferenceLevel closing_reference_level;
    ClosingReferenceTime closing_reference_time;
    HighLevel high_level;
    HighTime high_time;
    LowLevel low_level;
    LowTime low_time;
    LiquidationLevel liquidation_level;
    LiquidationTime liquidation_time;
    DerivativesInstrumentTradingCode derivatives_instrument_trading_code;
    ExchangeCode exchange_code;
    MaturityDate maturity_date;
    StrategyCode strategy_code;
    ContractSymbolIndex contract_symbol_index;
    CfiOptional cfi_optional;
    StrategyStandingDataGroup strategy_standing_data_group;
    ContractEventDate contract_event_date;
    ExerStyle exer_style;
    ContractName contract_name;
    ContractType contract_type;
    UnderlyingType underlying_type;
    PriceDecimalsOptional price_decimals_optional;
    RatioDecimalsOptional ratio_decimals_optional;
    CountryOfExchange country_of_exchange;
    ProductCode product_code;
    UnderlyingExpiry underlying_expiry;
    SettlementMethod settlement_method;
    TradingCurrency trading_currency;
    StrikePriceDecimalsRatio strike_price_decimals_ratio;
    ContractTradingType contract_trading_type;
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
    ContractEmmPropertiesGroup contract_emm_properties_group;
    LotSize lot_size;
    LastTradingDate last_trading_date;
    DaysToExpiry days_to_expiry;
    DerivativesInstrumentTradingCodeOptional derivatives_instrument_trading_code_optional;
    DerivativesInstrumentType derivatives_instrument_type;
    ExpiryCycleType expiry_cycle_type;
    UnderlyingDerivativesInstrumentTradingCode underlying_derivatives_instrument_trading_code;
    OutrightRepGroup outright_rep_group;
    LongOrderUpdatesGroup long_order_updates_group;
    PackageComponentsGroup package_components_group;
    MifidInstrumentIdType mifid_instrument_id_type;
    MifidInstrumentId mifid_instrument_id;
    Currency currency;
    LeiCode lei_code;
    QuoteUpdateType quote_update_type;
    MifidPrice mifid_price;
    ApaOrigin apa_origin;
    SecondNotionalCurrency second_notional_currency;
    UnderlyingIndexName underlying_index_name;
    UnderlyingIndexTerm underlying_index_term;
    OptionType option_type;
    ExpiryDate expiry_date;
    MifidTransactionId mifid_transaction_id;
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
    LongTradeReference long_trade_reference;
    IsinCodeOptional isin_code_optional;
    SedolCode sedol_code;
    LongIssuerName long_issuer_name;
    LongInstrumentName long_instrument_name;
    CurrencyOptional currency_optional;
    DateOfInitialListing date_of_initial_listing;
    ShareAmountInIssue share_amount_in_issue;
    OpenedClosedFund opened_closed_fund;
    LastNavPrice last_nav_price;
    GrossOfCdscIndicator gross_of_cdsc_indicator;
    Coupon coupon;
    ClosingPrice closing_price;
    MicOptional mic_optional;
    GrossDividendPayablePerUnit gross_dividend_payable_per_unit;
    DividendCurrency dividend_currency;
    DividendRecordDate dividend_record_date;
    DividendRate dividend_rate;
    ExDividendDate ex_dividend_date;
    DividendPaymentDate dividend_payment_date;
    TaxDescriptionAttachingToADividend tax_description_attaching_to_a_dividend;
    NextMeeting next_meeting;
    GrossDividendInEuros gross_dividend_in_euros;
    IssueDate issue_date;
    PaymentFrequency payment_frequency;
    MinimumAmount minimum_amount;
    InstrumentCategory instrument_category;
    SecurityCondition security_condition;
    PriceIndexLevelDecimals price_index_level_decimals;
    RatioMultiplierDecimals ratio_multiplier_decimals;
    InterestPaymentDateRepGroup interest_payment_date_rep_group;
    BidOfferDateTime bid_offer_date_time;
    MmtModificationIndicator mmt_modification_indicator;
    Price price;
    BidPrice bid_price;
    OfferPrice offer_price;
    Quantity quantity;
    NotionalAmountTraded notional_amount_traded;
    NavPrice nav_price;
    EventTimeOptional event_time_optional;
    NavBidPrice nav_bid_price;
    NavOfferPrice nav_offer_price;
    LastMdSeqNum last_md_seq_num;
    SnapshotTime snapshot_time;

    ArrowRecord() = default;

    // parquet record reset
    void reset() {
        event_type.reset();
        packet_time.reset();
        packet_sequence_number.reset();
        mdg_restart_count.reset();
        psn_high_weight.reset();
        channel_id.reset();
        md_seq_num.reset();
        session_trading_day.reset();
        event_time.reset();
        md_seq_num_optional.reset();
        technical_notification_type.reset();
        rebroadcast_indicator.reset();
        retransmission_start_time.reset();
        retransmission_end_time.reset();
        symbol_index_optional.reset();
        emm.reset();
        block_length_short.reset();
        num_in_group.reset();
        market_updates_group.reset();
        order_updates_group.reset();
        price_updates_group.reset();
        trading_date_time.reset();
        publication_date_time.reset();
        trade_type.reset();
        mifid_instrument_id_type_optional.reset();
        mifid_instrument_id_optional.reset();
        mifid_execution_id.reset();
        mifid_price_optional.reset();
        mifid_quantity.reset();
        mifid_price_notation.reset();
        mifid_currency.reset();
        mifid_qty_in_msrmt_unit_notation.reset();
        mifid_quantity_measurement_unit.reset();
        mifid_notional_amount.reset();
        notional_currency.reset();
        mifid_clearing_flag.reset();
        mmt_market_mechanism.reset();
        mmt_trading_mode.reset();
        mmt_transaction_category.reset();
        mmt_negotiation_indicator.reset();
        mmt_agency_cross_trade_indicator.reset();
        mmt_modification_indicator_char_4_optional.reset();
        mmt_benchmark_indicator.reset();
        mmt_special_dividend_indicator.reset();
        mmt_off_book_automated_indicator.reset();
        mmt_contributionto_price.reset();
        mmt_algorithmic_indicator.reset();
        mmt_publication_mode.reset();
        mmt_post_trade_deferral.reset();
        mmt_duplicative_indicator.reset();
        transaction_type.reset();
        effective_date_indicator.reset();
        block_trade_code.reset();
        trade_reference.reset();
        original_report_timestamp.reset();
        transparency_indicator.reset();
        currency_coefficient.reset();
        price_multiplier.reset();
        price_multiplier_decimals.reset();
        venue.reset();
        start_time_vwap.reset();
        end_time_vwap.reset();
        mifid_emission_allowance_type.reset();
        market_of_reference_mic.reset();
        evaluated_price.reset();
        message_price_notation.reset();
        settlement_date.reset();
        repo_settlement_date.reset();
        trade_unique_identifier.reset();
        not_used_group.reset();
        market_states_group.reset();
        emm_optional.reset();
        pattern_id.reset();
        timetables_group.reset();
        symbol_index.reset();
        optiq_segment.reset();
        partition_id.reset();
        full_instrument_name.reset();
        instrument_name.reset();
        instrument_trading_code.reset();
        instrument_group_code.reset();
        isin_code.reset();
        price_decimals.reset();
        quantity_decimals.reset();
        amount_decimals.reset();
        ratio_decimals.reset();
        cfi.reset();
        instrument_event_date.reset();
        strike_price.reset();
        dark_eligibility.reset();
        dark_lis_threshold.reset();
        dark_min_quantity.reset();
        date_of_last_trade.reset();
        depositary_list.reset();
        main_depositary.reset();
        first_settlement_date.reset();
        guarantee_indicator.reset();
        icb.reset();
        issuing_country.reset();
        last_adjusted_closing_price.reset();
        lot_size_optional.reset();
        maturity_date_optional.reset();
        maximum_decimals_in_quantity.reset();
        mic.reset();
        mic_list.reset();
        country_of_exchange_optional.reset();
        mnemonic.reset();
        underlying_mic.reset();
        underlying_isin_code.reset();
        trading_currency_optional.reset();
        trading_currency_indicator.reset();
        strike_currency_indicator.reset();
        number_instrument_circulating.reset();
        par_value.reset();
        quantity_notation.reset();
        inst_unit_exp.reset();
        settlement_delay.reset();
        strike_currency.reset();
        tax_code.reset();
        type_of_corporate_event.reset();
        type_of_market_admission.reset();
        repo_indicator.reset();
        issue_price.reset();
        nominal_currency.reset();
        issue_price_decimals.reset();
        strike_price_decimals.reset();
        liquid_instrument_indicator.reset();
        icb_code.reset();
        threshold_lis_post_trade_60mn.reset();
        threshold_lis_post_trade_120mn.reset();
        threshold_lis_post_trade_eod.reset();
        long_mnemonic.reset();
        max_order_amount_call.reset();
        max_order_amount_continuous.reset();
        max_order_quantity_call.reset();
        max_order_quantity_continuous.reset();
        pool_factor.reset();
        emm_pattern_rep_group.reset();
        index_level.reset();
        pctg_of_capitalization.reset();
        prct_varfrom_prev_close.reset();
        num_traded_instruments.reset();
        index_level_type.reset();
        index_price_code.reset();
        new_stats_group.reset();
        opening_level.reset();
        opening_time.reset();
        confirmed_reference_level.reset();
        confirmed_reference_time.reset();
        closing_reference_level.reset();
        closing_reference_time.reset();
        high_level.reset();
        high_time.reset();
        low_level.reset();
        low_time.reset();
        liquidation_level.reset();
        liquidation_time.reset();
        derivatives_instrument_trading_code.reset();
        exchange_code.reset();
        maturity_date.reset();
        strategy_code.reset();
        contract_symbol_index.reset();
        cfi_optional.reset();
        strategy_standing_data_group.reset();
        contract_event_date.reset();
        exer_style.reset();
        contract_name.reset();
        contract_type.reset();
        underlying_type.reset();
        price_decimals_optional.reset();
        ratio_decimals_optional.reset();
        country_of_exchange.reset();
        product_code.reset();
        underlying_expiry.reset();
        settlement_method.reset();
        trading_currency.reset();
        strike_price_decimals_ratio.reset();
        contract_trading_type.reset();
        underlying_subtype.reset();
        mother_stock_isin.reset();
        settlement_tick_size.reset();
        edsp_tick_size.reset();
        underlying_symbol_index.reset();
        trading_policy.reset();
        reference_spread_table_id.reset();
        derivatives_market_model.reset();
        trading_unit.reset();
        reference_price_origin_in_opening_call.reset();
        reference_price_origin_in_continuous.reset();
        reference_price_origin_in_trading_interruption.reset();
        collar_expansion_factor.reset();
        mifidii_liquid_flag.reset();
        pricing_algorithm.reset();
        contract_emm_properties_group.reset();
        lot_size.reset();
        last_trading_date.reset();
        days_to_expiry.reset();
        derivatives_instrument_trading_code_optional.reset();
        derivatives_instrument_type.reset();
        expiry_cycle_type.reset();
        underlying_derivatives_instrument_trading_code.reset();
        outright_rep_group.reset();
        long_order_updates_group.reset();
        package_components_group.reset();
        mifid_instrument_id_type.reset();
        mifid_instrument_id.reset();
        currency.reset();
        lei_code.reset();
        quote_update_type.reset();
        mifid_price.reset();
        apa_origin.reset();
        second_notional_currency.reset();
        underlying_index_name.reset();
        underlying_index_term.reset();
        option_type.reset();
        expiry_date.reset();
        mifid_transaction_id.reset();
        efficient_mmt_market_mechanism.reset();
        efficient_mmt_trading_mode.reset();
        efficient_mmt_transaction_category.reset();
        efficient_mmt_negotiation_indicator.reset();
        efficient_mmt_agency_cross_trade_indicator.reset();
        efficient_mmt_modification_indicator.reset();
        efficient_mmt_benchmark_indicator.reset();
        efficient_mmt_special_dividend_indicator.reset();
        efficient_mmt_off_book_automated_indicator.reset();
        efficient_mmt_contributionto_price.reset();
        efficient_mmt_algorithmic_indicator.reset();
        efficient_mmt_publication_mode.reset();
        efficient_mmt_post_trade_deferral.reset();
        efficient_mmt_duplicative_indicator.reset();
        long_trade_reference.reset();
        isin_code_optional.reset();
        sedol_code.reset();
        long_issuer_name.reset();
        long_instrument_name.reset();
        currency_optional.reset();
        date_of_initial_listing.reset();
        share_amount_in_issue.reset();
        opened_closed_fund.reset();
        last_nav_price.reset();
        gross_of_cdsc_indicator.reset();
        coupon.reset();
        closing_price.reset();
        mic_optional.reset();
        gross_dividend_payable_per_unit.reset();
        dividend_currency.reset();
        dividend_record_date.reset();
        dividend_rate.reset();
        ex_dividend_date.reset();
        dividend_payment_date.reset();
        tax_description_attaching_to_a_dividend.reset();
        next_meeting.reset();
        gross_dividend_in_euros.reset();
        issue_date.reset();
        payment_frequency.reset();
        minimum_amount.reset();
        instrument_category.reset();
        security_condition.reset();
        price_index_level_decimals.reset();
        ratio_multiplier_decimals.reset();
        interest_payment_date_rep_group.reset();
        bid_offer_date_time.reset();
        mmt_modification_indicator.reset();
        price.reset();
        bid_price.reset();
        offer_price.reset();
        quantity.reset();
        notional_amount_traded.reset();
        nav_price.reset();
        event_time_optional.reset();
        nav_bid_price.reset();
        nav_offer_price.reset();
        last_md_seq_num.reset();
        snapshot_time.reset();
    }

    // arrow schema
    static auto schema() {
        return arrow::schema( {
            EventType::column(),
            PacketTime::column(),
            PacketSequenceNumber::column(),
            MdgRestartCount::column(),
            PsnHighWeight::column(),
            ChannelId::column(),
            MdSeqNum::column(),
            SessionTradingDay::column(),
            EventTime::column(),
            MdSeqNumOptional::column(),
            TechnicalNotificationType::column(),
            RebroadcastIndicator::column(),
            RetransmissionStartTime::column(),
            RetransmissionEndTime::column(),
            SymbolIndexOptional::column(),
            Emm::column(),
            BlockLengthShort::column(),
            NumInGroup::column(),
            MarketUpdatesGroup::column(),
            OrderUpdatesGroup::column(),
            PriceUpdatesGroup::column(),
            TradingDateTime::column(),
            PublicationDateTime::column(),
            TradeType::column(),
            MifidInstrumentIdTypeOptional::column(),
            MifidInstrumentIdOptional::column(),
            MifidExecutionId::column(),
            MifidPriceOptional::column(),
            MifidQuantity::column(),
            MifidPriceNotation::column(),
            MifidCurrency::column(),
            MifidQtyInMsrmtUnitNotation::column(),
            MifidQuantityMeasurementUnit::column(),
            MifidNotionalAmount::column(),
            NotionalCurrency::column(),
            MifidClearingFlag::column(),
            MmtMarketMechanism::column(),
            MmtTradingMode::column(),
            MmtTransactionCategory::column(),
            MmtNegotiationIndicator::column(),
            MmtAgencyCrossTradeIndicator::column(),
            MmtModificationIndicatorChar4Optional::column(),
            MmtBenchmarkIndicator::column(),
            MmtSpecialDividendIndicator::column(),
            MmtOffBookAutomatedIndicator::column(),
            MmtContributiontoPrice::column(),
            MmtAlgorithmicIndicator::column(),
            MmtPublicationMode::column(),
            MmtPostTradeDeferral::column(),
            MmtDuplicativeIndicator::column(),
            TransactionType::column(),
            EffectiveDateIndicator::column(),
            BlockTradeCode::column(),
            TradeReference::column(),
            OriginalReportTimestamp::column(),
            TransparencyIndicator::column(),
            CurrencyCoefficient::column(),
            PriceMultiplier::column(),
            PriceMultiplierDecimals::column(),
            Venue::column(),
            StartTimeVwap::column(),
            EndTimeVwap::column(),
            MifidEmissionAllowanceType::column(),
            MarketOfReferenceMic::column(),
            EvaluatedPrice::column(),
            MessagePriceNotation::column(),
            SettlementDate::column(),
            RepoSettlementDate::column(),
            TradeUniqueIdentifier::column(),
            NotUsedGroup::column(),
            MarketStatesGroup::column(),
            EmmOptional::column(),
            PatternId::column(),
            TimetablesGroup::column(),
            SymbolIndex::column(),
            OptiqSegment::column(),
            PartitionId::column(),
            FullInstrumentName::column(),
            InstrumentName::column(),
            InstrumentTradingCode::column(),
            InstrumentGroupCode::column(),
            IsinCode::column(),
            PriceDecimals::column(),
            QuantityDecimals::column(),
            AmountDecimals::column(),
            RatioDecimals::column(),
            Cfi::column(),
            InstrumentEventDate::column(),
            StrikePrice::column(),
            DarkEligibility::column(),
            DarkLisThreshold::column(),
            DarkMinQuantity::column(),
            DateOfLastTrade::column(),
            DepositaryList::column(),
            MainDepositary::column(),
            FirstSettlementDate::column(),
            GuaranteeIndicator::column(),
            Icb::column(),
            IssuingCountry::column(),
            LastAdjustedClosingPrice::column(),
            LotSizeOptional::column(),
            MaturityDateOptional::column(),
            MaximumDecimalsInQuantity::column(),
            Mic::column(),
            MicList::column(),
            CountryOfExchangeOptional::column(),
            Mnemonic::column(),
            UnderlyingMic::column(),
            UnderlyingIsinCode::column(),
            TradingCurrencyOptional::column(),
            TradingCurrencyIndicator::column(),
            StrikeCurrencyIndicator::column(),
            NumberInstrumentCirculating::column(),
            ParValue::column(),
            QuantityNotation::column(),
            InstUnitExp::column(),
            SettlementDelay::column(),
            StrikeCurrency::column(),
            TaxCode::column(),
            TypeOfCorporateEvent::column(),
            TypeOfMarketAdmission::column(),
            RepoIndicator::column(),
            IssuePrice::column(),
            NominalCurrency::column(),
            IssuePriceDecimals::column(),
            StrikePriceDecimals::column(),
            LiquidInstrumentIndicator::column(),
            IcbCode::column(),
            ThresholdLisPostTrade60Mn::column(),
            ThresholdLisPostTrade120Mn::column(),
            ThresholdLisPostTradeEod::column(),
            LongMnemonic::column(),
            MaxOrderAmountCall::column(),
            MaxOrderAmountContinuous::column(),
            MaxOrderQuantityCall::column(),
            MaxOrderQuantityContinuous::column(),
            PoolFactor::column(),
            EmmPatternRepGroup::column(),
            IndexLevel::column(),
            PctgOfCapitalization::column(),
            PrctVarfromPrevClose::column(),
            NumTradedInstruments::column(),
            IndexLevelType::column(),
            IndexPriceCode::column(),
            NewStatsGroup::column(),
            OpeningLevel::column(),
            OpeningTime::column(),
            ConfirmedReferenceLevel::column(),
            ConfirmedReferenceTime::column(),
            ClosingReferenceLevel::column(),
            ClosingReferenceTime::column(),
            HighLevel::column(),
            HighTime::column(),
            LowLevel::column(),
            LowTime::column(),
            LiquidationLevel::column(),
            LiquidationTime::column(),
            DerivativesInstrumentTradingCode::column(),
            ExchangeCode::column(),
            MaturityDate::column(),
            StrategyCode::column(),
            ContractSymbolIndex::column(),
            CfiOptional::column(),
            StrategyStandingDataGroup::column(),
            ContractEventDate::column(),
            ExerStyle::column(),
            ContractName::column(),
            ContractType::column(),
            UnderlyingType::column(),
            PriceDecimalsOptional::column(),
            RatioDecimalsOptional::column(),
            CountryOfExchange::column(),
            ProductCode::column(),
            UnderlyingExpiry::column(),
            SettlementMethod::column(),
            TradingCurrency::column(),
            StrikePriceDecimalsRatio::column(),
            ContractTradingType::column(),
            UnderlyingSubtype::column(),
            MotherStockIsin::column(),
            SettlementTickSize::column(),
            EdspTickSize::column(),
            UnderlyingSymbolIndex::column(),
            TradingPolicy::column(),
            ReferenceSpreadTableId::column(),
            DerivativesMarketModel::column(),
            TradingUnit::column(),
            ReferencePriceOriginInOpeningCall::column(),
            ReferencePriceOriginInContinuous::column(),
            ReferencePriceOriginInTradingInterruption::column(),
            CollarExpansionFactor::column(),
            MifidiiLiquidFlag::column(),
            PricingAlgorithm::column(),
            ContractEmmPropertiesGroup::column(),
            LotSize::column(),
            LastTradingDate::column(),
            DaysToExpiry::column(),
            DerivativesInstrumentTradingCodeOptional::column(),
            DerivativesInstrumentType::column(),
            ExpiryCycleType::column(),
            UnderlyingDerivativesInstrumentTradingCode::column(),
            OutrightRepGroup::column(),
            LongOrderUpdatesGroup::column(),
            PackageComponentsGroup::column(),
            MifidInstrumentIdType::column(),
            MifidInstrumentId::column(),
            Currency::column(),
            LeiCode::column(),
            QuoteUpdateType::column(),
            MifidPrice::column(),
            ApaOrigin::column(),
            SecondNotionalCurrency::column(),
            UnderlyingIndexName::column(),
            UnderlyingIndexTerm::column(),
            OptionType::column(),
            ExpiryDate::column(),
            MifidTransactionId::column(),
            EfficientMmtMarketMechanism::column(),
            EfficientMmtTradingMode::column(),
            EfficientMmtTransactionCategory::column(),
            EfficientMmtNegotiationIndicator::column(),
            EfficientMmtAgencyCrossTradeIndicator::column(),
            EfficientMmtModificationIndicator::column(),
            EfficientMmtBenchmarkIndicator::column(),
            EfficientMmtSpecialDividendIndicator::column(),
            EfficientMmtOffBookAutomatedIndicator::column(),
            EfficientMmtContributiontoPrice::column(),
            EfficientMmtAlgorithmicIndicator::column(),
            EfficientMmtPublicationMode::column(),
            EfficientMmtPostTradeDeferral::column(),
            EfficientMmtDuplicativeIndicator::column(),
            LongTradeReference::column(),
            IsinCodeOptional::column(),
            SedolCode::column(),
            LongIssuerName::column(),
            LongInstrumentName::column(),
            CurrencyOptional::column(),
            DateOfInitialListing::column(),
            ShareAmountInIssue::column(),
            OpenedClosedFund::column(),
            LastNavPrice::column(),
            GrossOfCdscIndicator::column(),
            Coupon::column(),
            ClosingPrice::column(),
            MicOptional::column(),
            GrossDividendPayablePerUnit::column(),
            DividendCurrency::column(),
            DividendRecordDate::column(),
            DividendRate::column(),
            ExDividendDate::column(),
            DividendPaymentDate::column(),
            TaxDescriptionAttachingToADividend::column(),
            NextMeeting::column(),
            GrossDividendInEuros::column(),
            IssueDate::column(),
            PaymentFrequency::column(),
            MinimumAmount::column(),
            InstrumentCategory::column(),
            SecurityCondition::column(),
            PriceIndexLevelDecimals::column(),
            RatioMultiplierDecimals::column(),
            InterestPaymentDateRepGroup::column(),
            BidOfferDateTime::column(),
            MmtModificationIndicator::column(),
            Price::column(),
            BidPrice::column(),
            OfferPrice::column(),
            Quantity::column(),
            NotionalAmountTraded::column(),
            NavPrice::column(),
            EventTimeOptional::column(),
            NavBidPrice::column(),
            NavOfferPrice::column(),
            LastMdSeqNum::column(),
            SnapshotTime::column()
        } );
    }
};
}
