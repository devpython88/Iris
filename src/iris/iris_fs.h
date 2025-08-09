#pragma once

#include <fstream>
#include <optional>

#ifdef _WIN32
#include <sys/stat.h>
#define STAT _stat
#define STAT_STRUCT struct _stat
#define S_IFDIR_FLAG _S_IFDIR
#else
#include <sys/stat.h>
#define STAT stat
#define STAT_STRUCT struct stat
#define S_IFDIR_FLAG S_IFDIR
#endif

class FileSystem {
    public:

    static bool writeFile(const std::string& path, const std::string& text);
    static std::optional<std::string> readFile(const std::string& path);

    static bool fileExists(const std::string& path);
    static bool directoryExists(const std::string& path);

    static void createDirectory(const std::string& path);
    static void removeFile(const std::string& path);
    static void removeDirectory(const std::string& path);
};