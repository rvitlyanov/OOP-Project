#include "Menu.h"

int getFileSize() {
	ifstream file("StudentsGrades.db");
	char buffer[512];
	int count = 0;
	while (!file.eof()) {
		file.getline(buffer, 512, '\n');
		count++;
	}
	return count - 1;
	file.close();
}

void initFile(StudentDatabase& DB) {
	int fileSize = getFileSize();
	ifstream studentsDB("StudentsGrades.db");
	if (!studentsDB.is_open()) {
		cerr << "File failed to open." << endl;
	}
	if (fileSize != 0) {
		Student s;
		for (int i = 0; i < fileSize; i++) {
			studentsDB >> s;
			DB.addStudent(s);
		}
	}
	studentsDB.close();
}
void REPL() {
	char command[17];
	bool tips = false;

	StudentDatabase localDB;
	initFile(localDB);

	cout << "Type \"tips\" to show input guide." << endl;

	while (1) {
		if (tips)
			cout << "Available commands: \"create\", \"sequentialSearch\", \"update\", \"delete\" or \"exit\". Type \"tips\" to toggle the command guide off and on." << endl;
		cin >> command;
		if (!strcmp(command, "create")) {
			if (tips)
				cout << "Please enter a new student in format: \"FN\" \"First Name\" \"Last Name\" \"Grade\"" << endl;
			Menu::create(localDB);
		}
		else if (!strcmp(command, "sequentialSearch")) {
			if (tips)
				cout << "Please enter \"FN\"" << endl;
			Menu::search(localDB);
		}
		else if (!strcmp(command, "update")) {
			if (tips)
				cout << "Please enter \"FN\" followed by the desired \"Grade\"" << endl;
			Menu::update(localDB);
		}
		else if (!strcmp(command, "delete")) {
			if (tips)
				cout << "Please enter \"FN\"" << endl;
			Menu::deleteEntry(localDB);
		}
		else if (!strcmp(command, "tips")) {
			tips = !tips;
			if (tips)
				cout << "Input guide will now be displayed." << endl;
			else
				cout << "Input guide has been turned off." << endl;
		}
		else if (!strcmp(command, "exit"))
			break;
		else {
			cin.getline(command, 256);
			cout << "Invalid command. Try \"create\", \"sequentialSearch\", \"update\", \"delete\", \"tips\" or \"exit\"." << endl;
		}
	}
}

int main() {
	REPL();		

	return 0;
}