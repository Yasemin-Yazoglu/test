#include <iostream>

unsigned int fib (unsigned int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

unsigned int fibIter(unsigned int n) {
	unsigned int result;
	unsigned int prev = 0;
	unsigned int next = 1;

	if (n == 0)
		result = 0;
	else if (n == 1)
		result = 1;

	for (int i = 2; i <= n; i++) {
		result = prev + next;
		prev = next;
		next = result;
	}

	return result;
}



int main() {	
	unsigned int num;
	std::cout << "Enter number n: " << std::endl;
	std::cin >> num;

	std::cout << fib(num) << std::endl;
	std::cout << fibIter(num) << std::endl;

	return 0;
}

