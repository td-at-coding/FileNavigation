#include "text/GetFileExtension.h"
#include "path/IsFile.h"

namespace text
{
    std::string GetFileExtension(const std::string& filePath)
    {
        auto dotPos = filePath.rfind(".");

        auto slashPos = filePath.find_last_of("\\/");

        if(dotPos == std::string::npos or dotPos == 0)
        {
            return "";
        }
        else if(slashPos != std::string::npos and slashPos+1 == dotPos)
        {
            return "";
        }
        else if(slashPos != std::string::npos and slashPos > dotPos)
        {
            return "";
        }
        else return filePath.substr(dotPos+1);
    }
}