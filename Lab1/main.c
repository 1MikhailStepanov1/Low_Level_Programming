#include "include/file_handler.h"
#include "include/test.h"
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