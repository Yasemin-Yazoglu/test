#pragma once
#include <iostream>

class Temperatur {
    private:
        double kelvin;
    public:
        Temperatur();
        Temperatur(double kelvin);
        
        double getKelvin() const;

        double getCelsius() const;
        
        double getFahrenheit() const;

        void setKelvin(double kelvin);

        Temperatur add (const Temperatur& other) const;
};
