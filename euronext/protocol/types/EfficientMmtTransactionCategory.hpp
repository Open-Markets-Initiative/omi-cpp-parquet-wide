#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTTransactionCategory
struct EfficientMmtTransactionCategory {

    static constexpr const char* name = "Efficient Mmt Transaction Category";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr EfficientMmtTransactionCategory()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtTransactionCategory(const char value)
     : value{ value } {}

    // get value of EfficientMmtTransactionCategory field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
