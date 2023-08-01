#include "logger.hpp"
#include <stdexcept>

using namespace std;

std::string Logger::ms_logFileName;

void Logger::setLogFileName(std::string_view logFileName) {
    ms_logFileName = logFileName.data();
}

Logger &Logger::instance(void) {
    static Logger logger; // here the base of singleton class
    return logger;
}

void Logger::setLogLevel(LogLevel level) { m_logLevel = level; }

void Logger::log(std::string_view message, LogLevel level) {
    if (m_logLevel < level) {
        return;
    }
    m_outputStream << getLogLevelString(level) << ": " << message << "."
                   << endl;
}

Logger::Logger() {
    m_outputStream.open(ms_logFileName, ios_base::app);
    if (!m_outputStream.good()) {
        throw runtime_error{"Unable to initialize the logger file"};
    }
}

Logger::~Logger() {
    m_outputStream << "Logger Shutting Down ...";
    m_outputStream.close();
}

std::string_view Logger::getLogLevelString(LogLevel level) const {
    switch (level) {
    case LogLevel::Error:
        return "ERROR";
    case LogLevel::Debug:
        return "DEBUG";
    case LogLevel::Info:
        return "INFO";
    }
    throw runtime_error{"Invalid Log level"};
}
