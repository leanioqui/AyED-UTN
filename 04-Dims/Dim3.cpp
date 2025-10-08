/* Necesidad #4: Dado los importes, meses, números de los tres vendedores, y
números de las cuatro regiones (0, 1, 2, 4), mostrar total de ventas por mes,
vendedor, y región. */

/*  Ejecutar los siguientes comandos desde la terminal powershell estando en la carpeta 04-Dims:
    g++ Dim3.cpp -o Dim3.exe
    Get-Content Test3.txt | .\Dim3
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


using matriz = array<array<array<unsigned, 3>, 4>, 12>; //12 meses, 4 regiones, 3 vendedores

matriz ventasTotales (istream&);

int main(){

    array<const string, 12> nombresMeses = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
    array<const string, 4> nombresRegiones = {"Norte", "Sur", "Este", "Oeste"};
    array<const string, 3> nombresVendedores = {"Roberto", "Humberto", "Mamerto"};

    matriz final = ventasTotales(cin);

    const int anchoCelda = 8; // ancho fijo para cada columna

    for(int r=0; r<4; r++){ // Cambiar entre regiones
        //Encabezado de región
        cout << "\n======== Region: " << nombresRegiones.at(r) << " ========\n"; 

        // Encabezado de meses
        cout << setw(anchoCelda) << "Vendedor"; 
        for(int m=0; m<12; m++)
            cout << setw(anchoCelda) << nombresMeses.at(m) .substr(0,3); // abreviar a las tres primeras letras del mes y rellenar con caracteres de espacio
        cout << "\n";

        // Separador
        cout << string(anchoCelda*13, '-') << "\n"; // anchoCelda * (12 meses + columna vendedor)

        // Filas de vendedores
        for(int v=0; v<3; v++){
            cout << setw(anchoCelda) << nombresVendedores.at(v);
            for(int m=0; m<12; m++)
                cout << setw(anchoCelda) << final.at(m).at(r).at(v);
            cout << "\n";
        }
    }
    return 0;
}

matriz ventasTotales (istream& flujo){
    matriz total = {};
    for (int mes, region, vendedor, importe; flujo >> mes >> region >> vendedor >> importe;)
       total.at(mes).at(region).at(vendedor) += importe; //de afuera hacia adentro
       
    return total;
}