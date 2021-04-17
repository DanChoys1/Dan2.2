#pragma once
class Array final {
	int size;
	int *arr = nullptr;
public:
	explicit Array(int ArrSize);

	Array(int ArrSize, int *source);

	Array(const Array& old_arr);

	Array(Array&& old_array);

	~Array();

	int & operator [] (int index);

	int GetSize(void);

	void Sort(void);

	void Print(void);

};