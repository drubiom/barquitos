#include "cabecera.h"
/*
##Proyecto miniflota##
Realizado por David Rubio Mateos (bk0084)
main.c con el programa principal
funciones.c con el desarrollo de todas las funciones utilizadas
cabecera.h con la declaración de variables globales y cabeceras de funciones
*/

int main()
{
    int opc,auxi=0;
    inicializartableros();
    hundidoscompu=0;
    hundidosuser=0;
    printf("Hola, bienvenido al juego de hundir la flota. \n");
    Sleep(1000);
    printf("%cQu\202 quieres hacer? \n",168);
    do{
        printf("1.Iniciar nueva partida. \n");
        printf("2.Recuperar partida guardada. \n");
        scanf("%i",&opc);
        if (opc==1){
                system("cls");
                auxi=1;
            printf("Ahora se colocar\240n aleatoriamente los barcos en el tablero rival...\n");
            colocacompu();
            Sleep(1000);
            system("cls");
            printf("Ahora podr\240s colocar tus barquitos en tu tablero...\n");
            colocauser();
            system("pause");

            system("cls");
            printf("Ahora se va a sortear el turno...\n");
            int aleatorio=sorteaturno();
            if(aleatorio==1){
                printf("Enhorabuena, te toca jugar el primero.\n");
                juegauser();
                Sleep(1500);
                printf("Turno terminado, as\241 ha quedado mi tablero:\n");
                imprimircompu();
                Sleep(1500);
                turno=1;
            }
            else{
                printf("Vaya, la suerte dice que me toca empezar a mi. Prep\240rate!!\n");
                Sleep(1000);
                printf("3\n");
                Sleep(1000);
                printf("2\n");
                Sleep(1000);
                printf("1\n");
                Sleep(1000);
                system("cls");
                juegacompu();
                Sleep(1500);
                printf("Turno terminado, as\241 ha quedado tu tablero:\n");
                imprimiruser();
                Sleep(1500);
                turno=2;
            }
        }
        else if(opc==2){
            FILE *fich;
            if ((fich = fopen("miniflota_g.dat", "rb")) == NULL)
                { // control del error de apertura
                printf ( "Error en la apertura. Es posible que el fichero no exista \n");
                }
            else
                { fread (&hundidoscompu, sizeof(int), 1, fich);
                fread (&hundidosuser, sizeof(int), 1, fich);
                fread (&tablerocompuoculto, sizeof(tablerocompuoculto), 1, fich);
                fread (&tablerocompuvisible, sizeof(tablerocompuvisible), 1, fich);
                fread (&tablerouser, sizeof(tablerouser), 1, fich);
                fclose (fich);
                system("cls");
                printf("Partida recuperada!!\nContin\243a con la partida, as\241 est\240 mi tablero, Dispara!!\n");
                imprimircompu();
                juegauser();
                Sleep(1500);
                printf("Turno terminado, as\241 ha quedado mi tablero:\n");
                imprimircompu();
                Sleep(1500);
                turno=1;
                auxi=1;
                }


        }
    }while(auxi==0);

   while(hundidoscompu<3 && hundidosuser<3){
        if (turno==1){
            juegacompu();
            Sleep(1500);
            printf("Turno terminado, as\241 ha quedado tu tablero:\n");
            imprimiruser();
            Sleep(1500);
            turno=0;
        }
        else {
            juegauser();
            Sleep(1500);
            printf("Turno terminado, as\241 ha quedado mi tablero:\n");
            imprimircompu();
            Sleep(1500);
            turno=1;
        }

   }
   if(hundidosuser==3){
        system("cls");
    printf("ENHORABUENA!! ME HAS GANADO :( PREP\240RATE PARA LA PR\32XIMA \n");
    //¿EMPEZAR OTRA?
   }
   else if (hundidoscompu==3){
       system("cls");
    printf("JAJAJA TE HE GANADO, SUERTE LA PR\32XIMA VEZ ;) \n");
    //¿EMPEZAR OTRA?
   }


    return 0;
}
