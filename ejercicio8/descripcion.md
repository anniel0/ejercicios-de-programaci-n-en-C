# Ejercicio 2: Autómata celular

Un Autómata celular, es una máquina abstracta que consiste en un rejilla de una, dos o tres
dimensiones. En cada celda de la rejilla se almacena un valor que pertenece a un conjunto finito
de estados. El cambio de un estado a otro en una celda durante una iteración t+1 depende de lo
almacenado en ella misma y de los estados vecinos (celdas vecinas) en la iteración t.

Elabore un programa llamado 02-automata.c que simule un Autómata celular bidimensional de
dos estados: “vivo” o “muerto”. Para un número entero de iteraciones, se deben (por cada una)
evaluar todas las celdas y según sus ocho vecinos adyacentes y el valor que dicha celda
contenga, actualizarla según las siguientes reglas:

a) Se reemplaza una celda en estado muerto por vivo si tiene exactamente 3 vecinos en
estado vivo.

b) Se reemplaza una celda en estado vivo por muerto si no tiene más de 1 vecino en estado
vivo o si

c) Tiene más de 3 vecinos vivos.

d) Una celda en estado vivo permanecerá en ese estado si tiene 2 o 3 vecinos vivos.

e) De no ocurrir ninguna de las anteriores, el contenido de la celda en cuestión permanece
igual.

La información de entrada se almacena en un archivo llamado atc.txt con la siguiente estructura
```
n
nv
nit
```

Donde n es el número de celdas por dimensión del autómata; nv < = n, es el número de celdas
en estado vivo y nit, el número de iteraciones. La posiciones de celdas en estado vivo se
escogerán inicialmente de manera aleatoria.

El programa debe leer esa información y cargarla en una estructura conveniente e imprimir en
forma matricial en el mismo archivo el contenido del autómata correspondiente a las iteraciones
1, nit/2, nit/4, 3/4nit y nit.

Para una celda en estado vivo imprimir el carácter '#' , y '.' para el estado
muerto. Cada iteración se separará por una línea de esta forma:

==============k:ki===============

Además; al finalizar las iteraciones, hay que reportar la cantidad de celdas en estado vivo y el
porcentaje de incremento o decremento en esa cantidad respecto a nv.

NOTA: Para las celdas que pertenezcan al principio, final, extremo izquierdo y/o derecho de la
rejilla; los vecinos faltantes se toman, respectivamente, del final, principio, extremo derecho y/o
izquierdo (frontera periódica).
