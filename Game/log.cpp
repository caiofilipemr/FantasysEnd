#include "log.h"

std::string Log::log = "";

void Log::setLog(std::string new_log)
{
    log = new_log;
}

std::string Log::getLog()
{
    return log;
}

void Log::clear()
{
    log.clear();
}

bool Log::isEmpty()
{
    return log.empty();
}
