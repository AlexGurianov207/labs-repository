#include "myexception.h"

DateException::DateException(const std::string& newMessage)
    : message(newMessage) {}

const char* DateException::what() const noexcept { return message.c_str(); }


TrueDateException::TrueDateException(const std::string& newMessage):message(newMessage){}

const char* TrueDateException::what()const noexcept {
    return message.c_str();
}