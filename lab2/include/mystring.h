#ifndef MYSTRING_H
#define MYSTRING_H

#include <cctype>
#include <iostream>
#include <string>

class String {
 private:
  size_t length;
  char* data;
  bool isEncoded = false;

  static constexpr int alphabetSize = 26;
  static constexpr int shift = 1;

 public:
  String(const String& other);
  String();
  explicit String(const char* newString);

  String& operator++();
  String& operator--();
  String& operator=(const String& other);

  ~String();

  friend std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.data << std::endl;
    return os;
  }

  friend std::istream& operator>>(std::istream& is, String& str) {
    std::string buffer;
    std::getline(is, buffer);

    delete[] str.data;
    str.length = buffer.length();
    str.data = new char[str.length + 1];
    std::memcpy(str.data, buffer.data(), str.length);
    str.data[str.length] = '\0';

    str.isEncoded = false;

    return is;
  }
};

#endif
