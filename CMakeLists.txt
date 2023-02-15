cmake_minimum_required(VERSION 3.20.2)
project(LLP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

file(GLOB SRC "${CMAKE_CURRENT_LIST_DIR}/Lab1/include/*.h" "${CMAKE_CURRENT_LIST_DIR}/Lab1/src/*.cpp")
add_executable(LLP Lab1/main.cpp ${SRC})