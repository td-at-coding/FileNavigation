#pragma once
#include <string>
#include <vector>
#include "../utils/FileSubString.h"

namespace nav 
{
    namespace path
    {
        std::vector<utils::FileSubString> FindSubString(const std::string& directory, const std::string& subString);
    }

}
