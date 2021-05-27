#include <test/pch.h>
#include "glw/glw.h"

TEST(Hello, World)
{
    ASSERT_TRUE(hello());
}

int main()
{
    return RUN_ALL_TESTS();
}
