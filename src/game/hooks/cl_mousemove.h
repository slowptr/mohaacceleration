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

            auto sensitivity_scale_x    = sdk::funcs::cvar_findvar("sensitivity_scale_x");
            auto sensitivity_scale_y    = sdk::funcs::cvar_findvar("sensitivity_scale_y");
            auto cl_mouseacceloffset    = sdk::funcs::cvar_findvar("cl_mouseAccelOffset");
            auto cl_mouseacceloption    = sdk::funcs::cvar_findvar("cl_mouseAccelOption");
            auto cl_mouseaccelpower     = sdk::funcs::cvar_findvar("cl_mouseAccelPower");
            auto cl_mouseaccelthreshold = sdk::funcs::cvar_findvar("cl_mouseAccelThreshold");

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

            // post-scale
            mx *= sensitivity_scale_x->value;
            my *= sensitivity_scale_y->value;

            rate = sqrt(mx * mx + my * my) / (float)*sdk::variables::frame_msec;

            if (cl_mouseacceloffset->value > 0) {
                rate -= cl_mouseacceloffset->value;
                if (rate <= 0) {
                    clientactive_t->viewangles[0] += m_pitch->value * round(my);
                    clientactive_t->viewangles[1] -= m_yaw->value * round(mx);
                    return;
                }
            }
            {
                accel_sens = sensitivity->value;
                float a    = cl_mouseaccelthreshold->value - accel_sens;
                float b    = cl_mouseaccel->value / abs(a);
                switch (cl_mouseacceloption->integer) {
                    case 1:
                        accel_sens += pow(rate * cl_mouseaccel->value, cl_mouseaccelpower->value - 1); // standard interaccel or rawaccel(classic)
                        break;
                    case 2:
                        accel_sens += a - (a * exp((-rate * b))); // tauntyarmordillo's natural acceleration
                        break;
                    case 3:
                        accel_sens += log((rate * cl_mouseaccel->value) + 1); // natural logarithmic acceleration
                        break;
                    case 4:
                        accel_sens = powf(rate, max(0.0f, (cl_mouseaccelpower->value - 1.0f) / 2.0f)) * accel_sens; // should be the source acceleration :D
                        break;
                    default:
                        accel_sens += rate * cl_mouseaccel->value;
                        break;
                }
            }

            if (cl_mouseaccelthreshold->value > 0 && accel_sens > cl_mouseaccelthreshold->value)
                accel_sens = cl_mouseaccelthreshold->value;

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
