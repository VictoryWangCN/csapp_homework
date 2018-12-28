#include "gtest/gtest.h"
#include "chapter2.h"

namespace chapter2{

    TEST(ChangeBytesTest, test_extract_x_low_bytes_to_y) {
        size_t x = 0x12345678;
        size_t y = 0xabcdef01;

        ASSERT_EQ(0xabcdef78, chapter2::extractXLowBytesToY(x, y));
    }
}