/*
Cowsay, es una utilidad GNU que fue originalmente desarrollada por Tony Moroe mediante el
uso del lenguaje de programación Perl, lenguaje que se caracteriza por brindar una gran
flexibilidad al programador dado que permite representar una misma acción de numerosas
formas diferentes.

Esta peculiar utilidad le permite al usuario transformar un texto arbitrario en un ASCII-art de un
personaje diciendo aquél mensaje que fue proporcionado en un globo de texto, en el cual, el
personaje que aparece en la obra de arte le da nombre al programa, y no es más y nada menos
que una vaca.

Este programa le ha otorgado alegría a los desarrolladores desde 1999 y comúnmente se usa
junto a la utilidad fortune, para recibir sabios mensajes de una vaca (¡imagine que ocurriría si
fuesen dos vacas!).

Dada la importancia del programa, se ha creado un mirror (servidor de respaldo) del mismo en
la conocida página para almacenar código fuente, Github (https://github.com/cowsay-
org/cowsay), y se encuentra actualmente disponible a todo público.

Tomando en cuenta la relevancia histórica de cowsay, su equipo ha decidido realizar un
homenaje al planear una reimplementación del mismo utilizando el lenguaje C y usted, ha
recibido el honor de ser el desarollador encargado de la elaboración del programa.
Su tarea consiste en crear un programa llamado 01-cowsay.c que dado un archivo de entrada,
genere la siguiente salida:

No se evaluará su entrega si emplea arreglos o estructuras

*/
#include <stdio.h>

// calcula el tamaño de linea maximo de un archivo en caso de no estar vacio
void numero_de_espacio(int* num);

// dibuja la vaca 
void dibujo_vaca();

// realiza la lectura del mensaje 
void lectura_del_mensaje();

// crea la parte principal de al archivo 
void creacion_archivo();

int main() {

    // creacion del archivo y parte principal
    creacion_archivo();

    // lectura del archivo y colocar el mensaje en la vaca
    lectura_del_mensaje();

    // dibujo principal de la vaca
    dibujo_vaca();

    return 0;
}

// dibuja la vaca 
void dibujo_vaca(){
    FILE* salida = fopen("01-salida.txt","a");

    if(salida == NULL){
        printf("Error al abrir el archivo de salida.\n");
        return;
    }

    int maxEspacio;
    numero_de_espacio(&maxEspacio);
    
    // Dibujar linea inferior del marco
    for(int j=0; j < maxEspacio + 4; j++){
        fprintf(salida,"*");
    }
    fprintf(salida,"\n");

    fprintf(salida,"*\n");
    fprintf(salida,":\n");
    fprintf(salida,"^__^\n");
    fprintf(salida,"(oo)\\_______\n");
    fprintf(salida,"(__)\\       )\\/\\\n");
    fprintf(salida,"    ||----w||\n");
    fprintf(salida,"    ||     ||\n");
    
    fclose(salida);
}

// realiza la lectura del mensaje 
void lectura_del_mensaje(){
    FILE* entrada = fopen("01-mensaje.txt","r");
    FILE* salida = fopen("01-salida.txt","a");

    if(entrada == NULL){
        if(salida != NULL){
            fprintf(salida,"vacio");
            fclose(salida);
        }
        return;
    }

    if(salida == NULL){
        fclose(entrada);
        return;
    }

    int maxEspacio;
    numero_de_espacio(&maxEspacio);
    int count = 0;
    int primera_linea = 1;

    // Reiniciar el archivo de entrada para leer desde el inicio
    fclose(entrada);
    entrada = fopen("01-mensaje.txt","r");

    while(!feof(entrada)){
        char letra;
        
        fprintf(salida,"* ");
        fscanf(entrada,"%c",&letra);
        count = 0;
        
        while(!feof(entrada) && letra != '\n'){
            fprintf(salida,"%c",letra);
            count++;
            fscanf(entrada,"%c",&letra);
        }
        
        // Completar con espacios hasta el borde
        int espacios = maxEspacio - count;
        for(int i=0; i < espacios; i++){
            fprintf(salida," ");
        }
        fprintf(salida," *\n");
    }

    fclose(salida);
    fclose(entrada);
}

// calcula el tamaño de linea maximo de un archivo en caso de no estar vacio
void numero_de_espacio(int* num){
    FILE* archivo = fopen("01-mensaje.txt","r");
    *num = 0;

    if(archivo == NULL){
        return;
    }

    int max = 0, count = 0;
    
    while(!feof(archivo)){
        char letra;
        fscanf(archivo,"%c",&letra);
        
        if(letra == '\n' || feof(archivo)){
            if(count > max){
                max = count;
            }
            count = 0;
        } else {
            count++;
        }
    }
    
    *num = max;
    fclose(archivo);
}

// crea la parte principal de al archivo 
void creacion_archivo(){
    FILE* archivo = fopen("01-salida.txt","w");

    if(archivo == NULL){
        printf("Error al crear el archivo de salida.\n");
        return;
    }

    int maxEspacio;
    numero_de_espacio(&maxEspacio);
    
    // Dibujar linea superior del marco
    for(int j=0; j < maxEspacio + 4; j++){
        fprintf(archivo,"*");
    }
    fprintf(archivo,"\n");

    fclose(archivo);
}
