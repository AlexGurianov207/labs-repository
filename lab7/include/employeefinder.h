#ifndef EMPLOYEEFINDER_H
#define EMPLOYEEFINDER_H

#include "employee.h"

class EmployeeFinder {
 private:
	 std::string* names = nullptr;
	 int count = 0;

  void findEmployeeByHoursWorked(int targetHours);

 public:
  void seeFullNamesOfEmployeeByHoursWorked(int targetHours);

  ~EmployeeFinder();
};

#endif
