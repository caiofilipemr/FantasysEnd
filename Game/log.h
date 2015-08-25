#ifndef LOG_H
#define LOG_H

#include <string>

class Log
{
private:
    static std::string log;
public:
    static void setLog(std::string new_log);
    static std::string getLog();
    static void clear();
    static bool isEmpty();
};

#endif // LOG_H
