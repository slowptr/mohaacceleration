#include "sdk.h"
#include "../utils/pattern_scan.h"
#include "signatures.h"

namespace game::sdk {
    namespace funcs {
        type_cvar_get     cvar_get;
        type_cvar_findvar cvar_findvar;
    } // namespace funcs
    namespace structs {
        game::structs::clientactive_t* clientactive_t;
    } // namespace structs
    namespace variables {
        int* frame_msec;
    } // namespace variables

    void init(std::string_view file_name) {
        funcs::cvar_get         = (funcs::type_cvar_get)(utils::pattern_scan(file_name, game::signatures::cvar_get));
        funcs::cvar_findvar     = (funcs::type_cvar_findvar)(utils::pattern_scan_relative_call(file_name, game::signatures::cvar_findvar, 0x1));
        structs::clientactive_t = (game::structs::clientactive_t*)(*(uint32_t*)(utils::pattern_scan(file_name, game::signatures::clientactive_t, 0x2)));
        variables::frame_msec   = (int*)(*(uint32_t*)(utils::pattern_scan(file_name, game::signatures::frame_msec, 0x1)));
    }
} // namespace game::sdk