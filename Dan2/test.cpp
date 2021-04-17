#include <iostream>
#include "array_class.h"

using namespace std;

const int all_test_passed = 5;

bool Test1(void) {
	int entered_data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Array entered_arr(10, entered_data);
	int expected_result[] = {10, 2, 8, 4, 6, 5, 7, 3, 9, 1};
	Array expected_arr_change(entered_arr.GetSize(), expected_result);

	Array changed_arr(entered_arr.GetSize(), entered_data);
	changed_arr.Sort();

	try {
		for (int i = 0; i < entered_arr.GetSize(); i++) {
			if (changed_arr[i] != expected_arr_change[i]) throw i;
		}

		return true;

	} catch(int number_value) {
		cout << endl <<  "Test1 failed. Mismatch found in " << number_value << " item" << endl;
		cout << "Input array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << entered_arr[i] << " ";
		}

		cout << endl << "Expected output array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << expected_arr_change[i] << " ";
		}

		cout << endl << "Output array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << changed_arr[i] << " ";
		}

		return false;
	}
}

bool Test2(void) {
	int entered_data[] = { 3, 45, -53, -36, 35, 47, 75, -77, 35, 61 };
	Array entered_arr(10, entered_data);
	int expected_result[] = { -36, 45, -53, 3, 35, 47, 75, -77, 35, 61 };
	Array expected_arr_change(entered_arr.GetSize(), expected_result);

	Array changed_arr(entered_arr.GetSize(), entered_data);
	changed_arr.Sort();

	try {
		for (int i = 0; i < entered_arr.GetSize(); i++) {
			if (changed_arr[i] != expected_arr_change[i]) throw i;
		}

		return true;

	} catch (int number_value) {
		cout << endl << "Test2 failed. Mismatch found in " << number_value << " item" << endl;
		cout << "Input array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << entered_arr[i] << " ";
		}

		cout << endl << "Expected output array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << expected_arr_change[i] << " ";
		}

		cout << endl << "Output array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << changed_arr[i] << " ";
		}

		return false;
	}
}

bool Test3(void) {
	int entered_data[] = { 8, 7, 2, -1, 7, 4, -3, 5, -9, -9 };
	Array entered_arr(10, entered_data);
	int expected_result[] = { 8, 4, 2, -1, 7, 7, -3, 5, -9, -9 };
	Array expected_arr_change(entered_arr.GetSize(), expected_result);

	Array changed_arr(entered_arr.GetSize(), entered_data);
	changed_arr.Sort();

	try {
		for (int i = 0; i < entered_arr.GetSize(); i++) {
			if (changed_arr[i] != expected_arr_change[i]) throw i;
		}

		return true;

	} catch (int number_value) {
		cout << endl << "Test3 failed. Mismatch found in " << number_value << " item" << endl;
		cout << "Input array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << entered_arr[i] << " ";
		}

		cout << endl << "Expected output array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << expected_arr_change[i] << " ";
		}

		cout << endl << "Output array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << changed_arr[i] << " ";
		}

		return false;
	}
}

bool Test4(void) {
	int entered_data[] = { -12, 11, -2, -8, 2, -11, -16, -15, 19, 16, 14, -5, 3, 0, 0, 0, 0, 7, 10, -18 };
	Array entered_arr(20, entered_data);

	int expected_result[] = { -12, -18, -2, -8, 2, 10, -16, 0, 0, 16, 14, 0, 0, 3, -5, 19, -15, 7, -11, 11 };
	Array expected_arr_change(entered_arr.GetSize(), expected_result);

	Array changed_arr(entered_arr.GetSize(), entered_data);
	changed_arr.Sort();

	try {
		for (int i = 0; i < entered_arr.GetSize(); i++) {
			if (changed_arr[i] != expected_arr_change[i]) throw i;
		}

		return true;

	} catch (int number_value) {
		cout << endl << "Test4 failed. Mismatch found in " << number_value << " item" << endl;
		cout << "Input array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << entered_arr[i] << " ";
		}

		cout << endl << "Expected output array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << expected_arr_change[i] << " ";
		}

		cout << endl << "Output array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << changed_arr[i] << " ";
		}

		return false;
	}
}

bool Test5(void) {
	int entered_data[] = { 8, -2, 6, 8, -3 };
	Array entered_arr(5, entered_data);
	int expected_result[] = { 8, -2, 6, 8, -3 };
	Array expected_arr_change(entered_arr.GetSize(), expected_result);

	Array changed_arr(entered_arr.GetSize(), entered_data);
	changed_arr.Sort();

	try {
		for (int i = 0; i < entered_arr.GetSize(); i++) {
			if (changed_arr[i] != expected_arr_change[i]) throw i;
		}

		return true;

	} catch (int number_value) {
		cout << endl << "Test5 failed. Mismatch found in " << number_value << " item" << endl;
		cout << "Input array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << entered_arr[i] << " ";
		}

		cout << endl << "Expected output array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << expected_arr_change[i] << " ";
		}

		cout << endl << "Output array:" << endl;

		for (int i = 0; i < entered_arr.GetSize(); i++) {
			cout << changed_arr[i] << " ";
		}

		return false;
	}
}

void Test(void) {
	int value_test_passed = 0;

	if (Test1() == true) {
		value_test_passed++;
	}

	if (Test2() == true) {
		value_test_passed++;
	}

	if (Test3() == true) {
		value_test_passed++;
	}

	if (Test4() == true) {
		value_test_passed++;
	}

	if (Test5() == true) {
		value_test_passed++;
	}

	if (value_test_passed == all_test_passed) {
		cout << endl << "All test passed" << endl;
	}

}
