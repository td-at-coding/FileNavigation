#include "path/IsDirectory.h"
#if defined(__linux__) or defined(__APPLE__)
#include <sys/stat.h>
#endif

namespace path
{
    bool IsDirectory(const std::string& directoryPath)
    {
#ifdef _WIN32
    DWORD attributes = GetFileAttributesA(directoryPath.c_str());
    return (attributes != INVALID_FILE_ATTRIBUTES && 
           (attributes & FILE_ATTRIBUTE_DIRECTORY));
#else 
    struct stat info;

    if (stat(directoryPath.c_str(), &info) != 0) 
    {
        return false;
    }
    
    return (info.st_mode & S_IFDIR) != 0; 
#endif
    }
}