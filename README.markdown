**Autor:** Josué Alexis Campos Negrrón

**Fecha:** 13/12/20020

**Escuela:** Universidad de Guanajuato

# Descripción del programa

El programa es el *Juego de la vida*, este está dividido por secciones las cuales son:

- Menú principal (`menu_del_juego.txt`)
- Reglas del juego (`reglas_del_juego.txt`)
- Mapas del juego (`mapas_del_juego.txt`)
- Tablero del mapa seleccionado (`osciladores.txt`, `naves_espaciales.txt`, `mapa_de_usuario.txt`, `random.txt`)

Notese que cada seccion tiene archivos `.txt` que sin ellos no funciona el programa, por ello es **importante** tener los archivos de texto en la misma carpeta/direccion que el archivo `JuegoDeLaVida.c`. Cabe mencionar que el archivo `random.txt` no es necesario, el programa genera uno cada que el usuario decide juegar el mapa *aleatorio*, de igual forma, el archivo `mapa_de_usuario.txt` puede ser cualquier mapa con el que el usuario quiera jugar el juego. Dicho archivo debe tener las siguiente caracteristicas:

- 2 enteros $N$ y $M$ los cuales denotan el numero de renglones y el numero de columnas, seguido de ello un salto de linea.
- Luego, $N$ filas con $M + 1$ caracteres cada uno del tipo `' ', '*'` o `'#'`, el caracter numero $M + 1$ debe ser estrictamente un salto de linea, ademas, los caracteres en las posiciones $0, N-1, M-1$ deben ser estricamente el caracter `#` (el archivo `mapa_de_usuario.txt` es un ejemplo correcto).

Dado estas instrucciones procederemos a mecionar como utilizar el programa.


## ¿Cómo se compila el proyecto?

Es de suma importancia que todo los archivos antes mencionados esten en la misma carpeta/direccion.

Para compilar el proyecto acceda desde su terminal a la dirreccion donde esta situado los archivos. Seguido de ello, ejecute el siguiente comando:

**`gcc JuegoDeLaVida.c libreria.c -o juego.exe`**

El comandon anterior generará el archivo `juego.exe`.

## ¿Cómo se ejecuta el proyecto?

Una vez realizado el comando anterior ingresar el siguiente comando

**`.\juego.exe`**

seguido del archivo de texto con las caracteristicas antes mecionadas, para ejemplificar esta accion, utilizaremos el archivo `mapa_de_usuario.txt`, entonces, el comando queda de esta forma

**`.\juego.exe mapa_de_usuario.txt`**

Si no se ingresa el archivo `.txt` el juego se ejecuta sin la posibilidad de juegar el mapa de usuario, retornara un mensaje de error que no se proporciono dicho mapa al programa.

## ¿Cómo se juega?

El programa tiene instrucciones intuitivas, por lo tanto como se desarrolle el juego se sabra que teclas utilizar, sin embargo, enlistaremos las mas importantes.

- **Menu de inicio:** En esta parte tenemos la opciones de apretar las siguientes teclas:
  - `M:` Muesta los mapas dispobibles del juego.
  - `R:` Muestra las reglas del juego.
  - `S` Termina el programa.
  - **NOTA:** Cuando se ingresa una opcion diferente a las anterior el programa muestra un mensaje de error, se tiene que presionar la tecla `ENTER` para poder solicitar nuevamente la opcion de ingresar una tecla.
- **Reglas del juego:** En esta parte unicamente se puede leer las reglas del juego y apretar la tecla `ENTER` para regresar al menu del juego.
- **Mapas del juego:** En esta parte muestra los diferentes mapas que contiene el juego, con las siguientes opciones:
  - `1` para jugar el mapa *osciladores*.
  - `2` para jugar el mapa naves *espaciales*.
  - `3` para jugar el mapa del usuario.
  - `4` para jugar un mapa aleatorio.
  - `5` para regresar el menu.
  
  Una vez ingresado el mapa que desea jugar el programa lo envia al siguiente punto.

- **Tablero de juego:** Este tablero muestra el juego con el mapa seleccionado, dentro del tablero se tiene las siguiente opciones:
  - `SHIFT` para pausar el juego.
  - `ENTER` para despausar el juego.
  - `ESCAPE` para salir del juego.

Estas son todas las instrucciones necesarias para usar correctamente el programa.