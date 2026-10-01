#include "nav/path/FindSubString.h"
#include "nav/path/ListFilesAndFolders.h"
#include "nav/path/IsFile.h"
#include "nav/path/IsDirectory.h"
#include <fstream>
#include "nav/utils/FindAll.h"

namespace nav
{
namespace path
{
    std::vector<utils::FileSubString> FindSubString(const std::string &directory, const std::string &subString)
    {
        std::vector<utils::FileSubString> subStrings;
        for (const auto &fileOrDirectory : path::ListFilesAndFolders(directory))
        {
            auto val = directory + "/" + fileOrDirectory;
            if (IsFile(val))
            {
                std::string line;
                std::fstream fileStream(val);
                std::size_t lineNumber = 0;
                if (fileStream.good())
                {
                    while (std::getline(fileStream, line))
                    {
                        for (const auto &pos : utils::FindAll(line, subString))
                        {
                            subStrings.push_back((utils::FileSubString){val, line.substr(pos> 2 ?pos - 3:pos, subString.length() + 6), lineNumber, pos});
                        }
                        lineNumber++;
                    }
                }
            }
            else if(IsDirectory(val))
            {
                auto returns = FindSubString(val, subString);
                subStrings.insert(subStrings.end(), returns.begin(), returns.end());
            }
        }
        return subStrings;
    }
}
}