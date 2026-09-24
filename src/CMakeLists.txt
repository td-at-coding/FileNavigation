project(file_navigation)

include_directories(
    ../include
)

add_library(
    file_navigation STATIC 
    path/ListFilesAndFolders.cpp
    path/IsFile.cpp
    text/GetFileExtension.cpp
    path/IsDirectory.cpp
    text/GetFileName.cpp
    path/FindFilesByName.cpp
    utils/ToLower.cpp
    path/FindFilesByExtension.cpp
)