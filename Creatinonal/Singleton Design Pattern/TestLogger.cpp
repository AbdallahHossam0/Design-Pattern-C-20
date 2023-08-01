#include "logger.hpp"
#include <string>

using namespace std;

int main(void) {
    // set the name of the file to the logger
    Logger::setLogFileName("log.txt");

    // create the logger and set the logging level
    Logger::instance().setLogLevel(Logger::LogLevel::Debug);

    Logger::instance().log("Test Message", Logger::LogLevel::Debug);

    Logger::instance().setLogLevel(Logger::LogLevel::Error);

    Logger::instance().log("Debug Message", Logger::LogLevel::Debug);
}
