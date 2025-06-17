#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip> // Para poder usar std::setw y std::setprecision
#include <fstream>
#include <string>

bool AreNear(double a, double b, double tolerancia = 0.0001);
double Celsius (double fahrenheit);
double Fahrenheit (double celsius);
void TablaCelsiusAFahrenheit();
void TablaFahrenheitACelsius();
//Funciones para generar el grafico en SVG (visualizar en navegador Chrome)
int svg_x(double value);
int svg_y(double value);
void exportarGraficoSVG();


int main() {
    //Pruebas sobre la funcion AreNear
    assert(AreNear(1.0, 1.0, 0.0001) == true);

    assert(AreNear(1.0, 1.00005, 0.0001) == true);
    assert(AreNear(1.0, 0.99995, 0.0001) == true);

    assert(AreNear(1.0, 1.0001, 0.0001) == true);
    assert(AreNear(1.0, 0.9999, 0.0001) == true);

    assert(AreNear(1.0, 1.0002, 0.0001) == false);
    assert(AreNear(1.0, 0.9998, 0.0001) == false);

    assert(AreNear(-1.0, -1.00005, 0.0001) == true);
    assert(AreNear(-1.0, -0.9999, 0.0001) == true);
    assert(AreNear(-1.0, -1.0002, 0.0001) == false);

    assert(AreNear(-1.0, 1.0, 0.0001) == false);
    assert(AreNear(-0.00005, 0.00005, 0.0001) == true);

    assert(AreNear(1e10, 1e10 + 0.00005, 0.0001) == true);
    assert(AreNear(1e-10, -1e-10, 0.0001) == true);


    //Pruebas para la funcion Celsius
    assert(Celsius(32.0) == 0.0);
    assert(Celsius(212.0) == 100.0);
    assert(Celsius(50.0) == 10.0);
    assert(Celsius(14.0) == -10.0);
    assert(Celsius(68.0) == 20.0);
    assert(Celsius(104.0) == 40.0);
    assert(Celsius(122.0) == 50.0);
    assert(Celsius(-40.0) == -40.0);  // Punto donde ambas escalas coinciden


    //Pruebas para la funcion Fahrenheit
    assert(Fahrenheit(0.0) == 32.0);
    assert(Fahrenheit(100.0) == 212.0);
    assert(Fahrenheit(10.0) == 50.0);
    assert(Fahrenheit(-10.0) == 14.0);
    assert(Fahrenheit(20.0) == 68.0);
    assert(Fahrenheit(40.0) == 104.0);
    assert(Fahrenheit(50.0) == 122.0);
    assert(Fahrenheit(-40.0) == -40.0);  // Punto donde ambas escalas coinciden

    //Prueba que fallan por precisión
    assert(!(Fahrenheit(-273.15) == -459.67));   // Cero absoluto
    assert(!(Celsius(0.0) == -17.7778));         // Aprox -17.7778°C, pero no exacto
    assert(!(Fahrenheit(-17.7778) == 0.0));      // Mismo problema anterior

    // Pruebas de conversion y tolerancia de Celsius a Farenheit
    assert(AreNear(Fahrenheit(-5), 23.0));  // Conversión de Celsius(-5) a Fahrenheit (23.0)
    assert(AreNear(Fahrenheit(0), 32.0));  // Conversión de Celsius(0) a Fahrenheit (32.0)
    assert(AreNear(Fahrenheit(15), 59.0)); // Conversión de Celsius(15) a Fahrenheit (59.0)

    //Pruebas de conversion y tolerancia de Farenheit a Celsius
    assert(AreNear(Celsius(32.0), 0.0));
    assert(AreNear(Celsius(212.0), 100.0));
    assert(AreNear(Celsius(98.6), 37.0));
    assert(AreNear(Celsius(0.0), -17.7778));

    //Generacion de tablas
    TablaCelsiusAFahrenheit();
    TablaFahrenheitACelsius();

    //Generacion del grafico SVG de ambas funciones lineales
    exportarGraficoSVG();
    
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
    std::cout << "║    Celsius    ║     Fahrenheit     ║\n";
    std::cout << "╠═══════════════╬════════════════════╣\n";
    for (int celsius = -40; celsius <= 100; celsius+=5) {
        std::cout << "║" << std::setw(10) << celsius << " ºC"
                  << "  ║" << std::setw(10) << std::fixed << std::setprecision(1)
                  << Fahrenheit(celsius) << " ºF" << "       ║\n";
    }
    std::cout << "╚═══════════════╩════════════════════╝\n\n";
}

void TablaFahrenheitACelsius() {
    std::cout << "╔═══════════════╦════════════════════╗\n";
    std::cout << "║   Fahrenheit  ║       Celsius      ║\n";
    std::cout << "╠═══════════════╬════════════════════╣\n";
    for (int fahrenheit = -40; fahrenheit <= 212; fahrenheit += 5) {
        std::cout << "║" << std::setw(10) << fahrenheit << " °F"
                  << "  ║" << std::setw(10) << std::fixed << std::setprecision(1)
                  << Celsius(fahrenheit) << " °C" << "       ║\n";
    }
    std::cout << "╚═══════════════╩════════════════════╝\n";
}

int svg_x(double value) {
    return static_cast<int>(value * 4 + 300);
}

int svg_y(double value) {
    return static_cast<int>(300 - value * 4);
}

void exportarGraficoSVG() {
    std::ofstream file("temperaturas.svg");
    if (!file.is_open()) {
        std::cerr << "Error al crear el archivo SVG." << std::endl;
        return;
    }

    file << R"(<?xml version="1.0" standalone="no"?>)"
         << "\n<svg width=\"600\" height=\"600\" xmlns=\"http://www.w3.org/2000/svg\">\n";

    // Cuadriculado cada 30 unidades
    for (int i = -150; i <= 150; i += 30) {
        int x = svg_x(i);
        file << "<line x1=\"" << x << "\" y1=\"0\" x2=\"" << x << "\" y2=\"600\" stroke=\"#ddd\" />\n";
    }
    for (int j = -150; j <= 150; j += 30) {
        int y = svg_y(j);
        file << "<line x1=\"0\" y1=\"" << y << "\" x2=\"600\" y2=\"" << y << "\" stroke=\"#ddd\" />\n";
    }

    // Ejes principales
    file << "<line x1=\"0\" y1=\"300\" x2=\"600\" y2=\"300\" stroke=\"black\" stroke-width=\"1\" />\n";
    file << "<line x1=\"300\" y1=\"0\" x2=\"300\" y2=\"600\" stroke=\"black\" stroke-width=\"1\" />\n";

    // Números en los ejes
    for (int i = -150; i <= 150; i += 30) {
        if (i == 0) continue;
        int x = svg_x(i);
        file << "<text x=\"" << x - 10 << "\" y=\"315\" font-size=\"10\">" << i << "</text>\n";
    }
    for (int j = -150; j <= 150; j += 30) {
        if (j == 0) continue;
        int y = svg_y(j);
        file << "<text x=\"305\" y=\"" << y + 4 << "\" font-size=\"10\">" << j << "</text>\n";
    }

    // Etiquetas de ejes
    file << "<text x=\"580\" y=\"290\" font-size=\"12\">X</text>\n";
    file << "<text x=\"310\" y=\"12\" font-size=\"12\">Y</text>\n";

    // Línea de la funcion Celsius(fahrenheit)
    file << "<polyline fill=\"none\" stroke=\"blue\" stroke-width=\"2\" points=\"";
    for (int f = -100; f <= 212; ++f) {
        double c = Celsius(f);
        file << svg_x(f) << "," << svg_y(c) << " ";
    }
    file << "\" />\n";
    file << "<text x=\"400\" y=\"80\" fill=\"blue\" font-size=\"12\">Fahrenheit a Celsius</text>\n";
    file << "<text x=\"400\" y=\"100\" fill=\"blue\" font-size=\"12\">C=5/9(F - 32)</text>\n";


    // Línea de la funcion Fahrenheit(celsius)
    file << "<polyline fill=\"none\" stroke=\"red\" stroke-width=\"2\" points=\"";
    for (int c = -100; c <= 100; ++c) {
        double f = Fahrenheit(c);
        file << svg_x(c) << "," << svg_y(f) << " ";
    }
    file << "\" />\n";
    file << "<text x=\"100\" y=\"100\" fill=\"red\" font-size=\"12\">Celsius a Farenheit</text>\n";
    file << "<text x=\"100\" y=\"120\" fill=\"red\" font-size=\"12\">F=9/5 C + 32</text>\n";

    file << "</svg>\n";
    file.close();

    std::cout << "Gráfico SVG exportado como temperaturas.svg" << std::endl;
}