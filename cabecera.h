#ifndef _CAB
  #define _CAB
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <windows.h>

#include <unistd.h>

char tablerouser [7][7];
char tablerocompuvisible [7][7];
char tablerocompuoculto [7][7];
int turno, hundidoscompu, hundidosuser, num1, num2;

void colocacompu();//TERMINADA
void colocauser();//TERMINADA
void juegauser();//POR HACER
void juegacompu();//POR HACER
void imprimiruser();//TERMINADA
void imprimircompu();//TERMINADA
void inicializartableros();//TERMINADA
int sorteaturno();//TERMINADA
int comprobar(int num1, int num2, int tablero);//TERMINADA
int comprobarBARCOS(int num1, int num2, int tablero);//POR HACER
int comprobarsihundido(int num1,int num2,int tablero);
#endif
