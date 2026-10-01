#include "nav/path/FindFilesByName.h"
#include "nav/path/ListFilesAndFolders.h"
#include "nav/path/IsFile.h"
#include "nav/path/IsDirectory.h"
#include "nav/text/GetFileName.h"
#include "nav/utils/ToLower.h"

namespace nav
{
namespace path
{
    std::vector<std::string> FindFilesByName(
        const std::string &directory, const std::string &name, bool caseSensitive)
    {

        std::vector<std::string> res;

        for(const auto& fileOrDirectory : ListFilesAndFolders(directory))
        {
            auto val = directory + "/" + fileOrDirectory;
            if(IsFile(val))
            {
                if(caseSensitive and text::GetFileName(fileOrDirectory) == name)
                {
                    res.push_back(val);
                }
                else if(not caseSensitive and utils::ToLower(text::GetFileName(fileOrDirectory)) == utils::ToLower(name))
                {
                    res.push_back(val);
                }
            }
            else if(IsDirectory(val))
            {
                const auto& files = FindFilesByName(val, name, caseSensitive);
                res.insert(res.end(), files.begin(), files.end());
            }
        }

        return res;
    }
}
}

