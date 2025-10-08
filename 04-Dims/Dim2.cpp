/* Necesidad #3: Dado los importes, meses, y números de los tres vendedores
(0, 1, 2), mostrar total de ventas por mes y vendedor. */

/*  Ejecutar los siguientes comandos desde la terminal powershell estando en la carpeta 04-Dims:
    g++ Dim2.cpp -o Dim2.exe
    Get-Content Test2.txt | .\Dim2
*/

#include <iostream>
#include <cassert>
#include <array>
#include <string>
using std::array;
using std::cin;
using std::cout;
using std::istream;
using std::string;


using matriz = array<array<unsigned, 3>, 12>; //12 meses, 3 vendedores

matriz ventasTotales (istream&);

int main(){

    unsigned m, v;
    array<const string, 12> nombresMeses = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    array<const string, 3> nombresVendedores = {"Jose", "Maria", "Leandro"};
    matriz final = ventasTotales(cin);
        for (m = 0; m < final.size(); ++m){
    cout << "\nMes de " << nombresMeses.at(m) << ": \n";
    for (v = 0; v < final.at(m).size(); ++v)
        cout << "Vendedor/a " << nombresVendedores.at(v) << ": " << final.at(m).at(v) << "\n";

    }
    return 0;
}

matriz ventasTotales (istream& flujo){
    matriz total = {};
    for (int mes, vendedor, importe; flujo >> mes >> vendedor >> importe;)
       total.at(mes).at(vendedor) += importe; //de afuera hacia adentro
       
    return total;
}