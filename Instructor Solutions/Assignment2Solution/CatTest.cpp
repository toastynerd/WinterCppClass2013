#include "TestHarness.h"

#include "Cat.h"

TEST(CatCharPointer, Cat)
{
    char* actual = cat("George", "Washington");
    CHECK_EQUAL(std::string("GeorgeWashington"), actual);

    delete [] actual;
}

TEST(CatString, Cat)
{
    std::string george("George");
    std::string washington("Washington");
    CHECK_EQUAL("GeorgeWashington", cat(george, washington));
}