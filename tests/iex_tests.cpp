#include <gtest/gtest.h>

#include "../iex/protocol/definitions.hpp"
#include "../iex/parquet/Record.hpp"

TEST(IexStructs, IextpHeaderSize) {
    EXPECT_EQ(sizeof(iex::equities::tops::iextp::v1_6_6::IextpHeader), 40);
}

TEST(IexSchema, FieldCount) {
    auto schema = iex::ArrowRecord::schema();
    EXPECT_EQ(schema->num_fields(), 42);
}

TEST(IexSchema, FirstFieldIsEventType) {
    auto schema = iex::ArrowRecord::schema();
    EXPECT_EQ(schema->field(0)->name(), "event_type");
}

TEST(IexSchema, EventTypeIsNotNullable) {
    auto schema = iex::ArrowRecord::schema();
    EXPECT_FALSE(schema->field(0)->nullable());
}

TEST(IexSchema, MessageFieldsAreNullable) {
    auto schema = iex::ArrowRecord::schema();
    for (int i = 1; i < schema->num_fields(); ++i) {
        EXPECT_TRUE(schema->field(i)->nullable()) << schema->field(i)->name() << " should be nullable";
    }
}

TEST(IexSchema, NoDuplicateFieldNames) {
    auto schema = iex::ArrowRecord::schema();
    std::set<std::string> names;
    for (int i = 0; i < schema->num_fields(); ++i) {
        auto result = names.insert(schema->field(i)->name());
        EXPECT_TRUE(result.second) << "Duplicate field: " << schema->field(i)->name();
    }
}

TEST(IexRecord, SetAndReset) {
    iex::ArrowRecord record;
    record.event_type.set("Test");
    record.event_type.reset();
}
