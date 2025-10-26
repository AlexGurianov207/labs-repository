#ifndef EMPLOYEEFINDER_H
#define EMPLOYEEFINDER_H

#include "employee.h"

class EmployeeFinder {
 private:
  std::string* names;
  int count;

  void findEmployeeByHoursWorked(int targetHours);

 public:
  EmployeeFinder();

  void seeFullNamesOfEmployeeByHoursWorked(int targetHours);

  ~EmployeeFinder();
};

#endif
