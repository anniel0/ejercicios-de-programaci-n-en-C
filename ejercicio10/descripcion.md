# Ejercicio 2. Descifrador de medianoche (10ptos)

Eran las 3:39 AM. Un zumbido eléctrico recorría la sala de servidores subterránea. Tú, el único
técnico aún despierto, recibiste una notificación en rojo parpadeante:
"Mensaje interceptado. Formato: Código Morse. Prioridad: Alta. Oportunidades: 1."

En el archivo morse.txt se encontraba el mensaje, escrito por completo en código Morse, ocultando
la ubicación exacta de una brecha de seguridad que solo tú podías sellar.

No había segundas oportunidades. Una sola línea, un solo intento. Si fallabas en la decodificación:

• El sistema activaría un bloqueo permanente.

• Se eliminaría el rastro de acceso.

• Y tú serías el responsable de perder la última oportunidad de proteger la red.

Pero si lograbas traducir correctamente cada punto y raya, si eras lo suficientemente rápido, si eras
el verdadero descifrador...

El acceso se restauraría. El ataque sería contenido. La red sobreviviría.

El programa debe realizar lo siguiente:

1. Leer una línea del mensaje en código Morse desde el archivo de entrada morse.txt.

2. Traducir cada secuencia de código Morse a su carácter correspondiente (letra, número o
símbolo especial). Siendo los 3 puntos la secuencia final del mensaje.

3. Ignorar cualquier secuencia que no corresponda a un carácter válido.

4. Mostrar la traducción completa por pantalla.

5. Guardar el resultado traducido en un archivo de salida llamado mensaje.txt, una línea por
cada mensaje.

| Carácter | Código Morse |
|----------|--------------|
| A | .- |
| B | -... |
| C | -.-. |
| D | -.. |
| E | . |
| F | ..-. |
| G | --. |
| H | .... |
| I | .. |
| J | .--- |
| K | -.- |
| L | .-.. |
| M | -- |
| N | -. |
| O | --- |
| P | .--. |
| Q | --.- |
| R | .-. |
| S | ... |
| T | - |
| U | ..- |
| V | ...- |
| W | .-- |
| X | -..- |
| Y | -.-- |
| Z | --.. |
| Espacio | -..-. |
| Fin (.) | .-.-.- |

| Número | Código Morse |
|--------|--------------|
| 0 | ----- |
| 1 | .---- |
| 2 | ..--- |
| 3 | ...-- |
| 4 | ....- |
| 5 | ..... |
| 6 | -.... |
| 7 | --... |
| 8 | ---.. |
| 9 | ----. |

### Ejemplo: morse.txt:
.... --- .-.. .- .-.-.- .-.-.- .-.-.-
### Ejemplo: mensaje.txt:
HOLA...
