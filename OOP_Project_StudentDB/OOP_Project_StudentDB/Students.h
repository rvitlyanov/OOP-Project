#pragma once
#include"Student.h"
#include<fstream>

class StudentDatabase {
	Student* studentCollection;
	int size;
	int count;

	void clear();
	void copy(const StudentDatabase& other);
	void resize();
	int findFN(int fn);
	bool saveToFile(int n);
	bool replaceFile();
public:
	StudentDatabase();
	StudentDatabase(const StudentDatabase& other);
	StudentDatabase& operator=(const StudentDatabase& other);
	~StudentDatabase();
	
	void setSize(int size);
	void setCount(int count);

	void findStudent(int n);
	void updateStudent(int fn, int grade);
	void deleteStudent(int fn);

	void addStudent(const Student& other);
	void addStudent(int fn, const char* firstName, const char* lastName, int grade);
};

