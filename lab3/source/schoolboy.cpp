#include "schoolboy.h"

Schoolboy::Schoolboy() : Learner(), schoolName("Undefined"), grade(1) {}

Schoolboy::Schoolboy(const std::string& newName, int newAge,
                     const std::string& newSchoolName, int newGrade)
    : Learner(newName, newAge), schoolName(newSchoolName), grade(newGrade) {}

void Schoolboy::display() const {
  std::cout << "Name:" << getName() << " ";
  std::cout << "Age:" << getAge() << " ";

  std::cout << "School:" << schoolName << " ";
  std::cout << "Grade:" << grade << " ";
  std::cout << std::endl;
}

std::string Schoolboy::getType() const { return "Schoolboy"; }

std::string Schoolboy::getSchoolName() const { return schoolName; }

int Schoolboy::getGrade() const { return grade; }
