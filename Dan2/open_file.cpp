#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;

enum Opening {
	FAILED,
	COMPLITE
};

ofstream OpenFileOutput(void) {
	string path = "";
	bool file_open_complit = false;
	ofstream file;
	error_code ec;

	do {
		cout << "Enter the path to the file" << endl;
		cin >> path;

		if (ifstream(path)) {

			if (!filesystem::is_regular_file(path, ec)) {
				cout << "The file could not be opened. Try again." << endl;
				continue;
			}

			cout << "This file exists. Do you want overwrite a file?" << endl;
			string choice;

			do {
				cout << "y - Yes" << endl
					<< "n - No" << endl
					<< "Choice: ";

				cin >> choice;

				if (choice.compare("n") && choice.compare("y")) {
					cout << "There is no such action." << endl
						<< "Do you want overwrite a file?" << endl;
				}

			} while (choice.compare("n") && choice.compare("y"));

			if (!choice.compare("n")) {
				continue;
			}

		}

		file.open(path);

		if (!filesystem::is_regular_file(path, ec)) {
			cout << "The file could not be opened. Try again." << endl;
			continue;
		}

		if (!file.is_open()) {
			cout << "The file could not be opened. Try again." << endl;
			continue;
		}

		file_open_complit = true;
	} while (!file_open_complit);

	return file;
}

ifstream OpenFileInput(void) {

	cout << "Enter the path to the file" << endl;
	string path;
	int opening_file = 0;
	error_code ec;
	ifstream file;

	do {

		do {
			cin >> path;

			if (!filesystem::is_regular_file(path, ec)) {
				cout << "The file could not be opened." << endl
					<< "Enter a different name or path to the file: ";
			}

		} while (!filesystem::is_regular_file(path, ec));

		file.open(path);

		if (file.is_open()) {

			opening_file = COMPLITE;

		} else {

			cout << "The file could not be opened." << endl
				<< "Enter a different name or path to the file: ";

			opening_file = FAILED;

		}

	} while (opening_file == FAILED);

	return file;
}
