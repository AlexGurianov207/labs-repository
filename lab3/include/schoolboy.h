#ifndef SCHOOLBOY_H
#define SCHOOLBOY_H

#include "learner.h"

class Schoolboy : public Learner {
 private:
  std::string schoolName;
  int grade;

 public:
  Schoolboy();
  Schoolboy(const std::string& newName, int newAge,
            const std::string& newSchoolName, int newGrade);

  void display() const override;
  std::string getType() const override;
};

#endif
