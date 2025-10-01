#ifndef LEARNER_H
#define LEARNER_H

#include<iostream>
#include<string>

class Learner {
private:
	std::string name;
	int age;
public:
	Learner(const std::string& name, int age);
	Learner();

	std::string getName()const;
	int getAge()const;
	virtual void display() const;
	virtual std::string getType() const;

	virtual ~Learner() = default;

};

#endif