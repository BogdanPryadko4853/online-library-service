#include "../../include/logger/Logger.h"

void Logger::update(const std::string& message) {
    std::cout << "[LOG] " << message << std::endl;
}