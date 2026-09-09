#include <iostream>

int64_t getInput() {
	int64_t input;

	std::cout << "Enter an integer:";
	std::cin >> input;

	if (std::cin.fail())
		__fastfail(23);

	return input;
}

int main()
{
	int64_t a = getInput();
	int64_t b = getInput();

	int64_t* ptr_a = &a;
	int64_t* ptr_b = &b;


}