//
// Created by Victory on 2018-12-29.
//

#include "chapter2.h"

namespace chapter2 {
    // 2.61
    bool anyBitEqOne(int x) {
        return !~x;
    }

    bool anyBitEqZero(int x) {
        return !x;
    }

    bool leastSignificantIsOne(int x) {
        return anyBitEqOne(~0xFF | x);
    }

    bool mostSignificantIsZero(int x) {
        int offset = (sizeof(int) - 1) << 3;

        return anyBitEqZero(x >> offset);
    }

    bool int_shifts_are_arithmetic() {
        int x = -1;
        return !((x >> 1) ^ x);
    }

    unsigned srl(unsigned x, int k) {
        // arithmetic shift
        auto xsra = static_cast<unsigned>(static_cast<int>(x) >> k);
        int mask = -1 << ((sizeof(x) << 3) - k);

        return xsra & ~mask;
    }

    int sra(int x, int k) {
        // logical shift
        auto xsrl = static_cast<unsigned>(x) >> k;
        int mask = -1 << ((sizeof(x) << 3) - k);

        int high = 1 << ((sizeof(x) << 3) - 1);

        int realMask = mask & (!(high & x) - 1);

        return xsrl | realMask;

    }
}