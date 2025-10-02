#ifndef LEARNER_H
#define LEARNER_H

#include <iostream>
#include <span>
#include <string>

class Learner {
 private:
  static constexpr int minAge = 5;
  static constexpr int maxAge = 80;
  static constexpr int defaultAge = 0;

  std::string name;
  int age;

 public:
  Learner(const std::string& name, int age);
  Learner();

  std::string getName() const;
  int getAge() const;
  virtual void display() const;
  virtual std::string getType() const;

  static bool isValidAge(int age);
  static int getMinAge() { return minAge; }
  static int getMaxAge() { return maxAge; }

  virtual ~Learner() = default;
};

#endif
