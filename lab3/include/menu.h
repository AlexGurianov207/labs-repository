#ifndef MENU_H
#define MENU_H

#include "learner.h"
#include "schoolboy.h"
#include "student.h"

void showMenu();

void deleteData(Learner**& learners, int& count);

void viewSeparately(std::span<Learner*> learners);

void viewLearners(std::span<Learner*> learners);

void createTestData(Learner**& learners, int& count);

Learner** addLearner(Learner** learners, int& count, Learner* newLearner);

void addNewLearner(Learner**& learners, int& count);

#endif
