# Ejercicio 3. Mirror

Los archivos PPM (con extensión `.ppm`) son una forma concisa y legible de representar imágenes en el computador (https://netpbm.sourceforge.net/doc/ppm.html), los cuales se pueden codificar en texto plano mediante la especificación P3, y en formato binario, por medio de la variante P6. En particular, los archivos P3 siguen el formato a continuación:

Donde cada Pixel está constituido por los canales: Rojo, Verde y Azul.

Tomando en cuenta las especificaciones técnicas del formato PPM descritos en el Ejercicio 1. Nearest Neighbor Algorithm,
implemente la operación “espejo“.

Esta operación consiste en invertir el orden de uno de los ejes de la imagen.

Del mismo modo, su programa deberá leer la imagen desde la entrada estándar y mostrar la imagen `.ppm` resultante en la salida estándar.

Ello implica que para ejecutar su programa y guardar los resultados, deberá usar los operadores de redirección que ofrece bash:

Ejemplo de entrada estándar: personaje.ppm
```
P3
16 16
255
255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255
255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255
255 255 255 255 255 255
255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 201 11 0 201
11 0 201 11 0 165 17 41 165 17 41 255 255 255 255 255 255 255 255 255 255 255 255 255
255 255
255 255 255 255 255 255 255 255 255 255 255 255 255 255 255 201 11 0 221 103 85 221
103 85 221 103 85 221 103 85 201 11 0 165 17 41 255 255 255 255 255 255 255 255 255
255 255 255
255 255 255 255 255 255 255 255 255 255 255 255 129 0 56 221 103 85 201 11 0 201 11 0
201 11 0 201 11 0 201 11 0 201 11 0 129 0 56 255 255 255 255 255 255 255 255 255
255 255 255 255 255 255 255 255 255 255 255 255 201 11 0 201 11 0 201 11 0 78 125 195
110 156 204 110 156 204 110 156 204 110 156 204 78 125 195 255 255 255 255 255 255
255 255 255
255 255 255 255 255 255 255 255 255 221 103 85 129 0 56 201 11 0 78 125 195 147 201
227 147 201 227 147 201 227 255 255 255 255 255 255 147 201 227 110 156 204 255 255
255 255 255 255
255 255 255 255 255 255 221 103 85 201 11 0 129 0 56 201 11 0 58 100 163 147 201 227
147 201 227 147 201 227 147 201 227 147 201 227 147 201 227 110 156 204 255 255 255
255 255 255
255 255 255 255 255 255 129 0 56 201 11 0 97 12 49 201 11 0 165 17 41 58 100 163 110
156 204 110 156 204 110 156 204 110 156 204 58 100 163 255 255 255 255 255 255 255
255 255
255 255 255 255 255 255 97 12 49 201 11 0 78 6 24 201 11 0 201 11 0 165 17 41 165 17 41
165 17 41 165 17 41 165 17 41 129 0 56 255 255 255 255 255 255 255 255 255
255 255 255 255 255 255 78 6 24 129 0 56 78 6 24 165 17 41 201 11 0 201 11 0 201 11 0
201 11 0 201 11 0 201 11 0 78 6 24 255 255 255 255 255 255 255 255 255
255 255 255 255 255 255 78 6 24 97 12 49 78 6 24 129 0 56 201 11 0 201 11 0 201 11 0 201
11 0 201 11 0 201 11 0 78 6 24 255 255 255 255 255 255 255 255 255
255 255 255 255 255 255 255 255 255 78 6 24 78 6 24 129 0 56 165 17 41 201 11 0 201 11
0 201 11 0 201 11 0 201 11 0 78 6 24 255 255 255 255 255 255 255 255 255
255 255 255 255 255 255 255 255 255 255 255 255 78 6 24 129 0 56 129 0 56 97 12 49 97
12 49 129 0 56 129 0 56 165 17 41 78 6 24 255 255 255 255 255 255 255 255 255
255 255 255 255 255 255 255 255 255 255 255 255 78 6 24 129 0 56 129 0 56 97 12 49 255
255 255 255 255 255 78 6 24 129 0 56 78 6 24 255 255 255 255 255 255 255 255 255
255 255 255 255 255 255 175 198 205 175 198 205 78 6 24 78 6 24 78 6 24 78 6 24 175 198
205 175 198 205 78 6 24 78 6 24 78 6 24 177 192 197 255 255 255 255 255 255
255 255 255 255 255 255 255 255 255 175 198 205 175 198 205 175 198 205 175 198 205
175 198 205 175 198 205 175 198 205 175 198 205 175 198 205 175 198 205 255 255 255
255 255 255 255 255 255
```

De igual manera, **PROCURE LEER** las propiedades adicionales que debe cumplir su programa, las cuales están después de la página del ejemplo personaje.ppm.

## Propiedades adicionales que debe cumplir el programa:

- 0 ≤ Profundidad de Color ≤ 255
- 0 ≤ Rojo, Verde, Azul ≤ Profundidad de Color
- 0 ≤ Altura, Anchura
- La imagen generada por el programa no podrá tener unas dimensiones mayores a: 8192 x 8192 píxeles
- Cada Pixel de la entrada estará separado por 1 espacio en blanco, 1 tabulador o 1 caracter nueva línea
- Cada canal/componente del pixel estará separado por 1 espacio en blanco, 1 tabulador o 1 caracter nueva línea
- 0 < E, y además E ∈ N
- Si E = 1, La imagen generada debe ser idéntica a la imagen original
- El archivo fuente del programa deberá llamarse: `01-escalado.c`
- El archivo ejecutable deberá llamarse `escalado`
- El programa no debe alterar los colores de los pixeles originales. Ello implica que los colores que aparecerán en la imagen escalada deben ser los mismos que aquellos que están en la imagen original
- Puede comprobar si su programa ha realizado correctamente la tarea asignada al abrir el archivo generado con el visor de imágenes de su preferencia
- Su programa no deberá mostrar ningún mensaje en la terminal que haga referencia a la solicitud de los datos
- Del mismo modo, El programa debe limitarse a mostrar únicamente el contenido en formato `.ppm` en la salida estándar. Cualquier mensaje adicional mostrado en la salida estándar afectaría el formato del archivo y con ello, su nota
