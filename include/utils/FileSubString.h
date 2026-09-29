#pragma once
#include <string>


namespace utils
{
    struct FileSubString
    {
        std::string fileName, subString;
        std::size_t line, start;
    };
}