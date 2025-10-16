#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include<iostream>
#include<exception>

class DateException:public std::exception {
private:
	std::string message;

public:
	explicit DateException(std::string newMessage);
	const char* what() const noexcept override;

};

#endif
