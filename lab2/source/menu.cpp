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
