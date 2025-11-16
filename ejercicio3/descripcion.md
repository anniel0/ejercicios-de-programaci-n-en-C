🎯 Ejercicio 2: Juego de la Vieja (Tic-Tac-Toe)

📝 Descripción General

Este proyecto implementa el clásico juego "El Juego de la Vieja" (Tic-Tac-Toe), enfrentando al usuario contra la computadora en un total de tres manos.

El objetivo del ejercicio es demostrar la capacidad de manejar el estado del juego utilizando solamente variables sencillas y archivos para la persistencia y la configuración.

⚠️ Restricción Crucial

NO está permitido el uso de matrices (arreglos bidimensionales) para representar el tablero. Se debe utilizar una estructura de datos simple (e.g., una lista unidimensional o cadenas de caracteres) que simule las 9 posiciones.

⚙️ Funcionamiento del Juego

Tablero: El tablero es de 3x3 (9 posiciones).

Jugadas:

Computadora: Elige una posición aleatoria y vacía mediante un generador de números aleatorios.

Usuario: Ingresa su jugada indicando la fila (1, 2 o 3) y la columna (1, 2 o 3) por teclado.

Manos: Se jugarán exactamente tres manos, cada una con su propia configuración inicial.

📥 Archivo de Entrada: turnos.txt

El archivo turnos.txt debe contener exactamente tres líneas, una para la configuración de cada mano. Cada línea consta de dos caracteres sin espacio, siguiendo el formato: [Símbolo Comp.][Comienza].

Jugador que realiza el primer movimiento.

U (Usuario) o C (Computadora)

Contenido Ejemplo de turnos.txt:
```
XU
OC
OC
```

📺 Salidas Esperadas

1. Salida por Terminal

El programa debe imprimir el estado del tablero después de cada jugada, tanto la de la computadora como la del usuario.

Ejemplo de Salida por Terminal (después de una jugada en fila=2, columna=3 con 'o'):
```
.|.|.
-+-+-
.|.|o
-+-+-
.|.|.
```

2. Archivo de Salida: manos.txt

Al finalizar cada mano (victoria, derrota o empate), el programa debe imprimir el estado final del tablero y el resultado en el archivo manos.txt.

Cada resultado de mano debe estar separado por la secuencia de símbolos: \n#############################\n.

Ejemplo de manos.txt:
```
x|.|o
-+-+-
x|o|.
-+-+-
x|o|X
Ganador: Jugador
#############################
x|x|o
-+-+-
o|o|x
-+-+-
x|o|X
Ganador: Computadora
#############################
x|x|o
-+-+-
o|o|x
-+-+-
x|o|X
Empate
#############################
```
