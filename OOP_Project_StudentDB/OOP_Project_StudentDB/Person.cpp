#include "Person.h"

void Person::copy(const Person& other) {
	isValid = other.isValid;
	int fLen = strlen(other.firstName);
	int lLen = strlen(other.lastName);
	firstName = new char[fLen + 1];
	lastName = new char[lLen + 1];
	strcpy_s(this->firstName, fLen + 1, other.firstName);
	strcpy_s(this->lastName, lLen + 1, other.lastName);
}

void Person::clear() {
		delete[] firstName;
		delete[] lastName;
}

Person::Person() {
	isValid = 1;
	firstName = new char[8];
	strcpy_s(firstName, 8, "Default");
	lastName = new char[8];
	strcpy_s(lastName, 8, "Student");
}

Person::Person(const char* name, const char* lastName) {
	isValid = (setFirstName(name) && setLastName(lastName));
}

Person::Person(const Person& other) {
	copy(other);
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return*this;
}

Person::~Person() {
	clear();
}

const char* Person::getFirstName() const {
	return firstName;
}

const char* Person::getLastName() const {
	return lastName;
}

bool Person::setLastName(const char* name)
{
	int len = strlen(name);
	if (len == 0) {
		cout << "First name is required!" << endl;
		delete[] lastName;
		lastName = new char[8];
		strcpy_s(lastName, 8, "Default");
		return 0;
	}
	else {
		delete[] lastName;
		lastName = new char[len + 1];
		strcpy_s(lastName, len + 1, name);
		return 1;
	}
}

bool Person::setFirstName(const char* name) {
	int len = strlen(name);
	if (len == 0) {
		cout << "First name is required!" << endl;
		delete[] firstName;
		firstName = new char[8];
		strcpy_s(firstName, 8, "Default");
		return 0;
	}
	else {
		delete[] firstName;
		firstName = new char[len + 1];
		strcpy_s(firstName, len + 1, name);
		return 1;
	}
}
