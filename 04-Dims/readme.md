# 🟢 Arreglos & Dimensiones

Este es el cuarto trabajo práctico grupal de la materia **Algoritmos y Estructuras de Datos**.

## 🧾 Descripción

Diseñar un programa C++ para calcular el total de ventas. Se crearán distintas funciones para lograr 4 necesidades diferentes. Cada archivo .cpp será la resolución de una necesidad.

- Necesidad #1: Dado los importes, mostrar ventas totales.
- Necesidad #2: Dado los importes y meses (de 0 a 11), mostrar ventas totales
por mes.
- Necesidad #3: Dado los importes, meses, y números de los tres vendedores
(0, 1, 2), mostrar total de ventas por mes y vendedor.
- Necesidad #4: Dado los importes, meses, números de los tres vendedores, y
números de las cuatro regiones (0, 1, 2, 4), mostrar total de ventas por mes,
vendedor, y región.


## Objetivos
Construir tipos compuestos.
Aplicar ciclo for clásicos y de ciclo for de intervalos (range_for).
Aplicar redireccionamiento de los flujos estándar.

## Temas
- Producto cartesiano.
- Secuencias finitas.
- Tipos std::array<T,N>.
- Inferencia de tipo con auto.
- Streams (flujos).
- Redirección de entrada y salida.
- Interfaz fluida.
- for clásico: for ( sentencia-inic condiciónopc ; expresiónopc ) sentencia
- for intervalo: for ( sentencia-inicopc declaración-for-intervalo : inicializadorfor-intervalo ) sentencia

## Crédito Extra

### 🔹Comparativa entre `for` de intervalo (`for (auto x : contenedor)`) y `for` clásico (`for (int i = 0; i < n; i++)`)

**Ventajas:**

* El código queda **más limpio y fácil de leer**, evitando errores de índice.
* Se adapta automáticamente al tamaño del contenedor, sin necesidad de usar `.size()`.
* Es ideal cuando simplemente se quiere **recorrer todos los elementos** de un arreglo o colección.

**Desventajas:**

* No permite acceder fácilmente al **índice** de cada elemento.
* Si no se usa referencia (`auto&`), no se pueden modificar directamente los valores del contenedor.
* Menos flexible si se necesita recorrer solo una parte o hacerlo en orden inverso.

---

### 🔹 `std::array<T, N>` vs `T[N]` (arreglo clásico)

**Ventajas:**

* Mantiene el tamaño fijo como un arreglo común, pero con la **seguridad y ventajas** de las estructuras modernas de C++.
* **Permite usar funciones de la **STL** (`.size()`, `.begin()`, `.end()`, `std::sort()`, etc.).**
* Es más **seguro y fácil de manejar** al pasarlo a funciones.
* Detecta errores de tipo y de acceso con mayor facilidad.

**Desventajas:**

* Tiene una **mínima sobrecarga** respecto al arreglo clásico, aunque insignificante en la mayoría de los casos.
* No se puede redimensionar.
* Su sintaxis es un poco más larga o “pesada” de escribir.

---

### 🔹 `.at()` vs `[ ]`

**Ventajas de `.at()`:**

* Controla los **límites de acceso**: si se intenta acceder fuera del rango, lanza una excepción (`std::out_of_range`).
* Ayuda a **evitar errores de memoria** difíciles de rastrear.
* Ideal para entornos donde se prioriza la seguridad del programa.

**Desventajas de `.at()`:**

* Es **un poco más lenta** que el operador `[ ]` por hacer la verificación de rango.
* Si se tiene total certeza de que los índices son válidos, `[ ]` resulta más eficiente.