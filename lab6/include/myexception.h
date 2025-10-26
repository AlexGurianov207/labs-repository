#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <iostream>
#include <string>

class DateException : public std::exception {
 private:
  std::string message;

 public:
  explicit DateException(const std::string& newMessage);
  const char* what() const noexcept override;
};

class TrueDateException :public std::exception {
private:
	std::string message;
public:
	explicit TrueDateException(const std::string& newMessage);
	const char* what() const noexcept override;
};

#endif
