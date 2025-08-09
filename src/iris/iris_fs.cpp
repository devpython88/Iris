#include "iris_fs.h"

bool FileSystem::writeFile(const std::string &path, const std::string &text)
{
    std::ofstream file(path);
    if (!file.is_open()) return false;

    file << text;
    file.close();
    return true;
}

std::optional<std::string> FileSystem::readFile(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open()) return std::nullopt;

    std::string line;
    std::string text;

    while (std::getline(file, line)){
        text += line + "\n";
    }

    return text;
}

bool FileSystem::fileExists(const std::string &path)
{
    std::ifstream file(path);
    return file.good();
}

bool FileSystem::directoryExists(const std::string &path)
{
    STAT_STRUCT info;
    if (STAT(path.c_str(), &info) != 0){
        return false;
    }

    return (info.st_mode & S_IFDIR_FLAG) != 0;
}

void FileSystem::createDirectory(const std::string &path)
{
    #ifdef _WIN32
    std::system(("mkdir " + path).c_str());
    #else
    std::system(("mkdir -p " + path).c_str());
    #endif
}

void FileSystem::removeFile(const std::string &path)
{
    #ifdef _WIN32
    std::system(("del /f /q " + path).c_str());
    #else
    std::system(("rm -rf" + path).c_str());
    #endif
}

void FileSystem::removeDirectory(const std::string &path)
{
    #ifdef _WIN32
    std::system(("rmdir /s /q " + path).c_str());
    #else
    std::system(("rm -rf" + path).c_str());
    #endif
}
