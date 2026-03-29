#pragma once
#include "Car.h"

class BMW : public Car {
	public:
		BMW();
		const char* GetNume() override;
		double GetVitezaMedie(Weather w) override;
};