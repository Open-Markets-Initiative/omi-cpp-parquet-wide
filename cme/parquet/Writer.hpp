#pragma once

#include "Settings.hpp"
#include "Record.hpp"
#include "Batch.hpp"

namespace cme {

// arrow parquet batch writer
struct Writer : ArrowRecord {

    parquet::Options options;
    ArrowBatch batch;

    // parquet batch writer
    explicit Writer(const parquet::Options& options)
        : options{options},
          batch{schema(), options}
    {}

    ~Writer() {
        close();
    }

    // write record to batch
    void write() {
        PARQUET_THROW_NOT_OK(batch.write(*this));
        reset();
    }

    // close the parquet file
    void close() {
        PARQUET_THROW_NOT_OK(batch.close());
    }
};

}