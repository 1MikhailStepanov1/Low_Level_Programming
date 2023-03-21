cmake_minimum_required(VERSION 3.24)
project(Lab2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

file(GLOB_RECURSE C_FILES_LIB CONFIGURE_DEPENDS ./src/ast.cpp)
file(GLOB_RECURSE H_FILES_LIB CONFIGURE_DEPENDS ./include/ast.h)

find_package(BISON)
find_package(FLEX)

BISON_TARGET(MyParser parser.y ${CMAKE_CURRENT_SOURCE_DIR}/parser.cpp DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/parser.h)
FLEX_TARGET(MyScanner lexer.l  ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp DEFINES_FILE ${CMAKE_CURRENT_SOURCE_DIR}/lexer.h)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_library(${PROJECT_NAME}
        STATIC
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS}
        ${C_FILES_LIB}
        ${H_FILES_LIB}
        )
target_include_directories(${PROJECT_NAME} PUBLIC .)
