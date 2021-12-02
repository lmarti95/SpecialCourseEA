cmake_minimum_required(VERSION 3.12)

project (ea)

file(GLOB source
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ea ${source})

target_include_directories(ea PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# Set default compile flags for GCC
if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-sign-compare")
endif(CMAKE_COMPILER_IS_GNUCXX)
