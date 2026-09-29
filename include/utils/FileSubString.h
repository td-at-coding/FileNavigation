#pragma once
#include <string>


namespace utils
{
    struct FileSubString
    {
        std::string fileName;
        std::size_t line, start;
        std::string subString;
    };
}