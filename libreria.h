#ifndef LIBRERIA_H
#define LIBRERIA_H

// Macros

#define WHITE -1
#define GREEN 2
#define RED 4
#define CELL_COLOR 127
#define LETTER_COLOR 127

#define MENU_RENG_SIZE 40
#define MENU_COLS_SIZE 100


// Estructuras
typedef struct Cell{
    int turn_act, turn_sig;
}cell;

typedef struct Board{
    int nReng, nCols;
    cell **mat;
}board;

// Funciones de la terminal
void setColor(int idxColor);
void showColors();
void GotoXY(int x, int y);
void defineMargin(int N, int M);

// Funciones del juego
char showMenu();
void showRules();
int showMaps();

void printStartupMessage();
void clearStartupMessage();
int read_file(char *file_name, board *mi_tablero);
void printBoard(board *A);
void printMenuInGame();

void printCounter();
int cellState(board *A, int x, int y);
void printTurn(board *A);
char *createRandomMap();
void startGame(char *file_name);

void finishGame(board *A);
void clearBoard(board *A);
void clearCounter();
void clearMenuInGame();

// Funciones auxiliares
cell **createBoard(int N, int M);
void freeBoard(cell **mat, int N);
void delay();
void menu_delay();
void removeCursor();
void defineSIZE(board *A);



#endif // LIBRERIA_H
