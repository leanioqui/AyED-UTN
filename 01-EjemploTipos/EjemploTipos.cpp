#include <iostream>
#include <cassert>
#include <string>
using namespace std::string_literals;

int main() {
    
  // bool
  assert(not true == false);
  assert(true and false == false);
  assert(not(true and false) == (not true or not false));  // Ley de De Morgan expresada con boolenos: true == true
  assert(true or false == true);
  assert((60 > 20) == true); // Al comparar enteros, el tipo de dato devuelto es un booleano
  assert(not(28 >= 6) == false); // Al comparar enteros, el tipo de dato devuelto es un booleano


  // char
  assert('/' + 'O' == 0x7E); // Resultado en hexadecimal
  assert('x' / '<' == 2);
  assert(('m' > 'l') or ('n' < 'a') == true); // Comparación de la posición de los caracteres en ASCII
  assert('A'<'B'== true); // Combinacion de char con booleano. Comparación de la posición de los caracteres en ASCII
  assert('d' + '@' > 120);
  assert('a' - 'A' == 32); // Distancia entre minúscula y mayúscula en ASCII


  // unsigned
  assert(10u / 2u != 17u);
  assert(200u * 2u == 400u);
  assert(30u > 20u);
  assert(2u + 7u == 9u);
  assert(15u % 4u == 3u);
  assert(10u - 10u == 0u);


  // int
  assert(0b1010 + 0b0101 == 15);
  assert(0xA > 0b1001); // 10 > 9
  assert(9 / 5 == 1); // División entre enteros, devuelve la parte entera del resultado
  assert(24 + 24 != 50);
  assert(0xC6 - 100 == 98); // Operación combinando hexadecimal y decimal
  assert((8 % 3) + 1 == 3);
  
  
  // double
  assert(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 != 1.0); // Esto sucede a la imprecisión de los números de punto flotante a la hora de representarlos.
  assert(10.5 / 2.0 == 5.25);
  assert((0.3 - 0.2) != (0.2 - 0.1)); // Ambos deberían ser 0.1, en este caso son valores muy cercanos pero diferentes
  assert(3.5 or 6.1 > 4.5);
  assert(0.125 * 8.0 == 1.0);
  assert(0.1 * 3.0 != 0.3);


  // string
  assert("abc"s + "123"s > "abc122"s);
  assert(("pre"s + "fijo"s).length() == 7);
  assert(""s != "abc"s); // Comparación de cadenas vacías con cadenas no vacías
  assert(("A"s + "B"s + "C"s == "ABC"s));
  assert("Algoritmos"s != "algoritmos"s); // Comparación de cadenas con diferentes mayúsculas y minúsculas
  assert("Hola, "s + "mundo!"s == "Hola, mundo!"s);

}
