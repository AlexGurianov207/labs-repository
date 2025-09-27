#include "menu.h"
#include "mystring.h"

using namespace std;

int main() {
  bool running = true;

  char choice;

  String myString;

  while (running) {
    cout << "---------MENU---------" << endl;
    cout << "1.Input string" << endl;
    cout << "2.Print string" << endl;
    cout << "3.Coding string" << endl;
    cout << "4.Decoding string" << endl;
    cout << "0. Exit" << endl;

    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
      case '1':
        testInput(myString);
        break;
      case '2':
        cout << myString << endl;
        break;
      case '3':
        testCoding(myString);
        break;
      case '4':
        testDecoding(myString);
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
