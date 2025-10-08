#include <iostream>
#include <cassert>
#include <array>
using std::array;
using std::cin;
using std::cout;
using std::istream;


using matriz = array<array<unsigned, 3>, 12>; //12 meses, 3 vendedores

matriz ventasTotales (istream&);

int main(){

    unsigned m, v;
    const char* nombresMeses[] = {
    "Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"
};

    matriz final = ventasTotales(cin);
        for (m = 0; m < final.size(); ++m){
    cout << "\nMes de " << nombresMeses[m] << ": \n";
    for (v = 0; v < final.at(m).size(); ++v)
        cout << "Vendedor " << v << ": " << final.at(m).at(v) << "\n";

    }
    return 0;
}

matriz ventasTotales (istream& flujo){
    matriz total = {};
    for (int mes, vendedor, importe; flujo >> mes >> vendedor >> importe;)
       total.at(mes).at(vendedor) += importe; //de afuera hacia adentro
       
    return total;
}