#ifndef _CAB
  #define _CAB
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#include <unistd.h>

char tablerouser [7][7];//INICIALIZA TABLERO USUARIO
char tablerocompuvisible [7][7];//INICALIZA TABLERO CON LOS BARCOS DEL COMPU VISIBLE
char tablerocompuoculto [7][7];//INICALIZA TABLERO CON LOS BARCOS DEL COMPU OCULTO
int turno, hundidoscompu, hundidosuser, num1, num2;/*INICIALIZA LAS VARIABLES GLOBALES NECESARIAS (TURNO ACTUAL,
NÚMERO DE BARCOS HUNDIDOS POR CADA USER)*/

void colocacompu();//COLOCA LOS BARCOS DEL COMPU
void colocauser();//COLOCA LOS BARCOS DEL USUARIO, SE PIDEN LAS POSICIONES AL USUARIO
void juegauser();//JUEGA EL JUGADOR
void juegacompu();//JUEGA COMPU
void imprimiruser();//IMPRIME EL TABLERO DE USER
void imprimircompu();//IMPRIME EL TABLERO CON LOS BARCOS OCULTOS DE COMPU
void inicializartableros();//INICIALIZA LOS TABLEROS CON ASTERISCOS EN TODAS LAS POSICIONES
int sorteaturno();//TNUMERO ALEATORIO PARA SORTEAR TURNO
int comprobar(int num1, int num2, int tablero);
int comprobarBARCOS(int num1, int num2, int tablero);
int comprobarsihundido(int num1,int num2,int tablero);
//COMPRUEBA SI LOS DISPARON DAN A UN BARCO, SI EL BARCO ESTÁ HUNDIDO
#endif
