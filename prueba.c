#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <windows.h>

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
int comprobarBARCOS(int num1, int num2, int tablero);//COMPRUEBA SI LOS DISPARON DAN A UN BARCO
int comprobarsihundido(int num1,int num2,int tablero);//COMPRUEBA SI EL BARCO ESTÁ HUNDIDO

void colocauser(){
    int aux=0,i;
    for(i=0;i<2;i++){
        printf("Barco de 1 Unidad (%i)\n",i+1);
        int num1=1,num2=1;
        printf("Introduce Fila(1-7): \n");
         scanf("%i",&num1);
        while(num1>7 || num1<1){
            printf("Error, la fila tiene que estar entre 1 y 7.\n Introduce Fila(1-7): \n");
            scanf("%i",&num1);}
        printf("Introduce Columna(1-7): \n");
        scanf("%i",&num2);
        while(num2>7 || num2<1){
            printf("Error, la columna tiene que estar entre 1 y 7. Introduce Columna(1-7): \n");
            scanf("%i",&num2);}
        aux=comprobar(num1-1,num2-1,2);
        while (aux==1){
            printf("Error! En esta posición no se puede colocar el barco porque está junto a otro. Prueba de nuevo, así está tu tablero: \n");
            imprimiruser();
            printf("Introduce Fila(1-7): \n");
             scanf("%i",&num1);
            while(num1>7 || num1<1){
                printf("Error, la fila tiene que estar entre 1 y 7. Introduce Fila(1-7): \n");
                scanf("%i",&num1);}
            printf("Introduce Columna(1-7): \n");
            scanf("%i",&num2);
            while(num2>7 || num2<1){
                printf("Error, la columna tiene que estar entre 1 y 7. Introduce Columna(1-7): \n");
                scanf("%i",&num2);}
            aux=comprobar(num1-1,num2-1,2);
        }
        tablerouser[num1-1][num2-1]='O';
        printf("Barco colocado correctamente \n");
    }

        printf("Barco de 2 Unidades \n");
        int num1=1,num2=1;
        printf("Introduce Fila(1-7): \n");
        scanf("%i",&num1);
        while(num1>8 && num1<1){
            printf("Error, la fila tiene que estar entre 1 y 7. Introduce Fila(1-7): \n");
            scanf("%i",&num1);}
        printf("Introduce Columna(1-7): \n");
        scanf("%i",&num2);
        while(num2>8 && num2<1){
            printf("Error, la columna tiene que estar entre 1 y 7. Introduce Columna(1-7): \n");
            scanf("%i",&num2);}
        aux=comprobar(num1-1,num2-1,2);
        while (aux==1){
            printf("Error! En esta posición no se puede colocar el barco porque está junto a otro. Prueba de nuevo, así está tu tablero: \n");
            imprimiruser();
            printf("Introduce Fila(1-7): \n");
            scanf("%i",&num1);
            while(num1>8 && num1<1){
                printf("Error, la fila tiene que estar entre 1 y 7. Introduce Fila(1-7): \n");
                scanf("%i",&num1);}
            printf("Introduce Columna(1-7): \n");
            scanf("%i",&num2);
            while(num2>8 && num2<1){
                printf("Error, la columna tiene que estar entre 1 y 7. Introduce Columna(1-7): \n");
                scanf("%i",&num2);}
            aux=comprobar(num1-1,num2-1,2);
        }
    printf("Donde quieres introducir la segunda unidad del barco? \n");
     int aux3=0,aux2;
    while(aux3==0){
    printf("1. Arriba\n");
	printf("2. Derecha\n");
	printf("3. Abajo\n");
	printf("4. Izquierda\n");
	printf("Elija una orientacion(1-4): ");
        scanf("%i",&aux2);
            if(aux2==1){
                 if(num1!=0){
                    int numaux1=num1-1;
                    aux=comprobar(numaux1-1,num2-1,2);
                    if(aux==1){
                        printf("Error no puede ser introducido en este espacio porque tiene otro barco al lado, por favor, intentalo de nuevo, así está tu tablero:");
                        imprimiruser();
                    }
                    else {
                        tablerouser[num1-1][num2-1]='O';
                        tablerouser[numaux1-1][num2-1]='O';
                        aux3=1;
                        printf("Barco colocado correctamente\n");
                    }
                }
                else{
                printf("Error no puede ser introducido en este espacio, por favor, intentalo de nuevo, este es tu tablero:");
                imprimiruser();}
            }



          else if(aux2==2){
                     if(num2!=6){
                        int numaux2=num2+1;
                        aux=comprobar(num1-1,numaux2-1,2);
                        if(aux==1){
                            printf("Error no puede ser introducido en este espacio porque tiene otro barco al lado, por favor, intentalo de nuevo, así está tu tablero:");
                            imprimiruser();
                        }
                        else {
                            tablerouser[num1-1][num2-1]='O';
                            tablerouser[num1-1][numaux2-1]='O';
                            aux3=1;
                            printf("Barco colocado correctamente\n");
                        }
                    }
                    else{
                    printf("Error no puede ser introducido en este espacio, por favor, intentalo de nuevo, este es tu tablero:");
                    imprimiruser();}
                }


           else if(aux2==3){
                 if(num1!=6){
                    int numaux1=num1+1;
                    aux=comprobar(numaux1-1,num2-1,2);
                    if(aux==1){
                        printf("Error no puede ser introducido en este espacio porque tiene otro barco al lado, por favor, intentalo de nuevo, así está tu tablero:");
                        imprimiruser();
                    }
                    else {
                        tablerouser[num1-1][num2-1]='O';
                        tablerouser[numaux1-1][num2-1]='O';
                        aux3=1;
                        printf("Barco colocado correctamente\n");
                    }
                }
                else{
                printf("Error no puede ser introducido en este espacio, por favor, intentalo de nuevo, este es tu tablero:");
                imprimiruser();}
            }

           else if(aux2==4){
                 if(num2!=0){
                    int numaux2=num2-1;
                    aux=comprobar(num1-1,numaux2-1,2);
                    if(aux==1){
                        printf("Error no puede ser introducido en este espacio porque tiene otro barco al lado, por favor, intentalo de nuevo, así está tu tablero:");
                        imprimiruser();
                    }
                    else {
                        tablerouser[num1-1][num2-1]='O';
                        tablerouser[num1-1][numaux2-1]='O';
                        aux3=1;
                        printf("Barco colocado correctamente\n");
                    }
                }
                else{
                printf("Error no puede ser introducido en este espacio, por favor, intentalo de nuevo, este es tu tablero:");
                imprimiruser();}
            }

            else {
            printf("Error, el numero debe estar entre 1 y 7. intentalo de nuevo");}


        }
         printf("Todos los barcos han sido colocados correctamente \n");
         printf("Así ha quedado tu tablero final: \n");
         imprimiruser();




}

void colocacompu(){
    int aux=0,i;
    srand (time(NULL));
    for(i=0;i<2;i++){
        num1=rand()%7;
        sleep(1);
        num2=rand()%7;
        sleep(1);
        aux=comprobar(num1,num2,1);
        while (aux==1){
            int num1=rand()%7;
            sleep(1);
            int num2=rand()%7;
            sleep(1);
            aux=comprobar(num1,num2,1);
        }
        tablerocompuoculto[num1][num2]='O';
        printf("Barco %i colocado \n",i+1);


    }

        num1=rand()%7;
        sleep(1);
        num2=rand()%7;
        sleep(1);
        aux=comprobar(num1,num2,1);
    while (aux==1){
            num1=rand()%7;
            sleep(1);
            num2=rand()%7;
            sleep(1);
            aux=comprobar(num1,num2,1);
        }

        int aux2=rand()%4+1;
        //1 arriba, 2 derecha, 3 abajo, 4 izquierda
        int aux3=0;
        do{
            if(aux2==1){
                if(num1!=0){
                    int numaux1=num1-1;
                    aux=comprobar(numaux1,num2,1);
                    if(aux==1){
                        aux2=2;
                    }
                    else {tablerocompuoculto[numaux1][num2]='O';
                    printf("Barco 3 colocado \n");
                    aux3=1;}
                }
                else{ aux2=2;}
            }
            else if(aux2==2){
                if(num2!=6){
                    int numaux2=num2+1;
                    aux=comprobar(num1,numaux2,1);
                    if(aux==1){
                        aux2=3;
                    }
                    else {tablerocompuoculto[num1][numaux2]='O';
                    printf("Barco 3 colocado \n");
                    aux3=1;}
                }
                else{ aux2=3;
                }
            }
            else if(aux2==3){
                if(num1!=6){
                    int numaux1=num1+1;
                    aux=comprobar(numaux1,num2,1);
                    if((aux==1)){
                        aux2=4;
                    }
                    else {tablerocompuoculto[numaux1][num2]='O';
                    printf("Barco 3 colocado \n");
                    aux3=1;}
                }
                else {aux2=4;}
            }
            else if(aux2==4){
                if(num2!=0){
                    int numaux2=num2-1;
                    aux=comprobar(num1,numaux2,1);
                    if((aux==1)){
                        aux2=1;
                    }
                    else {tablerocompuoculto[num1][numaux2]='O';
                    printf("Barco 3 colocado \n");
                    aux3=1;}
                }
                else {aux2=1;}
            }

        }while (aux3==0);
        tablerocompuoculto[num1][num2]='O';
}

int comprobar(int num1, int num2, int tablero){
//9 casos diferentes
if(num1==0){
    if(num2==0){//1 esquina arriba izquierda
        if (tablero==1){
            if(tablerocompuoculto[num1][num2+1]=='O'||tablerocompuoculto[num1+1][num2]=='O'|| tablerocompuoculto[num1+1][num2+1]=='O'||tablerocompuoculto[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1][num2+1]=='O'||tablerouser[num1+1][num2]=='O'|| tablerouser[num1+1][num2+1]=='O'||tablerouser[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else if (num2==6){//2 esquina arriba derecha
        if (tablero==1){
            if(tablerocompuoculto[num1][num2-1]=='O'||tablerocompuoculto[num1+1][num2]=='O'|| tablerocompuoculto[num1+1][num2-1]=='O'||tablerocompuoculto[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1][num2-1]=='O'||tablerouser[num1+1][num2]=='O'|| tablerouser[num1+1][num2-1]=='O'||tablerouser[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else{//3 demas fila arriba
        if (tablero==1){
            if(tablerocompuoculto[num1][num2+1]=='O'||tablerocompuoculto[num1+1][num2]=='O'|| tablerocompuoculto[num1+1][num2+1]=='O'|| tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1+1][num2-1]=='O'||tablerocompuoculto[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1][num2+1]=='O'||tablerouser[num1+1][num2]=='O'|| tablerouser[num1+1][num2+1]=='O'|| tablerouser[num1][num2-1]=='O'|| tablerouser[num1+1][num2-1]=='O'||tablerouser[num1][num2]=='O'){
                return 1;
            }
           else return 0;
        }
    }
}

else if(num1==6){
    if (num2==0){//4 esquina abajo izquierda
        if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1-1][num2+1]=='O'|| tablerocompuoculto[num1][num2+1]=='O'||tablerocompuoculto[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1-1][num2+1]=='O'|| tablerouser[num1][num2+1]=='O'||tablerouser[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else if (num2==6){//5 esquina abajo derecha
        if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1-1][num2-1]=='O'||tablerocompuoculto[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1][num2-1]=='O'|| tablerouser[num1-1][num2-1]=='O'||tablerouser[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else{//6 demas fila abajo
        if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1-1][num2+1]=='O'|| tablerocompuoculto[num1][num2+1]=='O'|| tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1-1][num2-1]=='O'||tablerocompuoculto[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1-1][num2+1]=='O'|| tablerouser[num1][num2+1]=='O'|| tablerouser[num1][num2-1]=='O'|| tablerouser[num1-1][num2-1]=='O'||tablerouser[num1][num2]=='O'){
                return 1;
            }
           else return 0;
        }
    }
}

else if(num2==0 && num1!=0 && num1!=6){//7 demas columna izquierda
    if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1-1][num2+1]=='O'|| tablerocompuoculto[num1][num2+1]=='O'|| tablerocompuoculto[num1+1][num2+1]=='O'|| tablerocompuoculto[num1+1][num2]=='O'||tablerocompuoculto[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1-1][num2+1]=='O'|| tablerouser[num1][num2+1]=='O'|| tablerouser[num1+1][num2+1]=='O'|| tablerouser[num1+1][num2]=='O'||tablerouser[num1][num2]=='O'){
                return 1;
            }
           else return 0;
        }
}

else if(num2==6 && num1!=0 && num1!=6){//8 demas columna derecha
    if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1-1][num2-1]=='O'|| tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1+1][num2-1]=='O'|| tablerocompuoculto[num1+1][num2]=='O'||tablerocompuoculto[num1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1-1][num2-1]=='O'|| tablerouser[num1][num2-1]=='O'|| tablerouser[num1+1][num2-1]=='O'|| tablerouser[num1+1][num2]=='O'||tablerouser[num1][num2]=='O'){
                return 1;
            }
           else return 0;
        }
}

else{//9 todas las demas (centro)
    if (tablero==1){
                if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1-1][num2+1]=='O'|| tablerocompuoculto[num1][num2+1]=='O'|| tablerocompuoculto[num1+1][num2+1]=='O'|| tablerocompuoculto[num1+1][num2]=='O'|| tablerocompuoculto[num1+1][num2-1]=='O'|| tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1-1][num2-1]=='O'||tablerocompuoculto[num1][num2]=='O'){
                    return 1;
                }
                else return 0;
            }
            else if (tablero==2){
            if(tablerouser[num1-1][num2]=='O'||tablerouser[num1-1][num2+1]=='O'|| tablerouser[num1][num2+1]=='O'|| tablerouser[num1+1][num2+1]=='O'|| tablerouser[num1+1][num2]=='O'|| tablerouser[num1+1][num2-1]=='O'|| tablerouser[num1][num2-1]=='O'|| tablerouser[num1-1][num2-1]=='O'||tablerouser[num1][num2]=='O'){
                    return 1;
                }
               else return 0;
            }
}

return 0;
}

void juegacompu(){
    int barco, aux1=1;
    do{
    num1=rand()%7;
    num2=rand()%7;
    barco=comprobarBARCOS(num1,num2,2);
    if(barco==1){

    }
    else if(barco==2){
            printf("TE HE HUNDIDO UN BARCO\n");
            tablerouser[num1][num2]='X';
            hundidoscompu=hundidoscompu+1;
            aux1=0;
        }
    else if(barco==3){
            printf("HE TOCADO UN BARCO TUYO\n");
            tablerouser[num1][num2]='X';
            aux1=0;
        }
    else if(barco==4){
            tablerouser[num1][num2]='*';
            tablerouser[num1][num2]='*';
            printf("HE TOCADO AGUA!! \n");
            aux1=0;
        }
    }while(aux1==1);

}
void juegauser(){
    int barco, aux1=1;
    printf("ES TU TURNO. \n");
    do{
    int num1=1,num2=1;
    printf("Introduce Fila(1-7) o '100' para guardar la partida: \n");
    scanf("%i",&num1);
    if(num1==100){
        //GUARDAPARTIDA POR DESARROLLAR
    }
    else{
        while(num1>7 || num1<1){
            printf("Error, la fila tiene que estar entre 1 y 7.\n Introduce Fila(1-7): \n");
            scanf("%i",&num1);}
    }
    printf("Introduce Columna(1-7): \n");
    scanf("%i",&num2);
    while(num2>7 || num2<1){
        printf("Error, la columna tiene que estar entre 1 y 7. Introduce Columna(1-7): \n");
        scanf("%i",&num2);}
    barco=comprobarBARCOS(num1-1,num2-1,1);
    if(barco==1){
        printf("YA HAS DISPARADO A ESTA DIRECCION ANTERIORMENTE. INTÉNTALO DE NUEVO \n");
    }
    else if(barco==2){
            printf("HUNDIDO\n");
            tablerocompuoculto[num1-1][num2-1]='X';
            tablerocompuvisible[num1-1][num2-1]='X';
            hundidosuser=hundidosuser+1;
            aux1=0;
        }
    else if(barco==3){
            printf("TOCADO\n");
            tablerocompuoculto[num1-1][num2-1]='X';
            tablerocompuvisible[num1-1][num2-1]='X';
            aux1=0;
        }
    else if(barco==4){
            tablerocompuoculto[num1-1][num2-1]='*';
            tablerocompuvisible[num1-1][num2-1]='*';
            printf("AGUA!! MAS SUERTE LA PROXIMA VEZ  \n");
            aux1=0;
        }
    }while(aux1==1);
}
void imprimiruser(){
    int i,j;
    printf(" ");
    for(i=0;i<7;i++){
        printf("%i",i+1);
    }
    printf("\n");
    for(j=0;j<7;j++){
            printf("%i",j+1);
        for(i=0;i<7;i++){
            printf("%c",tablerouser[j][i]);
    }
    printf("\n");
    }
}
void imprimircompu(){
    int i,j;
    printf(" ");
    for(i=0;i<7;i++){
        printf("%i",i+1);
    }
    printf("\n");
    for(j=0;j<7;j++){
            printf("%i",j+1);
        for(i=0;i<7;i++){
            printf("%c",tablerocompuvisible[j][i]);
    }
    printf("\n");
    }
}

int comprobarBARCOS(int num1,int num2,int tablero){
   if(tablero==1){
        if(tablerocompuoculto[num1][num2]=='*'||tablerocompuoculto[num1][num2]=='X'){
            return 1;
        }
        else if(tablerocompuoculto[num1][num2]=='.'){
            return 4;
        }
        else{
            if(comprobarsihundido(num1,num2,1)==1){
                return 3;
            }
            else return 2;
        }
    }
    else{
        if(tablerouser[num1][num2]=='*'||tablerouser[num1][num2]=='X'){
            return 1;
        }
        else if(tablerouser[num1][num2]=='.'){
            return 4;
        }
        else{
            if(comprobarsihundido(num1,num2,2)==1){
                return 3;
            }
            else return 2;
        }
    }

}

void inicializartableros(){
    int i,j;
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            tablerocompuoculto[i][j]='.';
            tablerocompuvisible[i][j]='.';
            tablerouser[i][j]='.';
        }
    }
}
int sorteaturno(){
    int aleatorio;
    sleep(1);
    printf("SORTEANDO TURNO...\n");
    srand (time(NULL));
    aleatorio=rand()%2;
    //Sleep(1000);
    sleep(1);
    return aleatorio;
}

int comprobarsihundido(int num1,int num2,int tablero){
//9 casos diferentes
if(num1==0){
    if(num2==0){//1 esquina arriba izquierda
        if (tablero==1){
            if(tablerocompuoculto[num1][num2+1]=='O'||tablerocompuoculto[num1+1][num2]=='O'|| tablerocompuoculto[num1+1][num2+1]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1][num2+1]=='O'||tablerouser[num1+1][num2]=='O'|| tablerouser[num1+1][num2+1]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else if (num2==6){//2 esquina arriba derecha
        if (tablero==1){
            if(tablerocompuoculto[num1][num2-1]=='O'||tablerocompuoculto[num1+1][num2]=='O'|| tablerocompuoculto[num1+1][num2-1]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1][num2-1]=='O'||tablerouser[num1+1][num2]=='O'|| tablerouser[num1+1][num2-1]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else{//3 demas fila arriba
        if (tablero==1){
            if(tablerocompuoculto[num1][num2+1]=='O'||tablerocompuoculto[num1+1][num2]=='O'|| tablerocompuoculto[num1+1][num2+1]=='O'|| tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1+1][num2-1]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1][num2+1]=='O'||tablerouser[num1+1][num2]=='O'|| tablerouser[num1+1][num2+1]=='O'|| tablerouser[num1][num2-1]=='O'|| tablerouser[num1+1][num2-1]=='O'){
                return 1;
            }
           else return 0;
        }
    }
}

else if(num1==6){
    if (num2==0){//4 esquina abajo izquierda
        if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1-1][num2+1]=='O'|| tablerocompuoculto[num1][num2+1]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1-1][num2+1]=='O'|| tablerouser[num1][num2+1]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else if (num2==6){//5 esquina abajo derecha
        if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1-1][num2-1]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1][num2-1]=='O'|| tablerouser[num1-1][num2-1]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else{//6 demas fila abajo
        if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1-1][num2+1]=='O'|| tablerocompuoculto[num1][num2+1]=='O'|| tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1-1][num2-1]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1-1][num2+1]=='O'|| tablerouser[num1][num2+1]=='O'|| tablerouser[num1][num2-1]=='O'|| tablerouser[num1-1][num2-1]=='O'){
                return 1;
            }
           else return 0;
        }
    }
}

else if(num2==0 && num1!=0 && num1!=6){//7 demas columna izquierda
    if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1-1][num2+1]=='O'|| tablerocompuoculto[num1][num2+1]=='O'|| tablerocompuoculto[num1+1][num2+1]=='O'|| tablerocompuoculto[num1+1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1-1][num2+1]=='O'|| tablerouser[num1][num2+1]=='O'|| tablerouser[num1+1][num2+1]=='O'|| tablerouser[num1+1][num2]=='O'){
                return 1;
            }
           else return 0;
        }
}

else if(num2==6 && num1!=0 && num1!=6){//8 demas columna derecha
    if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1-1][num2-1]=='O'|| tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1+1][num2-1]=='O'|| tablerocompuoculto[num1+1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1-1][num2-1]=='O'|| tablerouser[num1][num2-1]=='O'|| tablerouser[num1+1][num2-1]=='O'|| tablerouser[num1+1][num2]=='O'){
                return 1;
            }
           else return 0;
        }
}

else{//9 todas las demas (centro)
    if (tablero==1){
                if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1-1][num2+1]=='O'|| tablerocompuoculto[num1][num2+1]=='O'|| tablerocompuoculto[num1+1][num2+1]=='O'|| tablerocompuoculto[num1+1][num2]=='O'|| tablerocompuoculto[num1+1][num2-1]=='O'|| tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1-1][num2-1]=='O'){
                    return 1;
                }
                else return 0;
            }
            else if (tablero==2){
            if(tablerouser[num1-1][num2]=='O'||tablerouser[num1-1][num2+1]=='O'|| tablerouser[num1][num2+1]=='O'|| tablerouser[num1+1][num2+1]=='O'|| tablerouser[num1+1][num2]=='O'|| tablerouser[num1+1][num2-1]=='O'|| tablerouser[num1][num2-1]=='O'|| tablerouser[num1-1][num2-1]=='O'){
                    return 1;
                }
               else return 0;
            }
}

return 0;


}
int main()
{
    int opc,auxi=0;
    inicializartableros();
    hundidoscompu=0;
    hundidosuser=0;
    printf("Hola, bienvenido al juego de hundir la flota. \n");
    sleep(1);
    printf("¿Qué quieres hacer? \n");
    do{
        printf("1.Iniciar nueva partida. \n");
        printf("2.Recuperar partida guardada. \n");
        scanf("%i",&opc);
        if (opc==1){
                auxi=1;
            printf("Ahora se colocará aleatoriamente los barcos en el tablero rival...\n");
            colocacompu();
            //Sleep(1000);
	    sleep(1);
            printf("Ahora podrás colocar tus barquitos en tu tablero...\n");
            colocauser();
            //Sleep(1000);
	    sleep(1);
            printf("Ahora se va a sortear el turno...\n");
            int aleatorio=sorteaturno();
            if(aleatorio==1){
                printf("Enhorabuena, te toca jugar el primero.\n");
                juegauser();
                //Sleep(1500);
		sleep(1);
                printf("turno terminado, asi ha quedado mi tablero:\n");
                imprimircompu();
                //Sleep(1500);
		sleep(1);
                turno=1;
            }
            else{
                printf("Vaya, la suerte dice que me toca empezar a mi. Prepárate!!\n");
                //Sleep(1000);
		sleep(1);
                printf("3\n");
                //Sleep(1000);
		sleep(1);
                printf("2\n");
                //Sleep(1000);
		sleep(1);
                printf("1\n");
                //Sleep(1000);
		sleep(1);
                juegacompu();
                //Sleep(1500);
		sleep(1);
                printf("turno terminado, asi ha quedado tu tablero:\n");
                imprimiruser();
                //Sleep(1500);
		sleep(1);
                turno=2;
            }
        }
        else if(opc==2){
            printf("En desarrollo.\n");//EN DESARROLLO
        }
    }while(auxi==0);

   while(hundidoscompu<3 && hundidosuser<3){
        if (turno==1){
            juegacompu();
            //Sleep(1500);
	    sleep(1);
            printf("turno terminado, asi ha quedado tu tablero:\n");
            imprimiruser();
            //Sleep(1500);
	    sleep(1);
            turno=0;
        }
        else {
            juegauser();
            //Sleep(1500);
	    sleep(1);
            printf("turno terminado, asi ha quedado mi tablero:\n");
            imprimircompu();
            //Sleep(1500);
	    sleep(1);
            turno=1;
        }
   }
  if(hundidosuser==3){
    printf("ENHORABUENA!! ME HAS GANADO :( PREPÁRATE PARA LA PRÓXIMA \n" );
         //¿EMPEZAR OTRA? POR DESARROLLAR
   }
  else if (hundidoscompu==3){
    printf("JAJAJA TE HE GANADO, SUERTE LA PRÓXIMA VEZ ;) \n");
         //¿EMPEZAR OTRA? POR DESARROLLAR
   }
          return 0;
 }
