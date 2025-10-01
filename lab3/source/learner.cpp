#include "learner.h"

Learner::Learner(const std::string& newName, int newAge)
    : name(newName), age(newAge) {}

Learner::Learner() : name("Undefined"), age(18) {}

void Learner::display() const {
    std::cout << "Name:" << name << " ";
    std::cout << "Age:" << age << " ";
}

std::string Learner::getType() const {
    return "Learner";
}