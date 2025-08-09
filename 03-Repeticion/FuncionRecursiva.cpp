#include <iostream>
#include <cassert>
#include <string>
using std::string;
using namespace std::string_literals;

unsigned int sumaDigitos(unsigned int n);
void pruebasSumaDigitos();
unsigned int contarVocales(string s, unsigned int i);
void pruebasContarVocales();

int main(){
    pruebasSumaDigitos();
    pruebasContarVocales();
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

void pruebasSumaDigitos(){
    assert(sumaDigitos(103)==4);
    assert(sumaDigitos(0)==0);
    assert(sumaDigitos(9)==9);
    assert(sumaDigitos(1358)==17);
}

void pruebasContarVocales(){
}