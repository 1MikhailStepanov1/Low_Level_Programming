cmake_minimum_required(VERSION 3.21)
project(LLP C)

set(CMAKE_C_STANDARD 90)

add_executable(LLP Lab1/main.c Lab1/file_handler/file_handler.h Lab1/file_handler/file_handler.c Lab1/page_manager/page_manager.h Lab1/page_manager/page_manager.c Lab1/header_manager/header_manager.h Lab1/header_manager/header_manager.c Lab1/tests/test.c Lab1/tests/test.h)
