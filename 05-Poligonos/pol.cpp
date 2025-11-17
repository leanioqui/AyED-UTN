#include <cassert>
#include <cstddef>
#include <array>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using std::array;
using std::cin;
using std::cout;
using std::vector;
using std::ifstream;

struct Punto {
    double PosX, PosY;
};


struct Puntos {                          // ANALIZAR SI NECESITAMOS ESTE
    vector<Punto> secuencia; 
};

struct Color {
    char r, g, b;
};

struct Segmento {                   // ANALIZAR SI NECESITAMOS SEGMENTO o podemos implementarlo de otra manera
    array<Punto, 2> puntos;
    double longitud;
};

struct Poligono{
    vector<Segmento> segmentos;   // si sacamos segmento, sacar esto tambien
    Color color;
    double perimetro;
    int lados;
};

struct SecuenciaDePuntos{
    array<Punto, 100> a;
    unsigned n; //número de puntos almacenados
};


struct SecuenciaPoligonos{
    vector<Poligono> secuencia;
};

Punto LeerPunto(ifstream&);

double getDistancia(Punto, Punto);

Segmento createSegmento(Punto, Punto);           // ANALIZAR SI NECESITAMOS ESTE 

Poligono createPoligono(Puntos, Color);        // create o CREAR?? ver consigna y analizarlo juntos

double getPerimetro(Poligono);

double getLados(Poligono);

void addPunto(Puntos, Punto);

void addPoligono(Poligono, Poligono);

Poligono getNewPoligono(ifstream&);

//Creditos extra
Punto getPunto(Poligono, int);
Poligono removePunto(Poligono);

int main(){
    ifstream archivo("flujoPol.txt");
    //Color
    Color c {0, 0, 0};

    //Triangulo
    Punto x1 {0, 0};
    Punto x2 {1, 1};
    Punto x3 {0, 2};

    Puntos puntosTriangulo;
    puntosTriangulo.secuencia = {x1, x2, x3};

    Poligono triangulo = createPoligono(puntosTriangulo, c);

    //Cuadrado
    Punto c1 {0, 0};
    Punto c2 {1, 0};
    Punto c3 {1, 1};
    Punto c4 {0, 1};

    Puntos puntosCuadrado;
    puntosCuadrado.secuencia = {c1, c2, c3, c4};

    Poligono cuadrado = createPoligono(puntosCuadrado, c);

    SecuenciaPoligonos secuenciaDePoligonos;
    secuenciaDePoligonos.secuencia = {triangulo, cuadrado};

    assert(triangulo.segmentos.at(2).longitud == 2.0);

    assert(triangulo.segmentos.at(0).longitud +
           triangulo.segmentos.at(1).longitud +
           triangulo.segmentos.at(2).longitud == getPerimetro(triangulo));

    assert(getLados(triangulo) == 3);

    assert(getLados(cuadrado) == 4);

    assert(getPerimetro(cuadrado) == 4);
    
    return 0;

}

Punto LeerPunto(ifstream& f){
    Punto p;
    f >> p.PosX >> p.PosY;
    return p;
}

double getDistancia(Punto p1, Punto p2){
   return std::sqrt(std::pow(p2.PosX - p1.PosX, 2)+ std::pow(p2.PosY - p1.PosY, 2));
}

Segmento createSegmento(Punto p1, Punto p2){
    array<Punto, 2> puntos {p1, p2};
    Segmento segmento {puntos, getDistancia(p1, p2)};
    return segmento;
}

Poligono createPoligono(Puntos p, Color c){
    Poligono pol;
    pol.color = c;
    for (int i = 0; i < p.secuencia.size() - 1; i++){
        pol.segmentos.push_back(createSegmento(p.secuencia.at(i), p.secuencia.at(i+1)));
    }
    pol.segmentos.push_back(createSegmento(p.secuencia.at(p.secuencia.size()-1), p.secuencia.at(0)));
    pol.perimetro = getPerimetro(pol);
    pol.lados = getLados(pol);
    return pol;
}

double getPerimetro(Poligono p){
    double perimetro {0.0};
    for (size_t i{0}; i < p.segmentos.size(); ++i){
        perimetro = perimetro + p.segmentos.at(i).longitud;
    }
    return perimetro;
}

double getLados(Poligono p){
    return p.segmentos.size();
}

void addPunto(Puntos& puntos, Punto p){
    puntos.secuencia.push_back(p);
}

void addPoligono(SecuenciaPoligonos poligonos, Poligono p){
    poligonos.secuencia.push_back(p);
}

