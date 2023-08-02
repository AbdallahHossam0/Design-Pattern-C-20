// ! Assume you have such a logger

#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>

using namespace std;

// Assume you have such a logger
class Logger {
  public:
    enum class LogLevel { Error, Info, Debug };
    Logger() { cout << "I am the old logger" << endl; }
    virtual ~Logger() = default;
    void log(LogLevel level, string message) {
        cout << getLogLevelString(level) << ": " << message << "\n";
    }

  private:
    string_view getLogLevelString(LogLevel level) {
        switch (level) {
        case LogLevel::Debug:
            return "DEBUG";
        case LogLevel::Info:
            return "INFO";
        case LogLevel::Error:
            return "ERROR";
        default:
            throw runtime_error{"Invalid Log Level"};
        }
    }
};

// ! you need to create a log function that doesn't care about the log level I
// ! know you can use bind or default args but also i need to make the type of
// ! the message is string_view not just string => by using the adapter pattern

class AdapterLogger {
  public:
    AdapterLogger() { cout << "I am the new logger\n"; }
    virtual ~AdapterLogger() = default;
    void log(string_view message) {
        m_logger.log(Logger::LogLevel::Info, message.data());
    }

  private:
    Logger m_logger;
};

// int main(void) {
//     AdapterLogger logger;
//     logger.log("Very Important Message");
// }