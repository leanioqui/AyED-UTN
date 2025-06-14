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

void TablaCelsiusAFahrenheit() {
    std::cout << "╔═══════════════╦════════════════════╗\n";
    std::cout << "║   Celsius     ║   Fahrenheit       ║\n";
    std::cout << "╠═══════════════╬════════════════════╣\n";
    for (int celsius = -40; celsius <= 100; celsius+=5) {
        std::cout << "║" << std::setw(10) << celsius << " ºC"
                  << "  ║" << std::setw(10) << std::fixed << std::setprecision(1)
                  << Fahrenheit(celsius) << " ºF" << "       ║\n";
    }
    std::cout << "╚═══════════════╩════════════════════╝\n\n";
}

void TablaFahrenheitACelsius() {
    std::cout << "\nTabla Fahrenheit → Celsius\n";
    std::cout << std::right << std::setw(15) << "Fahrenheit"
              << std::right << std::setw(10) << "Celsius\n";

    for (int fahrenheit = 20; fahrenheit <= 100; fahrenheit += 5) {
        double celsius = Celsius(fahrenheit);
        std::cout << std::right << std::setw(15) << fahrenheit
                  << std::right << std::setw(10)
                  << std::fixed << std::setprecision(1) << celsius << '\n';
    }
}
