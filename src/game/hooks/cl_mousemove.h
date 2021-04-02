#ifndef MOHAACCELERATION_CL_MOUSEMOVE_H
#define MOHAACCELERATION_CL_MOUSEMOVE_H

#include "../sdk.h"

namespace game::hooks::cl_mousemove {
    using type = void(__cdecl*)(void*); // usercmd_t
    type original;
    auto function(void* cmd) -> void {
        float mx, my;
        float accel_sens;
        float rate;

        {
            using sdk::structs::clientactive_t;

            auto m_filter      = sdk::funcs::cvar_findvar("m_filter");
            auto sensitivity   = sdk::funcs::cvar_findvar("sensitivity");
            auto m_pitch       = sdk::funcs::cvar_findvar("m_pitch");
            auto m_yaw         = sdk::funcs::cvar_findvar("m_yaw");
            auto cl_mouseaccel = sdk::funcs::cvar_findvar("cl_mouseAccel");

            // allow mouse smoothing
            if (m_filter->integer) {
                mx = (clientactive_t->mouse_dx[0] + clientactive_t->mouse_dx[1]) * 0.5;
                my = (clientactive_t->mouse_dy[0] + clientactive_t->mouse_dy[1]) * 0.5;
            } else {
                mx = clientactive_t->mouse_dx[clientactive_t->mouse_index];
                my = clientactive_t->mouse_dy[clientactive_t->mouse_index];
            }
            clientactive_t->mouse_index ^= 1;
            clientactive_t->mouse_dx[clientactive_t->mouse_index] = 0;
            clientactive_t->mouse_dy[clientactive_t->mouse_index] = 0;

            rate       = sqrt(mx * mx + my * my) / (float)*sdk::variables::frame_msec;
            accel_sens = sensitivity->value + rate * cl_mouseaccel->value;

            mx *= accel_sens;
            my *= accel_sens;
            if (mx == 0 && my == 0)
                return;

            clientactive_t->viewangles[0] += m_pitch->value * my;
            clientactive_t->viewangles[1] -= m_yaw->value * mx;
        }
    }
} // namespace game::hooks::cl_mousemove

#endif //MOHAACCELERATION_CL_MOUSEMOVE_H
