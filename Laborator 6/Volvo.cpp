#include "Volvo.h"
#include "Weather.h"

Volvo::Volvo() {
    capRezervor = 62;
    consum = 9.5;
    vitezaMedie[0] = 91; //ploaie
    vitezaMedie[1] = 130;//vreme normala
    vitezaMedie[2] = 70; //zapada
}

const char* Volvo::GetNume() {
    return "Volvo";
}

double Volvo::GetVitezaMedie(Weather w) {
    if (w == Weather::Ploaie) return this->vitezaMedie[0];
    if (w == Weather::Zapada) return this->vitezaMedie[2];
    return this->vitezaMedie[1];
}