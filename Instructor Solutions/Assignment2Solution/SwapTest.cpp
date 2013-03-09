#include "TestHarness.h"

#include "Swap.h"

TEST(ByPointerReference, Swap)
{
    int x = 4;
    int y = 122;

    swap(&x, &y);

    CHECK_EQUAL(122, x);
    CHECK_EQUAL(4, y);
}

TEST(ByReference, Swap)
{
    int x = 99;
    int y = -56;

    swap(x, y);

    CHECK_EQUAL(-56, x);
    CHECK_EQUAL(99, y);
}