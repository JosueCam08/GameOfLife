#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "libreria.h"

int MARG_COLM = 0, MARG_RENG = 0;
int numGeneration = 0, numPopulation = 0;
int RENG_SIZE = MENU_RENG_SIZE, COLS_SIZE = MENU_COLS_SIZE;

/* / / / / / / / / /  Operaciones en la terminal / / / / / / / / / */

/* Define el margen de la cuadricula respecto a la terminal */
void defineMargin(int N, int M){
    MARG_RENG = 5;
    MARG_COLM = 100 - (M/2);
}

/* Realiza un cambio de color en la pantalla */
void setColor(int idxColor){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(idxColor==-1){
        SetConsoleTextAttribute(hConsole, 7);
        return;
    }

    SetConsoleTextAttribute(hConsole, idxColor);
}

/* Posiciona en una coordenada de la pantalla */
void GotoXY(int x, int y){
    COORD coord;
    coord.X = y + MARG_COLM;
    coord.Y = x + MARG_RENG;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/* Muestra todos los colores */
void showColors(){
    for(int i = 0; i < 255; i++){
        setColor(i);
        printf("Este es el color numero %i ###///***\n", i);
    }
}


/* / / / / / / / / /  Operaciones de menu del juego / / / / / / / / / */

/* Muestra el menu principal del juego */
char showMenu(){

    FILE *finAptr = fopen("menu_del_juego.txt", "r");
    if(finAptr == NULL)
        return NULL;

    defineMargin(MENU_RENG_SIZE, MENU_COLS_SIZE);
    GotoXY(0,0);

    char c = ' ';
    int it = 1;
    while(c != EOF){

        c = getc(finAptr);

        if(c == '$'){
            setColor(GREEN);
            continue;
        }

        if(c == '/'){
            setColor(WHITE);
            continue;
        }

        if(c == '*'){
            setColor(LETTER_COLOR);
            printf("/");
            setColor(WHITE);
            continue;
        }

        if(c == '\n'){
            printf("\n");
            GotoXY(it++, 0);
            continue;
        }

        printf("%c", c);
    }

    while(1){
        GotoXY(MENU_RENG_SIZE + 1, 0);

        printf("Ingrese opcion: ");
        scanf("%c", &c);

        if(c != 'M' && c != 'R' && c != 'S'){
            GotoXY(MENU_RENG_SIZE + 1, 0);

            setColor(RED);
            printf("Opcion no valida    ");
            setColor(WHITE);

            getchar();getchar();

            continue;
        }

        break;
    }

    fclose(finAptr);
    return c;
}
/* / / / / / / / / /  Operaciones de reglas del juego/ / / / / / / / / */

/* Muestra las reglas del juego */
void showRules(){

    FILE *finAptr = fopen("reglas_del_juego.txt", "r");
    if(finAptr == NULL)
        return;

    defineMargin(MENU_RENG_SIZE, MENU_COLS_SIZE);
    GotoXY(0,0);

    char c = ' ';
    int it = 1;
    while(c != EOF){

        c = getc(finAptr);

        if(c == '$'){
            setColor(GREEN);
            continue;
        }

        if(c == '/'){
            setColor(WHITE);
            continue;
        }

        if(c == '*'){
            setColor(LETTER_COLOR);
            printf("/");
            setColor(WHITE);
            continue;
        }

        if(c == '\n'){
            printf("\n");
            GotoXY(it++, 0);
            continue;
        }

        printf("%c", c);
    }

    fclose(finAptr);
    delay();delay();
}

/* / / / / / / / / / / /  Operaciones de mapas del juego / / / / / / / / / / / */

/* Muestra los mapas del juego */
int showMaps(){

    FILE *finAptr = fopen("mapas_del_juego.txt", "r");
    if(finAptr == NULL)
        return NULL;

    defineMargin(MENU_RENG_SIZE, MENU_COLS_SIZE);
    GotoXY(0,0);

    char c = ' ';
    int it = 1;
    while(c != EOF){

        c = getc(finAptr);

        if(c == '$'){
            setColor(GREEN);
            continue;
        }

        if(c == '/'){
            setColor(WHITE);
            continue;
        }

        if(c == '*'){
            setColor(LETTER_COLOR);
            printf("/");
            setColor(WHITE);
            continue;
        }

        if(c == '\n'){
            printf("\n");
            GotoXY(it++, 0);
            continue;
        }

        printf("%c", c);
    }

    int opt;
    while(1){
        GotoXY(MENU_RENG_SIZE + 1, 0);

        printf("Ingrese opcion: ");
        scanf("%d", &opt);

        if(opt < 1 && opt > 5){
            GotoXY(MENU_RENG_SIZE + 1, 0);

            setColor(RED);
            printf("Opcion no valida    ");
            setColor(WHITE);

            getchar();getchar();

            continue;
        }

        getchar();
        break;
    }

    fclose(finAptr);
    return opt;
}

char *createRandomMap(){

    FILE *foutAptr = fopen("random.txt", "w");
    if(foutAptr == NULL)
        return NULL;

    int N = 40, M = 100;
    int contCells = 500;
    char c = ' ';

    fprintf(foutAptr, "%d %d\n", N, M);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == 0 || j == 0 || i == 39 || j == 99){
                c = '#';
                fprintf(foutAptr, "%c", c);
            }else{
                if(rand()%2 == 0 || !contCells)
                    c = ' ';
                else{
                    c = '*';;
                    contCells--;
                }
                fprintf(foutAptr, "%c", c);
            }
        }
        c = '\n';
        fprintf(foutAptr, "%c", c);
    }

    fclose(foutAptr);
    return "random.txt";
}

/* / / / / / / / / / / /  Operaciones del juego / / / / / / / / / / / */

/* / / / / / / / / /  Operaciones al inicio del juego / / / / / / / / / */

/* Imprime mensaje para iniciar el juego */
void printStartupMessage(){
    setColor(WHITE);
    printf("Presione ");
    setColor(GREEN);
    printf("ENTER ");
    setColor(WHITE);
    printf("para iniciar el juego...");
}

/* Borrra el mensaje de inicio de juego */
void clearStartupMessage(){
    GotoXY(0, 0);
    for(int i = 0; i < 40; i++)
        printf(" ");
}

/* Lee el board de juego */
int read_file(char *file_name, board *mi_tablero){

    FILE *finAptr = fopen(file_name, "r");
    if(finAptr==NULL)
        return NULL;

    fscanf(finAptr, "%d %d", &mi_tablero->nReng, &mi_tablero->nCols);

    mi_tablero->mat = createBoard(mi_tablero->nReng, mi_tablero->nCols);
    if(mi_tablero->mat==NULL)
        return NULL;

    char input = getc(finAptr); // Salto de linea despues de N M
    for(int i = 0; i < mi_tablero->nReng; i++){
        for(int j = 0; j < mi_tablero->nCols; j++){
            input = getc(finAptr);

            switch(input){
            case '#': mi_tablero->mat[i][j].turn_act = -1; break;
            case ' ': mi_tablero->mat[i][j].turn_act = 0; break;
            case '*': mi_tablero->mat[i][j].turn_act = 1; break;
            }

        }
        input = getc(finAptr); // Salto de linea al finalizar la fila
    }

    fclose(finAptr);
    return 1;
}

/* Imprime el board en la terminal */
void printBoard(board *A){
    for(int i = 0; i < A->nReng; i++){
        for(int j = 0; j < A->nCols; j++){
            GotoXY(i, j);

            switch(A->mat[i][j].turn_act){
            case -1: printf("%c", '#'); break;
            case 0: printf("%c", ' '); break;
            case 1: setColor(127); printf("%c", '/'); setColor(WHITE); break;
            }
        }
    }
    printCounter();
    printMenuInGame();
}

/* Imprime el menu durante el juego */
void printMenuInGame(){
    GotoXY(RENG_SIZE + 1, 0);
    printf("Presione ");
    setColor(2);
    printf("SHIFT");
    setColor(-1);
    printf(" para pausar el juego");

    GotoXY(RENG_SIZE + 2, 0);
    printf("Presione ");
    setColor(2);
    printf("ENTER");
    setColor(-1);
    printf(" para continuar el juego");

    GotoXY(RENG_SIZE + 3, 0);
    printf("Presione ");
    setColor(2);
    printf("ESC");
    setColor(-1);
    printf(" para salir del juego");
}

/* / / / / / / / / /  Operaciones durante el juego / / / / / / / / / */

/* Imprime contador de generacion y poblacion */
void printCounter(){
    GotoXY(0, COLS_SIZE + 2);
    printf("Generacion: %d", numGeneration++);
    GotoXY(1, COLS_SIZE + 2);
    printf("Poblacion: %d", numPopulation);
}

/* Retorna el estado de la cell en el siguiente turno */
int cellState(board *A, int x, int y){
    int arrX[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int arrY[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

    int contCelulas = 0, cordX, cordY;
    for(int i = 0; i < 8; i++){
        cordX = x + arrX[i];
        cordY = y + arrY[i];
        if(A->mat[cordX][cordY].turn_act==1)
            contCelulas++;
    }

    // Celula viva
    if(A->mat[x][y].turn_act){
        if(contCelulas == 2 || contCelulas == 3)
            return 1;
        return 0;
    }

    // Celula muerta
    if(contCelulas == 3)
        return 1;
    return 0;
}

/* Imprime el siguiente turno del juego */
void printTurn(board *A){
    int contPoblacion = 0;
    for(int i = 1; i < A->nReng - 1; i++){
        for(int j = 1; j < A->nCols - 1; j++){

            switch(A->mat[i][j].turn_act){
            case 0:
                A->mat[i][j].turn_act = A->mat[i][j].turn_sig;
                contPoblacion += A->mat[i][j].turn_act;

                if(A->mat[i][j].turn_sig == 1){
                    GotoXY(i, j);
                    setColor(127);
                    printf("%c", '/');
                    setColor(-1);
                }
                removeCursor();
                break;

            case 1:
                A->mat[i][j].turn_act = A->mat[i][j].turn_sig;
                contPoblacion += A->mat[i][j].turn_act;

                if(A->mat[i][j].turn_sig == 0){
                    GotoXY(i, j);
                    printf("%c", ' ');
                }
                removeCursor();
                break;
            }

        }
    }

    numPopulation = contPoblacion;
    printCounter();
}


/* Inicia el juego */
void startGame(char *file_name){

    board tab;
    if(!read_file(file_name, &tab))
        return;

    defineMargin(5, tab.nCols);
    defineSIZE(&tab);
    numPopulation = numGeneration = 0; // Inicializar contador
    printBoard(&tab);

    while(1){
        // Actualizamos siguiente turno
        for(int i = 1; i < tab.nReng - 1; i++)
            for(int j = 1; j < tab.nCols - 1; j++)
                tab.mat[i][j].turn_sig = cellState(&tab, i, j);


        // Terminar juego
        if(GetKeyState(VK_ESCAPE) & 0x8000)
            break;

        // Pausar juego
        if(GetKeyState(VK_SHIFT) & 0x8000)
            getchar();

        // Imprimimos turno
        printTurn(&tab);

        removeCursor();
    }


    freeBoard(tab.mat, tab.nReng);
    finishGame(&tab);
    delay();
}

/* / / / / / / / / /  Operaciones al final del juego / / / / / / / / / */

/* Termina el juego */
void finishGame(board *A){
    clearCounter();
    clearMenuInGame();
    clearBoard(A);
    GotoXY(0, 0);
    printf("Presione ");
    setColor(GREEN);
    printf("ENTER");
    setColor(WHITE);
    printf(" para regresar al menu...");
}

/* Limpia el board del juego */
void clearBoard(board *A){

    // Borramos bordes
    for(int i = 0; i < A->nReng; i++){
        GotoXY(i, 0);
        printf(" ");
        GotoXY(i, A->nCols - 1);
        printf(" ");
    }

    for(int i = 0; i < A->nCols; i++){
        GotoXY(0, i);
        printf(" ");
        GotoXY(A->nReng - 1, i);
        printf(" ");
    }

    // Borrar celulas
    for(int i = 1; i < A->nReng - 1; i++){
        for(int j = 1; j < A->nCols; j++){
            if(A->mat[i][j].turn_act){
                GotoXY(i, j);
                printf(" ");
            }
        }
    }
}

/* Limpia el contador del juego */
void clearCounter(){
    GotoXY(0, COLS_SIZE + 2);
    printf("                              ");
    GotoXY(1, COLS_SIZE + 2);
    printf("                              ");
}

/* Limpia el menu en el juego */
void clearMenuInGame(){
    GotoXY(RENG_SIZE + 1, 0);
    printf("                                        ");

    GotoXY(RENG_SIZE + 2, 0);
    printf("                                        ");

    GotoXY(RENG_SIZE + 3, 0);
    printf("                                        ");
}

/* / / / / / / / / /  Operaciones del auxiliares / / / / / / / / / */

/* Crea un board de N x M */
cell **createBoard(int N, int M){

    cell **mat = (cell **) malloc( N * sizeof(cell *) );
    if(mat==NULL)
        return NULL;

    for(int i = 0; i < N; i++){
        mat[i] = (cell *) malloc( M * sizeof(cell) );

        if(mat[i]==NULL){
            freeBoard(mat, i);
            return NULL;
        }
    }
    return mat;
}

/* Libera memoria del board */
void freeBoard(cell **mat, int N){
    for(int i = 0; i < N; i++)
        free(mat[i]);
    free(mat);
}

/* Crea un delay con el cursor fuera del board */
void delay(){
    removeCursor();
    getchar();
}

/* Crea un delay normal */
void menu_delay(){
    getchar();
}

/* Quita el cursor fuera del board */
void removeCursor(){
    GotoXY(RENG_SIZE + 4, 0);
}

/* Asigna valor a las variables globales RENG_SIZE y COLS_SIZE */
void defineSIZE(board *A){
    RENG_SIZE = A->nReng;
    COLS_SIZE = A->nCols;
}
