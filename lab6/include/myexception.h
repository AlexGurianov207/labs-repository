#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include<iostream>
#include<exception>

class DateException:public std::exception {
private:
	std::string message;

public:
	DateException(std::string newMessage);
	const char* what() const override;

};

#endif
