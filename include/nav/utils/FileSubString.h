#pragma once
#include <string>

namespace nav
{
    namespace utils
    {
        struct FileSubString
        {
            std::string fileName, subString;
            std::size_t line, start;
        };
    }
}
