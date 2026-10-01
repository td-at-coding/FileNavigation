#include "nav/utils/FindAll.h"

namespace nav
{
namespace utils
{
    std::vector<std::size_t> FindAll(const std::string& text, const std::string& subString)
    {
        std::vector<std::size_t> res;
        auto pos = text.find(subString);
        while(pos != std::string::npos)
        {
            res.push_back(pos);
            pos = text.find(subString, pos + subString.length());
        }
        return res;
    }
}
}