#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <charconv>

namespace json {

// High-performance JSON writer
// Builds a JSON object as a std::string for embedding in parquet columns
struct Writer {

    std::string buffer_;
    bool first_field_ = true;

    // Start a new JSON object
    void start() {
        buffer_.clear();
        buffer_ += '{';
        first_field_ = true;
    }

    // Finish object
    void finish() {
        buffer_ += '}';
    }

    // Start a new JSON array
    void start_array() {
        buffer_.clear();
        buffer_ += '[';
        first_field_ = true;
    }

    // Finish array
    void finish_array() {
        buffer_ += ']';
    }

    // Start array element object
    void start_element() {
        separator();
        buffer_ += '{';
        first_field_ = true;
    }

    // End array element object
    void end_element() {
        buffer_ += '}';
        first_field_ = false;
    }

    // Get result
    std::string_view view() const {
        return std::string_view(buffer_);
    }

    // Field separator
    void separator() {
        if (!first_field_) {
            buffer_ += ',';
        }
        first_field_ = false;
    }

    // Write key
    void key(std::string_view k) {
        separator();
        buffer_ += '"';
        buffer_.append(k.data(), k.size());
        buffer_ += "\":";
    }

    // Integer value
    void value(std::int64_t v) {
        char buf[24];
        auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), v);
        buffer_.append(buf, static_cast<std::size_t>(ptr - buf));
    }

    void value(std::uint64_t v) {
        char buf[24];
        auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), v);
        buffer_.append(buf, static_cast<std::size_t>(ptr - buf));
    }

    void value(std::int32_t v) { value(static_cast<std::int64_t>(v)); }
    void value(std::uint32_t v) { value(static_cast<std::uint64_t>(v)); }
    void value(std::int16_t v) { value(static_cast<std::int64_t>(v)); }
    void value(std::uint16_t v) { value(static_cast<std::uint64_t>(v)); }
    void value(std::int8_t v) { value(static_cast<std::int64_t>(v)); }
    void value(std::uint8_t v) { value(static_cast<std::uint64_t>(v)); }

    // Char value
    void value(char v) {
        buffer_ += '"';
        if (v == '"' || v == '\\') { buffer_ += '\\'; }
        buffer_ += v;
        buffer_ += '"';
    }

    // Double value
    void value(double v) {
        char buf[32];
        auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), v);
        buffer_.append(buf, static_cast<std::size_t>(ptr - buf));
    }

    // String value (with escaping)
    void value(std::string_view v) {
        buffer_ += '"';
        for (char c : v) {
            switch (c) {
                case '"': buffer_ += "\\\""; break;
                case '\\': buffer_ += "\\\\"; break;
                case '\n': buffer_ += "\\n"; break;
                case '\r': buffer_ += "\\r"; break;
                case '\t': buffer_ += "\\t"; break;
                default: buffer_ += c; break;
            }
        }
        buffer_ += '"';
    }

    // Bool value
    void value(bool v) {
        buffer_.append(v ? "true" : "false");
    }

    // Convenience: key + value in one call
    template<typename T>
    void field(std::string_view k, T v) {
        key(k);
        value(v);
    }
};

} // namespace json