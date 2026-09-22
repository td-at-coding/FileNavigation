#include "text/GetFileName.h"

namespace text 
{
    std::string GetFileName(const std::string& filePath)
    {
        auto dotPos = filePath.rfind(".");

        auto slashPos = filePath.find_last_of("/\\");
        
        auto filePathLength = filePath.size();

        if(dotPos != std::string::npos)
        {
            if(slashPos != std::string::npos)
            {
                if(slashPos > dotPos)
                {
                    return filePath.substr(slashPos+1);
                }
                else if(slashPos+1 == dotPos)
                {
                    return filePath.substr(dotPos);
                }
                else 
                {
                    return filePath.substr(slashPos+1, dotPos - slashPos+1 );
                }
            }
            else if(dotPos == 0)
            {
                return filePath.substr(0);
            }
            else
            {
                return filePath.substr(0, dotPos);
            }
        }
        else 
        {
            if(slashPos != std::string::npos)
            {
                if(slashPos+1 == filePathLength)
                {
                    return "";
                }
                else
                {
                    return filePath.substr(slashPos+1);
                }
            }
            else 
            {
                return filePath;
            }
        }
    }
}