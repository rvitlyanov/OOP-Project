#pragma once
#include<iostream>
#include<cstring>

using namespace std;

class Person {
	char* firstName;
	char* lastName;

	void copy(const Person&);
	void clear();
protected:
	bool isValid;
	Person();
	Person(const char*, const char*);
	Person(const Person&);
	Person& operator=(const Person&);
	~Person();

	const char* getFirstName() const;
	const char* getLastName() const;

	bool setFirstName(const char*);
	bool setLastName(const char*);
};

