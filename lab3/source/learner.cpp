#include "learner.h"

Learner::Learner(const std::string& newName, int newAge)
    : name(newName), age(newAge) {}

Learner::Learner() : name("Undefined"), age(defaultAge) {}

void Learner::display() const {
  std::cout << "Name:" << name << " ";
  std::cout << "Age:" << age << " ";
}

std::string Learner::getType() const { return "Learner"; }

std::string Learner::getName() const { return name; }

int Learner::getAge() const { return age; }

bool Learner::isValidAge(int age) { return age >= minAge && age <= maxAge; }
