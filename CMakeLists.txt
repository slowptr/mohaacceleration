cmake_minimum_required(VERSION 3.19)
project(mohaacceleration)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/inc)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_library(mohaacceleration SHARED src/dllmain.cpp src/game/c_hook.cpp src/game/c_hook.h src/game/structs/clientactive_t.h src/game/structs/cvar_t.h)
target_link_libraries(mohaacceleration PRIVATE libMinHook-x86-v141-md)