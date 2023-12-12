#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>

void reverseList(std::list<int>& list) {
	int n = list.size();

	auto it = list.begin();
	auto its = list.end();
	auto prev = std::prev(its, 1);
	for (int i = 0; i < n/2; i++) {
		std::swap(*it, *prev);

		++it;
		--prev;
	}
}

int main() {
	std::list<int> list = {1,2,3,4,5, 6};
	
	reverseList(list);
	
	for (auto entry : list) {
		std::cout << entry << " ";
		std::cout << std::endl;
	}

	return 0;
}
