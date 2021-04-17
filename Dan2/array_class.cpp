#include <cstdlib>
#include <iostream>
#include "array_class.h"

using namespace std;

Array::Array(int ArrSize) : size(ArrSize) {
	arr = new int[size];
}

Array::Array(int ArrSize, int *source) : size(ArrSize) {
	arr = new int[size];

	for (int i = 0; i < size; i++) {
		arr[i] = source[i];
	}

}

Array::Array(const Array& old_arr) : size(old_arr.size) {
	arr = new int[size];

	for (int i = 0; i < size; i++) {
		arr[i] = old_arr.arr[i];
	}

};

Array::Array(Array&& old_array) {
	arr = old_array.arr;
	size = old_array.size;
	old_array.arr = nullptr;
	old_array.size = 0;
}

Array::~Array() {
	delete[] arr;
}

int & Array::operator [] (int index) {
	return arr[index];
}

int Array::GetSize(void) {
	return size;
}

void Array::Sort(void) {
	int i = 0;
	int safe_arr = 0;
	int safe_size = size;

	while ((safe_size - 1) > i) {

		if (abs(arr[i]) % 2 == 1) {

			while ((abs(arr[safe_size - 1]) % 2 == 1) && ((safe_size - 1) > i)) {
				safe_size--;
			}

			if ((safe_size - 1) > i) {
				safe_arr = arr[safe_size - 1];
				arr[safe_size - 1] = arr[i];
				arr[i] = safe_arr;
			}

		}

		i++;
	}

}

void Array::Print(void) {

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
}