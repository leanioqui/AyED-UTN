#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip> // Para poder usar std::setw y std::setprecision

bool AreNear(double a, double b, double tolerancia = 0.0001);
double Celsius (double fahrenheit);
double Fahrenheit (double celsius);
void TablaCelsiusAFahrenheit();
void TablaFahrenheitACelsius();


int main() {
    assert(AreNear(Fahrenheit(-5), 23.0));  // Conversión de Celsius(-5) a Fahrenheit (23.0)
    assert(AreNear(Fahrenheit(0), 32.0));  // Conversión de Celsius(0) a Fahrenheit (32.0)
    assert(AreNear(Fahrenheit(15), 59.0)); // Conversión de Celsius(15) a Fahrenheit (59.0)

    TablaCelsiusAFahrenheit();
    TablaFahrenheitACelsius();
    
    return 0;
}


bool AreNear(double a, double b, double tolerancia) {
    return std::abs(a - b) <= tolerancia; // Compara el valor absoluto de la diferencia entre a y b, con la tolerancia 0.0001
}

double Celsius (double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0; // Convierte Fahrenheit a Celsius
}

double Fahrenheit (double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0; // Convierte Celsius a Fahrenheit
}


