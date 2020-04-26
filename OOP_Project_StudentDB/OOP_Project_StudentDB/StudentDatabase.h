#pragma once
#include"Student.h"
#include<fstream>

class StudentDatabase {
	Student* studentCollection;
	int size;
	int count;

	void clear();
	void copy(const StudentDatabase&);
	void resize();
	int findFN(int);
	bool saveToFile(int);
	bool replaceFile();
public:
	StudentDatabase();
	StudentDatabase(const StudentDatabase&);
	StudentDatabase& operator=(const StudentDatabase&);
	~StudentDatabase();
	
	void setSize(int);
	void setCount(int);

	void findStudent(int);
	void updateStudent(int, int);
	void deleteStudent(int);

	void addStudent(const Student&);
	void addStudent(int, const char*, const char*, int);
};

