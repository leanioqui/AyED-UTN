#include <iostream>
#include <cassert>
#include <string>
using std::string;
using namespace std::string_literals;

unsigned int sumaDigitos(unsigned int n);

int main(){
    return 0;
}

unsigned int sumaDigitos(unsigned int n){
    return n<10?n:(n%10)+sumaDigitos(n/10);
}