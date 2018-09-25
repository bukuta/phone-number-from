#ifndef Logger_hpp
#define Logger_hpp

#include <spdlog/spdlog.h>
#include <iostream>

class Logger {
 private:
  //   Logger() { std::cout << "Logger()" << std::endl; }
  static std::shared_ptr<spdlog::logger> console;

 public:
  //   ~Logger() { std::cout << "~Logger()" << std::endl; }
  template <typename... Args>
  static void trace(const char *fmt, const Args &... args) {
    console->trace(fmt, args...);
  }
  template <class T>
  static void trace(const T &fmt) {
    console->trace(fmt);
  };

  template <typename... Args>
  static void debug(const char *fmt, const Args &... args) {
    console->debug(fmt, args...);
  }

  template <class T>
  static void debug(const T &fmt) {
    console->debug(fmt);
  };

  template <typename... Args>
  static void info(const char *fmt, const Args &... args) {
    console->info(fmt, args...);
  }

  template <class T>
  static void info(const T &fmt) {
    console->info(fmt);
  };

  template <typename... Args>
  static void warn(const char *fmt, const Args &... args) {
    console->warn(fmt, args...);
  }

  template <class T>
  static void warn(const T &fmt) {
    console->warn(fmt);
  };

  template <typename... Args>
  static void error(const char *fmt, const Args &... args) {
    console->error(fmt, args...);
  }

  template <class T>
  static void error(const T &fmt) {
    console->error(fmt);
  };
};

#endif /* Logger_hpp */
