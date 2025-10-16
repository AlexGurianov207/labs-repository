#include"myexception.h"

DateException::DateException(const std::string newMessage):message(newMessage) {

}

const char* DateException::what()const {
	return message.c_str();
}