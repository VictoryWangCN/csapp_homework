#include "gtest/gtest.h"
#include "chapter2.h"

namespace chapter2{

    TEST(ReplaceBytesTest, test_replace_3_bytes) {
        unsigned x = 0x12345678;

        ASSERT_EQ(0x66345678, chapter2::replace_byte(x, 3, 0x66));
    }
}