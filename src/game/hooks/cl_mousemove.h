#ifndef MOHAACCELERATION_CL_MOUSEMOVE_H
#define MOHAACCELERATION_CL_MOUSEMOVE_H

namespace game::hooks::cl_mousemove {
    using type = void(__cdecl*)(void*); // usercmd_t
    type original;
    auto function(void* cmd) -> void {
        original(cmd);
    }
} // namespace game::hooks::cl_mousemove

#endif //MOHAACCELERATION_CL_MOUSEMOVE_H
