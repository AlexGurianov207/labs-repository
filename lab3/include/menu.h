#ifndef MENU_H
#define MENU_H

#include"learner.h"
#include"student.h"
#include"schoolboy.h"

void showMenu();

void deleteData(Learner**& learners, int& count);

void viewSeparately(Learner** learners, int count);

void viewLearners(Learner** learners, int count);

void createTestData(Learner**& learners, int& count);

Learner** addLearner(Learner** learners, int& count, Learner* newLearner);

void addNewLearner(Learner**& learners, int& count);

#endif