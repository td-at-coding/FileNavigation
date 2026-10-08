#include "nav/text/GetFileBaseName.h"

namespace nav
{
namespace text
{
    std::string GetFileBaseName(const std::string& filePath)
    {
        auto slashPos = filePath.find_last_of("/\\");
        if(slashPos != std::string::npos)
        {
            return filePath.substr(slashPos + 1);
        }
        return filePath;
    }
}
}