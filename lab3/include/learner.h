#ifndef LEARNER_H
#define LEARNER_H

#include<iostream>
#include<string>

class Learner {
protected:
	std::string name;
	int age;
public:
	Learner(const std::string& name, int age);
	Learner();

	virtual void display() const;
	virtual std::string getType() const;

	virtual ~Learner() = default;

};

#endif