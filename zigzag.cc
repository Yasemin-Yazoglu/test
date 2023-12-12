#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <functional>

std::list<int> zigzag(std::list<int>& list) {
	list.sort();
	int n = list.size();
	std::list<int> result;
	
	auto it = list.begin();
	auto itend = list.end();
	auto prev = std::prev(itend, 1);
	for (int i = 0; i < (n/2); ++i) {
		result.push_back(*it);
		result.push_back(*prev);
		++it;
		--prev;
	}

	if (n%2 == 1) {
		result.push_back(*it);
	}

	return result;
}

int main() {
	std::list<int> list = {4, 2, 7, 1, 8, 3, 5, 9, 32, 65, 11};
	
	std::list<int> mylist;
	mylist = zigzag(list);

	for (auto entry : mylist) {
		std::cout << entry << " ";
		std::cout << std::endl;
	}

	return 0;
}
