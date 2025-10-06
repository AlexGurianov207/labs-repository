#include "learner.h"

Learner::Learner(const std::string& newName, int newAge)
    : name(newName), age(newAge) {}

Learner::Learner() : name("Undefined"), age(defaultAge) {}

std::string Learner::getName() const { return name; }

int Learner::getAge() const { return age; }

bool Learner::isValidAge(int age) { return age >= minAge && age <= maxAge; }
