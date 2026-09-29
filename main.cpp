#include <iostream>
#include "path/ListFilesAndFolders.h"
#include "path/IsFile.h"
#include "text/GetFileExtension.h"
#include "path/IsDirectory.h"
#include "text/GetFileName.h"
#include "path/FindFilesByName.h"
#include "path/FindFilesByExtension.h"
#include "text/GetFileDirectory.h"
#include "utils/FindAll.h"
#include "path/FindSubString.h"

int main()
{
    auto filesAndFolders = path::ListFilesAndFolders("..");
    for(const auto& fileOrFolder : filesAndFolders)
    {
        std::cout << fileOrFolder << std::endl;
    }
    
    std::cout << "-----------------------" << std::endl;

    std::cout << "../main.cpp is a file? '" << std::boolalpha << path::IsFile("../main.cpp") << "'" << std::endl;
    std::cout << "../main.cppc is a file? '" << std::boolalpha << path::IsFile("../main.cppc") << "'" << std::endl;
    
    std::cout << "-----------------------" << std::endl;

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

            
    std::cout << "-----------------------" << std::endl;

    std::cout << ".. is a directory? '" << std::boolalpha << path::IsDirectory("..") << "'" << std::endl;
    std::cout << "../main.cpp is a directory? '" << std::boolalpha << path::IsDirectory("../main.cpp") << "'" << std::endl;
    std::cout << "./hello is a directory? '" << std::boolalpha << path::IsDirectory("./hello") << "'" << std::endl;

    std::cout << "-----------------------" << std::endl;

    std::cout 
        << "File name of 'main.cpp' should equal to 'main'? '" 
        << std::boolalpha 
        << (text::GetFileName("main.cpp") == "main") 
        << "'" 
        << std::endl;


    std::cout 
        << "File name of '/opt/share/myfile.d/text' should equal to 'text'? '" 
        << std::boolalpha 
        << (text::GetFileName("/opt/share/myfile.d/text") == "text") 
        << "'" 
        << std::endl;

        
    std::cout 
        << "File name of '.gitignore' should equal to '.gitignore'? '" 
        << std::boolalpha 
        << (text::GetFileName(".gitignore") == ".gitignore") 
        << "'" 
        << std::endl;
        
    std::cout 
        << "File name of '/home/' should equal to ''? '" 
        << std::boolalpha 
        << (text::GetFileName("/home/") == "") 
        << "'" 
        << std::endl;
    std::cout 
        << "File name of '/home/Documents/main.cpp' should equal to 'main'? '" 
        << std::boolalpha 
        << (text::GetFileName("/home/Documents/main.cpp") == "main") 
        << "'"
        << std::endl;
    
    std::cout 
        << "File name of '/home/Documents/maths.mate' should equal to 'maths'? '" 
        << std::boolalpha 
        << (text::GetFileName("/home/Documents/maths.mate") == "maths") 
        << "'"
        << std::endl;

    
    std::cout << "-----------------------" << std::endl;


    for(const auto& name : path::FindFilesByName("../testsDirectory", "file"))
    {
        std::cout << name << std::endl;
    }

    std::cout << "-----------------------" << std::endl;


    for(const auto& name : path::FindFilesByExtension("../testsDirectory", "txt"))
    {
        std::cout << name << std::endl;
    }

    std::cout << "-----------------------" << std::endl;

    
    std::cout 
        << "File directory of '/home/Documents/maths.mate' should equal to '/home/Documents'? '" 
        << std::boolalpha 
        << (text::GetFileDirectory("/home/Documents/maths.mate") == "/home/Documents") 
        << "'" 
        << std::endl;

    std::cout 
        << "File directory of 'file.txt' should equal to ''? '" 
        << std::boolalpha 
        << (text::GetFileDirectory("file.txt") == "") 
        << "'" 
        << std::endl;

    std::cout 
        << "File directory of '../documents/file.txt' should equal to '../documents'? '" 
        << std::boolalpha 
        << (text::GetFileDirectory("../documents/file.txt") == "../documents") 
        << "'" 
        << std::endl;

    std::cout << "-----------------------" << std::endl;

    std::cout << "Find all ones in string '11111'" << std::endl;
    for(const auto& pos : utils::FindAll("11111", "1"))
    {
        std::cout << "\tAt pos = " << pos << std::endl;
    }
    
    std::cout << "Find all elevens in string '11111'" << std::endl;
    for(const auto& pos : utils::FindAll("11111", "11"))
    {
        std::cout << "\tAt pos = " << pos << std::endl;
    }

    std::cout << "Find all twos in string '11111'" << std::endl;
    for(const auto& pos : utils::FindAll("11111", "2"))
    {
        std::cout << "\tAt pos = " << pos << std::endl;
    }

    std::cout << "-----------------------" << std::endl;

    std::cout << "Find all files containing '#include <string>' in '../'" << std::endl;
    for(const auto& subString : path::FindSubString("..", "#include <string>"))
    {
        std::cout 
            << "File: " << subString.fileName 
            << ", line: " << subString.line 
            << ", start pos: " << subString.start 
            << ", substring: '" << subString.subString << "'"
            << std::endl;
    }

}