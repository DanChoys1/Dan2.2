#include <Windows.h>
#undef max
#include <iostream>
#include "input.h"
#include "save_data.h"

using namespace std;

Input *ChoiceInputType(bool *user_selected_file_input);

void ArrayInterface(void) {
	bool user_selected_file_input = false;

	Input* inp = ChoiceInputType(&user_selected_file_input);

	Array arr = inp->Read();

	delete inp;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 4));
	cout << endl << "Input value" << endl;
	arr.Print();

	Array saved_arr = arr;

	arr.Sort();

	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 2));
	cout << "Sorted value" << endl;
	arr.Print();
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));

	if (user_selected_file_input != true) {
		SaveInputArray(move(saved_arr));
	}

	SaveChangeArray(move(arr));
}
