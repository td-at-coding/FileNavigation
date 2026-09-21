#include <iostream>
#include "path/ListFilesAndFolders.h"


int main()
{
    auto filesAndFolders = path::ListFilesAndFolders("..");
    for(auto& fileOrFolder : filesAndFolders)
    {
        std::cout << fileOrFolder << std::endl;
    }
}