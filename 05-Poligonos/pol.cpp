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
using std::swap;

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


Punto LeerPunto(ifstream&);

SecuenciaDePoligonos LeerPoligonos(ifstream&);

double GetDistancia(Punto, Punto);

double GetPerimetro(const Poligono&);

unsigned GetCantidadDePuntos(const SecuenciaDePuntos&);

unsigned GetCantidadDeLados(const Poligono&);

Poligono CrearPoligono(ifstream&);

void AddPunto(SecuenciaDePuntos&, Punto);

SecuenciaDePoligonos OrdenarPorCantLados (const SecuenciaDePoligonos&);

SecuenciaDePoligonos OrdenarPorPerimetro (const SecuenciaDePoligonos&);

void Pruebas();

int main()
{
    //Pruebas
        //Pruebas de Punto (GetDistancia)

        //Pruebas de Poligono (GetCantidadDeLados, GetPerimetro, AddPunto, CrearPoligono)

    //Procesar
        //LeerPoligonos (usando la función LeerPunto)

        //CrearPoligono (usando la función AddPunto)

        //CrearSecuenciaDePoligonos (usando la funcion LeerPoligonos)

        //OrdenarPorCantidadDeLados

        //EscribirPoligonos

        //OrdenarPorPerimetro 

        //EscribirPoligonos


    return 0;
}

Punto LeerPunto(ifstream& f)
{
    Punto p;
    f >> p.x >> p.y; //Lee al primer elemento del flujo y lo asigna a p.x, luego lee el segundo elemento y lo asigna a p.y
    return p;
}

double GetDistancia(Punto a, Punto b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
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

double GetPerimetro(const Poligono& pol)
{
    double perimetro = 0.0;
    unsigned cantidadDePuntos = GetCantidadDePuntos(pol.secuenciaDePuntos);
    for (unsigned i = 0; i < cantidadDePuntos; ++i)
    {
        Punto actual = pol.secuenciaDePuntos.puntos.at(i);
        Punto siguiente = pol.secuenciaDePuntos.puntos.at((i + 1) % cantidadDePuntos); // El uso del operador módulo (%) permite que el último punto se conecte con el primero
        perimetro += GetDistancia(actual, siguiente);
    }
    return perimetro;
}

SecuenciaDePoligonos OrdenarPorCantLados(const SecuenciaDePoligonos& secuencia)
{
    SecuenciaDePoligonos ordenada = secuencia;

    if (ordenada.n < 2) return ordenada;

    for (unsigned i = 0; i < ordenada.n - 1; ++i) {
        for (unsigned j = 0; j < ordenada.n - i - 1; ++j) {
            unsigned ladosActual    = GetCantidadDeLados(ordenada.poligonos.at(j));
            unsigned ladosSiguiente = GetCantidadDeLados(ordenada.poligonos.at(j + 1));

            if (ladosActual > ladosSiguiente) {
                swap(ordenada.poligonos.at(j), ordenada.poligonos.at(j + 1));
            }
        }
    }
    return ordenada;
}

SecuenciaDePoligonos OrdenarPorPerimetro (const SecuenciaDePoligonos& secuencia){
    SecuenciaDePoligonos ordenada = secuencia; // Copiamos la secuencia original para no modificarla

    // Usamos el algoritmo de burbuja para ordenar los polígonos por perímetro
    for (unsigned i = 0; i < ordenada.n - 1; ++i)
    {
        for (unsigned j = 0; j < ordenada.n - i - 1; ++j)
        {
            if (GetPerimetro(ordenada.poligonos.at(j)) > GetPerimetro(ordenada.poligonos.at(j + 1)))
            {
                swap(ordenada.poligonos.at(j), ordenada.poligonos.at(j + 1)); // Intercambiamos los polígonos si están en el orden incorrecto
            }
        }
    }

    return ordenada;
}


void Pruebas(){

//Pruebas de Punto

    //Pruebas de GetDistancia

    assert(GetDistancia({0,0}, {3,4}) == 5.0);
    assert(GetDistancia({1,1}, {4,5}) == 5.0); 
    assert(GetDistancia({-1,-1}, {2,0}) != 6.7);
    assert(GetDistancia({0,0}, {0,0}) == 0.0);
    assert(GetDistancia({-1,-1}, {-1,-1}) == 0.0);

//Pruebas de Poligono

    //Pruebas de GetCantidadDeLados

    assert(GetCantidadDeLados({{{{{0,0}, {1,0}, {1,1}, {0,1}}}}}) == 4);
    assert(GetCantidadDeLados({{{{{0,0}, {2,0}, {1,1}}}}}) == 3);
    assert(GetCantidadDeLados({{{{{0,0}, {1,0}}}}}) == 2);
    assert(GetCantidadDeLados({{{{{0,0}}}}}) == 1);
    assert(GetCantidadDeLados({{{{}}}}) == 0);

    //Pruebas de GetPerimetro

    assert(GetPerimetro({{{{{0,0}, {1,0}, {1,1}, {0,1}}}}}) == 4.0);
    assert(GetPerimetro({{{{{0,0}, {3,0}, {0,4}}}}}) == 12.0);
    assert(GetPerimetro({{{{{0,0}, {0,5}, {5,5}, {5,0}}}}}) == 20.0);
    assert(GetPerimetro({{{{{1,1}, {4,1}, {4,5}, {1,5}}}}}) == 14.0);
    assert(GetPerimetro({{{{{0,0}, {2,0}, {1,1}}}}}) != 7.0);

    //Pruebas de CrearPoligono y AddPunto

}
