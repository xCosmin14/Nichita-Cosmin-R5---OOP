#pragma once
 
float operator""_Kelvin(long double k) {
    return static_cast<float>(k - 273.15L);
}
 
float operator""_Kelvin(unsigned long long k) {
    return static_cast<float>(k - 273.15);
}
 
float operator""_Fahrenheit(long double f) {
    return static_cast<float>((f - 32.0L) * 5.0L / 9.0L);
}
 
float operator""_Fahrenheit(unsigned long long f) {
    return static_cast<float>((static_cast<double>(f) - 32.0) * 5.0 / 9.0);
}
