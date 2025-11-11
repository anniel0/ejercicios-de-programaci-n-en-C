// fecha: 17 / 10 / 2025
// Nombre: Martin Natera
// Cedula: 30445341
// seccion: 1
// Taller 2
// ejercicio 1

#include <stdio.h>
#include <string.h>

#define N 8192

// estructura del pixel de imagenes
typedef struct {
    int r,g,b;
} pixel;

// estructura de la imagen
typedef struct {
    char tipo[3];
    int profundidad,altura,anchura;
    pixel pixeles[N][N];
} imagen;

// lectura de los datos de la imagen
void lectura_archivo( imagen* imagenOriginal ) {
    FILE *dato = fopen("personaje.ppm","r");

    if( dato == NULL ) {
        return;
    }

    // lectura de tipo,altura,anchura y profundidad
    fscanf(dato,"%s\n%d %d\n%d",imagenOriginal->tipo,&imagenOriginal->altura,&imagenOriginal->anchura,&imagenOriginal->profundidad);

    // loop 1
    for( int i = 0; i < imagenOriginal->altura ;i++ ) {
        // loop 2
        for( int j = 0; j < imagenOriginal->anchura ;j++ ) {
            // lectura de cada pixel
            fscanf(dato,"%d %d %d",&imagenOriginal->pixeles[i][j].r,&imagenOriginal->pixeles[i][j].g,&imagenOriginal->pixeles[i][j].b);
        }
    }

    fclose(dato);
}

// salida de datos de archivo
void salida_archivo( imagen* imagenModificada ) {

    FILE *dato = fopen("personaje-modificado.ppm","w");

    // escritura de tipo,altura,anchura y profundidad
    fprintf(dato,"%s\n%d %d\n%d\n",imagenModificada->tipo,imagenModificada->anchura,imagenModificada->altura,imagenModificada->profundidad);

    // loop 1
    for( int i = 0; i < imagenModificada->altura ;i++ ) {
        // loop 2
        for( int j = 0; j < imagenModificada->anchura ;j++ ) {
            // escritura de cada pixel
            fprintf(dato,"%d %d %d ",imagenModificada->pixeles[i][j].r,imagenModificada->pixeles[i][j].g,imagenModificada->pixeles[i][j].b);
        }
        // salto de linea
        fprintf(dato,"\n");
    }

    fclose(dato);

}

// lectura de valor de escalado
void lectura_escalado(int* escalado) {
    FILE *dato = fopen("escalado.conf","r");

    if( dato == NULL ) {
        *escalado = 1;
        return;
    }

    //lectura de valor de escalado
    fscanf(dato,"%d",escalado);

    fclose(dato);
}

// funcion modifica y escala la imagen a un valor especificado
void modificarEscalamientoDeImagen( int escalado ,imagen* original,imagen* modificada ) {
    strcpy(modificada->tipo,original->tipo);

    if( escalado <= 0 || escalado > N ) {
        escalado = 1;
    }

    modificada->altura = original->altura * escalado;
    modificada->anchura = original->anchura * escalado;
    modificada->profundidad = original->profundidad;

    for( int i = 0; i < original->altura ;i++ ) {
        for( int j = 0; j < original->anchura;j++ ) {
            int inicioFil = i * escalado;
            int inicioCol = j * escalado;
            for( int di = 0; di < escalado ;di++ ) {
                for( int dj = 0; dj < escalado ;dj++ ) {
                    modificada->pixeles[inicioFil + di][inicioCol + dj] = original->pixeles[i][j];
                }
            }
        }
    }
}

int escalado; 
imagen original, modificada;

int main() {
    
    lectura_archivo(&original);
    lectura_escalado(&escalado);
    modificarEscalamientoDeImagen(escalado,&original,&modificada);
    salida_archivo(&modificada);

    return 0;
}