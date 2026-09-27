#include "text/GetFileDirectory.h"


namespace text 
{
    std::string GetFileDirectory(const std::string& filePath)
    {
        auto slashPos = filePath.find_last_of("/\\");

        if(slashPos == std::string::npos)
        {
            return ".";
        }
        else 
        {
            return filePath.substr(0,slashPos);
        }
    }
}