#include <iostream>
#include <cassert>
#include <string>
using std::string;
using namespace std::string_literals;

string frase(unsigned int n);

int main(){
    assert(frase(0)==""s);
    assert(frase(3)=="Voy a estudiar programacion \nVoy a estudiar programacion \nVoy a estudiar programacion \n"s);
    std::cout << frase(0);
    return 0;
}

string frase(unsigned int n){
    return n==0?""s:"Voy a estudiar programacion \n"s+frase(n-1);   
}