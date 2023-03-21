#ifndef LOW_LEVEL_PROGRAMMING_EXCEPTIONS_H
#define LOW_LEVEL_PROGRAMMING_EXCEPTIONS_H

#include <exception>
#include <string>

struct MyException : std::exception{
    std::string message;

    MyException(std::string message){
        this->message = message;
    }

    const char* reason() const throw() {
        return message.c_str();
    }
};

struct IOException : public MyException {
    IOException(std::string message) : MyException(message){}
};

struct ConnectionException : public MyException{
    ConnectionException(std::string message) : MyException(message){}
};

#endif
