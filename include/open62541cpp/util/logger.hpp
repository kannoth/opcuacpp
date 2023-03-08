#ifndef logger_backend_HPP
#define logger_backend_HPP

#include <utility>

namespace opcua {
namespace util {

enum LogSeverity : unsigned char { trace, debug, info, warning, error, fatal };

template <LogSeverity s>
struct LogSeverityStr_;

template <>
struct LogSeverityStr_<LogSeverity::trace> {
  static constexpr const char* value = "\x1B[35m[TRACE]";
};

template <>
struct LogSeverityStr_<LogSeverity::debug> {
  static constexpr const char* value = "\x1B[36m[DEBUG]";
};

template <>
struct LogSeverityStr_<LogSeverity::info> {
  static constexpr const char* value = "\x1B[32m[INFO ]";
};

template <>
struct LogSeverityStr_<LogSeverity::warning> {
  static constexpr const char* value = "\x1B[33m[WARN ]";
};

template <>
struct LogSeverityStr_<LogSeverity::error> {
  static constexpr const char* value = "\x1B[31m[ERROR]";
};

template <>
struct LogSeverityStr_<LogSeverity::fatal> {
  static constexpr const char* value = "\x1B[31m[FATAL]";
};

template <typename Backend>
class Logger {
 private:
  Backend logger_backend_;

 public:
  template <typename... Args>
  Logger(Args&&... args)
      : logger_backend_(Backend(std::forward<Args>(args)...)) {}

  virtual ~Logger() = default;

  template <typename... Msgs>
  void log_trace(Msgs&&... msgs) {
    logger_backend_.log_trace(std::forward<Msgs>(msgs)...);
  }

  template <typename... Msgs>
  void log_debug(Msgs&&... msgs) {
    logger_backend_.log_debug(std::forward<Msgs>(msgs)...);
  }

  template <typename... Msgs>
  void log_info(Msgs&&... msgs) {
    logger_backend_.log_info(std::forward<Msgs>(msgs)...);
  }

  template <typename... Msgs>
  void log_warning(Msgs&&... msgs) {
    logger_backend_.log_warning(std::forward<Msgs>(msgs)...);
  }

  template <typename... Msgs>
  void log_error(Msgs&&... msgs) {
    logger_backend_.log_error(std::forward<Msgs>(msgs)...);
  }

  template <typename... Msgs>
  void log_fatal(Msgs&&... msgs) {
    logger_backend_.log_fatal(std::forward<Msgs>(msgs)...);
  }
};

}  // namespace util
}  // namespace opcua

#endif