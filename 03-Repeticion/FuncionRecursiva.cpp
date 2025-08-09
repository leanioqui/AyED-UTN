#include <iostream>
#include <cassert>
#include <string>
using std::string;
using namespace std::string_literals;

unsigned int sumaDigitos(unsigned int n);
void pruebasSumaDigitos();
unsigned int contarVocales(string s, unsigned int i);
void pruebasContarVocales();
unsigned int sumaMultiplos4(unsigned int);
void pruebaSumaMultiplos4();

int main(){
    pruebasSumaDigitos();
    pruebasContarVocales();
    pruebaSumaMultiplos4();
    return 0;
}

unsigned int sumaDigitos(unsigned int n){
    return n<10?n:(n%10)+sumaDigitos(n/10);
}

unsigned int contarVocales(string s, unsigned int i) {
    if (i > s.size()) return 0;
    if (i == s.size()) return 0;
    char c = tolower(s[i]);
    bool esVocal = (c=='a' or c=='e' or c=='i' or c=='o' or c=='u');
    return (esVocal ? 1 : 0) + contarVocales(s, i + 1);
}

unsigned int sumaMultiplos4(unsigned int n)
{
    return (n <= 0) 
    ? 0 
    : (n % 4 == 0 ? n + sumaMultiplos4(n - 4) : sumaMultiplos4(n - 1));
}

void pruebasSumaDigitos(){
    assert(sumaDigitos(103)==4);
    assert(sumaDigitos(0)==0);
    assert(sumaDigitos(9)==9);
    assert(sumaDigitos(1358)==17);
}

void pruebasContarVocales(){
    assert(contarVocales("habla"s, 0)==2);
    assert(contarVocales("habla"s, 2)==1);
    assert(contarVocales(""s,0)==0);
    assert(contarVocales("n"s, 0)==0);
    assert(contarVocales(""s,3)==0);
    assert(contarVocales("HabLA"s, 0)==2);
}

void pruebaSumaMultiplos4(){
    assert(sumaMultiplos4(3) == 0); // No hay múltiplos de 4 <= 3
    assert(sumaMultiplos4(4) == 4); // 4 es el único múltiplo de 4 <= 4
    assert(sumaMultiplos4(10) == 12); // 4 + 8 = 12
    assert(sumaMultiplos4(25) == 84); // 4 + 8 + 12 + 16 + 20 + 24 = 84
}
