cmake_minimum_required(VERSION 3.24)
project(Lab1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

include(ExternalProject)
ExternalProject_Add(cereal
        GIT_REPOSITORY https://github.com/USCiLab/cereal.git
        PREFIX cereal
        SOURCE_DIR "${CMAKE_BINARY_DIR}/third-party/cereal"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        )
include_directories(${CMAKE_BINARY_DIR}/third-party/cereal/include)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "../Lab1/include/*.h"
        "../Lab1/src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ../Lab1)
