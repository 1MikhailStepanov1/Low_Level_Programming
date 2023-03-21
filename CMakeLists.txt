cmake_minimum_required(VERSION 3.24)
project(LLP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CLIENT_NAME client)
set(SERVER_NAME server)

file(GLOB_RECURSE C_FILES_CLIENT CONFIGURE_DEPENDS "./Lab3/client/src/*.cpp" "./Lab3/client/*.cpp")
file(GLOB_RECURSE H_FILES_CLIENT CONFIGURE_DEPENDS "./Lab3/client/include/*.h")

file(GLOB_RECURSE C_FILES_COMMON CONFIGURE_DEPENDS "./Lab3/common/*.cxx")
file(GLOB_RECURSE H_FILES_COMMON CONFIGURE_DEPENDS "./Lab3/common/*.hxx")

add_compile_options(
        -fsanitize=address,undefined,leak
        -pedantic-errors
        -Wall -Werror
        -g3
        -O0
)
add_link_options("-fsanitize=address,undefined,leak")

add_executable(${CLIENT_NAME} ${C_FILES_CLIENT} ${H_FILES_CLIENT} ${C_FILES_COMMON} ${H_FILES_COMMON})
target_include_directories(${CLIENT_NAME} PUBLIC "./Lab3/client" "./Lab2" "./Lab3/common")
add_subdirectory(./Lab2)
target_link_libraries(${CLIENT_NAME} xerces-c "Lab2")

file(GLOB_RECURSE C_FILES_SERVER CONFIGURE_DEPENDS "./Lab3/server/src/*.cpp" "./Lab3/server/*.cpp")
file(GLOB_RECURSE H_FILES_SERVER CONFIGURE_DEPENDS "./Lab3/server/include/*.h")

add_executable(${SERVER_NAME} ${C_FILES_SERVER} ${H_FILES_SERVER} ${C_FILES_COMMON} ${H_FILES_COMMON})
target_include_directories(${SERVER_NAME} PUBLIC "./Lab3/server" "./Lab1" "./Lab3/common")
add_subdirectory(./Lab1)
target_link_libraries(${SERVER_NAME} xerces-c "Lab1")
