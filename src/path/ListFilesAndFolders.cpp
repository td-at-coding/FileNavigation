#include "path/ListFilesAndFolders.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <dirent.h>
#endif
#include <cstring>
#include <stdexcept>
#include <sstream>


namespace path
{
    std::vector<std::string> ListFilesAndFolders(const std::string& folder)
    {
        std::vector<std::string> filesAndFolders;
#ifdef _WIN32

        WIN32_FIND_DATAA findData;
        std::stringstream ss;
        ss << folder << "/*";
        HANDLE hFind = FindFirstFileA(ss.str().c_str(), &findData);

        if (hFind == INVALID_HANDLE_VALUE) {
            std::stringstream sse;
            sse << "Directory not found or inaccessible. Error: " << GetLastError;
            throw std::runtime_error(sse.str());
        }

        do {
            if (strcmp(findData.cFileName, ".") == 0 || strcmp(findData.cFileName, "..") == 0) {
                continue;
            }

            //if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                //continue;
            //}

            filesAndFolders.push_back(findData.cFileName);


        } while (FindNextFileA(hFind, &findData));

        FindClose(hFind);

#else 

        DIR* dir = opendir(folder.c_str());

        if (dir == nullptr) {
            throw std::runtime_error("Folder not found!");
        }

        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            else
            {
                filesAndFolders.push_back(entry->d_name);
            }
        }

#endif

        return filesAndFolders;
    }
}
