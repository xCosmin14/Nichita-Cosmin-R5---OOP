#include <iostream>
#include "NumberList.h"

NumberList::NumberList() {}

void NumberList::Init() {
	count = 0;
}

bool NumberList::Add(int x) {
	if (count >= 10) return 0;

	numbers[count] = x;
	count++;
	return 1;
}

void NumberList::Sort() {
	for (int i = 0; i < count; i++)
		for (int j = i + 1; j < count; j++)
			if (numbers[j] < numbers[i]) {
				int aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
}

void NumberList::Print() {
	for (int i = 0; i < count; i++) std::cout << numbers[i] << ' ';
}
