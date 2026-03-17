#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cstring>

Sort::Sort(int nrVal, int minVal, int maxVal) {
	this->elemente = new int[nrVal];
	this->nrElemente = nrVal;
	for (int i = 0; i < nrVal; i++) {
		this->elemente[i] = rand() % (maxVal - minVal + 1) + minVal;
	}
}

Sort::Sort(std::initializer_list<int> list) {
	this->elemente = new int[list.size()];
	this->nrElemente = list.size();

	int i = 0;
	for (int element : list) this->elemente[i++] = element;
}

Sort::Sort(int* vector, int size) {
	this->elemente = new int[size];
	this->nrElemente = size;
	for (int i = 0; i < size; i++) this->elemente[i] = vector[i];
}

Sort::Sort(int size, ...) {
	this->nrElemente = size;
	this->elemente = new int[size]; 

	va_list args;
	va_start(args, size); 

	for (int i = 0; i < size; i++) 
		this->elemente[i] = va_arg(args, int);
	
	va_end(args); 
}

Sort::Sort(const char* str) {
	int size = 0, putere = 1, numar = 0, current = 0;

	for (int i = 0; i < strlen(str); i++) if (str[i] == ',') size++;
	size++;

	this->elemente = new int[size];
	this->nrElemente = size;

	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] != ',') {
			numar += putere * (str[i] - '0');
			putere *= 10;
		} else {
			this->elemente[current] = numar;
			current++;
			numar = 0, putere = 1;
		}
	}

	this->elemente[current] = numar;
}

void Sort::InsertSort(bool ascendent) {
	int i, key, j;
	for (i = 1; i < this->nrElemente; i++) {
		key = this->elemente[i];
		j = i - 1;

		while (j >= 0 && (ascendent ? (this->elemente[j] > key) : (this->elemente[j] < key))) {
			this->elemente[j + 1] = this->elemente[j];
			j = j - 1;
		}

		this->elemente[j + 1] = key;
	}
}

int Sort::partition(int* v, int p, int q, bool ascendent) {
	int pivot = v[q], i = (p - 1);   

	for (int j = p; j <= q - 1; j++) {
		bool condition = ascendent ? (v[j] < pivot) : (v[j] > pivot);

		if (condition) {
			i++;
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
	}

	int aux = v[i+1];
	v[i+1] = v[q];
	v[q] = aux;
	return (i + 1);
}

void Sort::QuickSortRec(int* v, int p, int q, bool ascendent) {
	if (p < q) {
		int pi = partition(v, p, q, ascendent);

		QuickSortRec(v, p, pi - 1, ascendent);
		QuickSortRec(v, pi + 1, q, ascendent);
	}
}

void Sort::QuickSort(bool ascendent) {
	if (this->elemente != nullptr && this->nrElemente > 1) {
		Sort::QuickSortRec(this->elemente, 0, this->nrElemente - 1, ascendent);
	}
}

void Sort::BubbleSort(bool ascendent) {

	for (int i=0; i < this->nrElemente; i++) 
		for (int j = i + 1; j < this->nrElemente; j++) {
			bool condition = ascendent ? (elemente[i] > elemente[j]) : (elemente[i] < elemente[j]);

			if (condition) {
				int aux = elemente[i];
				elemente[i] = elemente[j];
				elemente[j] = aux;
			}
		}
}

void Sort::Print() {
	for (int i = 0; i < this->nrElemente; i++) std::cout << this->elemente[i] << ' ';
	std::cout << '\n';
}

int Sort::GetElementsCount() {
	return this->nrElemente;
}

int Sort::GetElementFromIndex(int index) {
	return this->elemente[index];
}