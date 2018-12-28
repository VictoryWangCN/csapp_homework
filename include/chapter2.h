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
}