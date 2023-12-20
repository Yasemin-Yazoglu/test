#include <iostream>
#include "temperatur.hh"

int main() {
    char scale;
    double value;

    std::cout << "Bitte geben Sie die Skala ('K', 'C', oder 'F') ein: " << std::flush;
    std::cin >> scale;

    std::cout << "Bitte geben Sie den Temperaturwert ein: " << std::flush;
    std::cin >> value;

    Temperatur temperatur;

    switch (scale) {
        case 'K':
            temperatur.setKelvin(value);
            break;
        case 'C':
            temperatur.setKelvin(value + 273.15);
            break;
        case 'F':
            temperatur.setKelvin((value - 32.0) * 5.0 / 9.0 + 273.15);
            break;
        default:
            std::cerr << "Ungültige Skala eingegeben."<< std::endl;
            return 1;
    }

    std::cout << "Kelvin: " << temperatur.getKelvin() << " K" << std::endl;
    std::cout << "Celsius: " << temperatur.getCelsius() << " °C" << std::endl;
    std::cout << "Fahrenheit: " << temperatur.getFahrenheit() << " °F" << std::endl;

    return 0;
}
