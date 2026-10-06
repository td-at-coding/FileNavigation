#include "nav/path/FindFilesByMultipleExtensions.h"
#include "nav/path/ListFilesAndFolders.h"
#include "nav/path/IsFile.h"
#include "nav/path/IsDirectory.h"
#include "nav/text/GetFileExtension.h"
#include "nav/path/FindFilesByExtension.h"
#include "nav/utils/IsOneOf.h"


namespace nav 
{
namespace path
{
    std::vector<std::string> FindFilesByMultipleExtensions(const std::string& directory, const std::vector<std::string>& extensions)
    {
        std::vector<std::string> res;

        for(const auto& fileOrDirectory : ListFilesAndFolders(directory))
        {
            auto val = directory + "/" + fileOrDirectory;
            if(IsFile(val) and utils::IsOneOf(text::GetFileExtension(val), extensions.cbegin(), extensions.cend()))
            {
                res.push_back(val);
            }
            if(IsDirectory(val))
            {
                auto files = FindFilesByMultipleExtensions(val, extensions);

                res.insert(res.end(), files.begin(), files.end());
            }
        }
        return res;
    }
}
}