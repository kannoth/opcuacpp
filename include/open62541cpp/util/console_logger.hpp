#ifndef CONSOLE_LOGGER_HPP
#define CONSOLE_LOGGER_HPP

#include <chrono>
#include <iomanip>
#include <iostream>
#include <open62541cpp/util/logger.hpp>
#include <sstream>
#include <string>

namespace opcua {
namespace util {

template <typename Backend>
class Logger;

class ConsoleLogger {
 private:
  std::string entity_;
  LogSeverity severity_;

 public:
  ConsoleLogger(const std::string& entity, LogSeverity severity)
      : entity_(entity), severity_(severity) {}

  virtual ~ConsoleLogger() = default;

  template <typename... Args>
  void log_trace(Args&&... args) {
    if (severity_ <= LogSeverity::trace) {
      log(LogSeverityStr_<LogSeverity::trace>::value,
          std::forward<Args>(args)...);
    }
  }

  template <typename... Args>
  void log_debug(Args&&... args) {
    if (severity_ <= LogSeverity::debug) {
      log(LogSeverityStr_<LogSeverity::debug>::value,
          std::forward<Args>(args)...);
    }
  }

  template <typename... Args>
  void log_info(Args&&... args) {
    if (severity_ <= LogSeverity::info) {
      log(LogSeverityStr_<LogSeverity::info>::value,
          std::forward<Args>(args)...);
    }
  }

  template <typename... Args>
  void log_warning(Args&&... args) {
    if (severity_ <= LogSeverity::warning) {
      log(LogSeverityStr_<LogSeverity::warning>::value,
          std::forward<Args>(args)...);
    }
  }

  template <typename... Args>
  void log_error(Args&&... args) {
    if (severity_ <= LogSeverity::error) {
      log(LogSeverityStr_<LogSeverity::error>::value,
          std::forward<Args>(args)...);
    }
  }

  template <typename... Args>
  void log_fatal(Args&&... args) {
    if (severity_ <= LogSeverity::fatal) {
      log(LogSeverityStr_<LogSeverity::fatal>::value,
          std::forward<Args>(args)...);
    }
  }

 public:
  std::string timestamp() {
    std::ostringstream oss;
    auto now{
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())};
    oss << std::put_time(localtime(&now), "%F %T");
    return "[" + oss.str() + "]";
  }

  template <typename T, typename... Args>
  void log(T value, Args&&... args) {
    print(timestamp());
    print(value);
    print("[");
    print(entity_);
    print("]");
    print(" ");
    print(std::forward<Args>(args)...);
    print("\x1B[0m\n");
  }

  template <typename T, typename... Args>
  void print(T value, Args&&... args) {
    std::cout << value;  // TODO : Needs to be replaced with fmt
    if constexpr (sizeof...(Args)) {
      print(std::forward<Args>(args)...);
      fflush(stdout);
    }
  }
};
}  // namespace util
}  // namespace opcua

#endif