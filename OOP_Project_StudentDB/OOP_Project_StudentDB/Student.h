#pragma once
#include "Person.h"

using namespace std;

class Student : private Person {
	int fn;
	int grade;

public:
	Student();
	Student(int, const char*, const char*, int);
	Student(const Student&);

	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);

	int getFN() const;
	int getGrade() const;
	bool getIsValid() const;
	const char* getFirstName() const;
	const char* getLastName() const;

	void setFN(int);
	void setFirstName(const char*);
	void setLastName(const char*);
	void setGrade(int);

	void printStudent();
};

