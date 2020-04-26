#include "Student.h"

Student::Student() : Person() {
	fn = 0;
	grade = 2;
}

Student::Student(int fn, const char* fName, const char* lName, int grade) : Person(fName, lName) {
	setFN(fn);
	setGrade(grade);
}

Student::Student(const Student& other) : Person(other){
	fn = other.fn;
	grade = other.grade;
}

int Student::getFN() const {
	return fn;
}
int Student::getGrade() const {
	return grade;
}
bool Student::getIsValid() const {
	return isValid;
}
const char* Student::getFirstName() const {
	return Person::getFirstName();
}
const char* Student::getLastName() const {
	return Person::getLastName();
}

void Student::setFN(int fn) {
	if (fn < 1 || fn > 99999) {
		fn = 0;
		cout << "Invalid faculty number! ";
		isValid = 0;
	}
	this->fn = fn;
}
void Student::setFirstName(const char* name) {
	if(!Person::setFirstName(name)) 
		isValid = 0;
}
void Student::setLastName(const char* lName) {
	if (!Person::setLastName(lName))
		isValid = 0;
}
void Student::setGrade(int grade) {
	if (grade < 2 || grade > 6) {
		cout << "Invalid grade! " << endl;
		grade = 2;
		isValid = 0;
	}
	this->grade = grade;
}

void Student::printStudent() {
	cout << *this;
}

ostream& operator<<(ostream& os, const Student& s)
{
	os << s.getFN() << " " << s.getFirstName() << " " << s.getLastName() << " " << s.getGrade() << '\n';
	return os;
}
istream& operator>>(istream& is, Student& s) {
	int fn;
	int grade;
	char* fName = new char[128];
	char* lName = new char[128];
	is >> fn >> fName >> lName >> grade;
	s.setFN(fn);
	s.setGrade(grade);
	s.setFirstName(fName);
	s.setLastName(lName);
	delete[]fName;
	delete[]lName;
	return is;
}