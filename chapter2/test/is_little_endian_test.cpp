#include "gtest/gtest.h"
#include "chapter2.h"
#include <machine/endian.h>

namespace chapter2{

    TEST(EndianTest, test_check_is_little_endian_work_well) {
        #if BYTE_ORDER == LITTLE_ENDIAN
            ASSERT_EQ(1, chapter2::isLittleEndian());
        #elif BYTE_ORDER == BIG_ENDIAN
            ASSERT_EQ(0, isLittleEndian());
        #else
            #error "No endianness macro defined"
        #endif
    }
}