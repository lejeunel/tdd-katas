#pragma once
#include <array>
#include <iomanip>
#include <random>
#include <sstream>

inline std::string uuid_v4() {
    static thread_local std::mt19937 gen{std::random_device{}()};
    static thread_local std::uniform_int_distribution<int> dist(0, 255);

    std::array<uint8_t, 16> data;
    for (auto &b : data)
        b = static_cast<uint8_t>(dist(gen));

    data[6] = (data[6] & 0x0F) | 0x40;
    data[8] = (data[8] & 0x3F) | 0x80;

    std::ostringstream oss;
    for (size_t i = 0; i < 16; ++i) {
        if (i == 4 || i == 6 || i == 8 || i == 10)
            oss << "-";
        oss << std::hex << std::setw(2) << std::setfill('0')
            << static_cast<int>(data[i]);
    }
    return oss.str();
}
