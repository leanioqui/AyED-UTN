#include <iostream>
#include <cassert>
#include <string>
using namespace std::string_literals;

int main() {
    
  // bool
  assert(not true == false);
  assert(true and false == false);


  // char
  assert('/' + 'O' == 0x7E); // Resultado en hexadecimal
  assert('x' / '<' == 2);


  // unsigned
  assert(10u / 2u != 17u);
  assert(200u * 2u == 400u);


  // int
  assert(0b1010 + 0b0101 == 15);
  assert(0xA > 0b1001); // 10 > 9

  
  // double
  assert(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 != 1.0); // Esto sucede a la imprecisión de los números de punto flotante a la hora de representarlos.
  assert(10.5 / 2.0 == 5.25);


  // string
  assert("abc"s + "123"s > "abc122"s);
  assert(("pre"s + "fijo"s).length() == 7);

}
