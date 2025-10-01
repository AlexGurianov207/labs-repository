#ifndef STUDENT_H
#define STUDENT_H

#include"learner.h"

class Student :public Learner {
private:
	std::string university;
	std::string faculty;
	int course;
public:
	Student();
	Student(const std::string& newName, int age, const std::string& newUniversity, const std::string& newFaculty, int course);

	void display() const override;
	std::string getType() const override;
};

#endif