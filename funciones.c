#include "cabecera.h"
/*
##Proyecto miniflota##
Realizado por David Rubio Mateos (bk0084)
main.c con el programa principal
funciones.c con el desarrollo de todas las funciones utilizadas
cabecera.h con la declaración de variables globales y cabeceras de funciones
*/

void colocauser(){//PERMITE AL USUARIO COLOCAR SUS BARCOS EN EL TABLERO
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
            printf("Error! En esta posici\242n no se puede colocar el barco porque est\240 junto a otro. Prueba de nuevo, as\241 est\240 tu tablero: \n");
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
            printf("Error! En esta posici\242n no se puede colocar el barco porque est\240 junto a otro. Prueba de nuevo, as\241 est\240 tu tablero: \n");
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
    printf("%cDonde quieres introducir la segunda unidad del barco? \n",168);
     int aux3=0,aux2;
    while(aux3==0){
    printf("1. Arriba\n");
	printf("2. Derecha\n");
	printf("3. Abajo\n");
	printf("4. Izquierda\n");
	printf("Elija una orientaci\242n(1-4): ");
        scanf("%i",&aux2);
            if(aux2==1){
                 if(num1!=1){
                    int numaux1=num1-1;
                    aux=comprobar(numaux1-1,num2-1,2);
                    if(aux==1){
                        printf("Error no puede ser introducido en este espacio porque tiene otro barco al lado, por favor, int\202ntalo de nuevo, as\241 est\240 tu tablero:");
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
                printf("Error no puede ser introducido en este espacio, por favor, int\202ntalo de nuevo, \202ste es tu tablero:");
                imprimiruser();}
            }



          else if(aux2==2){
                     if(num2!=7){
                        int numaux2=num2+1;
                        aux=comprobar(num1-1,numaux2-1,2);
                        if(aux==1){
                            printf("Error no puede ser introducido en este espacio porque tiene otro barco al lado, por favor, int\202ntalo de nuevo, as\241 est\240 tu tablero:");
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
                    printf("Error no puede ser introducido en este espacio, por favor, int\202ntalo de nuevo, \202ste es tu tablero:");
                    imprimiruser();}
                }


           else if(aux2==3){
                 if(num1!=7){
                    int numaux1=num1+1;
                    aux=comprobar(numaux1-1,num2-1,2);
                    if(aux==1){
                        printf("Error no puede ser introducido en este espacio porque tiene otro barco al lado, por favor, int\202ntalo de nuevo, as\241 est\240 tu tablero:");
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
                printf("Error no puede ser introducido en este espacio, por favor, int\202ntalo de nuevo, \202ste es tu tablero:");
                imprimiruser();}
            }

           else if(aux2==4){
                 if(num2!=1){
                    int numaux2=num2-1;
                    aux=comprobar(num1-1,numaux2-1,2);
                    if(aux==1){
                        printf("Error no puede ser introducido en este espacio porque tiene otro barco al lado, por favor, int\202ntalo de nuevo, as\241 est\240 tu tablero:");
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
                printf("Error no puede ser introducido en este espacio, por favor, int\202ntalo de nuevo, \202ste es tu tablero:");
                imprimiruser();}
            }

            else {
            printf("Error, el numero debe estar entre 1 y 4. int\202ntalo de nuevo:");}


        }
         system("cls");
         printf("Todos los barcos han sido colocados correctamente \n");
         printf("As\241 ha quedado tu tablero final: \n");
         imprimiruser();




}

void colocacompu(){//COLOCA LOS BARCOS ALEATORIAMENTE EN EL TABLERO
    int aux=0,i;
    srand (time(NULL));
    for(i=0;i<2;i++){
        num1=rand()%7;
        Sleep(500);
        num2=rand()%7;
        Sleep(1001);
        aux=comprobar(num1,num2,1);
        while (aux==1){
            int num1=rand()%7;
            Sleep(1);
            int num2=rand()%7;
            Sleep(1);
            aux=comprobar(num1,num2,1);
        }
        tablerocompuoculto[num1][num2]='O';
        printf("Barco %i colocado \n",i+1);


    }

        num1=rand()%7;
        Sleep(1000);
        num2=rand()%7;
        Sleep(1000);
        aux=comprobar(num1,num2,1);
    while (aux==1){
            num1=rand()%7;
            Sleep(1);
            num2=rand()%7;
            Sleep(1);
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

int comprobar(int num1, int num2, int tablero){//COMPRUEBA QUE AL COLOCAR LOS BARCOS, NO HAYA MAS BARCOS COLINDANTES A ESTE
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

void juegacompu(){//TURNO DE JUEGO DEL ORDENADOR
    int barco, aux1=1;
    do{
    num1=rand()%7;
    num2=rand()%7;
    barco=comprobarBARCOS(num1,num2,2);
    if(barco==1){

    }
    else if(barco==2){

            printf("TE HE HUNDIDO UN BARCO\n");
            Sleep(1000);
            tablerouser[num1][num2]='X';
            hundidoscompu=hundidoscompu+1;
            marcardisparos(num1,num2,2);
            aux1=0;
        }
    else if(barco==3){

            printf("HE TOCADO UN BARCO\n");
            Sleep(1000);
            tablerouser[num1][num2]='X';
            aux1=0;
        }
    else if(barco==4){
            tablerouser[num1][num2]='*';
            tablerouser[num1][num2]='*';

            printf("HE DISPARADO AGUA!! \n");
            Sleep(1000);
            aux1=0;
        }
    }while(aux1==1);

}

void juegauser(){//TURNO DE JUEGO DEL USUARIO
    int barco, aux1=1;
    printf("ES TU TURNO. \n");
    do{
    int num1=1,num2=1;
    printf("Introduce Fila(1-7) o '100' para guardar la partida: \n");
    scanf("%i",&num1);
    if(num1==100){
        guardapartida();

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
        printf("YA HAS DISPARADO A ESTA DIRECCI%cN ANTERIORMENTE. INT\112NTALO DE NUEVO \n",32);
    }
    else if(barco==2){
            system("cls");
            printf("ME HAS HUNDIDO UN BARCO\n");
            Sleep(2000);
            tablerocompuoculto[num1-1][num2-1]='X';
            tablerocompuvisible[num1-1][num2-1]='X';
            hundidosuser=hundidosuser+1;
            marcardisparos(num1-1,num2-1,1);
            aux1=0;
        }
    else if(barco==3){
            system("cls");
            printf("ME HAS TOCADO UN BARCO\n");
            Sleep(2000);
            tablerocompuoculto[num1-1][num2-1]='X';
            tablerocompuvisible[num1-1][num2-1]='X';
            aux1=0;
        }
    else if(barco==4){
            tablerocompuoculto[num1-1][num2-1]='*';
            tablerocompuvisible[num1-1][num2-1]='*';
            system("cls");
            printf("AGUA!! MAS SUERTE LA PROXIMA VEZ  \n");
            Sleep(2000);
            aux1=0;
        }
    }while(aux1==1);
}

void imprimiruser(){//IMPRIME TABLERO USUARIO
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

void imprimircompu(){//IMPRIME TABLERO ORDENADOR
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

int comprobarBARCOS(int num1,int num2,int tablero){//COMPRUEBA SI AL DISPARAR HAY BARCOS EN ESA POSICION
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

void inicializartableros(){//INICIALIZA LOS TABLEROS DE USUARIO Y ORDENADOR
    int i,j;
    for(i=0;i<7;i++){
        for(j=0;j<7;j++){
            tablerocompuoculto[i][j]='.';
            tablerocompuvisible[i][j]='.';
            tablerouser[i][j]='.';
        }
    }
}

int sorteaturno(){//SORTEA EL TURNO AL PRINCIPIO DEL JUEGO
    int aleatorio;
    Sleep(1000);
    printf("SORTEANDO TURNO...\n");
    srand (time(NULL));
    aleatorio=rand()%2;
    Sleep(1000);
    return aleatorio;
}

int comprobarsihundido(int num1,int num2,int tablero){//COMPRUEBA SI AL DISPARAR A UN BARCO ES TOCADO O HUNDIDO
//9 casos diferentes
if(num1==0){
    if(num2==0){//1 esquina arriba izquierda
        if (tablero==1){
            if(tablerocompuoculto[num1][num2+1]=='O'||tablerocompuoculto[num1+1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1][num2+1]=='O'||tablerouser[num1+1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else if (num2==6){//2 esquina arriba derecha
        if (tablero==1){
            if(tablerocompuoculto[num1][num2-1]=='O'||tablerocompuoculto[num1+1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1][num2-1]=='O'||tablerouser[num1+1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else{//3 demas fila arriba
        if (tablero==1){
            if(tablerocompuoculto[num1][num2+1]=='O'||tablerocompuoculto[num1+1][num2]=='O'|| tablerocompuoculto[num1][num2-1]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1][num2+1]=='O'||tablerouser[num1+1][num2]=='O'|| tablerouser[num1][num2-1]=='O'){
                return 1;
            }
           else return 0;
        }
    }
}

else if(num1==6){
    if (num2==0){//4 esquina abajo izquierda
        if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'|| tablerocompuoculto[num1][num2+1]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'|| tablerouser[num1][num2+1]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else if (num2==6){//5 esquina abajo derecha
        if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'||tablerocompuoculto[num1][num2-1]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'||tablerouser[num1][num2-1]=='O'){
                return 1;
            }
            else return 0;
        }
    }
    else{//6 demas fila abajo
        if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'|| tablerocompuoculto[num1][num2+1]=='O'|| tablerocompuoculto[num1][num2-1]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'|| tablerouser[num1][num2+1]=='O'|| tablerouser[num1][num2-1]=='O'){
                return 1;
            }
           else return 0;
        }
    }
}

else if(num2==0 && num1!=0 && num1!=6){//7 demas columna izquierda
    if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'|| tablerocompuoculto[num1][num2+1]=='O'|| tablerocompuoculto[num1+1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'|| tablerouser[num1][num2+1]=='O'|| tablerouser[num1+1][num2]=='O'){
                return 1;
            }
           else return 0;
        }
}

else if(num2==6 && num1!=0 && num1!=6){//8 demas columna derecha
    if (tablero==1){
            if(tablerocompuoculto[num1-1][num2]=='O'|| tablerocompuoculto[num1][num2-1]=='O'|| tablerocompuoculto[num1+1][num2]=='O'){
                return 1;
            }
            else return 0;
        }
        else if (tablero==2){
        if(tablerouser[num1-1][num2]=='O'|| tablerouser[num1][num2-1]=='O'|| tablerouser[num1+1][num2]=='O'){
                return 1;
            }
           else return 0;
        }
}

else{//9 todas las demas (centro)
    if (tablero==1){
                if(tablerocompuoculto[num1-1][num2]=='O'|| tablerocompuoculto[num1][num2+1]=='O'|| tablerocompuoculto[num1+1][num2]=='O'|| tablerocompuoculto[num1][num2-1]=='O'){
                    return 1;
                }
                else return 0;
            }
            else if (tablero==2){
            if(tablerouser[num1-1][num2]=='O'|| tablerouser[num1][num2+1]=='O'|| tablerouser[num1+1][num2]=='O'|| tablerouser[num1][num2-1]=='O'){
                    return 1;
                }
               else return 0;
            }
}

return 0;
}

void guardapartida(){//GUARDA LOS TABLEROS Y LAS VARIABLES NECESARIAS EN UN FICHERO BINARIO

FILE *fich;
if ((fich = fopen("miniflota_g.dat", "wb")) == NULL){
    printf ("Error en apertura del fichero para escritura\n");
    }
else {
    system("cls");
    printf ("Guardando partida...\n");
    fwrite(&hundidoscompu, sizeof(int), 1, fich);
    fwrite(&hundidosuser, sizeof(int), 1, fich);
    fwrite(&tablerocompuoculto, sizeof(tablerocompuoculto), 1, fich);
    fwrite(&tablerocompuvisible, sizeof(tablerocompuvisible), 1, fich);
    fwrite(&tablerouser, sizeof(tablerouser), 1, fich);
    Sleep(1000);
    printf ("Partida guardada\n");
    Sleep(1000);
    system("cls");
    printf ("Ahora el programa se cerrar\240.\n");
    Sleep(1000);
    exit(0);

 }
fclose (fich);
}

void marcardisparos(int num1,int num2, int tablero){//CUANDO SE HUNDE UN BARCO, MARCA COMO DISPARADAS LAS POSICIONES DIRECTAMENTE COLINDANTES
    int auxnum1, auxnum2;
    if(tablero==1){
        auxnum1=num1;
        auxnum2=num2+1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
                if (tablerocompuoculto[auxnum1][auxnum2]=='.'){
                    tablerocompuoculto[auxnum1][auxnum2]='*';
                    tablerocompuvisible[auxnum1][auxnum2]='*';
                }
                else if(tablerocompuoculto[auxnum1][auxnum2]=='X'){
                    tablerocompuoculto[num1][num2]='T';
                    marcardisparos(auxnum1,auxnum2,1);
                    tablerocompuoculto[num1][num2]='X';
                }
        }
        auxnum1=num1;
        auxnum2=num2-1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
                if (tablerocompuoculto[auxnum1][auxnum2]=='.'){
                    tablerocompuoculto[auxnum1][auxnum2]='*';
                    tablerocompuvisible[auxnum1][auxnum2]='*';
                }
                else if(tablerocompuoculto[auxnum1][auxnum2]=='X'){
                    tablerocompuoculto[num1][num2]='T';
                    marcardisparos(auxnum1,auxnum2,1);
                    tablerocompuoculto[num1][num2]='X';
                }
        }
        auxnum1=num1+1;
        auxnum2=num2;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
                if (tablerocompuoculto[auxnum1][auxnum2]=='.'){
                    tablerocompuoculto[auxnum1][auxnum2]='*';
                    tablerocompuvisible[auxnum1][auxnum2]='*';
                }
                else if(tablerocompuoculto[auxnum1][auxnum2]=='X'){
                    tablerocompuoculto[num1][num2]='T';
                    marcardisparos(auxnum1,auxnum2,1);
                    tablerocompuoculto[num1][num2]='X';
                }
        }
        auxnum1=num1-1;
        auxnum2=num2;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
                if (tablerocompuoculto[auxnum1][auxnum2]=='.'){
                    tablerocompuoculto[auxnum1][auxnum2]='*';
                    tablerocompuvisible[auxnum1][auxnum2]='*';
                }
                else if(tablerocompuoculto[auxnum1][auxnum2]=='X'){
                    tablerocompuoculto[num1][num2]='T';
                    marcardisparos(auxnum1,auxnum2,1);
                    tablerocompuoculto[num1][num2]='X';
                }
        }
        auxnum1=num1+1;
        auxnum2=num2+1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
            tablerocompuoculto[auxnum1][auxnum2]='*';
            tablerocompuvisible[auxnum1][auxnum2]='*';
        }
        auxnum1=num1+1;
        auxnum2=num2-1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
            tablerocompuoculto[auxnum1][auxnum2]='*';
            tablerocompuvisible[auxnum1][auxnum2]='*';
        }
        auxnum1=num1-1;
        auxnum2=num2-1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
            tablerocompuoculto[auxnum1][auxnum2]='*';
            tablerocompuvisible[auxnum1][auxnum2]='*';
        }
        auxnum1=num1-1;
        auxnum2=num2+1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
            tablerocompuoculto[auxnum1][auxnum2]='*';
            tablerocompuvisible[auxnum1][auxnum2]='*';
        }
    }
    else {
        auxnum1=num1;
        auxnum2=num2+1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
                if (tablerouser[auxnum1][auxnum2]=='.'){
                    tablerouser[auxnum1][auxnum2]='*';
                }
                else if(tablerouser[auxnum1][auxnum2]=='X'){
                    tablerouser[num1][num2]='T';
                    marcardisparos(auxnum1,auxnum2,2);
                    tablerouser[num1][num2]='X';
                }
        }
        auxnum1=num1;
        auxnum2=num2-1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
                if (tablerouser[auxnum1][auxnum2]=='.'){
                    tablerouser[auxnum1][auxnum2]='*';
                }
                else if(tablerouser[auxnum1][auxnum2]=='X'){
                    tablerouser[num1][num2]='T';
                    marcardisparos(auxnum1,auxnum2,2);
                    tablerouser[num1][num2]='X';
                }
        }
        auxnum1=num1+1;
        auxnum2=num2;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
                if (tablerouser[auxnum1][auxnum2]=='.'){
                    tablerouser[auxnum1][auxnum2]='*';
                }
                else if(tablerouser[auxnum1][auxnum2]=='X'){
                    tablerouser[num1][num2]='T';
                    marcardisparos(auxnum1,auxnum2,2);
                    tablerouser[num1][num2]='X';
                }
        }
        auxnum1=num1-1;
        auxnum2=num2;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
                if (tablerouser[auxnum1][auxnum2]=='.'){
                    tablerouser[auxnum1][auxnum2]='*';
                }
                else if(tablerouser[auxnum1][auxnum2]=='X'){
                    tablerouser[num1][num2]='T';
                    marcardisparos(auxnum1,auxnum2,2);
                    tablerouser[num1][num2]='X';
                }
        }
        auxnum1=num1+1;
        auxnum2=num2+1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
            tablerouser[auxnum1][auxnum2]='*';
        }
        auxnum1=num1+1;
        auxnum2=num2-1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
            tablerouser[auxnum1][auxnum2]='*';
        }
        auxnum1=num1-1;
        auxnum2=num2-1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
            tablerouser[auxnum1][auxnum2]='*';
        }
        auxnum1=num1-1;
        auxnum2=num2+1;
        if(auxnum1>=0 && auxnum1<7 && auxnum2>=0 && auxnum2<7){
            tablerouser[auxnum1][auxnum2]='*';
        }

    }

}
