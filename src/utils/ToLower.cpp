#include "utils/ToLower.h"



namespace utils
{
    std::string ToLower(const std::string& value)
    {
        std::string res = "";

        for(const auto& character : value)
        {
            res += std::tolower(character);
        }
        return res;
    }
}