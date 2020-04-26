#pragma once
#include "StudentDatabase.h"

class Menu { 
public:
	static void create(StudentDatabase& localDB){
		int fn, grade;
		char firstName[128];
		char lastName[128];
		cin >> fn >> firstName >> lastName >> grade;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Not a number." << endl;
			return;
		}
		localDB.addStudent(fn, firstName, lastName, grade);
	}
	static void search(StudentDatabase& localDB) {
		int n;
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Not a number." << endl;
			return;
		}
		localDB.findStudent(n);
	}
	static void update(StudentDatabase& localDB) {
		int fn, grade;
		cin >> fn >> grade;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Not a number." << endl;
			return;
		}
		localDB.updateStudent(fn, grade);
	}
	static void deleteEntry(StudentDatabase& localDB) {
		int fn;
		cin >> fn;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "Not a number." << endl;
			return;
		}
		localDB.deleteStudent(fn);
	}
private:
	Menu() {};
};
