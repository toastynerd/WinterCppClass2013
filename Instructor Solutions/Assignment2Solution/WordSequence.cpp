#include "WordSequence.h"

#include <algorithm>
#include <vector>
#include <sstream>

namespace // anonymous namespace - forces internal linkage
{
    bool isWordFound(
        const std::vector<std::string>& words,
        const std::string& word)
    {
        for (size_t i = 0; i < words.size(); ++i)
        {
            if (word == words[i])
            {
                return true;
            }
        }

        return false;
    }

    std::vector<std::string> getUniqueWordVector(
        std::istream& input)
    {
        std::vector<std::string> words;

        std::string word;
        while (input >> word)
        {
            if (word == "Quit")
            {
                break;
            }

            if (!isWordFound(words, word))
    //        if (std::find(words.begin(), words.end(), word) == words.end()) // this uses the find algorithm - will learn about this later in the C++ program
            {
                words.push_back(word);
            }
        }

        return words;
    }

    std::string toString(
        const std::vector<std::string>& words)
    {
        std::stringstream result;
        for (size_t i = 0; i < words.size(); ++i)
        {
            if (i != 0)
            {
                result << " ";
            }

            result << words[i];
        }

        return result.str();
    }
}

std::string getUniqueWords(
    std::istream& input)
{
    std::vector<std::string> words = getUniqueWordVector(input);

    return toString(words);
}

std::string getSortedUniqueWords(
    std::istream& input)
{
    std::vector<std::string> words = getUniqueWordVector(input);
    std::sort(words.begin(), words.end());

    return toString(words);
}