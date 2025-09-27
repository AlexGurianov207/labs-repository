#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class MyString {
 private:
  size_t length;
  char* str;

 public:
  MyString();
  explicit MyString(const char* newString);
  MyString(const MyString& other);

  void printStr() const;
  void inputStr();
  MyString intersection(const MyString& other) const;

  MyString& operator=(const MyString& other) = delete;

  ~MyString();
};

void testInputPrint();

void testIntersection();

void testConstructors();

#endif
