#include <iostream>
#include <cmath>

bool isEven (unsigned int number) {
	if (number % 2 == 0){
		return 1;
	}
	else {
		return 0;
	}
}

void collatz (unsigned int number) {
	while (number >= 0) {
		std::cout << number << std::endl;
		if (isEven(number) == true) {
			number = number / 2;
		}
		else {
			number = number * 3 + 1;
		}

		if (number == 1 || number == 0) {
			break;
		}
	}

	std::cout << number << std::endl;
}

int main() {
	unsigned int myNumber;
	std::cout << "Enter a number: " << std::flush;
	std::cin >> myNumber;

	collatz(myNumber);

	return 0;	
}

