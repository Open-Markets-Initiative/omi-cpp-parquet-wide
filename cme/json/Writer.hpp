#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <charconv>

namespace json {

// High-performance JSON writer
// Builds a JSON object as a std::string for embedding in parquet columns
struct Writer {

    std::string buffer;
    bool first_field = true;

    // Start a new JSON object
    void start() {
        buffer.clear();
        buffer += '{';
        first_field = true;
    }

    // Finish object
    void finish() {
        buffer += '}';
    }

    // Start a new JSON array
    void start_array() {
        buffer.clear();
        buffer += '[';
        first_field = true;
    }

    // Finish array
    void finish_array() {
        buffer += ']';
    }

    // Start array element object
    void start_element() {
        separator();
        buffer += '{';
        first_field = true;
    }

    // End array element object
    void end_element() {
        buffer += '}';
        first_field = false;
    }

    // Get result
    std::string_view view() const {
        return std::string_view(buffer);
    }

    // Field separator
    void separator() {
        if (!first_field) {
            buffer += ',';
        }
        first_field = false;
    }

    // Write key
    void key(std::string_view k) {
        separator();
        buffer += '"';
        buffer.append(k.data(), k.size());
        buffer += "\":";
    }

    // Integer value
    void value(std::int64_t v) {
        char buf[24];
        auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), v);
        buffer.append(buf, static_cast<std::size_t>(ptr - buf));
    }

    void value(std::uint64_t v) {
        char buf[24];
        auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), v);
        buffer.append(buf, static_cast<std::size_t>(ptr - buf));
    }

    void value(std::int32_t v) { value(static_cast<std::int64_t>(v)); }
    void value(std::uint32_t v) { value(static_cast<std::uint64_t>(v)); }
    void value(std::int16_t v) { value(static_cast<std::int64_t>(v)); }
    void value(std::uint16_t v) { value(static_cast<std::uint64_t>(v)); }
    void value(std::int8_t v) { value(static_cast<std::int64_t>(v)); }
    void value(std::uint8_t v) { value(static_cast<std::uint64_t>(v)); }

    // Char value
    void value(char v) {
        buffer += '"';
        if (v == '"' || v == '\\') { buffer += '\\'; }
        buffer += v;
        buffer += '"';
    }

    // Double value
    void value(double v) {
        char buf[32];
        auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), v);
        buffer.append(buf, static_cast<std::size_t>(ptr - buf));
    }

    // String value (with escaping)
    void value(std::string_view v) {
        buffer += '"';
        for (char c : v) {
            switch (c) {
                case '"': buffer += "\\\""; break;
                case '\\': buffer += "\\\\"; break;
                case '\n': buffer += "\\n"; break;
                case '\r': buffer += "\\r"; break;
                case '\t': buffer += "\\t"; break;
                default: buffer += c; break;
            }
        }
        buffer += '"';
    }

    // Bool value
    void value(bool v) {
        buffer.append(v ? "true" : "false");
    }

    // Convenience: key + value in one call
    template<typename T>
    void field(std::string_view k, T v) {
        key(k);
        value(v);
    }
};

} // namespace json