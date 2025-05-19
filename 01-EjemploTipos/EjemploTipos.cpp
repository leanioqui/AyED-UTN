#include <iostream>
#include <cassert>
#include <string>
using namespace std::string_literals;

int main() {
    
  // bool
  assert(not true == false);


  // char
  assert('/' + 'O' == 0x7E); // Resultado en hexadecimal


  // unsigned
  assert(10u / 2u != 17u);


  // int
  assert(0b1010 + 0b0101 == 15);

  
  // double
  assert(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 != 1.0); // Esto sucede a la imprecisión de los números de punto flotante a la hora de representarlos.


  // string
  assert("abc"s + "123"s > "abc122"s);

}
