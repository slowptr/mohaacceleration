#ifndef MOHAACCELERATION_CVAR_T_H
#define MOHAACCELERATION_CVAR_T_H

#include <cstdint>
namespace game::structs {
    enum E_CVAR_FLAGS {
        ARCHIVE      = 1,
        USERINFO     = 2,
        SERVERINFO   = 4,
        SYSTEMINFO   = 8,
        INIT         = 16,
        LATCH        = 32,
        ROM          = 64,
        USER_CREATED = 128,
        TEMP         = 256,
        CHEAT        = 512,
        NORESTART    = 1024
    };

    struct cvar_t {
        char*        name;
        char*        string;
        char*        reset_string;
        char*        latched_string;
        E_CVAR_FLAGS flags;
        bool         modified;
        char         pad_0015[3];
        uint32_t     modification_count;
        float        value;
        int          integer;
        cvar_t*      next;
        cvar_t*      hash_next;
    };
} // namespace game::structs

#endif //MOHAACCELERATION_CVAR_T_H
