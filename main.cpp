#include <iostream>
#include "path/ListFilesAndFolders.h"
#include "path/IsFile.h"
#include "text/GetFileExtension.h"


int main()
{
    auto filesAndFolders = path::ListFilesAndFolders("..");
    for(auto& fileOrFolder : filesAndFolders)
    {
        std::cout << fileOrFolder << std::endl;
    }
    std::cout << "../main.cpp is a file? '" << std::boolalpha << path::IsFile("../main.cpp") << "'" << std::endl;
    std::cout << "../main.cppc is a file? '" << std::boolalpha << path::IsFile("../main.cppc") << "'" << std::endl;

    std::cout 
        << "File extension of 'main.cpp' should equal to 'cpp'? '" 
        << std::boolalpha 
        << (text::GetFileExtension("main.cpp") == "cpp") 
        << "'" 
        << std::endl;

    std::cout 
        << "File extension of '/opt/share/myfile.d/text' should equal to ''? '" 
        << std::boolalpha 
        << (text::GetFileExtension("/opt/share/myfile.d/text") == "") 
        << "'" 
        << std::endl;

    std::cout 
        << "File extension of '.gitignore' should equal to ''? '" 
        << std::boolalpha 
        << (text::GetFileExtension(".gitignore") == "") 
        << "'" 
        << std::endl;
}