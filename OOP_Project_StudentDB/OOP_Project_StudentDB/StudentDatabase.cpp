#include "StudentDatabase.h"

void StudentDatabase::clear() {
	delete[]studentCollection;
}
void StudentDatabase::copy(const StudentDatabase& other) {
	setSize(size);
	setCount(count);
	studentCollection = new Student[size];
	for (int i = 0; i < count; i++)
		studentCollection[i] = other.studentCollection[i];
}
void StudentDatabase::resize() {
	Student* temp = new Student[size * 2];
	size *= 2;
	for (int i = 0; i < count; i++) {
		temp[i] = studentCollection[i];
	}
	delete[]studentCollection;
	studentCollection = temp;
}

bool StudentDatabase::saveToFile(int n) {
	ofstream file("StudentsGrades.db", ios::app);
	if (!file.is_open()) {
		cerr << "File failed to open. " << endl;
		return 0;
	}
	file << studentCollection[n];
	file.close();
	return 1;
}
bool StudentDatabase::replaceFile() {
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

StudentDatabase::StudentDatabase(){
	size = 4;
	count = 0;
	studentCollection = new Student[size];
}
StudentDatabase::StudentDatabase(const StudentDatabase& other) {
	copy(other);
}
StudentDatabase& StudentDatabase::operator=(const StudentDatabase& other) {
	if (this != &other) {
		clear();
		copy(other);
	}
	return*this;
}
StudentDatabase::~StudentDatabase() {
	clear();
}

void StudentDatabase::setSize(int size) {
	if (size < 1)
		size = 1;
	this->size = size;
}
void StudentDatabase::setCount(int count) {
	if (count > size)
		count = 0;
	this->count = count;
}

void StudentDatabase::findStudent(int n) {
	int student = findFN(n);
	if (student != -1) {
		studentCollection[student].printStudent();
	}
}

void StudentDatabase::updateStudent(int fn, int grade) {
	int student = findFN(fn);
	if (student != -1) {
		studentCollection[student].setGrade(grade);
		if (studentCollection[student].getIsValid()) {
			if (replaceFile())
				cout << "Record saved!" << endl;
		}
	}
	else
		cout << "Record not found!" << endl;
}

void StudentDatabase::deleteStudent(int fn) {
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

void StudentDatabase::addStudent(const Student& other) {
	if (count == size)
		resize();
	studentCollection[count] = other;
	count++;
}
void StudentDatabase::addStudent(int fn, const char* firstName, const char* lastName, int grade) {
	for (int i = 0; i < count; i++) {
		if (studentCollection[i].getFN() == fn) {
			cerr << "A record with this faculty number exists. Try with action \"update\"." << endl;
			return;
		}
	}
	if (count == size)
		resize();

	Student s(fn, firstName, lastName, grade);
	studentCollection[count] = s;

	if (studentCollection[count].getIsValid()) {
		if (saveToFile(count)) {
			count++;
			cout << "Record saved!" << endl;
		}
		else
			cout << "Please try again!" << endl;
	}
}

int StudentDatabase::findFN(int fn) {
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
