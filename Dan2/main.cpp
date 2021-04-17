#include <iostream>
#include <limits>
#include <string>
#include "main_menu.h"

using namespace std;

enum ChoiceTypeInput {
	CHOICE_ARRAY = 1,
	CHOICE_TESTING
};

int GetInt(void);
void Test(void);
void ArrayInterface(void);

int main() {
	Greeting();

	int choice = 0;
	string choice_repeat = "";

	do {

		do {
			ArrayOrTestingMenu();
			choice = GetInt();

			switch (choice) {
			case CHOICE_ARRAY:

				ArrayInterface();

				break;
			case CHOICE_TESTING:

				Test();

				break;
			default:
				cout << "There is no such action. Try again" << endl;
			}

		} while ( (choice != CHOICE_ARRAY) && (choice != CHOICE_TESTING) );

		do {
			EndProgramMenu();

			cin >> choice_repeat;

			if (choice_repeat.compare("n") && choice_repeat.compare("y")) {
				cout << "There is no such action." << endl;
			}

		} while (choice_repeat.compare("n") && choice_repeat.compare("y"));
	} while (choice_repeat.compare("n"));

	return 0;
}
