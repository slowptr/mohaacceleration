#ifndef MOHAACCELERATION_SIGNATURES_H
#define MOHAACCELERATION_SIGNATURES_H

namespace game::signatures {
    constexpr std::string_view cl_mousemove   = "A1 ? ? ? ? 83 EC 14 8B 48 20";
    constexpr std::string_view cvar_get       = "53 55 8B 6C 24 10 56 57 8B 7C 24 14 85 FF 74 04 85 ED 75 0F"; // could be shorter, but cross-game.
    constexpr std::string_view cvar_findvar   = "E8 ? ? ? ? 83 C4 04 85 C0 75 07";
    constexpr std::string_view frame_msec     = "A1 ? ? ? ? 89 5E 10 D1 E8 03 C8";
    constexpr std::string_view clientactive_t = "8B 0D ? ? ? ? 8B 15 ? ? ? ? 03 D1"; // not even the actual start of the struct lul. pssshht tho.
} // namespace game::signatures

#endif //MOHAACCELERATION_SIGNATURES_H
