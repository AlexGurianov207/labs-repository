#include"student.h"

Student::Student():Learner(), university("Undefined"), faculty("Undefined"), course(1) {}

Student::Student(const std::string& newName, int newAge, const std::string& newUniversity, const std::string& newFaculty, int newCourse):
	Learner(newName,newAge),university(newUniversity),faculty(newFaculty),course(newCourse){}

void Student::display() const {
	Learner::display();
	std::cout << "University:" << university << " ";
	std::cout << "Course:" << course << " ";
	std::cout << "Faculty:" << faculty << " ";
	std::cout << std::endl;
}

std::string Student::getType() const {
	return "Student";
}