#include "temperatur.hh"

Temperatur::Temperatur() : kelvin(0.0) {}
Temperatur::Temperatur(double kelvin) : kelvin(kelvin) {};  

double Temperatur::getKelvin() const {
    return kelvin;
}

double Temperatur::getCelsius() const {
    return kelvin - 273.15;
}

double Temperatur::getFahrenheit() const {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

void Temperatur::setKelvin(double kelvin) {
    this->kelvin = kelvin;
}

Temperatur Temperatur::add(const Temperatur& other) const {
    return Temperatur(this->kelvin + other.getKelvin());
}
