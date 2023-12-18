#include "fach.hh"

Fach::Fach(std::string name, std::string kuerzel, unsigned int ects)
    : name(name), kuerzel(kuerzel), ects(ects), note(0.0) {}

bool Fach::noteEintragen(double note) {
    if (note >= 1.0 && note <= 5.0) {
        if (bestanden()) {
            this->note = note;
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool Fach::bestanden() const {
    return this->note <= 4.0;
}

double Fach::gewerteteNote() const {
    if (bestanden()) {
        return this->note * ects;
    } else {
        return 0.0;
    }
}

unsigned int Fach::getECTS() const {
    if (bestanden()) {
        return ects;
    } else {
        return 0;
    }
}

std::string Fach::getName() const {
    return name;
}

std::string Fach::getKuerzel() const {
    return kuerzel;
}

std::string Fach::toString() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1);
    ss << "Kür: " << kuerzel << " [" << name << "] [" << ects << "]: " << note;
    return ss.str();
}

