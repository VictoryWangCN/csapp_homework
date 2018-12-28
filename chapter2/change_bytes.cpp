//
// Created by Victory on 2018-12-28.
//
#include "chapter2.h"

namespace chapter2 {
    size_t extractXLowBytesToY(size_t x, size_t y) {
        size_t mask = 0xFF;
        return (x & mask) | (y & ~mask);
    }
}
