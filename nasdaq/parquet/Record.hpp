#pragma once

#include <memory>

#include "fields/EventType.hpp"
#include "fields/StockLocate.hpp"
#include "fields/TrackingNumber.hpp"
#include "fields/Timestamp.hpp"
#include "fields/EventCode.hpp"
#include "fields/Stock.hpp"
#include "fields/MarketCategory.hpp"
#include "fields/FinancialStatusIndicator.hpp"
#include "fields/RoundLotSize.hpp"
#include "fields/RoundLotsOnly.hpp"
#include "fields/IssueClassification.hpp"
#include "fields/IssueSubType.hpp"
#include "fields/Authenticity.hpp"
#include "fields/ShortSaleThresholdIndicator.hpp"
#include "fields/IpoFlag.hpp"
#include "fields/LuldReferencePriceTier.hpp"
#include "fields/EtpFlag.hpp"
#include "fields/EtpLeverageFactor.hpp"
#include "fields/InverseIndicator.hpp"
#include "fields/TradingState.hpp"
#include "fields/Reserved.hpp"
#include "fields/ReasonCode.hpp"
#include "fields/LocateCode.hpp"
#include "fields/RegShoAction.hpp"
#include "fields/Mpid.hpp"
#include "fields/PrimaryMarketMaker.hpp"
#include "fields/MarketMakerMode.hpp"
#include "fields/MarketParticipantState.hpp"
#include "fields/Level1.hpp"
#include "fields/Level2.hpp"
#include "fields/Level3.hpp"
#include "fields/BreachedLevel.hpp"
#include "fields/IpoQuotationReleaseTime.hpp"
#include "fields/IpoQuotationReleaseQualifier.hpp"
#include "fields/IpoPrice.hpp"
#include "fields/AuctionCollarReferencePrice.hpp"
#include "fields/UpperAuctionCollarPrice.hpp"
#include "fields/LowerAuctionCollarPrice.hpp"
#include "fields/AuctionCollarExtension.hpp"
#include "fields/MarketCode.hpp"
#include "fields/OperationalHaltAction.hpp"
#include "fields/OrderReferenceNumber.hpp"
#include "fields/BuySellIndicator.hpp"
#include "fields/Shares.hpp"
#include "fields/Price.hpp"
#include "fields/Attribution.hpp"
#include "fields/ExecutedShares.hpp"
#include "fields/MatchNumber.hpp"
#include "fields/Printable.hpp"
#include "fields/ExecutionPrice.hpp"
#include "fields/CanceledShares.hpp"
#include "fields/OriginalOrderReferenceNumber.hpp"
#include "fields/NewOrderReferenceNumber.hpp"
#include "fields/CrossShares.hpp"
#include "fields/CrossPrice.hpp"
#include "fields/CrossType.hpp"
#include "fields/PairedShares.hpp"
#include "fields/ImbalanceShares.hpp"
#include "fields/ImbalanceDirection.hpp"
#include "fields/FarPrice.hpp"
#include "fields/NearPrice.hpp"
#include "fields/CurrentReferencePrice.hpp"
#include "fields/PriceVariationIndicator.hpp"
#include "fields/InterestFlag.hpp"
#include "fields/OpenEligibilityStatus.hpp"
#include "fields/MinimumAllowablePrice.hpp"
#include "fields/MaximumAllowablePrice.hpp"
#include "fields/NearExecutionPrice.hpp"
#include "fields/NearExecutionTime.hpp"
#include "fields/LowerPriceRangeCollar.hpp"
#include "fields/UpperPriceRangeCollar.hpp"

namespace nasdaq {
struct ArrowRecord {

    EventType event_type;
    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    EventCode event_code;
    Stock stock;
    MarketCategory market_category;
    FinancialStatusIndicator financial_status_indicator;
    RoundLotSize round_lot_size;
    RoundLotsOnly round_lots_only;
    IssueClassification issue_classification;
    IssueSubType issue_sub_type;
    Authenticity authenticity;
    ShortSaleThresholdIndicator short_sale_threshold_indicator;
    IpoFlag ipo_flag;
    LuldReferencePriceTier luld_reference_price_tier;
    EtpFlag etp_flag;
    EtpLeverageFactor etp_leverage_factor;
    InverseIndicator inverse_indicator;
    TradingState trading_state;
    Reserved reserved;
    ReasonCode reason_code;
    LocateCode locate_code;
    RegShoAction reg_sho_action;
    Mpid mpid;
    PrimaryMarketMaker primary_market_maker;
    MarketMakerMode market_maker_mode;
    MarketParticipantState market_participant_state;
    Level1 level_1;
    Level2 level_2;
    Level3 level_3;
    BreachedLevel breached_level;
    IpoQuotationReleaseTime ipo_quotation_release_time;
    IpoQuotationReleaseQualifier ipo_quotation_release_qualifier;
    IpoPrice ipo_price;
    AuctionCollarReferencePrice auction_collar_reference_price;
    UpperAuctionCollarPrice upper_auction_collar_price;
    LowerAuctionCollarPrice lower_auction_collar_price;
    AuctionCollarExtension auction_collar_extension;
    MarketCode market_code;
    OperationalHaltAction operational_halt_action;
    OrderReferenceNumber order_reference_number;
    BuySellIndicator buy_sell_indicator;
    Shares shares;
    Price price;
    Attribution attribution;
    ExecutedShares executed_shares;
    MatchNumber match_number;
    Printable printable;
    ExecutionPrice execution_price;
    CanceledShares canceled_shares;
    OriginalOrderReferenceNumber original_order_reference_number;
    NewOrderReferenceNumber new_order_reference_number;
    CrossShares cross_shares;
    CrossPrice cross_price;
    CrossType cross_type;
    PairedShares paired_shares;
    ImbalanceShares imbalance_shares;
    ImbalanceDirection imbalance_direction;
    FarPrice far_price;
    NearPrice near_price;
    CurrentReferencePrice current_reference_price;
    PriceVariationIndicator price_variation_indicator;
    InterestFlag interest_flag;
    OpenEligibilityStatus open_eligibility_status;
    MinimumAllowablePrice minimum_allowable_price;
    MaximumAllowablePrice maximum_allowable_price;
    NearExecutionPrice near_execution_price;
    NearExecutionTime near_execution_time;
    LowerPriceRangeCollar lower_price_range_collar;
    UpperPriceRangeCollar upper_price_range_collar;

    ArrowRecord() = default;

    // parquet record reset
    void reset() {
        event_type.reset();
        stock_locate.reset();
        tracking_number.reset();
        timestamp.reset();
        event_code.reset();
        stock.reset();
        market_category.reset();
        financial_status_indicator.reset();
        round_lot_size.reset();
        round_lots_only.reset();
        issue_classification.reset();
        issue_sub_type.reset();
        authenticity.reset();
        short_sale_threshold_indicator.reset();
        ipo_flag.reset();
        luld_reference_price_tier.reset();
        etp_flag.reset();
        etp_leverage_factor.reset();
        inverse_indicator.reset();
        trading_state.reset();
        reserved.reset();
        reason_code.reset();
        locate_code.reset();
        reg_sho_action.reset();
        mpid.reset();
        primary_market_maker.reset();
        market_maker_mode.reset();
        market_participant_state.reset();
        level_1.reset();
        level_2.reset();
        level_3.reset();
        breached_level.reset();
        ipo_quotation_release_time.reset();
        ipo_quotation_release_qualifier.reset();
        ipo_price.reset();
        auction_collar_reference_price.reset();
        upper_auction_collar_price.reset();
        lower_auction_collar_price.reset();
        auction_collar_extension.reset();
        market_code.reset();
        operational_halt_action.reset();
        order_reference_number.reset();
        buy_sell_indicator.reset();
        shares.reset();
        price.reset();
        attribution.reset();
        executed_shares.reset();
        match_number.reset();
        printable.reset();
        execution_price.reset();
        canceled_shares.reset();
        original_order_reference_number.reset();
        new_order_reference_number.reset();
        cross_shares.reset();
        cross_price.reset();
        cross_type.reset();
        paired_shares.reset();
        imbalance_shares.reset();
        imbalance_direction.reset();
        far_price.reset();
        near_price.reset();
        current_reference_price.reset();
        price_variation_indicator.reset();
        interest_flag.reset();
        open_eligibility_status.reset();
        minimum_allowable_price.reset();
        maximum_allowable_price.reset();
        near_execution_price.reset();
        near_execution_time.reset();
        lower_price_range_collar.reset();
        upper_price_range_collar.reset();
    }

    // arrow schema
    static auto schema() {
        return arrow::schema( {
            EventType::column(),
            StockLocate::column(),
            TrackingNumber::column(),
            Timestamp::column(),
            EventCode::column(),
            Stock::column(),
            MarketCategory::column(),
            FinancialStatusIndicator::column(),
            RoundLotSize::column(),
            RoundLotsOnly::column(),
            IssueClassification::column(),
            IssueSubType::column(),
            Authenticity::column(),
            ShortSaleThresholdIndicator::column(),
            IpoFlag::column(),
            LuldReferencePriceTier::column(),
            EtpFlag::column(),
            EtpLeverageFactor::column(),
            InverseIndicator::column(),
            TradingState::column(),
            Reserved::column(),
            ReasonCode::column(),
            LocateCode::column(),
            RegShoAction::column(),
            Mpid::column(),
            PrimaryMarketMaker::column(),
            MarketMakerMode::column(),
            MarketParticipantState::column(),
            Level1::column(),
            Level2::column(),
            Level3::column(),
            BreachedLevel::column(),
            IpoQuotationReleaseTime::column(),
            IpoQuotationReleaseQualifier::column(),
            IpoPrice::column(),
            AuctionCollarReferencePrice::column(),
            UpperAuctionCollarPrice::column(),
            LowerAuctionCollarPrice::column(),
            AuctionCollarExtension::column(),
            MarketCode::column(),
            OperationalHaltAction::column(),
            OrderReferenceNumber::column(),
            BuySellIndicator::column(),
            Shares::column(),
            Price::column(),
            Attribution::column(),
            ExecutedShares::column(),
            MatchNumber::column(),
            Printable::column(),
            ExecutionPrice::column(),
            CanceledShares::column(),
            OriginalOrderReferenceNumber::column(),
            NewOrderReferenceNumber::column(),
            CrossShares::column(),
            CrossPrice::column(),
            CrossType::column(),
            PairedShares::column(),
            ImbalanceShares::column(),
            ImbalanceDirection::column(),
            FarPrice::column(),
            NearPrice::column(),
            CurrentReferencePrice::column(),
            PriceVariationIndicator::column(),
            InterestFlag::column(),
            OpenEligibilityStatus::column(),
            MinimumAllowablePrice::column(),
            MaximumAllowablePrice::column(),
            NearExecutionPrice::column(),
            NearExecutionTime::column(),
            LowerPriceRangeCollar::column(),
            UpperPriceRangeCollar::column()
        } );
    }
};
}
