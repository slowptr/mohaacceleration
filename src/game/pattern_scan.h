#ifndef MOHAACCELERATION_PATTERN_SCAN_H
#define MOHAACCELERATION_PATTERN_SCAN_H

#include <cstdint>
#include <xstring>
namespace game {
    auto pattern_scan(std::string_view module_name, std::string_view pattern) -> uint32_t;
    auto pattern_scan(std::string_view module_name, std::string_view pattern, int offset) -> uint32_t;
    auto pattern_scan_relative_call(std::string_view module_name, std::string_view pattern, int offset) -> uint32_t;
} // namespace game

#endif //MOHAACCELERATION_PATTERN_SCAN_H
