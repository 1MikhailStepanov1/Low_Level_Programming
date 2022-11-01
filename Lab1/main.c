#include "file_handler/file_handler.h"
#include "tests/test.h"
#include <stdio.h>

int main(int argc, char** argv){
    if (argc != 2){
        fprintf(stderr, "%s", "Incorrect number of arguments.");
        return 0;
    }
    create_file(argv[1]);
    run_tests();
    return 0;
}