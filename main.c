/*
* Autor: Josue Alexis Campos Negron
* Fecha: 13/12/2020
* Proyecto final
* Descripcion: El programa es el juego de la vida, contiene un menu principal en donde
* se puede ver las reglas del juego, los mapas del juego y la opcion de salir del juego.
* El juego contiene 4 opciones de mapas, osciladores, naves espaciales, mapa generado por
* el usuario y un mapa aleatorio.
* Despues de seleccionar el unico procedimiento que queda es ver la evolucion de las celulas,
* en el menu durante el juego, se puede ver el contador de la poblacion, el numero de generacion,
* opciones para pausar y salir del juego al menu principal.
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "libreria.h"

int main(int argc, char **argv)
{
    system("cls");
    printStartupMessage();
    menu_delay();
    clearStartupMessage();

    while(1){
        char opt = showMenu();

        if(opt == 'S')
            break;

        if(opt == 'R'){
            showRules();
            continue;
        }

        switch(showMaps()){
    case 1: startGame("osciladores.txt"); break;
    case 2: startGame("naves_espaciales.txt"); break;
    case 3:
        if(argc < 2){
            GotoXY(MENU_RENG_SIZE + 1, 0);
            setColor(RED);
            printf("El usuario no ingreso ningun archivo");
            setColor(WHITE);
            menu_delay();

            GotoXY(MENU_RENG_SIZE + 1, 0);
            printf("                                    ");
            continue;
        }

        startGame(argv[1]); break;
    case 4: startGame(createRandomMap()); break;
    case 5: continue;
        }

    }

    return 0;
}
