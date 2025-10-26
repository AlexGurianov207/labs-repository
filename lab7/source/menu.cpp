#include "menu.h"

void showMenu() {
  std::cout << "1. Read data from file" << std::endl;
  std::cout << "2. Add emloyee to file" << std::endl;
  std::cout << "3. Get a name based on the number of hours worked" << std::endl;
  std::cout << "4. Delete data from file" << std::endl;
  std::cout << "0. Exit" << std::endl;
  std::cout << "Your choice:";
}

void readDataFromFile() {
  Employee myEmployee;
  std::ifstream file("data.txt");

  if (!file.is_open()) {
    std::cout << "Error in opening file" << std::endl;
    return;
  }

  while (file >> myEmployee) {
    std::cout << "Name:" << myEmployee.getFullName() << std::endl;
    std::cout << "Service number:" << myEmployee.getServiceNumber()
              << std::endl;
    std::cout << "Hours worked per month:"
              << myEmployee.getHoursWorkedPerMonth() << std::endl;
    std::cout << "Hourly rate:" << myEmployee.getHourlyRate() << std::endl;
    std::cout << '\n';
  }

  if (file.bad()) {
    std::cout << "Error in reading data from file" << std::endl;
    return;
  }
}

void addEmployeeToFile() {
  Employee myEmployee;

  std::cout << "Enter the employee info" << std::endl;

  std::cout << "Enter the full name:";
  std::string name;
  std::getline(std::cin, name);
  myEmployee.setFullName(name);

  std::cout << "Enter the service number:";
  int number;
  std::cin >> number;
  if (std::cin.fail() || number <= 0) {
    std::cout << "Error:Number should be positive digit" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    return;
  }

  myEmployee.setServiceNumber(number);

  std::cout << "Enter the hours worked per month:";
  int hoursWorked;
  std::cin >> hoursWorked;
  if (std::cin.fail() || hoursWorked < 0) {
    std::cout << "Error:Hours should be positive digit or zero" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    return;
  }
  myEmployee.setHoursWorkedPerMonth(hoursWorked);

  std::cout << "Enter the hourly rate:";
  int rate;
  std::cin >> rate;
  if (std::cin.fail() || rate <= 0) {
    std::cout << "Error:Rate should be positive digit" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    return;
  }
  myEmployee.setHourlyRate(rate);

  std::ofstream file("data.txt", std::ios::app);

  if (!file.is_open()) {
    std::cout << "Error in opening file" << std::endl;
    return;
  }

  file << myEmployee;

  if (file.bad()) {
    std::cout << "Error in writing data to file" << std::endl;
    return;
  }
}

void findNamesBasedOnTheNumberOfHoursWorked() {
  EmployeeFinder myEmployeeFinder;

  int targetHoursWorked;
  std::cout << "Enter the target hours worked to find employees:";
  std::cin >> targetHoursWorked;
  if (std::cin.fail() || targetHoursWorked < 0) {
    std::cout << "Error:Hours should be positive digit or zero" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    return;
  }
  std::cin.ignore();

  myEmployeeFinder.seeFullNamesOfEmployeeByHoursWorked(targetHoursWorked);
}

void deleteDataFromFile() {
  std::cout << "Do you want to delete(y/n):";
  char confirm;
  std::cin >> confirm;
  if (confirm == 'y') {
    std::ofstream("data.txt");
  }
}
