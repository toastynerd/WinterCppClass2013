#include "Cat.h"

char* cat(const char* start, const char* end)
{
    char* result = new char[strlen(start) + strlen(end) + 1];
    char* p = result;

    // you could use strcpy here as well. This solution copies strings with pointer arithmetic and assignment

    while (*p++ = *start++)
    {
        if (*start == '\0')
        {
            break;
        }
    }

    while (*p++ = *end++)
    {
    }

    return result;
}

std::string cat(const std::string& start, const std::string& end)
{
    return start + end;
}
