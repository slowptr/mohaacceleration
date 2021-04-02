#include "c_hook.h"
#include <MinHook.h>
#include <filesystem>
#include "hooks/cl_mousemove.h"
#include "pattern_scan.h"
#include "signatures.h"

auto game::c_hook::init() -> bool {
    if (MH_Initialize() != MH_OK)
        return false;

    // get file name of the process, we're injected to.
    char proc_name[MAX_PATH]{0};
    GetModuleFileName(GetModuleHandle(nullptr), proc_name, MAX_PATH);
    const auto file_name = std::filesystem::path(proc_name).filename().string();

    if (!_add_hook(reinterpret_cast<void*>(pattern_scan(file_name, signatures::cl_mousemove)),
                   hooks::cl_mousemove::function,
                   reinterpret_cast<void**>(&hooks::cl_mousemove::original)))
        return false;

    return true;
}
auto game::c_hook::finish() -> bool {
    return (MH_DisableHook(MH_ALL_HOOKS) == MH_OK && MH_Uninitialize() == MH_OK);
}
auto game::c_hook::_add_hook(void* target, void* hook, void** original) -> bool {
    return (MH_CreateHook(target, hook, original) == MH_OK && MH_EnableHook(target) == MH_OK);
}