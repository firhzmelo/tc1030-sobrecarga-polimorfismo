# Análisis de los ejercicios de practica

Preguntas guía:
1. ¿Qué clase se define?
2. ¿Qué operador se sobrecarga?
3. ¿Cuántos operandos utiliza?
4. ¿Qué tipo de dato devuelve?
5. ¿El operador modifica el objeto actual o crea uno nuevo?
6. ¿La sobrecarga hace que el código sea más claro?
7. ¿Qué error común ayuda a evitar este ejemplo?

## Ejemplo 1

En este ejercicio se define la clase `Punto`, y el operador sobrecargado es el de la suma `+`, el cual ocupa 2 operandos. La sobrecarga devuelve un objeto nuevo de la clase `Punto`.

Esto si ayuda a la legibilidad del código, ya que no tienes que sumar las coordenadas de cada punto "manualmente", sino que definimos este comportamiento intuitivo y sea más sencillo de programar.

## Ejemplo 2

Se define la clase `Libro` y el operador sobrecargado es el de la comparación de igualdad `==`, el cual necesita de 2 operandos.

Esta sobrecarga regresa un `bool` y no modifica a los objetos involucrados, además de que nos ayuda a tener un código más legible y no tener que estar comparando atricutos por separado.

## Ejemplo 3

La clase creada es `Persona`, el operador sobrecargado es el operador de salida `<<`, la sobrecarga nos ayuda a definir el comportamiento de cómo debe de imprimirse una clase (qué atributos y en qué formato). Esto no modifica al objeto a imprimir.

## Ejemplo 4

Se define la clase `Contador` y se sobrecarga el operador unario `++` (solo necesita 1 operando), el cual devuelve un nuevo objeto que tiene el mismo contenido al objeto que estamos aplicando el incremento antes del incremento, pero si modifica al objeto que queremos aplicar el incremento.

Esto nos sirve para definir algun tipo de incremento, en una sola operación.

## Ejemplo 5

Se define la clase de `Cadena` y se sobrecarga el operador de asignación `=`, que regresa una referencia de un objeto `Cadena`. Y ocupa 2 operandos, el objeto que quires asignar y el cual vas a asignar.

Esta sobrecarga si modifica al objeto de la clase. Esta sobrecarga es muy útil ya que podemos crear e igualar nuevos objetos con unos ya existentes sin tener que usar el constructor.

## Ejemplo 6

Se define la clase `Tempertura`, y el operador sobrecargado es la converción de tipo o **casting**, en este caso `double()`, esta operación solo ocupa 1 operando y no modifica al objeto al que estas realizando la conversión.

Esto es de gran ayuda ya que nos pertime convertir entre objetos de una forma tradicional haciendo el código más intuitivo.