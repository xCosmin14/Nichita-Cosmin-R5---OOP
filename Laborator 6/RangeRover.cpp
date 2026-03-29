#include "RangeRover.h"
#include "Weather.h"

RangeRover::RangeRover() {
    capRezervor = 65;
    consum = 11.0;
    vitezaMedie[0] = 100; //ploaie
    vitezaMedie[1] = 125;//vreme normala
    vitezaMedie[2] = 55; //zapada
}

const char* RangeRover::GetNume() {
    return "RangeRover";
}

double RangeRover::GetVitezaMedie(Weather w) {
    if (w == Weather::Ploaie) return this->vitezaMedie[0];
    if (w == Weather::Zapada) return this->vitezaMedie[2];
    return this->vitezaMedie[1];
}