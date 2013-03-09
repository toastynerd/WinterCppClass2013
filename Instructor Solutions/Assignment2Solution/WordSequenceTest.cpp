#include "TestHarness.h"

#include "WordSequence.h"

TEST(RemoveDuplicates, WordSequence)
{
    std::stringstream words("Small Large Little Big Little Quit End Small Big");
    std::string actual = getUniqueWords(words);

    std::string expected("Small Large Little Big");
    CHECK_EQUAL(expected, actual);
}

TEST(RemoveDuplicatesNoQuit, WordSequence)
{
    std::stringstream words("Small Large Little Big Little End Small Big");
    std::string actual = getUniqueWords(words);

    std::string expected("Small Large Little Big End");
    CHECK_EQUAL(expected, actual);
}
TEST(Sorted, WordSequence)
{
    std::stringstream words("Small Large Little Big Little Quit End Small Big");
    std::string actual = getSortedUniqueWords(words);

    std::string expected("Big Large Little Small");
    CHECK_EQUAL(expected, actual);

}