#include "Fiat.h"
#include "Weather.h"

Fiat::Fiat() {
    capRezervor = 50;
    consum = 5.5;
    vitezaMedie[0] = 60; //ploaie
    vitezaMedie[1] = 90;//vreme normala
    vitezaMedie[2] = 40; //zapada
}

const char* Fiat::GetNume() {
    return "Fiat";
}

double Fiat::GetVitezaMedie(Weather w) {
    if (w == Weather::Ploaie) return this->vitezaMedie[0];
    if (w == Weather::Zapada) return this->vitezaMedie[2];
    return this->vitezaMedie[1];
}