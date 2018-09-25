#ifndef Logger_hpp
#define Logger_hpp

#include <iostream>
#include <spdlog/spdlog.h>

class Logger{
    public:
        Logger(){
            std::cout<<"Logger()"<<std::endl;
        }
        static std::shared_ptr<spdlog::logger> console;

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
            console->info(fmt);
        };
      template <class T>
        static void warn(const T& fmt){
            std::cout<<"warn::"<<std::endl;
            console->warn(fmt);
            // instance()->warn(fmt);
        };
      template <class T>
        static void error(const T& fmt){
            std::cout<<"error::"<<std::endl;
            console->error(fmt);
        };
};


#endif /* Logger_hpp */
