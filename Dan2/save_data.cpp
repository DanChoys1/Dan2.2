#include <iostream>
#include <fstream>
#include <string>
#include "open_file.h"
#include "array_class.h"

using namespace std;

void SaveInputArray(Array arr) {
	cout << endl << "Do you want to save the initial data in the file?" << endl
		<< "Initial data: " << endl;
		
	for (int i = 0; i < arr.GetSize(); i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	string choice = "";
	
	do {
		cout << "y - Yes" << endl
			<< "n - No" << endl
			<< "Choice: ";

		cin >> choice;

		if (choice.compare("n") && choice.compare("y")) {
			cout << "There is no such action." << endl
				<< "Do you still want to save the initial data in the file?" << endl;
		}

	} while (choice.compare("n") && choice.compare("y"));

	if (choice.compare("n")) {
		ofstream file = OpenFileOutput();

		file << arr.GetSize() << endl;

		for (int i = 0; i < arr.GetSize(); i++) {
			file << arr[i] << endl;
		}

		file.close();
	}

};

void SaveChangeArray(Array arr) {
	cout << endl << "Do you want to save the result of the program?" << endl;

	for (int i = 0; i < arr.GetSize(); i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	string choice = "";

	do {
		cout << "y - Yes" << endl
			<< "n - No" << endl
			<< "Choice: ";

		cin >> choice;

		if (choice.compare("n") && choice.compare("y")) {
			cout << "There is no such action." << endl
				<< "Do you still want to save the initial data in the file?" << endl;
		}

	} while (choice.compare("n") && choice.compare("y"));

	if (choice.compare("n")) {
		ofstream file;
		file = OpenFileOutput();

		for (int i = 0; i < arr.GetSize(); i++) {
			file << arr[i] << endl;
		}

		file.close();
	}

}