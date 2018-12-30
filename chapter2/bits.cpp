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

    // 2.64
    bool andOddOne(unsigned x) {
        return !!(x & 0xAAAAAAAA);
    }

    // 2.65
    int oddOnes(unsigned x) {
        // 最容易理解的套路是循环异或一遍，然而不能用
        x ^= x >> 1;
        // 31 31^30 .... 4^3 3^2 2^1 1^0
        x ^= x >> 2;
        // .......  .... 6^5^4^3 5^4^3^2 4^3^2^1 3^2^1^0
        x ^= x >> 4;
        x ^= x >> 8;
        x ^= x >> 16;
        // 32^31^....^2^1^0
        return x & 1;
    }

    // 2.66
    int leftMostOne(unsigned x) {
        x |= x >> 1;
        x |= x >> 2;
        x |= x >> 4;
        x |= x >> 8;
        x |= x >> 16;
        // x is [00....1111]
        // <- 有一个1 就是1
        return x ^ (x >> 1);
    }

    // 2.67
    int intSizeIs32() {
        // we cannot use 1 << 32, see c standard
        // If the value of the right operand is negative or is greater than
        // or equal to the width of the promoted left operand, the behavior it undefined.

        // 0x80......
        int leftMostOne = 1 << 15 << 15 << 1; // suit 16-bit

        // but we can use that
        int overflow = leftMostOne << 1;

        return leftMostOne && !overflow;
    }

    // 2.68
    int lowerOneMask(int n) {
        int w = sizeof(int) << 3;
        return (unsigned) -1 >> (w - n);
    }

    // 2.69
    unsigned rotateLeft(unsigned x, int n) {
        int size = sizeof(x) << 8;

        unsigned extractLeft = x >> (size - n);
        unsigned nowLeft = x << n;

        return extractLeft | nowLeft;
    }

    // 2.70
    int fitsBits(int x, int n) {
        int size = sizeof(x) << 3;

        return (x << (size - n) >> (size - n)) == x;
    }


    // 2.71
    int xbyte(packet_t word, int byteIndex) {
        int leftShift = 24 - (byteIndex << 3);
        return word << leftShift >> 24;
    }

    // 2.73
    int saturatingAdd(int x, int y) {
        int sum = x + y;
        int highBitMask = INT_MIN;

        bool posOver = !(x & highBitMask) && !(y & highBitMask) && (sum & highBitMask);
        bool negOver = (x & highBitMask) && (y & highBitMask) && !(sum & highBitMask);

        (posOver && (sum = INT_MAX)) || (negOver && (sum = INT_MIN));

        return sum;
    }

    // 2.74
    int tsubOk(int x, int y) {
        // y == INT_MIN must overflow
        return ((x & INT_MIN) && y == INT_MIN) || (y != INT_MIN && (saturatingAdd(x, -y) == (x - y)));

    }

}