#ifndef MOHAACCELERATION_SDK_H
#define MOHAACCELERATION_SDK_H

#include <string_view>
#include "structs/clientactive_t.h"
#include "structs/cvar_t.h"

namespace game::sdk {
    namespace funcs {
        using type_cvar_get     = game::structs::cvar_t*(__cdecl*)(const char*, const char*, int flags);
        using type_cvar_findvar = game::structs::cvar_t*(__cdecl*)(const char*);

        extern type_cvar_get     cvar_get;
        extern type_cvar_findvar cvar_findvar;
    } // namespace funcs
    namespace structs {
        extern game::structs::clientactive_t* clientactive_t;
    } // namespace structs
    namespace variables {
        extern int* frame_msec;
    } // namespace variables
    void init(std::string_view file_name);
} // namespace game::sdk

#endif //MOHAACCELERATION_SDK_H
