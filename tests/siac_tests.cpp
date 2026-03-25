#include <gtest/gtest.h>

#include "../siac/protocol/definitions.hpp"
#include "../siac/parquet/Record.hpp"

TEST(SiacStructs, BlockHeaderSize) {
    EXPECT_EQ(sizeof(siac::opra::recipient::obi::v6_2::BlockHeader), 21);
}

TEST(SiacSchema, FieldCount) {
    auto schema = siac::ArrowRecord::schema();
    EXPECT_EQ(schema->num_fields(), 65);
}

TEST(SiacSchema, FirstFieldIsEventType) {
    auto schema = siac::ArrowRecord::schema();
    EXPECT_EQ(schema->field(0)->name(), "event_type");
}

TEST(SiacSchema, EventTypeIsNotNullable) {
    auto schema = siac::ArrowRecord::schema();
    EXPECT_FALSE(schema->field(0)->nullable());
}

TEST(SiacSchema, MessageFieldsAreNullable) {
    auto schema = siac::ArrowRecord::schema();
    for (int i = 1; i < schema->num_fields(); ++i) {
        EXPECT_TRUE(schema->field(i)->nullable()) << schema->field(i)->name() << " should be nullable";
    }
}

TEST(SiacSchema, NoDuplicateFieldNames) {
    auto schema = siac::ArrowRecord::schema();
    std::set<std::string> names;
    for (int i = 0; i < schema->num_fields(); ++i) {
        auto result = names.insert(schema->field(i)->name());
        EXPECT_TRUE(result.second) << "Duplicate field: " << schema->field(i)->name();
    }
}

TEST(SiacRecord, SetAndReset) {
    siac::ArrowRecord record;
    record.event_type.set("Test");
    record.event_type.reset();
}
