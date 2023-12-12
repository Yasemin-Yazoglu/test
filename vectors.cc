#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

void print (std::vector<double>& vector) {
	int n = vector.size();

	if (n == 0) {
		std::cout << "[]" << std::endl;
	}
	else {
		std::cout << "[" << std::flush;
		for (int i = 0; i < n - 1; i++) {
			std::cout << vector[i] << ", ";
		}
		std::cout << vector[n-1] << "]" << std::endl;
	}
}

struct myclass {
	bool operator() (double i,double j) { return (i<j);}
} myobject;

std::vector<double> sort(std::vector<double>& vector) {
	std::sort(vector.begin(), vector.end(), myobject);
	return vector;
}

double median (std::vector<double> vector) {
	int n = vector.size();
	std::vector<double> sorted = sort(vector);

	if (n % 2 == 1) {
		return sorted[n/2];
	}
	else {
		int k = n/2;
		int l = n/2 - 1;
		double first = sorted[l];
		double second = sorted[k];

		double c = (first + second) / 2;

		return c;
	}
}

void sin (const std::vector<double>& vector) {
	std::cout << "[";
    
	for (size_t i = 0; i < vector.size(); ++i) {
        	double sinusValue = std::sin(vector[i]);
        	std::cout << sinusValue;

        	if (i < vector.size() - 1) {
            	std::cout << ", ";
        	}
    	}
    
    std::cout << "]" << std::endl;



/*	std::vector<double> result;
	for (const auto& x : vector) {
		double sinValue = std::sin(x);
		result.push_back(sinValue);
	}

	for (auto e : result) {
		std::cout << e << ", ";
	}
*/
}

std::vector<double> sums (std::vector<std::vector<double>>& vector) {
	std::vector<double> solution;
	double sum = 0.0;

	for (const auto& inner : vector) {

		sum = std::accumulate(inner.begin(), inner.end(), 0.0);
		solution.push_back(sum);
	}

	return solution;
}

int main() {
	std::vector<double> a {6.7, 5.2, 8.1};
	std::vector<double> c {3.7, 5.2, 3.3, 6.5, 2.3, 8.1};

	print(a);
	std::cout << median(a) << std::endl;
	
	std::vector<double> hello = sort(c);
	print(hello);
	std::cout << median(c) << std::endl;

	std::vector<std::vector<double>> s {{1.3, 5.4, 2.8},{6.5, 3.9, 9.8},{1.2, 2.7}};
	std::vector<double> result = sums(s);
	print(result);

	sin(a);

	return 0;
}
