#include <iostream>

int64_t getInput() {
	int64_t input;

	std::cout << "Enter an integer: ";
	std::cin >> input;

	if (std::cin.fail())
		__fastfail(23);

	return input;
}

constexpr int getMax(const int* arr, int size) {
	int max = INT_MIN;
	int index = -1;

	for (int i = 0; i < size; ++i) {
		if (*(arr + i) > max) {
			max = *(arr + i);
			index = i;
		}
	}

	return index;
}

consteval size_t getStringSize(const char* str) {
	size_t size = 0;

	while (*(str + size) != '\0') {
		++size;
	}

	return size;
}

consteval const char* reverseString(const char* str) {
	size_t size = getStringSize(str);

	for (int i = size - 1; i >= 0) {

	}
}

/*
	The functions below are for the assignment exercises
*/

void AssignmentAndDeferefencing() {
	const int64_t a = getInput();
	const int64_t b = getInput();

	const int64_t* ptr_a = &a;
	const int64_t* ptr_b = &b;

	std::cout << *ptr_a << "\n";
	std::cout << *ptr_b << "\n";
}

void MaximumInAnArray() {
	constexpr int numbers[] = { 8, 2, 5, 9, 1, 5 };

	const int max_index = getMax(numbers, sizeof(numbers) / sizeof(int));
	// You can even hover over it and VS already knows the index

	if constexpr (max_index < 0)
	{
		std::cout << "Error, index is <0\n";
		__fastfail(82);
	}
	else {
		const int* max_ptr = &numbers[max_index];

		std::cout << "max value: " << *max_ptr << "\n";
	}

}

void LengthOf_C_String() {
	constexpr size_t len = getStringSize("Hey");

	std::cout << "Size of 'Hey': " << len << "\n";
}

void Reverse_C_String() {
	constexpr const char* name = "Victor";

}

int main()
{
	//AssignmentAndDeferefencing();
	//MaximumInAnArray();
	//LengthOf_C_String();
	Reverse_C_String();
}