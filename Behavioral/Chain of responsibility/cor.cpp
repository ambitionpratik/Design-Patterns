#include <iostream>
#include <memory>
#include <string>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

// Abstract class
class Logger {
protected:
    std::shared_ptr<Logger> next;

public:
    void SetNext(std::shared_ptr<Logger> nextLogger) {
        next = nextLogger;
    }

    void Log(LogLevel level, const std::string& message) {
        if (Handle(level, message) == false && next) {
            next->Log(level, message);
        }
    }

    virtual ~Logger() = default;

protected:
    virtual bool Handle(LogLevel level, const std::string& message) = 0;
};

// Concrete class
class DebugLogger : public Logger {
protected:
    bool Handle(LogLevel level, const std::string& message) override {
        if (level == LogLevel::DEBUG) {
            std::cout << "[DEBUG] " << message << "\n";
            return true;
        }
        return false;
    }
};

// Concrete class
class ErrorLogger : public Logger {
protected:
    bool Handle(LogLevel level, const std::string& message) override {
        if (level == LogLevel::ERROR) {
            std::cerr << "[ERROR] " << message << "\n";
            return true;
        }
        return false;
    }
};

// Concrete class
class InfoLogger : public Logger {
protected:
    bool Handle(LogLevel level, const std::string& message) override {
        if (level == LogLevel::INFO || level == LogLevel::WARNING) {
            std::cout << "[INFO] " << message << "\n";
            return true;
        }
        return false;
    }
};

// Client code
int main() {
    auto debugLogger = std::make_shared<DebugLogger>();
    auto infoLogger = std::make_shared<InfoLogger>();
    auto errorLogger = std::make_shared<ErrorLogger>();

    debugLogger->SetNext(infoLogger);
    infoLogger->SetNext(errorLogger);

    // Send requests
    debugLogger->Log(LogLevel::DEBUG, "Debugging variable x");
    debugLogger->Log(LogLevel::INFO, "System is starting");
    debugLogger->Log(LogLevel::WARNING, "Low memory warning");
    debugLogger->Log(LogLevel::ERROR, "File not found");

    return 0;
}
