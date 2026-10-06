#pragma once
#include <string>
#include <vector>

namespace nav 
{
    namespace path
    {
        std::vector<std::string> FindFilesByMultipleExtensions(const std::string& directory, const std::vector<std::string>& extensions);
    }
}