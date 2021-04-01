#include "c_hook.h"
#include <MinHook.h>

auto game::c_hook::init() -> bool {
    if (MH_Initialize() != MH_OK)
        return false;

    // TODO: add hooks here.

    return true;
}
auto game::c_hook::finish() -> bool {
    return (MH_DisableHook(MH_ALL_HOOKS) == MH_OK && MH_Uninitialize() == MH_OK);
}
auto game::c_hook::_add_hook(void* target, void* hook, void** original) -> bool {
    return (MH_CreateHook(target, hook, original) == MH_OK && MH_EnableHook(target) == MH_OK);
}