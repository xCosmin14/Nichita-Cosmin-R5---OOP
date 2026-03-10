#include "Math.h"
#include <cstdarg>
#include <cstring>
using namespace std;

int Math::Add(int x1_i, int y1_i) {
	return x1_i + y1_i;
}

int Math::Add(int x2_i, int y2_i, int z1_i) {
	return x2_i + y2_i + z1_i;
}

int Math::Add(double x1_d, double y1_d) {
	return x1_d + y1_d;
}

int Math::Add(double x2_d, double y2_d, double z2_d) {
	return x2_d + y2_d + z2_d;
}

int Math::Mul(int x1_i, int y1_i) {
	return x1_i * y1_i;
}

int Math::Mul(int x2_i, int y2_i, int z1_i) {
	return x2_i * y2_i * z1_i;
}

int Math::Mul(double x1_d, double y1_d) {
	return x1_d * y1_d;
}

int Math::Mul(double x2_d, double y2_d, double z1_d) {
	return x2_d * y2_d * z1_d;
}

int Math::Add(int count, ...) {
	int sum = 0;

	va_list args;          
	va_start(args, count);

	for (int i = 0; i < count; i++) sum += va_arg(args, int); 
	

	va_end(args); 

	return sum;
}

char* Math::Add(const char* x1, const char* y1) {
	if (x1 == nullptr || y1 == nullptr) return nullptr;

	unsigned int length = strlen(x1) + strlen(y1) + 1;

	char* result = new char[length];

	strcpy(result, x1);	strcat(result, y1);

	return result;
}