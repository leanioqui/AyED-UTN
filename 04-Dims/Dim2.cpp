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
#include <iomanip>
using std::array;
using std::cin;
using std::cout;
using std::istream;
using std::string;
using std::setw;


using matriz = array<array<unsigned, 3>, 12>; //12 meses, 3 vendedores

matriz ventasTotales (istream&);

int main(){
    array<const string, 12> nombresMeses = {
        "Enero","Febrero","Marzo","Abril","Mayo","Junio",
        "Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"
    };
    array<const string, 3> nombresVendedores = {"Jose", "Maria", "Manuel"};

    matriz final = ventasTotales(cin);

    const int anchoCelda = 8; // ancho fijo para cada columna

    // Encabezado de meses
    cout << setw(anchoCelda) << "Vendedor";
    for(int m=0; m<12; m++)
        cout << setw(anchoCelda) << nombresMeses.at(m).substr(0,3); // abreviar a las tres primeras letras del mes y rellenar con caracteres de espacio
    cout << "\n";

    // Separador
    cout << string(anchoCelda*13, '-') << "\n"; // anchoCelda * (12 meses + columna vendedor)

    // Filas de vendedores
    for(int v=0; v<3; v++){
        cout << setw(anchoCelda) << nombresVendedores.at(v);
        for(int m=0; m<12; m++)
            cout << setw(anchoCelda) << final.at(m).at(v);
        cout << "\n";
    }

    return 0;
}

matriz ventasTotales (istream& flujo){
    matriz total = {};
    for (int mes, vendedor, importe; flujo >> mes >> vendedor >> importe;)
       total.at(mes).at(vendedor) += importe; //de afuera hacia adentro
       
    return total;
}