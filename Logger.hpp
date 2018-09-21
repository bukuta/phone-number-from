#ifndef Logger_hpp
#define Logger_hpp

#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_sinks.h>
static auto console = spdlog::stdout_color_mt("console");

class Logger{
    public:
        Logger(){
            std::cout<<"Logger()"<<std::endl;
        }
        std::shared_ptr<spdlog::logger> console;
        static Logger instance;
        // static Logger getInstance(){
        //     return instance;
        // };

    public:
    ~Logger(){
        std::cout<<"~Logger()"<<std::endl;
    }

      template <class T>
      static void debug(const T & fmt) {
            std::cout<<"debug::"<<std::endl;
        //   instance()->debug(fmt);
        };
      template <class T>
        static void info(const T& fmt){
            std::cout<<"info::"<<std::endl;
            Logger().console->info(fmt);
        };
      template <class T>
        static void warn(const T& fmt){
            std::cout<<"warn::"<<std::endl;
            Logger().console->warn(fmt);
            // instance()->warn(fmt);
        };
      template <class T>
        static void error(const T& fmt){
            std::cout<<"error::"<<std::endl;
            // instance()->error(fmt);
        };
};


#endif /* Logger_hpp */
