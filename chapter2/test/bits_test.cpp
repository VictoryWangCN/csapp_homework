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
}