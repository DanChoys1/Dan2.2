#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "array_class.h"
#include "open_file.h"
#include "input.h"

using namespace std;

enum ChoiceTypeInput {
	CHOICE_KEYBOARD = 1,
	CHOICE_FILE,
	CHOICE_RANDOM,
};

enum Opening {
	FAILED,
	COMPLITE
};

int GetInt(void);
void ValueInputMenu(void);

Array KeyboardInput::Read() {
	int size = 0;

	do {
		cout << endl << "Enter the size of the array: ";
		size = GetInt();

		if (size <= 0) {
			cout << endl << "Size must be > 0. Try again." << endl;
		}

	} while (size <= 0);

	Array arr(size);

	for (int i = 0; i < size; i++) {
		cout << i + 1 << ")";
		arr[i] = GetInt();
	}

	return arr;
}

Array FileInput::Read() {
	while (true) {
		cout << endl << "Input data." << endl;
		ifstream file = OpenFileInput();

		try {
			string size_in_file;

			getline(file, size_in_file);
			int size = stoi(size_in_file);

			if (size <= 0) {
				cout << endl << "Size in file must be > 0. Try again." << endl;
				continue;
			}

			Array arr(size);

			string value;

			for (int i = 0; i < size; i++) {
				getline(file, value);
				arr[i] = stoi(value);
			}

			cout << "Input size = " << size;

			file.close();

			return arr;
		} catch (invalid_argument inv_arg) {
			cout << endl << "The values in the file are not correct. Try again" << endl;
			file.close();
		}

	}

}

Array RandomInput::Read() {
	int size = 0;

	do {
		cout << endl << "Enter the size of the array: ";
		size = GetInt();

		if (size <= 0) {
			cout << endl << "Size must be > 0. Try again." << endl;
		}

	} while (size <= 0);

	Array arr(size);

	srand((unsigned int)time(NULL));
	int random_limits = 0;

	do {
		cout << endl << "Random numbers in a range (-a, a)" << endl
			<< "Enter a: ";
		random_limits = GetInt();

		if (random_limits <= 0) {
			cout << endl << "a must be > 0. Try again." << endl;
		}

	} while (random_limits <= 0);

	for (int i = 0; i < size; i++) {

		if (rand() % 2) {
			arr[i] = rand() % random_limits;
		} else {
			arr[i] = -1 * (rand() % random_limits);
		}

	}

	return arr;
}

Input *ChoiceInputType(bool *user_selected_file_input) {
	int choice = 0;

	do {
		ValueInputMenu();
		choice = GetInt();

		if (choice == CHOICE_KEYBOARD) {

			KeyboardInput *keyboard_iput = new KeyboardInput;
			return keyboard_iput;

		} else if (choice == CHOICE_FILE) {

			*user_selected_file_input = true;
			FileInput *file_input = new FileInput;
			return file_input;

		} else if (choice == CHOICE_RANDOM) {

			RandomInput *random_input = new RandomInput;
			return random_input;

		} else {

			cout << "There is no such action" << endl;

		}

	} while ((choice != CHOICE_KEYBOARD) && (choice != CHOICE_FILE)
		&& (choice != CHOICE_RANDOM));
}
