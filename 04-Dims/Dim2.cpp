#include <iostream>
#include <cassert>
#include <array>
using std::array;
using std::cin;
using std::cout;
using std::istream;

using matriz = array<array<unsigned, 12>, 3>;

matriz ventasTotales (istream& flujo){
    matriz total = {};
    for (int mes, vendedor, importe; flujo >> mes >> vendedor >> importe;)
       total.at(vendedor).at(mes) += importe;
       
    return total;
}

int main(){
    
    return 0;
}