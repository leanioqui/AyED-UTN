#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip> // Para poder usar std::setw y std::setprecision

bool AreNear(double a, double b, double tolerancia = 0.0001);
double Celsius (double fahrenheit);
double Fahrenheit (double celsius);
void TablaCelsiusAFahrenheit(double inicio, double fin, double paso, double tolerancias[], int cantidadTolerancias);
void TablaFahrenheitACelsius();


int main() {
    assert(AreNear(Fahrenheit(-5), 23.0));  // Conversión de Celsius(-5) a Fahrenheit (23.0)
    assert(AreNear(Fahrenheit(0), 32.0));  // Conversión de Celsius(0) a Fahrenheit (32.0)
    assert(AreNear(Fahrenheit(15), 59.0)); // Conversión de Celsius(15) a Fahrenheit (59.0)
    
    double tolerancias[] = {0.01, 0.0001, 0.00001};
    int cantidadTolerancias = sizeof(tolerancias) / sizeof(tolerancias[0]);
    
    double inicioC = 0.0, finC = 100.0, pasoC = 10.0;

    TablaCelsiusAFahrenheit(inicioC, finC, pasoC, tolerancias, cantidadTolerancias);
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

void TablaCelsiusAFahrenheit(double inicio, double fin, double paso, double tolerancias[], int cantidadTolerancias) {
    for (int i = 0; i < cantidadTolerancias; ++i) {
        double tolerancia = tolerancias[i];

        std::cout << "\nTabla Celsius → Fahrenheit (Tolerancia: " << tolerancia << ")\n";
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "-------------------------------------------\n";
        std::cout << "|  Celsius   | Fahrenheit | ¿Precisión OK? |\n";
        std::cout << "-------------------------------------------\n";

        for (double tempC = inicio; tempC <= fin; tempC += paso) {
            double tempF = Fahrenheit(tempC);
            double reconvertido = Celsius(tempF);
            bool ok = AreNear(tempC, reconvertido, tolerancia);

            std::cout << "|   " << std::setw(8) << tempC
                      << " | " << std::setw(10) << tempF
                      << " |       " << (ok ? "Sí" : "No") << "       |\n";
        }

        std::cout << "-------------------------------------------\n";
    }
}

void TablaFahrenheitACelsius(){
}
