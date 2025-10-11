#include "menu.h"

using namespace std;

void showMenu() {
  cout << "----------MENU----------" << endl;
  cout << "1. Work with <int>" << endl;
  cout << "2. Work with <double>" << endl;
  cout << "3. Work with <string>" << endl;
  cout << "4. Work with <char>" << endl;
  cout << "5. Work with <bool>" << endl;
  cout << "0. Exit" << endl;
  cout << "Your choice:";
}

void testIntArray() {
  cout << "Test <int> array" << endl;
  testArray<int>();
}

void testBoolArray() {
  cout << "Test <bool> array" << endl;
  testArray<bool>();
}

void testDoubleArray() {
  cout << "Test <double> array" << endl;
  testArray<double>();
}

void testStringArray() {
  cout << "Test <string> array" << endl;
  testArray<string>();
}

void testCharArray() {
  cout << "Test <char> array" << endl;
  testArray<char>();
}
