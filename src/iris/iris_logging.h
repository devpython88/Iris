#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

class LogService
{
    public:
    
    template <typename... Args>
    static void log(std::string level, std::string text, Args... args)
    {
        std::time_t now = std::time(nullptr);
        std::tm* local_now = std::localtime(&now);

        std::cout << std::put_time(local_now, "%H:%M:%S") << " >> " << level << " >> " << text;
        
        (void)std::initializer_list<int>{(std::cout << args, 0)...};
        std::cout << std::endl;
    }

    
    template <typename... Args>
    
    static void info(std::string txt, Args... args){
        log("info", txt, args...);
    }
    
    template <typename... Args>
    
    static void error(std::string txt, Args... args){
        log("error", txt, args...);
    }
    
    template <typename... Args>
    
    static void warning(std::string txt, Args... args){
        log("warning", txt, args...);
    }
};