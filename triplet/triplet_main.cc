#include <iostream>
#include "triplet.hh"

int main() {
    Triplet<int, double, char> myTriplet(42, 3.14, 'F');

    std::cout << "First: " << myTriplet.first() << std::endl;
    std::cout << "Second: " << myTriplet.second() << std::endl;
    std::cout << "Third: " << myTriplet.third() << std::endl;

    myTriplet.setFirst(100);
    myTriplet.setSecond(2.718);
    myTriplet.setThird('A');

    std::cout << "First after modification: " << myTriplet.first() << std::endl;
    std::cout << "Seconst after modification: " << myTriplet.second() << std::endl;
    std::cout << "Third after modification: " << myTriplet.third() << std::endl;

    return 0;
}
