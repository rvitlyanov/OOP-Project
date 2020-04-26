#include "Students.h"

void Students::clear() {
	delete[]studentCollection;
}
void Students::copy(const Students& other) {
	setSize(size);
	setCount(count);
	studentCollection = new Student[size];
	for (int i = 0; i < count; i++)
		studentCollection[i] = other.studentCollection[i];
}
void Students::resize() {
	Student* temp = new Student[size * 2];
	size *= 2;
	for (int i = 0; i < count; i++) {
		temp[i] = studentCollection[i];
	}
	delete[]studentCollection;
	studentCollection = temp;
}

bool Students::saveToFile(int n) {
	ofstream file("StudentsGrades.db", ios::app);
	if (!file.is_open()) {
		cerr << "File failed to open. " << endl;
		return 0;
	}
	file << studentCollection[n];
	file.close();
	return 1;
}
bool Students::replaceFile() {
	ofstream file("StudentsGrades.db", ios::trunc);
	if (!file.is_open()) {
		cerr << "File failed to open." << endl;
		return 0;
	}
	for (int i = 0; i < count; i++)
		file << studentCollection[i];
	file.close();
	return 1;
}

Students::Students(){
	size = 4;
	count = 0;
	studentCollection = new Student[size];
}
Students::Students(const Students& other) {
	copy(other);
}
Students& Students::operator=(const Students& other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return*this;
}
Students::~Students() {
	clear();
}

void Students::setSize(int size) {
	if (size < 1)
		size = 1;
	this->size = size;
}
void Students::setCount(int count) {
	if (count > size)
		count = 0;
	this->count = count;
}

void Students::findStudent(int n) {
	int student = findFN(n);
	if (student != -1) {
		studentCollection[student].printStudent();
	}
}

void Students::updateStudent(int fn, int grade) {
	int student = findFN(fn);
	if (student != -1) {
		studentCollection[student].setGrade(grade);
	}
	if (studentCollection[student].getIsValid()) {
		if (replaceFile())
			cout << "Record saved!";
	}
}

void Students::deleteStudent(int fn) {
	int record = findFN(fn);
	if (record != -1) {
		for (int i = record; i < count; i++) {
			studentCollection[i] = studentCollection[i + 1];
		}
		count--;
	}
	if (replaceFile()) {
		cout << "Record deleted!" << endl;
	}
}

void Students::addStudent(const Student& other) {
	if (count == size)
		resize();
	studentCollection[count] = other;
	count++;
}
void Students::addStudent(int fn, const char* firstName, const char* lastName, int grade) {
	for (int i = 0; i < count; i++) {
		if (studentCollection[i].getFN() == fn) {
			cerr << "A record with this faculty number exists. Try with action \"update\"." << endl;
			return;
		}
	}
	if (count == size)
		resize();
	studentCollection[count].setFN(fn);
	studentCollection[count].setFirstName(firstName);
	studentCollection[count].setLastName(lastName);
	studentCollection[count].setGrade(grade);

	if (studentCollection[count].getIsValid()) {
		if (saveToFile(count)) {
			count++;
			cout << "Record saved!" << endl;
		}
		else
			cout << "Please try again!" << endl;
	}
}

int Students::findFN(int fn) {
	int location = -1;
	for (int i = 0; i < count; i++) {
		if (studentCollection[i].getFN() == fn) {
			location = i;
			break;
		}
	}
	if (location == -1) {
		cout << "Record not found!" << endl;
	}
	return location;
}
