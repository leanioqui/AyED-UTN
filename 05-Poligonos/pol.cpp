#include <cassert>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using std::array;
using std::cin;
using std::cout;
using std::istream;
using std::sqrt;
using std::swap;
using std::string;
using std::istringstream;

constexpr unsigned CANTIDAD_MAXIMA_DE_PUNTOS {100};

constexpr unsigned CANTIDAD_MAXIMA_DE_POLIGONOS {1000};

struct Punto
{
    double x, y;
};

inline bool operator==(const Punto &a, const Punto &b)
{
    return a.x == b.x && a.y == b.y;
}

inline bool operator!=(const Punto &a, const Punto &b)
{
    return !(a == b);
}

struct Color
{
    char r, g, b;
};

struct SecuenciaDePuntos
{
    array<Punto, CANTIDAD_MAXIMA_DE_PUNTOS> puntos;
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


Punto LeerPunto(istream&);

SecuenciaDePoligonos LeerPoligonos(istream&);

SecuenciaDePoligonos EscribirPoligonos(const SecuenciaDePoligonos&);

double GetDistancia(Punto, Punto);

double GetPerimetro(const Poligono&);

unsigned GetCantidadDePuntos(const SecuenciaDePuntos&);

unsigned GetCantidadDeLados(const Poligono&);

Poligono CrearPoligono(istream&);

bool AddPunto(SecuenciaDePuntos&, Punto);

SecuenciaDePoligonos crearSecuenciaDePoligonos(istream&);

SecuenciaDePoligonos OrdenarPorPerimetro(const SecuenciaDePoligonos&);

SecuenciaDePoligonos OrdenarPorCantLados(const SecuenciaDePoligonos&);

void EscribirPoligonos(const SecuenciaDePoligonos&, string);

bool Pruebas();

int main()
{
    assert(Pruebas()); //Rompe, revisar

    istream& flujo = cin;

    SecuenciaDePoligonos poligonos = crearSecuenciaDePoligonos(flujo);

    SecuenciaDePoligonos ordenarPorCantidadDeLados = OrdenarPorCantLados(poligonos);

    EscribirPoligonos(ordenarPorCantidadDeLados, "Poligonos ordenados por cantidad de lados:");

    SecuenciaDePoligonos ordenadaPorPerimetro = OrdenarPorPerimetro(poligonos);

    EscribirPoligonos(ordenadaPorPerimetro, "Poligonos ordenados por perímetro:");
    
    return 0;
}

Punto LeerPunto(istream &f)
{
    Punto p;
    f >> p.x >> p.y;
    // Lee al primer elemento del flujo y lo asigna a p.x, luego lee el segundo elemento y lo asigna a p.y
    return p;
}

double GetDistancia(Punto a, Punto b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Poligono CrearPoligono(std::istream &f)
{
    Poligono pol;
    Punto p;
    pol.secuenciaDePuntos.n = 0u;
    Punto p0 = LeerPunto(f);
    if (!f) return pol;

    if (!AddPunto(pol.secuenciaDePuntos, p0))
    {
        return pol;
    }

    while ((p = LeerPunto(f)) != p0)
    {
        if (!f)
        {
            break; 
        }

        if (!AddPunto(pol.secuenciaDePuntos, p))
        {
            break; 
        }
    }
    
    return pol;
}

unsigned GetCantidadDePuntos(const SecuenciaDePuntos& s)
{
    return s.n;
}

unsigned GetCantidadDeLados(const Poligono& pol)
{
    return GetCantidadDePuntos(pol.secuenciaDePuntos);
}

bool AddPunto(SecuenciaDePuntos& s, Punto p)
{
    if (s.n >= CANTIDAD_MAXIMA_DE_PUNTOS)
    {
        std::cerr << "Error: cantidad máxima de puntos alcanzada (" << CANTIDAD_MAXIMA_DE_PUNTOS << ")\n";
        return false; 
    }

    s.puntos.at(s.n) = p;
    ++s.n;
    return true; 
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
    if (ordenada.n < 2) return ordenada;

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


bool Pruebas(){

//Pruebas de Punto

    //Pruebas de GetDistancia

    assert(GetDistancia({0,0}, {3,4}) == 5.0);
    assert(GetDistancia({1,1}, {4,5}) == 5.0); 
    assert(GetDistancia({-1,-1}, {2,0}) != 6.7);
    assert(GetDistancia({0,0}, {0,0}) == 0.0);
    assert(GetDistancia({-1,-1}, {-1,-1}) == 0.0);

//Pruebas de Poligono

    //Pruebas de GetCantidadDeLados

    assert(GetCantidadDeLados({{{{{0,0}, {1,0}, {1,1}, {0,1}}}, 4u}}) == 4);
    assert(GetCantidadDeLados({{{{{0,0}, {2,0}, {1,1}}}, 3u}}) == 3);
    assert(GetCantidadDeLados({{{{{0,0}, {1,0}}}, 2u}}) == 2);
    assert(GetCantidadDeLados({{{{{0,0}}}, 1u}}) == 1);
    assert(GetCantidadDeLados({{{{}}, 0u}}) == 0);

    //Pruebas de GetPerimetro

    assert(GetPerimetro({{{{{0,0}, {1,0}, {1,1}, {0,1}}}, 4u}}) == 4.0);
    assert(GetPerimetro({{{{{0,0}, {3,0}, {0,4}}}, 3u}}) == 12.0);
    assert(GetPerimetro({{{{{0,0}, {0,5}, {5,5}, {5,0}}}, 4u}}) == 20.0);
    assert(GetPerimetro({{{{{1,1}, {4,1}, {4,5}, {1,5}}}, 4u}}) == 14.0);
    assert(GetPerimetro({{{{{0,0}, {2,0}, {1,1}}}, 3u}}) != 7.0);

    //Pruebas de CrearPoligono
    istringstream input("0 0\n1 0\n1 1\n0 1\n0 0\n");
    Poligono pol = CrearPoligono(input);
    assert(GetCantidadDeLados(pol) == 4);
    assert(GetPerimetro(pol) == 4.0);

    //Pruebas de AddPunto
    SecuenciaDePuntos secuenciaDePuntos;
    AddPunto(secuenciaDePuntos, {0,0});
    AddPunto(secuenciaDePuntos, {1,0});
    AddPunto(secuenciaDePuntos, {1,1});
    AddPunto(secuenciaDePuntos, {0,1});
    assert(GetCantidadDePuntos(secuenciaDePuntos) == 4);

    //Pruebas de SecuenciaDePoligonos
    SecuenciaDePoligonos secuencia;
    secuencia.n = 3;
    secuencia.poligonos.at(0) = {{{{{0,0}, {1,0}, {1,1}, {0,1}}}, 4u}}; // Perímetro 4.0, Lados 4
    secuencia.poligonos.at(1) = {{{{{0,0}, {3,0}, {0,4}}}, 3u}};       // Perímetro 12.0, Lados 3
    secuencia.poligonos.at(2) = {{{{{0,0}, {0,5}, {5,5}, {5,0}}}, 4u}}; // Perímetro 20.0, Lados 4

    //Pruebas de OrdenarPorPerimetro
    SecuenciaDePoligonos ordenadaPorPerimetro = OrdenarPorPerimetro(secuencia);
    assert(GetPerimetro(ordenadaPorPerimetro.poligonos.at(0)) == 4.0);
    assert(GetPerimetro(ordenadaPorPerimetro.poligonos.at(1)) == 12.0);
    assert(GetPerimetro(ordenadaPorPerimetro.poligonos.at(2)) == 20.0);

    // //Pruebas de OrdenarPorCantidadDeLados
    // SecuenciaDePoligonos ordenadaPorLados = OrdenarPorCantLados(secuencia);
    // assert(GetCantidadDeLados(ordenadaPorLados.poligonos.at(0)) == 3);
    // assert(GetCantidadDeLados(ordenadaPorLados.poligonos.at(1)) == 4);
    // assert(GetCantidadDeLados(ordenadaPorLados.poligonos.at(2)) == 4);

    return true;

}

SecuenciaDePoligonos crearSecuenciaDePoligonos(std::istream& f){

    SecuenciaDePoligonos secuencia;
    secuencia.n = 0u; 
    
    while (true){
        if (secuencia.n >= CANTIDAD_MAXIMA_DE_POLIGONOS)
        {
            std::cerr << "Error: cantidad máxima de polígonos ("
                      << CANTIDAD_MAXIMA_DE_POLIGONOS
                      << ") alcanzada. Se detiene la lectura.\n";
            break;
        }

        Poligono pol = CrearPoligono(f);
        if (!f){break;}

        secuencia.poligonos.at(secuencia.n) = pol;
        ++secuencia.n; 
    }

    return secuencia;
}

void EscribirPoligonos(const SecuenciaDePoligonos& secuencia, string titulo)
{
    cout << titulo << "\n";
    for (unsigned i = 0; i < secuencia.n; ++i)
    {
        cout << "Polígono " << (i + 1) << ":\n";
        const Poligono& pol = secuencia.poligonos.at(i);
        unsigned cantidadDePuntos = GetCantidadDePuntos(pol.secuenciaDePuntos);
        for (unsigned j = 0; j < cantidadDePuntos; ++j)
        {
            const Punto& p = pol.secuenciaDePuntos.puntos.at(j);
            cout << "  Punto " << (j + 1) << ": (" << p.x << ", " << p.y << ")\n";
        }
        cout << "  Perímetro: " << GetPerimetro(pol) << "\n";
        cout << "  Cantidad de lados: " << GetCantidadDeLados(pol) << "\n";
    }
}