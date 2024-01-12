#pragma once
#include <iostream>
#include <sstream>

template <typename T>
class Collector {
    private:
        T sum;
        T adder;

    public:
        Collector(T initialSum, T initialAdder) : sum(initialSum), adder(initialAdder) {}

        // Methode zum Hinzufügen eines Werts zu sum und adder
        void add(T value) {
            sum += adder;
            sum += value;
        }

        // Methode zum Abrufen des aktuellen Werts von sum
        T digest() const {
            return sum;
        }
};

template <>
class Collector<std::string> {
    private:
        std::string sum;
        std::string adder;
    
    public:
        Collector(std::string initialSum, std::string initialAdder) : sum(initialSum), adder(initialAdder) {}

        // Methode zum Hinzufügen eines Werts zu sum und adder
        
        void add(std::string value) {
            if (!sum.empty()) {
                sum += adder;
            }
            sum += value;
        }

        // Methode zum Abrufen des aktuellen Werts von sum
        std::string digest() const {
            return sum;
        }
};
