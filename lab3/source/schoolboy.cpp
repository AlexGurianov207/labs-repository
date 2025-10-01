#include"schoolboy.h"

Schoolboy::Schoolboy():Learner(),schoolName("Undefined"),grade(11){}

Schoolboy::Schoolboy(const std::string& newName, int newAge,
    const std::string& newSchoolName, int newGrade):Learner(newName,newAge),schoolName(newSchoolName),grade(newGrade){}

void Schoolboy::display() const {
    Learner::display();
    std::cout << "School:" << schoolName << " ";
    std::cout << "Grade:" << grade << " ";
    std::cout << std::endl;
}

std::string Schoolboy::getType() const {
    return "Schoolboy";
}