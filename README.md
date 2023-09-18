# Juego de NIM en C++ con IA Estrategia Perfecta

## Reglas del Juego

El juego de NIM se juega entre 2 jugadores y consta de varias pilas de piezas. Los jugadores se turnan para tomar piezas de una sola pila en su respectivo turno. En esta versión de NIM, el objetivo es ser el jugador que tome la última pieza.

## Programa

Este programa en C++ te permite jugar al NIM contra una IA que utiliza una estrategia perfecta para ganar. Aquí hay una descripción de las características principales:

- El usuario puede seleccionar el número de pilas y la cantidad de piezas por pila en cada partida.
- La IA elegirá los turnos y nunca perderá.

## Cómo Jugar

1. Ejecuta el programa.
2. Ingresa "1" para jugar o "0" para salir.
3. En el juego, selecciona una pila de la cual tomar piezas e ingresa el número de piezas que deseas tomar.
4. La IA también tomará su turno, utilizando una estrategia perfecta para ganar.
5. Continúa tomando turnos hasta que alguien tome la última pieza.
6. El jugador que tome la última pieza es el ganador.

## Cómo Ejecutar el Programa

Asegúrate de tener un entorno de desarrollo C++ configurado.

1. Clona el repositorio o descarga el código fuente.
2. Compila el programa utilizando un compilador C++.
3. Ejecuta el programa resultante.

## Estrategia de la IA

La IA utiliza una estrategia perfecta para ganar. En cada turno, encuentra una pila que le permita aplicar una operación XOR entre todas las pilas de manera que el resultado sea igual a cero. Luego, selecciona una cantidad de piezas que reduzca el valor en esa pila a un valor deseado.

## Pruebas

El programa también incluye una opción para realizar pruebas, donde la IA juega contra sí misma con movimientos aleatorios. Puedes probar la IA en diferentes configuraciones de pilas y piezas.

## Contribución

Si deseas contribuir a este proyecto o tienes sugerencias para mejorarlo, ¡estamos abiertos a tus ideas! Siéntete libre de abrir solicitudes de extracción o informar problemas.

