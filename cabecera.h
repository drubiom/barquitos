#ifndef _CAB
  #define _CAB
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <unistd.h>
/*
##Proyecto miniflota##
Realizado por David Rubio Mateos (bk0084)
main.c con el programa principal
funciones.c con el desarrollo de todas las funciones utilizadas
cabecera.h con la declaración de variables globales y cabeceras de funciones
*/


char tablerouser [7][7];
char tablerocompuvisible [7][7];
char tablerocompuoculto [7][7];
int turno, hundidoscompu, hundidosuser, num1, num2;

void colocacompu();
void colocauser();
void juegauser();
void juegacompu();
void imprimiruser();
void imprimircompu();
void inicializartableros();
int sorteaturno();
int comprobar(int num1, int num2, int tablero);
int comprobarBARCOS(int num1, int num2, int tablero);
int comprobarsihundido(int num1,int num2,int tablero);
void guardapartida();
void marcardisparos(int num1,int num2, int tablero);
#endif
