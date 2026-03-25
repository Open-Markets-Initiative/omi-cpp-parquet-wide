#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTBenchmarkIndicator
struct EfficientMmtBenchmarkIndicator {

    static constexpr const char* name = "Efficient Mmt Benchmark Indicator";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr EfficientMmtBenchmarkIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtBenchmarkIndicator(const char value)
     : value{ value } {}

    // get value of EfficientMmtBenchmarkIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
