#ifndef MOHAACCELERATION_CLIENTACTIVE_T_H
#define MOHAACCELERATION_CLIENTACTIVE_T_H

#include <cstdint>
namespace game::structs {
    struct clientactive_t { // very, veeeeeery incomplete! :D
        int32_t  mouse_dx[2]; //0x0000
        int32_t  mouse_dy[2]; //0x0008
        uint32_t mouse_index; //0x0010
        char     pad_0014[3368]; //0x0014
        float    viewangles[3]; //0x0D3C
    };
    inline clientactive_t* m_clientactive_t;
} // namespace game::structs

#endif //MOHAACCELERATION_CLIENTACTIVE_T_H
