#include "test/test.h"
#include "test/stress_test.h"

int main(int argc, char** argv){

    test test;
    test.run_tests();

    stress_test s_test;
    s_test.run_tests();
    return 0;

}