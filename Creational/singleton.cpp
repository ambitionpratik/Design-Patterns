#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

enum class ELogLevel {
    Info,
    Warning,
    Error
};

class Logger {
public:
    // Thread safe version of creating and getting the single instance in C++11 or later.
    static Logger& Get();

    void Log(const std::string& message, ELogLevel level = ELogLevel::Info);

    // Optional: Set log file
    void SetLogFile(const std::string& filePath);

private:
    Logger() = default;
    ~Logger();

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::ofstream LogFile;
    std::mutex Mutex;

    std::string GetLevelPrefix(ELogLevel level);
};

Logger& Logger::Get() {
    static Logger instance;
    return instance;
}

Logger::~Logger() {
    if (LogFile.is_open()) {
        LogFile.close();
    }
}

void Logger::SetLogFile(const std::string& filePath) {
    std::lock_guard<std::mutex> lock(Mutex);
    if (LogFile.is_open()) {
        LogFile.close();
    }
    LogFile.open(filePath, std::ios::out | std::ios::app);
}

void Logger::Log(const std::string& message, ELogLevel level) {
    std::lock_guard<std::mutex> lock(Mutex);
    std::string output = GetLevelPrefix(level) + message;

    std::cout << output << std::endl;

    if (LogFile.is_open()) {
        LogFile << output << std::endl;
    }
}

std::string Logger::GetLevelPrefix(ELogLevel level) {
    switch (level) {
        case ELogLevel::Info: return "[INFO] ";
        case ELogLevel::Warning: return "[WARNING] ";
        case ELogLevel::Error: return "[ERROR] ";
        default: return "";
    }
}


int main() {
    // Optional: Set a file for logging
    Logger::Get().SetLogFile("log.txt");

    Logger::Get().Log("Application started");
    Logger::Get().Log("Something might be wrong", ELogLevel::Warning);
    Logger::Get().Log("An error occurred", ELogLevel::Error);

    return 0;
}
