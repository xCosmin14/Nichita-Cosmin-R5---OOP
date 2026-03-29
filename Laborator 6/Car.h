#pragma once
#include "Weather.h"

class Car {
	public:
		double capRezervor;
		double consum;
		double vitezaMedie[3];

		virtual const char* GetNume() = 0;
		virtual double GetVitezaMedie(Weather w) = 0;

		virtual ~Car() {};
};