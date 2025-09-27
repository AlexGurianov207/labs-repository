#include "menu.h"

#include <iostream>

void testInput(String& myString) {
  std::cout << "Enter the string:";
  std::cin >> myString;
}

void testCoding(String& myString) {
  ++myString;
  std::cout << myString << std::endl;
}

void testDecoding(String& myString) {
  --myString;
  std::cout << myString << std::endl;
}

void printMenu() {
  std::cout << "---------MENU---------" << std::endl;
  std::cout << "1.Input string" << std::endl;
  std::cout << "2.Print string" << std::endl;
  std::cout << "3.Coding string" << std::endl;
  std::cout << "4.Decoding string" << std::endl;
  std::cout << "0. Exit" << std::endl;
}

void testPrint(const String& myString) {
  std::cout << myString;
  std::cout << std::endl;
}
