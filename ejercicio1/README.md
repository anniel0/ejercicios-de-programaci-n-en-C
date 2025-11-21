
No se evaluará su entrega si emplea arreglos o estructuras (temas que no han sido cubiertos en clase todavía).
No seguir las indicaciones antes mencionadas repercutirá en la nota final de su entrega.

## Ejercicio 1. Mensajes Bovinos

Cowsay, es una utilidad GNU que fue originalmente desarrollada por Tony Moroe mediante el uso del lenguaje de programación Perl, lenguaje que se caracteriza por brindar una gran flexibilidad al programador dado que permite representar una misma acción de numerosas formas diferentes.

Esta peculiar utilidad le permite al usuario transformar un texto arbitrario en un ASCII-art de un personaje diciendo aquél mensaje que fue proporcionado en un globo de texto, en el cual, el personaje que aparece en la obra de arte le da nombre al programa, y no es más y nada menos que una vaca.

Este programa le ha otorgado alegría a los desarrolladores desde 1999 y comúnmente se usa junto a la utilidad fortune, para recibir sabios mensajes de una vaca (¡imagine que ocurriría si fuesen dos vacas!).

Dada la importancia del programa, se ha creado un mirror (servidor de respaldo) del mismo en la conocida página para almacenar código fuente, Github (https://github.com/cowsay-org/cowsay), y se encuentra actualmente disponible a todo público.

Tomando en cuenta la relevancia histórica de cowsay, su equipo ha decidido realizar un homenaje al planear una reimplementación del mismo utilizando el lenguaje C y usted, ha recibido el honor de ser el desarollador encargado de la elaboración del programa.

Su tarea consiste en crear un programa llamado `01-cowsay.c` que dado un archivo de entrada, genere la siguiente salida:

### Ejemplo de entrada y salida

**Entrada:** `01-mensaje.txt`
```
ABC

def

abc defghijkl 0- limit
 Texto

12345
 ABC

 def

There's a risk, an it's of rain
 abc defghijkl 0- limit

it's cinema
 12345



 There's a risk, an it's of rain

 it's cinema
```


**Salida:** `01-salida.txt`
```
*******************************************
* ABC                                     *
*                                         *
* def                                     *
*                                         *
* abc defghijkl 0- limit                 *
* Texto                                   *
*                                         *
* 12345                                   *
* ABC                                     *
*                                         *
* def                                     *
*                                         *
* There's a risk, an it's of rain         *
* abc defghijkl 0- limit                  *
*                                         *
* it's cinema                             *
* 12345                                   *
*                                         *
*                                         *
* There's a risk, an it's of rain         *
*                                         *
* it's cinema                             *
*                                         *
*                                         *
*******************************************
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```
