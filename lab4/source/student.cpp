#include "student.h"

Student::Student()
    : Learner(),
    university("Undefined"),
    faculty("Undefined"),
    course(defaultCourse) {}

Student::Student(const std::string& newName, int newAge,
    const std::string& newUniversity,
    const std::string& newFaculty, int newCourse)
    : Learner(newName, newAge),
    university(newUniversity),
    faculty(newFaculty),
    course(newCourse) {}

void Student::display() const {
    std::cout << "Name:" << getName() << " ";
    std::cout << "Age:" << getAge() << " ";

    std::cout << "University:" << university << " ";
    std::cout << "Course:" << course << " ";
    std::cout << "Faculty:" << faculty << " ";
    std::cout << std::endl;
}

std::string Student::getType() const { return "Student"; }

std::string Student::getUniversity() const { return university; }

std::string Student::getFaculty() const { return faculty; }

int Student::getCourse() const { return course; }

bool Student::isValidCourse(int course) {
    return course >= minCourse && course <= maxCourse;
}

