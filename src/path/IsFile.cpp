#include "path/IsFile.h"
#if defined(__linux__) or defined(__APPLE__)
#include <sys/stat.h>
#endif

namespace path
{
    bool IsFile(const std::string& filePath)
    {
#ifdef _WIN32
    DWORD attributes = GetFileAttributesA(filePath.c_str());
    return (attributes != INVALID_FILE_ATTRIBUTES && 
           !(attributes & FILE_ATTRIBUTE_DIRECTORY));
#else 
    struct stat buffer;   
    return (stat (filePath.c_str(), &buffer) == 0); 
#endif
    }
}