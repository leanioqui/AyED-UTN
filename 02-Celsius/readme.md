# 🟢 Funciones y Comparación de Valores en Punto Flotante

Este es el segundo trabajo práctico grupal de la materia **Algoritmos y Estructuras de Datos**.

## 🧾 Descripción

Diseñar un programa C++ trabajando con las funciones AreNear, Celsius y Fahrenheit. Se calcularán las conversiones de temperaturas, se harán pruebas acompañadas de tablas y gráficos.

## Objetivos
Demostrar el manejo de funciones y valores punto flotante.

## Temas
- Funciones
- Tipo double
- División entera y flotante
- Pruebas con assert
- Argumentos con valor por defecto
- Introducción a iteraciones con for

## Definiciones matematica de las funciones

Se definen las funciones de conversión entre grados Fahrenheit y grados Celsius de forma matematica. Como tambien se define y se explica la funcion AreNear.

---


### Función Celsius

Definimos la función `C: ℝ → ℝ` como:

  C(F) = (5/9) × (F − 32)

donde F es la temperatura en grados Fahrenheit, y C(F) es la temperatura en grados Celsius.

---

### Función Fahrenheit

Definimos la función `F: ℝ → ℝ` como:

  F(C) = (9/5) × C + 32

donde C es la temperatura en grados Celsius, y F(C) es la temperatura en grados Fahrenheit.

---

Ambas funciones son inversas entre sí:

C(F(C)) = C  
F(C(F)) = F

---

### Función AreNear

Definimos la función `h: ℝ × ℝ × ℝ≥0 → {true, false}` como:

  h(a, b, ε) =  
    true  si |a − b| ≤ ε  
    false en otro caso

donde:  
- `a` y `b` son números reales.  
- `ε` (épsilon) es una tolerancia real no negativa (`ε ≥ 0`).  
- `|a − b|` representa el valor absoluto de la diferencia entre `a` y `b`.

---

#### Interpretación

La función `AreNear` devuelve `true` si los números `a` y `b` están a una distancia menor o igual que `ε`.  
Esto se utiliza frecuentemente para comparar valores en **cálculos numericos**, donde pueden existir errores de redondeo.

---

#### Propiedades

- Es simétrica: `h(a, b, ε) == h(b, a, ε)`
- Si `ε = 0`, entonces `h(a, b, 0)` es equivalente a `a == b`
- Si `|a − b| > ε`, entonces `h(a, b, ε)` devuelve `false`