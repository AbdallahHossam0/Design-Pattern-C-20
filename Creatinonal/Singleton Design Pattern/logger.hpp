#pragma once

#include <fstream>
#include <string>
#include <string_view>

class Logger final {
  public:
    enum class LogLevel { Error, Info, Debug };

    static void setLogFileName(std::string_view);

    static Logger &instance(void);

    Logger(const Logger &) = delete;
    Logger(const Logger &&) = delete;

    Logger &operator=(const Logger &) = delete;
    Logger &operator=(const Logger &&) = delete;

    void setLogLevel(LogLevel);

    void log(std::string_view message, LogLevel level);

  private:
    Logger();
    ~Logger();

    std::string_view getLogLevelString(LogLevel) const;

    static std::string ms_logFileName;
    std::ofstream m_outputStream;
    LogLevel m_logLevel{LogLevel ::Error};
};