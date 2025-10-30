#ifndef EMPLOYEEFINDER_H
#define EMPLOYEEFINDER_H

#include "employee.h"

class EmployeeFinder {
 private:
  std::string* findEmployeeByHoursWorked(int targetHours,int& count);

 public:

  void seeFullNamesOfEmployeeByHoursWorked(int targetHours);

};

#endif
