#include "gtest/gtest.h"
#include "chapter2.h"

namespace chapter2 {

    TEST(ReplaceBytesTest, test_replace_3_bytes) {
        unsigned x = 0x12345678;

        ASSERT_EQ(0x66345678, chapter2::replace_byte(x, 3, 0x66));
    }

    TEST(ReplaceBytesTest, test_replace_replace_negative_i) {
        unsigned x = 0x12345678;

        ASSERT_THROW(chapter2::replace_byte(x, -1, 0x66), std::invalid_argument);
    }

    TEST(ReplaceBytesTest, test_replace_replace_out_range_of_x) {
        unsigned x = 0x12345678;

        try {
            chapter2::replace_byte(x, 5, 0x66);
            FAIL();
        } catch (const std::invalid_argument& err) {
            ASSERT_STREQ("i is greater than sizeof(unsigned).", err.what());
        }
    }
}