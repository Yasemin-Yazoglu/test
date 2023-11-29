#include <iostream>
#include <cmath>

int main() {
	double p;
	double q;
	std::cout << "Enter values for p and q: " << std::flush;
	std::cin >> p >> q;
	
	double diskriminante;
	double x1;
	double x2;

	double zwischenergebnis = p/2;
	double quadrat = zwischenergebnis * zwischenergebnis;

	diskriminante = quadrat - q;
	x1 = -(p/2) + std::sqrt(diskriminante);
	x2 = -(p/2) - std::sqrt(diskriminante);

	if (diskriminante < 0) {
		std::cout << "Error" << std::endl;
	}
	else if (diskriminante == 0) {
		std::cout << "0" << std::endl;
	}
	else {
		std::cout << "X1 is: " << x1 << std::endl;
		std::cout << "X2 is: " << x2 << std::endl;
	}

	return 0;

}
