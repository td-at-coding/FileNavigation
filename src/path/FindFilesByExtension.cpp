#include "path/FindFilesByExtension.h"
#include "path/ListFilesAndFolders.h"
#include "path/IsFile.h"
#include "path/IsDirectory.h"
#include "text/GetFileExtension.h"

namespace path 
{
    std::vector<std::string> FindFilesByExtension(const std::string& directory, const std::string& extension)
    {
        
        std::vector<std::string> res;

        for(const auto& fileOrDirectory : ListFilesAndFolders(directory))
        {
            auto val = directory + "/" + fileOrDirectory;
            if(IsFile(val) and text::GetFileExtension(val) == extension)
            {
                res.push_back(val);
            }
            else if(IsDirectory(val))
            {
                auto files = FindFilesByExtension(val, extension);

                res.insert(res.end(), files.begin(), files.end());
            }
        }
        return res;
    }
}