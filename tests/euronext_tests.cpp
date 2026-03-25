#include <gtest/gtest.h>

#include "../euronext/protocol/definitions.hpp"
#include "../euronext/parquet/Record.hpp"

TEST(EuronextStructs, MarketDataPacketHeaderSize) {
    EXPECT_EQ(sizeof(euronext::optiq::marketdatagateway::sbe::v5_25::MarketDataPacketHeader), 16);
}

TEST(EuronextSchema, FieldCount) {
    auto schema = euronext::ArrowRecord::schema();
    EXPECT_EQ(schema->num_fields(), 275);
}

TEST(EuronextSchema, FirstFieldIsEventType) {
    auto schema = euronext::ArrowRecord::schema();
    EXPECT_EQ(schema->field(0)->name(), "event_type");
}

TEST(EuronextSchema, EventTypeIsNotNullable) {
    auto schema = euronext::ArrowRecord::schema();
    EXPECT_FALSE(schema->field(0)->nullable());
}

TEST(EuronextSchema, MessageFieldsAreNullable) {
    auto schema = euronext::ArrowRecord::schema();
    for (int i = 1; i < schema->num_fields(); ++i) {
        EXPECT_TRUE(schema->field(i)->nullable()) << schema->field(i)->name() << " should be nullable";
    }
}

TEST(EuronextSchema, NoDuplicateFieldNames) {
    auto schema = euronext::ArrowRecord::schema();
    std::set<std::string> names;
    for (int i = 0; i < schema->num_fields(); ++i) {
        auto result = names.insert(schema->field(i)->name());
        EXPECT_TRUE(result.second) << "Duplicate field: " << schema->field(i)->name();
    }
}

TEST(EuronextRecord, SetAndReset) {
    euronext::ArrowRecord record;
    record.event_type.set("Test");
    record.event_type.reset();
}
