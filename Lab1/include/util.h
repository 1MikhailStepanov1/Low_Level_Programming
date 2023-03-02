#ifndef LLP_UTIL_H
#define LLP_UTIL_H

#include <fstream>
#include <iostream>
#include <cassert>
#include <cinttypes>
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>


#define PAGE 4 * 1024
#define META 256 * 1024 * 1024
#define BIO std::ios::binary | std::ios::out | std::ios::in
#define BIN std::ios::binary

#endif
