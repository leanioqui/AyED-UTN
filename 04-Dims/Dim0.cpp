/* Necesidad #1: Dado los importes, mostrar ventas totales. */

/*  Ejecutar los siguientes comandos desde la terminal powershell estando en la carpeta 04-Dims:
    g++ Dim0.cpp -o Dim0.exe
    Get-Content Test0.txt | .\Dim0
*/


#include <iostream>
#include <cassert>
using std::cin;
using std::cout;
using std::istream;

int ventasTotales (istream& flujo){
    int total = {};
    for (int importe; flujo >> importe;){
        total += importe;
    }
    return total;
}

int main(){
    int total = ventasTotales(cin);
    cout << "El total de ventas es: " << total << '\n';
    return 0;
}

