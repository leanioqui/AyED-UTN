/*  Necesidad #4: Dado los importes, meses, números de los tres vendedores, y
    números de las cuatro regiones (0, 1, 2, 4), mostrar total de ventas por mes,
    vendedor, y región. 

    • Implementar las funciones que permitan representar a
    los vendedores con strings y las regiones con enum
    (Norte, Sur, Este, y Oeste), en vez de representarlos
    con números.

    • Implementar las funciones LeerDatos y MostrarTotales.

    • Presentar las tablas lo más claro posible con formato,
    alineación numérica y con títulos.

    • Agregar estadísticas, por lo menos una que aplique
    máximo, otra mínimo, y otra promedio. Por ejemplo:
    GetVendedorConMasVentas(mes, región).

    • Describir en readme.md las ventajas y desventajas de
    aplicar:
    ◦ for-intervalo en vez de for clásico.
    ◦ std::array<T,N> en vez de T[N].
    ◦ •.at(•) en vez de •[•].
*/

/*  Ejecutar los siguientes comandos desde la terminal powershell estando en la carpeta 04-Dims:
    g++ Dim3Extra.cpp -o Dim3Extra.exe
    Get-Content Test3.txt | .\Dim3Extra
*/

#include <iostream>
#include <cassert>
#include <array>
#include <string>
#include <iomanip>
#include <limits>
using std::array;
using std::cin;
using std::cout;
using std::istream;
using std::string;
using std::setw;
using std::numeric_limits;

using matriz = array<array<array<unsigned, 3>, 4>, 12>; //12 meses, 4 regiones, 3 vendedores

enum class Region { Norte, Sur, Este, Oeste };   // Enum para regiones
const array<const string, 12> nombresMeses = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"}; // Array de strings para Meses
const array<const string, 4> nombresRegiones = {"Norte", "Sur", "Este", "Oeste"};   //Array de strings para Regiones
const array<const string, 3> nombresVendedores = {"Roberto", "Humberto", "Mamerto"};   //Array de strings para Vendedores

void TablaFinal(istream& flujo, matriz& final);
matriz LeerDatos(istream& flujo);
unsigned GetMaximo(const matriz&, int mes, int region);
unsigned GetMinimo(const matriz&, int mes, int region);
double GetPromedio(const matriz&, int mes, int region);
int GetVendedorConMasVentas(const matriz&, int mes, int region);

int main(){
    matriz final;
    TablaFinal(cin, final);
}

matriz LeerDatos(istream& flujo){
    matriz totalDatos = {};
    int mes, region, vendedor, importe;
    while(flujo >> mes >> region >> vendedor >> importe)
        totalDatos.at(mes).at(region).at(vendedor) += importe;
    return totalDatos;
}

 void TablaFinal(istream& flujo, matriz& final){
    final = LeerDatos(flujo);
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
        // Agregar estadísticas por región
        cout << string(anchoCelda * 13, '-') << "\n";
        for (int m = 0; m < 12; m++) {
            unsigned max = GetMaximo(final, m, r);
            unsigned min = GetMinimo(final, m, r);
            double prom = GetPromedio(final, m, r);
            int mejor = GetVendedorConMasVentas(final, m, r);

            cout << "Mes " << nombresMeses.at(m) << ": "
                 << "Max=" << max
                 << " (" << nombresVendedores.at(mejor) << ") "
                 << "| Min=" << min
                 << " | Prom=" << prom << "\n";
        }
        cout << "\n";
    }
}
//---------------- ESTADÍSTICAS ----------------//

unsigned GetMaximo(const matriz& datos, int mes, int region) {
    unsigned maximo = 0;
    for (int v = 0; v < 3; v++)
        if (datos.at(mes).at(region).at(v) > maximo)
            maximo = datos.at(mes).at(region).at(v);
    return maximo;
}

unsigned GetMinimo(const matriz& datos, int mes, int region) {
    unsigned minimo = numeric_limits<unsigned>::max(); //inicializo al valor maximo posible del tipo unsigned
    for (int v = 0; v < 3; v++)
        if (datos.at(mes).at(region).at(v) < minimo)
            minimo = datos.at(mes).at(region).at(v);
    return minimo == numeric_limits<unsigned>::max() ? 0 : minimo; // Si minimo es igual al valor maximo, significa que no hubo ventas, entonces retorno 0, sino retorno el minimo encontrado
}

double GetPromedio(const matriz& datos, int mes, int region) {
    unsigned suma = 0;
    for (int v = 0; v < 3; v++)
        suma += datos.at(mes).at(region).at(v);
    return static_cast<double>(suma) / 3.0;
}

int GetVendedorConMasVentas(const matriz& datos, int mes, int region) {
    unsigned maximo = 0;
    int mejor = 0;
    for (int v = 0; v < 3; v++) {
        if (datos.at(mes).at(region).at(v) > maximo) {
            maximo = datos.at(mes).at(region).at(v);
            mejor = v;
        }
    }
    return mejor;
}