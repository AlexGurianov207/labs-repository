#include "menu.h"

int main() {
  char choice;

  do {
    showMenu();

    std::cin >> choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
      case '1':
        readDataFromFile();
        break;
      case '2':
        addEmployeeToFile();
        break;
      case '3':
        findNamesBasedOnTheNumberOfHoursWorked();
        break;
      case '4':
        deleteDataFromFile();
        break;
      case '0':
        std::cout << "Exit" << std::endl;
        break;
      default:
        std::cout << "Invalid input" << std::endl;
        break;
    }

  } while (choice != '0');

  return 0;
}
