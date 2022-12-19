cmake_minimum_required(VERSION 3.20.2)
project(LLP C)

set(CMAKE_C_STANDARD 90)

add_executable(LLP Lab1/main.c Lab1/include/file_handler.h Lab1/src/file_handler.c Lab1/include/page_manager.h Lab1/src/page_manager.c Lab1/include/header_manager.h Lab1/src/header_manager.c Lab1/src/test.c Lab1/include/test.h)
