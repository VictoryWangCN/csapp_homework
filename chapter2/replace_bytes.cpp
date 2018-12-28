//
// Created by Victory on 2018-12-28.
//
#include "chapter2.h"

namespace chapter2 {

    unsigned replace_byte(unsigned x, int i, unsigned char b) {
        if (i < 0) {
            throw std::invalid_argument("i is less than zero.");
        }

        if (i > sizeof(unsigned) - 1) {
            throw std::invalid_argument("i is greater than sizeof(unsigned).");
        }

        unsigned mask = ((unsigned) 0xFF) << (i << 3);
        unsigned replaceItem = ((unsigned) b) << (i << 3);

        return (x & ~mask) | replaceItem;
    }
}
