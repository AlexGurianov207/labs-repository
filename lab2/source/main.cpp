#include "menu.h"
#include "mystring.h"

using namespace std;

int main() {
  bool running = true;

  char choice;

  String myString;

  while (running) {
    printMenu();

    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
      case '1':
        testInput(myString);
        break;
      case '2':
        testPrint(myString);
        break;
      case '3':
        testCoding(myString);
        break;
      case '4':
        testDecoding(myString);
        break;
      case '5':
        testAssignment();
        break;
      case '0':
        running = false;
        cout << "Exit" << endl;
        break;
      default:
        cout << "Error" << endl;
    }
  }

  return 0;
}
