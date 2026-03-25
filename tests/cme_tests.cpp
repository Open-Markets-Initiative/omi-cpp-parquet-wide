#include <gtest/gtest.h>

#include "../cme/protocol/definitions.hpp"
#include "../cme/parquet/Record.hpp"

TEST(CmeStructs, BinaryPacketHeaderSize) {
    EXPECT_EQ(sizeof(cme::mdp3::v8::BinaryPacketHeader), 12);
}

TEST(CmeSchema, FieldCount) {
    auto schema = cme::ArrowRecord::schema();
    EXPECT_EQ(schema->num_fields(), 102);
}

TEST(CmeSchema, FirstFieldIsEventType) {
    auto schema = cme::ArrowRecord::schema();
    EXPECT_EQ(schema->field(0)->name(), "event_type");
}

TEST(CmeSchema, EventTypeIsNotNullable) {
    auto schema = cme::ArrowRecord::schema();
    EXPECT_FALSE(schema->field(0)->nullable());
}

TEST(CmeSchema, MessageFieldsAreNullable) {
    auto schema = cme::ArrowRecord::schema();
    for (int i = 1; i < schema->num_fields(); ++i) {
        EXPECT_TRUE(schema->field(i)->nullable()) << schema->field(i)->name() << " should be nullable";
    }
}

TEST(CmeSchema, NoDuplicateFieldNames) {
    auto schema = cme::ArrowRecord::schema();
    std::set<std::string> names;
    for (int i = 0; i < schema->num_fields(); ++i) {
        auto result = names.insert(schema->field(i)->name());
        EXPECT_TRUE(result.second) << "Duplicate field: " << schema->field(i)->name();
    }
}

TEST(CmeRecord, SetAndReset) {
    cme::ArrowRecord record;
    record.event_type.set("Test");
    record.event_type.reset();
}
