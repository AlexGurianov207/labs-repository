#include "menu.h"

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
  std::cout << "5.Test assignment operator" << std::endl;
  std::cout << "0. Exit" << std::endl;
}

void testPrint(const String& myString) {
  std::cout << myString;
  std::cout << std::endl;
}

void testAssignment() {
  std::cout << "\n=== Testing assignment operator ===" << std::endl;

  std::cout << "Test 1 - Normal assignment:" << std::endl;
  String a("Hello");
  String b("World");
  std::cout << "a = " << a << "b = " << b << std::endl;
  a = b;
  std::cout << "After a = b: a = " << a << std::endl;

  std::cout << "\nTest 2 - Self-assignment:" << std::endl;
  String c("Test");
  std::cout << "Before: c = " << c << std::endl;
  c = c;
  std::cout << "After c = c: c = " << c << std::endl;

  std::cout << "Assignment test completed" << std::endl;
}
