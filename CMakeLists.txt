cmake_minimum_required(VERSION 3.24)
project(LLP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CLIENT_NAME client)
set(SERVER_NAME server)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

add_compile_options(
        -fsanitize=address,undefined,leak
        -pedantic-errors
        -Wall -Werror
        -g3
        -O0
)
add_link_options("-fsanitize=address,undefined,leak")

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

file(GLOB_RECURSE C_FILES_CLIENT CONFIGURE_DEPENDS "./Lab3/client/src/*.cpp" "./Lab3/client/*.cpp")
file(GLOB_RECURSE H_FILES_CLIENT CONFIGURE_DEPENDS "./Lab3/client/include/*.h")

file(GLOB_RECURSE C_FILES_COMMON CONFIGURE_DEPENDS "./Lab3/common/*.cxx")
file(GLOB_RECURSE H_FILES_COMMON CONFIGURE_DEPENDS "./Lab3/common/*.hxx")

file(GLOB_RECURSE C_FILES_SERVER CONFIGURE_DEPENDS "./Lab3/server/src/*.cpp" "./Lab3/server/*.cpp")
file(GLOB_RECURSE H_FILES_SERVER CONFIGURE_DEPENDS "./Lab3/server/include/*.h")

file(GLOB_RECURSE C_FILES_DB CONFIGURE_DEPENDS "./Lab1/src/*.cpp")
file(GLOB_RECURSE H_FILES_DB CONFIGURE_DEPENDS "./Lab1/include/*.h")

file(GLOB_RECURSE C_FILES_PARSE CONFIGURE_DEPENDS ./Lab2/src/ast.cpp)
file(GLOB_RECURSE H_FILES_PARSE CONFIGURE_DEPENDS ./Lab2/include/ast.h)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(MyParser ./Lab2/parser.y ${CMAKE_CURRENT_SOURCE_DIR}/Lab2/parser.cpp DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Lab2/parser.h)
FLEX_TARGET(MyScanner ./Lab2/lexer.l  ${CMAKE_CURRENT_SOURCE_DIR}/Lab2/lexer.cpp DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/Lab2/lexer.h)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_library(PARSE_MODULE
        STATIC
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
        ${C_FILES_PARSE}
        ${H_FILES_PARSE}
        )

add_executable(${CLIENT_NAME} ${C_FILES_CLIENT} ${H_FILES_CLIENT} ${C_FILES_COMMON} ${H_FILES_COMMON})
target_include_directories(${CLIENT_NAME} PUBLIC "./Lab3/client")
target_link_libraries(${CLIENT_NAME} xerces-c PARSE_MODULE)


add_library(DB_MODULE STATIC ${C_FILES_DB} ${H_FILES_DB})
add_executable(${SERVER_NAME} ${C_FILES_SERVER} ${H_FILES_SERVER} ${C_FILES_COMMON} ${H_FILES_COMMON})
target_include_directories(${SERVER_NAME} PUBLIC "./Lab3/server")
target_link_libraries(${SERVER_NAME} xerces-c DB_MODULE)
