#include "mystring.h"

using namespace std;

int main() {
    bool running = true;

    char choice;

    while (running) {
        cout << "---------MENU---------" << endl;
        cout << "1.Testing constructors" << endl;
        cout << "2.Testing input and print functions" << endl;
        cout << "3.Testing intersection" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case '1':
            testConstructors();
            break;
        case '2':
            testInputPrint();
            break;
        case '3':
            testIntersection();
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

