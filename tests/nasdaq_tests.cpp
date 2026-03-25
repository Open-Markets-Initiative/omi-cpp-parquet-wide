#include <gtest/gtest.h>

#include "../nasdaq/protocol/definitions.hpp"
#include "../nasdaq/parquet/Record.hpp"

TEST(NasdaqStructs, PacketHeaderSize) {
    EXPECT_EQ(sizeof(nasdaq::nsmequities::totalview::itch::v5_0::PacketHeader), 20);
}

TEST(NasdaqSchema, FieldCount) {
    auto schema = nasdaq::ArrowRecord::schema();
    EXPECT_EQ(schema->num_fields(), 73);
}

TEST(NasdaqSchema, FirstFieldIsEventType) {
    auto schema = nasdaq::ArrowRecord::schema();
    EXPECT_EQ(schema->field(0)->name(), "event_type");
}

TEST(NasdaqSchema, EventTypeIsNotNullable) {
    auto schema = nasdaq::ArrowRecord::schema();
    EXPECT_FALSE(schema->field(0)->nullable());
}

TEST(NasdaqSchema, MessageFieldsAreNullable) {
    auto schema = nasdaq::ArrowRecord::schema();
    for (int i = 1; i < schema->num_fields(); ++i) {
        EXPECT_TRUE(schema->field(i)->nullable()) << schema->field(i)->name() << " should be nullable";
    }
}

TEST(NasdaqSchema, NoDuplicateFieldNames) {
    auto schema = nasdaq::ArrowRecord::schema();
    std::set<std::string> names;
    for (int i = 0; i < schema->num_fields(); ++i) {
        auto result = names.insert(schema->field(i)->name());
        EXPECT_TRUE(result.second) << "Duplicate field: " << schema->field(i)->name();
    }
}

TEST(NasdaqRecord, SetAndReset) {
    nasdaq::ArrowRecord record;
    record.event_type.set("Test");
    record.event_type.reset();
}
