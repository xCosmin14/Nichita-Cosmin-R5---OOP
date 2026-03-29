#include "BMW.h"
#include "Weather.h"

BMW::BMW() {
    capRezervor = 60;
    consum = 7.5;
    vitezaMedie[0] = 80; //ploaie
    vitezaMedie[1] = 110;//vreme normala
    vitezaMedie[2] = 50; //zapada
}

const char* BMW::GetNume() {
    return "BMW";
}

double BMW::GetVitezaMedie(Weather w) {
    if (w == Weather::Ploaie) return this->vitezaMedie[0];
    if (w == Weather::Zapada) return this->vitezaMedie[2];
    return this->vitezaMedie[1];
}