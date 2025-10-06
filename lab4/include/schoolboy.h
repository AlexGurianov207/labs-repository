#ifndef SCHOOLBOY_H
#define SCHOOLBOY_H

#include "learner.h"

class Schoolboy : public Learner {
private:
    std::string schoolName;
    int grade;

    static constexpr int minGrade = 1;
    static constexpr int maxGrade = 11;
    static constexpr int defaultGrade = 1;

public:
    Schoolboy();
    Schoolboy(const std::string& newName, int newAge,
        const std::string& newSchoolName, int newGrade);

    std::string getSchoolName() const;
    int getGrade() const;
    void display() const override;
    std::string getType() const override;

    static bool isValidGrade(int grade);
    static int getMinGrade() { return minGrade; }
    static int getMaxGrade() { return maxGrade; }
};

#endif
