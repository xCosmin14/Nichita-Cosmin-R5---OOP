#include <iostream>
#include "Circuit.h"
#include "Weather.h"

void Circuit::SetLength(unsigned int lungime) {
	this->lungimeCircuit = lungime;
}

void Circuit::SetWeather(Weather vreme) {
	this->vreme = vreme;
}

void Circuit::AddCar(Car* masinaNoua) {
	if (this->numarParticipanti < lungime_masini)
		this->masini[this->numarParticipanti++] = masinaNoua;
	else std::cout << "Masina cu numarul " << this->numarParticipanti++ << " nu mai are loc";
}

void Circuit::Race() {
	for (int i = 0; i < this->numarParticipanti; i++) {
		if ((masini[i]->capRezervor / masini[i]->consum)*100 < this->lungimeCircuit)
			this->nuAuTerminat[this->numarDNF++] = masini[i];
	}
}

void Circuit::ShowWhoDidNotFinish() {
	if (this->numarDNF == 0) std::cout << "\nToate masinile au terminat cursa \n"; else
	for (int i = 0; i < this->numarDNF; i++) std::cout << i+1 << ". " << this->nuAuTerminat[i]->GetNume() << '\n';
}

void Circuit::ShowFinalRanks() {
	for (int i = 0; i < this->numarParticipanti; i++) {
		if ((masini[i]->capRezervor / masini[i]->consum) * 100 >= this->lungimeCircuit) {
			this->clasament[this->numarClasament].masina = this->masini[i];
			this->clasament[this->numarClasament].timp = this->lungimeCircuit / this->masini[i]->GetVitezaMedie(this->vreme);
			this->numarClasament++;
		}
	}

	for (int i = 0; i < numarClasament - 1; i++) {
		for (int j = i + 1; j < numarClasament; j++) {
			if (this->clasament[i].timp > this->clasament[j].timp) {
				auto aux = this->clasament[i];
				this->clasament[i] = this->clasament[j];
				this->clasament[j] = aux;
			}
		}
	}

	for (int i = 0; i < numarClasament; i++) 
		std::cout << i+1 << ". " << this->clasament[i].masina->GetNume() << " - " << this->clasament[i].timp << '\n';
}