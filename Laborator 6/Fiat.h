#pragma once
#include "Car.h"

class Fiat : public Car {
public:
	Fiat();
	const char* GetNume() override;
	double GetVitezaMedie(Weather w) override;
};