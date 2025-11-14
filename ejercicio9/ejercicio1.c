#include <stdio.h>
#include <math.h>

// cantida de puntos para cada jugador
int cantidad_puntos(FILE *tiros, int cantidad, int x, int y);

// punto correspondiente por cada tiro
int puntos_distancia(float posicion);

// coloca el nombre del ganador
void ganador_juego(int jugador);

// lectura de cada arhcivo de entrada de datos
void lectura_archivos();

int main()
{
    lectura_archivos();
    return 0;
}

void ganador_juego(int jugador)
{
    // archivos:
    FILE *juego = fopen("juego.txt", "r"),
         *puntiacion = fopen("puntuacion.txt", "a");

    // variables:
    int centro_x, centro_y, posicion = 0;
    char letraNombre;

    // centro del circulo
    fscanf(juego, "%d %d", &centro_x, &centro_y);

    // -----------------------JUGADOR 1------------------------------ //
    fprintf(puntiacion, "\nFelicidades ");
    while (fscanf(juego, "%c", &letraNombre) != EOF && posicion <= jugador)
    {
        if (posicion == jugador && letraNombre != ' ' && letraNombre != '\n')
        {
            fprintf(puntiacion, "%c", letraNombre);
        }
        else if (posicion == jugador && letraNombre == ' ')
        {
            break;
        }

        if (letraNombre == '\n')
        {
            posicion++;
        }
    }
    fprintf(puntiacion, ", has ganado.\n");

    // cerrado de archivo
    fclose(juego);
    fclose(puntiacion);
}

// lectura de cada arhcivo de entrada de datos
void lectura_archivos()
{
    // archivos:
    FILE *juego = fopen("juego.txt", "r"),
         *tiros = fopen("tiros.txt", "r"),
         *puntiacion = fopen("puntuacion.txt", "w");

    if (juego == NULL || tiros == NULL)
    {
        return;
    }

    // variables:
    int centro_x, centro_y, tiroJugador1, tiroJugador2, puntosJugador1, puntosJugador2;
    char letraNombre;

    // centro del circulo
    fscanf(juego, "%d %d", &centro_x, &centro_y);

    // -----------------------JUGADOR 1------------------------------ //

    while (fscanf(juego, "%c", &letraNombre) != EOF && letraNombre != ' ')
    {
        if (letraNombre != '\n')
        {
            fprintf(puntiacion, "%c", letraNombre);
        }
    }
    fscanf(juego, "%d", &tiroJugador1); // cantidad de tiros de cada jugador

    puntosJugador1 = cantidad_puntos(tiros, tiroJugador1, centro_x, centro_y);
    fprintf(puntiacion, " %d\n", puntosJugador1);

    // -----------------------JUGADOR 2------------------------------ //

    while (fscanf(juego, "%c", &letraNombre) != EOF && letraNombre != ' ')
    {
        if (letraNombre != '\n')
        {
            fprintf(puntiacion, "%c", letraNombre);
        }
    }
    fscanf(juego, "%d", &tiroJugador2); // cantidad de tiros de cada jugador

    puntosJugador2 = cantidad_puntos(tiros, tiroJugador1, centro_x, centro_y);
    fprintf(puntiacion, " %d", puntosJugador2);

    // cerrado de archivo
    fclose(juego);
    fclose(tiros);

    if (puntosJugador1 > puntosJugador2)
    {
        ganador_juego(1);
    }
    else if (puntosJugador2 > puntosJugador1)
    {
        ganador_juego(2);
    }
    else
    {
        fprintf(puntiacion, "\nEmpate\n");
    }
    fclose(puntiacion);
}

// cantida de puntos para cada jugador
int cantidad_puntos(FILE *tiros, int cantidad, int x, int y)
{
    int pos_x, pos_y, puntos = 0;
    float distancia;
    for (int i = 1; i <= cantidad; i++)
    {
        fscanf(tiros, "%d %d", &pos_x, &pos_y);
        distancia = sqrt(pow(pos_x - x, 2) + pow(pos_y - y, 2));
        puntos += puntos_distancia(distancia);
    }
    return puntos;
}

// punto correspondiente por cada tiro
int puntos_distancia(float posicion)
{
    int resp;

    if (posicion >= 0 && posicion <= 1)
    {
        resp = 10; // Circulo central
    }
    else if (posicion > 1 && posicion <= 5)
    {
        resp = 5; // Circulo medio
    }
    else if (posicion > 5 && posicion <= 10)
    {
        resp = 1; // Círculo grande
    }
    else if (posicion > 11)
    {
        resp = 0; // Fuera de la diana
    }
    else
    {
        resp = -1;
    }
    return resp;
}