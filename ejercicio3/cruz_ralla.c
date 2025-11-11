
/*
Implementar el juego de la vieja, utilizando solamente variables sencillas y archivos, es decir, no
está permitido el uso de matrices.

En esta ocasión usted jugará tres manos contra la computadora. Ésta, mediante el uso de un
generador de números aleatorios, eligirá una posición aleatoria del tablero, y usted ingresará la
posición de su elección por teclado, indicando un valor para la fila y otro para la columna del
tablero.

En un archivo de entrada llamado turnos.txt se indicará quien comienza por cada mano, además
que símbolo toma la computadora:

Archivo: ./turnos.txt
XU
OC
OC

En el caso de la primera mano, la computadora jugará con la “X” y usted con la “O” y
adicionalmente, usted jugará primero. En cambio, en la segunda y tercera mano, la computadora
jugará con la “O”, y ella comenzará la partida, etc.

Cada vez que sea el turno de la computadora, la misma deberá realizar su jugada y
posteriormente, el programa deberá mostrar por pantalla el estado del tablero. Por ejemplo, si la
posición elegida es fila=1 y columna=2, se imprimirá el tablero de la siguiente:

Salida por Terminal (1):

.|.|.
-+-+-
.|.|o
-+-+-
.|.|.

Cuando sea su turno, se le pedirá la fila y la columna, y una vez que elija, se imprimirá el tablero
(si su elección fue la posición fue fila=2, columna=1):
Salida por Terminal (2):

.|.|.
-+-+-
.|.|o
-+-+-
.|x|.

Si la mano se tranca o hay un ganador se debe imprimir en un archivo llamado manos.txt el
estado final del tablero y decir quien ganó o si hubo “empate”. Cada resultado debe ir separada
por la secuencia de símbolos: “\n#############################\n”
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// variables globales para el inicio del juego
char pos_1_1, pos_1_2, pos_1_3,
    pos_2_1, pos_2_2, pos_2_3,
    pos_3_1, pos_3_2, pos_3_3;

// funcion que retorna un numero aleatorio entre un rango(minimo,maximo)
int aleatorio(int minimo, int maximo);
// lectura del archivo
void lectura_archivo();
// inicio de cada partida de juego
void inicio_juego(int partidas, char letra, char jugadorInicial);
// decidir la letra de cada jugador
int decidir_letrasJugador(char letra, char jugadorInicial, char *letraJugador, char *letraComputadora);
// modifica las casillas
int modificar_casilla(int pos_x, int pos_y, char letra);
// toma la posicion del usuario
void turno_jugador(char letraJugador);
// toma la posicion de la computadora
void turno_computadora(char letraComputadora);
// imprime el juego
void imprimir_juego();
// indica si se alguien gano y detiene el juego
int punto_ganador(char *letraGanadora);

int main()
{
    lectura_archivo();
    return 0;
}
// lectura del archivo
void lectura_archivo()
{
    FILE *archivo = fopen("turnos.txt", "r");

    if (archivo == NULL)
    {
        printf("Error: No se pudo abrir el archivo turnos.txt\n");
        return;
    }

    char letra, jugador;
    int i = 1;
    while (fscanf(archivo, " %c %c", &letra, &jugador) == 2)
    {
        inicio_juego(i, letra, jugador);
        i++;
    }

    fclose(archivo);
}
// inicio de cada partida de juego
void inicio_juego(int partidas, char letra, char jugadorInicial)
{
    // variables:
    FILE *archivo_salida;
    if (partidas == 1)
    {
        archivo_salida = fopen("manos.txt", "w");
    }
    else
    {
        archivo_salida = fopen("manos.txt", "a");
    }
    if (archivo_salida == NULL)
    {
        printf("Error: No se pudo abrir el archivo manos.txt\n");
        return;
    }

    char letraJugador, letraComputadora;
    if (decidir_letrasJugador(letra, jugadorInicial, &letraJugador, &letraComputadora))
    {
        fclose(archivo_salida);
        return;
    }

    // casillas disponibles
    char letraGanadora = 'V';
    int casillasDisponibles = 9;

    // variables para el inicio del juego
    pos_1_1 = '*';
    pos_1_2 = '*';
    pos_1_3 = '*';
    pos_2_1 = '*';
    pos_2_2 = '*';
    pos_2_3 = '*';
    pos_3_1 = '*';
    pos_3_2 = '*';
    pos_3_3 = '*';

    printf("Nuevo juego: Jugador=%c, Computadora=%c, Inicia=%c\n",
           letraJugador, letraComputadora, jugadorInicial);

    for (int i = 0; i < casillasDisponibles && !punto_ganador(&letraGanadora); i++)
    {
        if (jugadorInicial == 'U')
        {
            // elección del jugador
            turno_jugador(letraJugador);
            if (punto_ganador(&letraGanadora))
                break;

            // elección de la computadora (si hay casillas disponibles)
            if (i < casillasDisponibles - 1)
            {
                turno_computadora(letraComputadora);
            }
        }
        else
        {
            // eleccion de la computadora
            turno_computadora(letraComputadora);
            if (punto_ganador(&letraGanadora))
                break;

            // eleccion del jugador (si hay casillas disponibles)
            if (i < casillasDisponibles - 1)
            {
                turno_jugador(letraJugador);
            }
        }

        // imprimir juego en terminal
        imprimir_juego();
        printf("###################################################\n");
    }

    // Guardar resultado final en el archivo
    fprintf(archivo_salida,
            "%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n",
            pos_1_1, pos_1_2, pos_1_3,
            pos_2_1, pos_2_2, pos_2_3,
            pos_3_1, pos_3_2, pos_3_3);

    if (letraGanadora == letraJugador)
    {
        fprintf(archivo_salida, "Ganador: USUARIO\n");
        printf("Ganador: USUARIO\n");
    }
    else if (letraGanadora == letraComputadora)
    {
        fprintf(archivo_salida, "Ganador: COMPUTADORA\n");
        printf("Ganador: COMPUTADORA\n");
    }
    else
    {
        fprintf(archivo_salida, "Ganador: EMPATE\n");
        printf("Ganador: EMPATE\n");
    }
    fprintf(archivo_salida, "###################################################\n");

    fclose(archivo_salida);
}
// decidir la letra de cada jugador
int decidir_letrasJugador(char letra, char jugadorInicial, char *letraJugador, char *letraComputadora)
{
    int noValido = 0;
    switch (jugadorInicial)
    {
    case 'U':
        switch (letra)
        {
        case 'X':
            *letraJugador = letra;
            *letraComputadora = 'O';
            break;
        case 'O':
            *letraJugador = letra;
            *letraComputadora = 'X';
            break;
        default:
            noValido = 1;
            break;
        }
        break;
    case 'C':
        switch (letra)
        {
        case 'X':
            *letraComputadora = letra;
            *letraJugador = 'O';
            break;
        case 'O':
            *letraComputadora = letra;
            *letraJugador = 'X';
            break;
        default:
            noValido = 1;
            break;
        }
        break;
    default:
        noValido = 1;
        break;
    }
    return noValido;
}
// funcion que retorna un numero aleatorio entre un rango(minimo,maximo)
int aleatorio(int minimo, int maximo)
{
    static int inicializado = 0;
    if (!inicializado)
    {
        srand(time(NULL));
        inicializado = 1;
    }
    return minimo + rand() % (maximo - minimo + 1);
}
// modifica las casillas
int modificar_casilla(int pos_x, int pos_y, char letra)
{
    int valido = 0;
    if (pos_x == 1 && pos_y == 1 && pos_1_1 == '*')
    {
        pos_1_1 = letra;
        valido = 1;
    }
    else if (pos_x == 1 && pos_y == 2 && pos_1_2 == '*')
    {
        pos_1_2 = letra;
        valido = 1;
    }
    else if (pos_x == 1 && pos_y == 3 && pos_1_3 == '*')
    {
        pos_1_3 = letra;
        valido = 1;
    }
    else if (pos_x == 2 && pos_y == 1 && pos_2_1 == '*')
    {
        pos_2_1 = letra;
        valido = 1;
    }
    else if (pos_x == 2 && pos_y == 2 && pos_2_2 == '*')
    {
        pos_2_2 = letra;
        valido = 1;
    }
    else if (pos_x == 2 && pos_y == 3 && pos_2_3 == '*')
    {
        pos_2_3 = letra;
        valido = 1;
    }
    else if (pos_x == 3 && pos_y == 1 && pos_3_1 == '*')
    {
        pos_3_1 = letra;
        valido = 1;
    }
    else if (pos_x == 3 && pos_y == 2 && pos_3_2 == '*')
    {
        pos_3_2 = letra;
        valido = 1;
    }
    else if (pos_x == 3 && pos_y == 3 && pos_3_3 == '*')
    {
        pos_3_3 = letra;
        valido = 1;
    }
    return valido;
}
// toma la posicion del usuario
void turno_jugador(char letraJugador)
{
    int pos_x, pos_y;
    do
    {
        printf("Selecciona una casilla vacia (fila,columna): ");
        scanf("%d %d", &pos_x, &pos_y);
        if (pos_x < 1 || pos_x > 3)
        {
            printf("Numero de fila fuera de rango (1-3)\n");
            continue;
        }
        if (pos_y < 1 || pos_y > 3)
        {
            printf("Numero de columna fuera de rango (1-3)\n");
            continue;
        }
        if (!modificar_casilla(pos_x, pos_y, letraJugador))
        {
            printf("Casilla ya ocupada\n");
        }
        else
        {
            break;
        }
    } while (1);
}
// toma la posicion de la computadora
void turno_computadora(char letraComputadora)
{
    int pos_x, pos_y;
    do
    {
        pos_x = aleatorio(1, 3);
        pos_y = aleatorio(1, 3);
    } while (!modificar_casilla(pos_x, pos_y, letraComputadora));
    printf("Computadora juega en (%d,%d)\n", pos_x, pos_y);
}
// imprime el juego
void imprimir_juego()
{
    printf("\n%c|%c|%c\n-+-+-\n%c|%c|%c\n-+-+-\n%c|%c|%c\n\n",
           pos_1_1, pos_1_2, pos_1_3,
           pos_2_1, pos_2_2, pos_2_3,
           pos_3_1, pos_3_2, pos_3_3);
}
// indica si se alguien gano y detiene el juego
int punto_ganador(char *letraGanadora)
{
    // caso por fila
    if (pos_1_1 != '*' && pos_1_1 == pos_1_2 && pos_1_2 == pos_1_3)
    {
        *letraGanadora = pos_1_1;
        return 1;
    }
    else if (pos_2_1 != '*' && pos_2_1 == pos_2_2 && pos_2_2 == pos_2_3)
    {
        *letraGanadora = pos_2_1;
        return 1;
    }
    else if (pos_3_1 != '*' && pos_3_1 == pos_3_2 && pos_3_2 == pos_3_3)
    {
        *letraGanadora = pos_3_1;
        return 1;
    }
    // caso por columna
    else if (pos_1_1 != '*' && pos_1_1 == pos_2_1 && pos_2_1 == pos_3_1)
    {
        *letraGanadora = pos_1_1;
        return 1;
    }
    else if (pos_1_2 != '*' && pos_1_2 == pos_2_2 && pos_2_2 == pos_3_2)
    {
        *letraGanadora = pos_1_2;
        return 1;
    }
    else if (pos_1_3 != '*' && pos_1_3 == pos_2_3 && pos_2_3 == pos_3_3)
    {
        *letraGanadora = pos_1_3;
        return 1;
    }
    // por diagonal derecha
    else if (pos_1_1 != '*' && pos_1_1 == pos_2_2 && pos_2_2 == pos_3_3)
    {
        *letraGanadora = pos_1_1;
        return 1;
    }
    // por diagonal izquierda
    else if (pos_1_3 != '*' && pos_1_3 == pos_2_2 && pos_2_2 == pos_3_1)
    {
        *letraGanadora = pos_1_3;
        return 1;
    }

    return 0;
}
