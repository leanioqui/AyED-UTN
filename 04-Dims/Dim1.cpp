/* Necesidad #2: Dado los importes y meses (de 0 a 11), mostrar ventas totales
por mes. */

/*  Ejecutar los siguientes comandos desde la terminal powershell estando en la carpeta 04-Dims:
    g++ Dim1.cpp -o Dim1.exe
    Get-Content Test1.txt | .\Dim1
*/
#include <iostream>
#include <cassert> // No se pidio, pero sirve para comprobar que salga todo correctamente
#include <array>
using std::array;
using std::cin;
using std::cout;

template<unsigned N>
array<unsigned, N> ventasPorMes(std::istream& in) {
    array<unsigned, N> ventas = {};
    int importe, mes;
    for (; in >> importe >> mes; ) {
        if (mes >= 0 and mes < N)
            ventas.at(mes) += importe; 
    }

    return ventas;
}

int main(){
    auto ventas = ventasPorMes<12>(cin); 

    unsigned mes = 0; 
    // for de intervalo
    for (unsigned importe : ventas) {
        cout << "Mes " << mes << " = " << importe << '\n';
        ++mes; 
    }

    assert(ventas[0] == 240);
    assert(ventas[1] == 400);
    assert(ventas[2] == 0);
    assert(ventas[3] == 45);
    assert(ventas[4] == 0);
    assert(ventas[5] == 50);
    assert(ventas[6] == 300);
    assert(ventas[7] == 0);
    assert(ventas[8] == 0);
    assert(ventas[9] == 120);
    assert(ventas[10] == 0);
    assert(ventas[11] == 50);
    return 0;
}
