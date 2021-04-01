cmake_minimum_required(VERSION 3.19)
project(mohaacceleration)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/inc)
link_directories(${CMAKE_SOURCE_DIR}/lib)

add_library(mohaacceleration SHARED src/dllmain.cpp)
target_link_libraries(mohaacceleration PRIVATE libMinHook-x86-v141-md)