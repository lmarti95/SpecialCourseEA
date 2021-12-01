cmake_minimum_required(VERSION 3.12)

project (ea)

file(GLOB source
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ea ${source})

target_include_directories(ea PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(ea PUBLIC "-Wall" "-Wno-sign-compare")
