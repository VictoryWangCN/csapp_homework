#include "gtest/gtest.h"
#include "chapter2.h"

namespace chapter2 {

    TEST(BitsTest, test_all_bit_of_x_is_1) {

        ASSERT_FALSE(chapter2::anyBitEqOne(0x12345678));
        ASSERT_FALSE(chapter2::anyBitEqOne(0));
        ASSERT_TRUE(chapter2::anyBitEqOne(0xFFFFFFFF));

    }

    TEST(BitsTest, test_all_bit_of_x_is_zero) {
        ASSERT_FALSE(chapter2::anyBitEqZero(0x12345678));
        ASSERT_FALSE(chapter2::anyBitEqZero(0xFFFFFFFF));
        ASSERT_TRUE(chapter2::anyBitEqZero(0));
    }

    TEST(BitsTest, test_least_significant_is_one) {
        ASSERT_FALSE(chapter2::leastSignificantIsOne(0x12345601));
        ASSERT_TRUE(chapter2::leastSignificantIsOne(0xFFFFFFFF));
        ASSERT_FALSE(chapter2::leastSignificantIsOne(0xF0));
        ASSERT_TRUE(chapter2::leastSignificantIsOne(0x334455FF));
    }

    TEST(BitsTest, test_most_significant_is_zero) {
        ASSERT_FALSE(chapter2::mostSignificantIsZero(0x12345601));
        ASSERT_FALSE(chapter2::mostSignificantIsZero(0xFFFFFFFF));
        ASSERT_FALSE(chapter2::mostSignificantIsZero(0x10FFFFFF));
        ASSERT_TRUE(chapter2::mostSignificantIsZero(0));
        ASSERT_TRUE(chapter2::mostSignificantIsZero(0xFF));
    }

    TEST(BitsTest, test_is_arithmetic_shift) {
        ASSERT_TRUE(chapter2::int_shifts_are_arithmetic());
    }

    TEST(BitsTest, test_shift_right_logical) {
        ASSERT_EQ(0x7FFFFFFF, chapter2::srl(0xFFFFFFFF, 1));
    }

    TEST(BitsTest, test_shift_right_arithmetic) {
        ASSERT_EQ(static_cast<int>(0xFFFFFFFF), chapter2::sra(0xFFFFFFFF, 1));
        ASSERT_EQ(0x7, chapter2::sra(0xF, 1));
    }

    TEST(BitsTest, test_any_odd_bit_is_one) {
        ASSERT_FALSE(chapter2::andOddOne(0x1));
        ASSERT_TRUE(chapter2::andOddOne(0x2));
        ASSERT_FALSE(chapter2::andOddOne(0x4));
    }

    TEST(BitsTest, test_one_count_is_odd) {
        ASSERT_TRUE(chapter2::oddOnes(0xFFFFFFFE));
        ASSERT_FALSE(chapter2::oddOnes(0xFFFFFFFF));
    }

    TEST(BitsTest, test_get_left_most_one) {
        ASSERT_EQ(0x80000000, chapter2::leftMostOne(0xFFFFFFFF));
        ASSERT_EQ(0, chapter2::leftMostOne(0));

        unsigned x = (unsigned)1 << 31;
    }

    TEST(BitsTest, test_int_is_32_bit) {
        #if UINT_MAX == 4294967295
            ASSERT_TRUE(chapter2::intSizeIs32());
        #else
            #error "can not use intSizeIs32"
        #endif
    }


    TEST(BitsTest, test_n_bits_mask) {
        ASSERT_EQ(0x3F, chapter2::lowerOneMask(6));
        ASSERT_EQ(0xFFFFFFFF, chapter2::lowerOneMask(32));
    }

    TEST(BitsTest, test_rotate_left) {
        ASSERT_EQ(0x23456781, chapter2::rotateLeft(0x12345678, 4));
        ASSERT_EQ(0x67812345, chapter2::rotateLeft(0x12345678, 20));
        ASSERT_EQ(0x12345678, chapter2::rotateLeft(0x12345678, 0));
        ASSERT_EQ(0x7FFFFFFF, chapter2::rotateLeft(0xFFFFFFFE, 31));
    }

    TEST(BitsTest, test_enough_bit_for_represent_x) {
        ASSERT_TRUE(chapter2::fitsBits(0xFFFFFFFF, 31));
        ASSERT_TRUE(chapter2::fitsBits(0xFFFFFFFF, 32));
        ASSERT_FALSE(chapter2::fitsBits(0b0110, 3)); // notice: 3位的二进制补码数，表示不了6
    }

    TEST(BitsTest, test_get_byte_by_index) {
        ASSERT_EQ(0xFF, chapter2::xbyte(0xFFFFFFFF, 1));
    }

    TEST(BitsTest, test_check_over_flow) {
        ASSERT_EQ(INT_MAX, chapter2::saturatingAdd(INT_MAX, 1));
        ASSERT_EQ(4, chapter2::saturatingAdd(3, 1));
        ASSERT_EQ(INT_MAX, chapter2::saturatingAdd(INT_MAX, 1));
        ASSERT_EQ(INT_MIN, chapter2::saturatingAdd(INT_MIN, INT_MIN));
        ASSERT_EQ(INT_MIN, chapter2::saturatingAdd(-4, INT_MIN));
        ASSERT_EQ(-6, chapter2::saturatingAdd(-4, -2));
    }

    TEST(BitsTest, test_check_sub_overflow) {
        ASSERT_EQ(1, chapter2::tsubOk(INT_MAX, 1));
        ASSERT_EQ(1, chapter2::tsubOk(3, 1));
        ASSERT_EQ(1, chapter2::tsubOk(INT_MAX, 1));
        ASSERT_EQ(0, chapter2::tsubOk(INT_MAX, -1));
        ASSERT_EQ(1, chapter2::tsubOk(INT_MIN, INT_MIN));
        ASSERT_EQ(1, chapter2::tsubOk(-4, INT_MIN));
        ASSERT_EQ(0, chapter2::tsubOk(0, INT_MIN));
    }
}