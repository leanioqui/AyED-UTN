/* Necesidad #2: Dado los importes y meses (de 0 a 11), mostrar ventas totales
por mes. */

/*  Ejecutar los siguientes comandos desde la terminal powershell estando en la carpeta 04-Dims:
    g++ Dim1.cpp -o Dim1.exe
    Get-Content Test1.txt | .\Dim1
*/
#include <iostream>
#include <cassert>
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
    
    return 0;
}
