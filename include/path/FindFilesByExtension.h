#pragma once
#include <string>
#include <vector>

namespace path
{
    std::vector<std::string> FindFilesByExtension(const std::string &directory, const std::string &extension);
}