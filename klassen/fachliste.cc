#include <iostream>
#include "fachliste.hh"
#include <vector>

FachListe::FachListe() {}

FachListe::FachListe(std::vector<Fach> faecher) : _faecher(faecher) {}

void FachListe::addFach(Fach fach) {
    _faecher.push_back(fach);
}

unsigned int FachListe::summeECTS() {
    unsigned int summe = 0;
    for (const Fach& fach : _faecher) {
        if (fach.bestanden()) {
            summe += fach.getECTS();
        }
    }
    return summe;
}

double FachListe::durchschnitt() {
    double summeGewerteteNoten = 0.0;
    unsigned int summeECTSBestanden = 0;

    for (const Fach& fach : _faecher) {
        if (fach.bestanden()) {
            summeGewerteteNoten += fach.gewerteteNote();
            summeECTSBestanden += fach.getECTS();
        }
    }

    if (summeECTSBestanden == 0) {
        return 0.0;
    }

    return summeGewerteteNoten / summeECTSBestanden;
}

std::vector<std::string> FachListe::list() {
    std::vector<std::string> fachliste;
    for (const Fach& fach : _faecher) {
        fachliste.push_back(fach.toString());
    }
    return fachliste;
}

bool FachListe::noteEintragen(std::string kuerzel, double note) {
    for (Fach& fach : _faecher) {
        if (fach.getKuerzel() == kuerzel) {
            return fach.noteEintragen(note);
        }
    }
    return false;
}
