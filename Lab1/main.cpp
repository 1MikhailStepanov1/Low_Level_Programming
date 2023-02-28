#include <cstdio>
#include "test/test.h"

int main(int argc, char** argv){
    if (argc != 2){
        fprintf(stderr, "%s", "Incorrect number of arguments.");
        return 0;
    }

    test test;
    test.run_tests();
    return 0;

}