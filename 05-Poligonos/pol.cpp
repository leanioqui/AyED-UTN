#include <cassert>
#include <array>
#include <iostream>
#include <fstream>
#include <cmath>

using std::array;
using std::cin;
using std::cout;
using std::ifstream;
using std::sqrt;

constexpr unsigned CANTIDAD_MAXIMA_DE_PUNTOS {100};

constexpr unsigned CANTIDAD_MAXIMA_DE_POLIGONOS {1'000};

struct Punto
{
    double x, y;
};

struct Color
{
    char r, g, b;
};

struct SecuenciaDePuntos
{
    array<Punto, CANTIDAD_MAXIMA_DE_PUNTOS> puntos ;
    unsigned n;
};

struct Poligono
{
    SecuenciaDePuntos secuenciaDePuntos;
    Color color;
};

struct SecuenciaDePoligonos
{
    array<Poligono, CANTIDAD_MAXIMA_DE_POLIGONOS> poligonos;
    unsigned n;
};

double GetDistancia(Punto, Punto);

Punto LeerPunto(ifstream&);

unsigned GetCantidadDePuntos(const SecuenciaDePuntos&);

unsigned GetCantidadDeLados(const Poligono&);

void AddPunto(SecuenciaDePuntos&, Punto);

Poligono GetNewPoligono(ifstream&);



int main()
{
    //Pruebas
        //Pruebas de Punto

        //Pruebas de Poligono

    //Procesar
        //LeerPoligonos

        //OrdenarPorCantidadDeLados

        //EscribirPoligonos

        //OrdenarPorPerimetro

        //EscribirPoligonos


    return 0;
}

double GetDistancia(Punto a, Punto b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Punto LeerPunto(ifstream& f)
{
    Punto p;
    f >> p.x >> p.y;
    return p;
}

unsigned GetCantidadDePuntos(const SecuenciaDePuntos& s)
{
    return s.n;
}

unsigned GetCantidadDeLados(const Poligono& pol)
{
    return GetCantidadDePuntos(pol.secuenciaDePuntos);
}

void AddPunto(SecuenciaDePuntos& s, Punto p)
{
    s.puntos.at(s.n) = p;
    ++s.n;
}