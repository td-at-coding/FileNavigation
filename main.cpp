#include <iostream>
#include "path/ListFilesAndFolders.h"
#include "path/IsFile.h"

int main()
{
    auto filesAndFolders = path::ListFilesAndFolders("..");
    for(auto& fileOrFolder : filesAndFolders)
    {
        std::cout << fileOrFolder << std::endl;
    }
    std::cout << "../main.cpp is a file? '" << std::boolalpha << path::IsFile("../main.cpp") << "'" << std::endl;
    std::cout << "../main.cppc is a file? '" << std::boolalpha << path::IsFile("../main.cppc") << "'" << std::endl;
}