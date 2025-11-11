// fecha: 17 / 10 / 2025
// Nombre: Martin Natera
// Cedula: 30445341
// seccion: 1
// Taller 2
// ejercicio 3

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

// funcion modifica y rota la imagen 
void modificarInvertirImagen(imagen* original,imagen* modificada ) {
    strcpy(modificada->tipo,original->tipo);

    modificada->altura = original->altura ;
    modificada->anchura = original->anchura;
    modificada->profundidad = original->profundidad;

    int col = modificada->anchura - 1;
    for( int i = 0; i < modificada->altura ;i++ ) {
        for( int j = 0; j < modificada->anchura ;j++ ) {
            modificada->pixeles[i][j] = original->pixeles[i][col-j];
        }
    }
}

// valida los valores de cada pixel
int pixelesValidos( pixel valores ) {
    return( valores.r >= 0 && valores.r <= 255 && valores.g >= 0 && valores.g <= 255 && valores.b >= 0 && valores.b <= 255  );
}
// funcion verifica y valida la imagen
int validarImagen( imagen* original ) {
    int resp = 0; 

    if( original->altura >= 0 && original->anchura >= 0 ) {
        resp = 1;
    } else {
        !resp;
    }
    

    if( original->profundidad >= 0 && original->profundidad <= 255 ) {
        resp = 1;
    }else {
        !resp;
    }

    // loop 1
    for( int i = 0; i < original->altura ;i++ ) {
        // loop 2
        for( int j = 0; j < original->anchura ;j++ ) {
            // valida cada pixel en caso de no cumplir los valores
            if(  pixelesValidos(original->pixeles[i][j]) ){
                resp = 1;
            } else {
                resp = 0;
            }
        }
    }

}

imagen original, modificada;

int main() {

    // lectura de archivo
    lectura_archivo(&original);

    if( validarImagen(&original) ){

        // rotacion de la imagen
        modificarInvertirImagen(&original,&modificada);

        // salida de imagen modificada
        salida_archivo(&modificada);
    }



    return 0;
}