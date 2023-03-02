#ifndef LLP_STRESS_TEST_H
#define LLP_STRESS_TEST_H

#include <iostream>
#include <ctime>
#include <chrono>
#include <cassert>
#include <string>
#include "../include/node.h"
#include "../include/database.h"

struct stress_test{

    static std::string file;

    void run_tests();

};

#endif
