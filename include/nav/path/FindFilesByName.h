#pragma once
#include <string>
#include <vector>


namespace nav 
{
    namespace path
    {
        std::vector<std::string> FindFilesByName(const std::string& directory, const std::string& name, bool caseSensitive = false);
    }

}

