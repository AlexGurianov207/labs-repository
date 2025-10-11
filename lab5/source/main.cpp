#include"menu.h"

int main() {
    system("chcp 1251");

    char choice;

    do {
        showMenu();

        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case '1':
            testIntArray();
            break;
        case '2':
            testDoubleArray();
            break;
        case '3':
            testStringArray();
            break;
        case '4':
            testCharArray();
            break;
        case '5':
            testBoolArray();
            break;
        case '0':
            std::cout << "Exit" << std::endl;
            break;
        default:
            std::cout << "Error" << std::endl;
            break;
        }

    } while (choice != '0');

    return 0;
}