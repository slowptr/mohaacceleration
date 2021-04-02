cmake_minimum_required(VERSION 3.19)
project(mohaacceleration)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/inc)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_library(mohaacceleration SHARED src/dllmain.cpp src/utils/c_hook.cpp src/utils/c_hook.h src/game/structs/clientactive_t.h src/game/structs/cvar_t.h src/game/hooks/cl_mousemove.h src/game/signatures.h src/utils/pattern_scan.cpp src/utils/pattern_scan.h src/game/sdk.h src/game/sdk.cpp)
target_link_libraries(mohaacceleration PRIVATE libMinHook-x86-v141-md)