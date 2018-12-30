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

    // 2.64
    bool andOddOne(unsigned x);

    // 2.65
    int oddOnes(unsigned x);

    // 2.66
    int leftMostOne(unsigned x);

    // 2.67
    int intSizeIs32();

    // 2.68
    int lowerOneMask(int n);

    // 2.69
    unsigned rotateLeft(unsigned x, int n);

    // 2.70
    int fitsBits(int x, int n);

    // 2.71
    typedef unsigned packet_t;
    int xbyte(packet_t word, int byteIndex);

    // 2.73
    int saturatingAdd(int x, int y);

    // 2.74
    int tsubOk(int x, int y);
}