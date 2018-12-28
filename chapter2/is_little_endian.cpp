//
// Created by Victory on 2018-12-28.
//
#include "chapter2.h"

namespace chapter2 {

    int isLittleEndian() {
        unsigned t = 0xFF;
        return 0xFF == (&t)[0];
    }
}
