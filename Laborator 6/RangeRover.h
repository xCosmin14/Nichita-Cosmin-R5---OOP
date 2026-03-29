#pragma once
#include "Car.h"

class RangeRover : public Car {
	public:
		RangeRover();
		const char* GetNume() override;
		double GetVitezaMedie(Weather w) override;
};