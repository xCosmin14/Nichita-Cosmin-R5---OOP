#pragma once
#include "Weather.h"
#include "Car.h"

#define lungime_masini 128

struct pozitieClasament { Car* masina; double timp; };

class Circuit {
	private:
		unsigned int lungimeCircuit=0, numarParticipanti=0, numarDNF=0, numarClasament=0;

		Weather vreme;

		Car* masini[lungime_masini];
		Car* nuAuTerminat[lungime_masini];

		pozitieClasament clasament[lungime_masini];

	public:
		void SetLength(unsigned int lungime);
		void SetWeather(Weather vreme);
		void AddCar(Car* masinaNoua);
		void Race();
		void ShowWhoDidNotFinish();
		void ShowFinalRanks();
};