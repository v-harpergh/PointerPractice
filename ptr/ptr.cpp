#include <iostream>

#include <vector>

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

constexpr size_t getStringSize(const char* str) {
	size_t size = 0;

	while (*(str + size) != '\0') {
		++size;
	}

	return size;
}

void printReverseString(const char* str) {
	const size_t size = getStringSize(str);

	for (int64_t i = size - 1; i >= 0; --i) {
		std::cout << *(str + i);
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

	constexpr int max_index = getMax(numbers, sizeof(numbers) / sizeof(int));
	// You can even hover over it and VS already knows the index

	if constexpr (max_index < 0)
	{
		std::cout << "Error, index is <0\n";
		__fastfail(82);
	}
	else {
		const int* max_ptr = numbers + max_index;

		std::cout << "max value: " << *max_ptr << "\n";
	}

}

void LengthOf_C_String() {
	constexpr char str[] = "Hey";

	const char* ptr = str;
	const size_t len = getStringSize(ptr);

	std::cout << "Size of 'Hey': " << len << "\n";
}

void Reverse_C_String() {
	constexpr char name[] = "Victor";

	const char* ptr = name;
	printReverseString(ptr);
}

void MidpointInVector() {
	const std::vector<int> numbers = { 7, 2, 3, 1, 9, 7, 2};

	if (numbers.size() == 0) {
		std::cout << "No midpoint, vector size is zero\n";
		return;
	} else if (numbers.size() == 1) {
		std::cout << "Mid point is idx [0], and is " << *numbers.data() << "\n";
		return;
	}

	const int* begin_ptr = numbers.data();
	const int* end_ptr = numbers.data() + numbers.size() - 1;

	for (size_t i = 0; i < numbers.size(); ++i) {
		--end_ptr;

		if (begin_ptr == end_ptr) {
			std::cout << "Is even, midpoint is [" << i << "], " << *begin_ptr << "\n";
			break;
		}

		++begin_ptr;

		if (begin_ptr == end_ptr) {
			std::cout << "Mid point is idx [" << i + 1 << "], and is " << *begin_ptr << "\n"; 
			break;
		}
	}
	
}

int main()
{
	//AssignmentAndDeferefencing();
	//MaximumInAnArray();
	//LengthOf_C_String();
	//Reverse_C_String();
	MidpointInVector();
}