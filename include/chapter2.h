//
// Created by Victory on 2018-12-28.
//

#pragma once

#include <cstddef>
#include <iostream>

namespace chapter2 {
    int isLittleEndian();

    size_t extractXLowBytesToY(size_t x, size_t y);

    unsigned replace_byte (unsigned x, int i, unsigned char b);

    // 2.61
    bool anyBitEqOne(int x);
    bool anyBitEqZero(int x);
    bool leastSignificantIsOne(int x);
    bool mostSignificantIsZero(int x);

    // 2.62
    bool int_shifts_are_arithmetic();

    // 2.63
    unsigned srl(unsigned x, int k);
    int sra(int x, int k);
}