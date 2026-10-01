project(file_navigation)

include_directories(
    ../include
)

add_library(
    file_navigation STATIC 
    nav/path/ListFilesAndFolders.cpp
    nav/path/IsFile.cpp
    nav/text/GetFileExtension.cpp
    nav/path/IsDirectory.cpp
    nav/text/GetFileName.cpp
    nav/path/FindFilesByName.cpp
    nav/utils/ToLower.cpp
    nav/path/FindFilesByExtension.cpp
    nav/text/GetFileDirectory.cpp
    nav/utils/FindAll.cpp
    nav/path/FindSubString.cpp
)