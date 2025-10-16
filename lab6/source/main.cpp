#include"menu.h"

int main() {
    Date myDate;

    char choice;

    do {
        showMenu();

        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case '1':
            testConstructors();
            break;
        case '2':
            testInputDate(myDate);
            break;
        case '3':
            std::cout << myDate << std::endl;
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