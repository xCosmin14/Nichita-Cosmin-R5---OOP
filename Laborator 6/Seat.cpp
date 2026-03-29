#include "Seat.h"
#include "Weather.h"

Seat::Seat() {
    capRezervor = 45;
    consum = 6.7;
    vitezaMedie[0] = 65; //ploaie
    vitezaMedie[1] = 100;//vreme normala
    vitezaMedie[2] = 38; //zapada
}

const char* Seat::GetNume() {
    return "Seat";
}

double Seat::GetVitezaMedie(Weather w) {
    if (w == Weather::Ploaie) return this->vitezaMedie[0];
    if (w == Weather::Zapada) return this->vitezaMedie[2];
    return this->vitezaMedie[1];
}