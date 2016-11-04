#include "cabecera.h"

int main()
{
    int opc,auxi=0;
    inicializartableros();
    hundidoscompu=0;
    hundidosuser=0;
    printf("Hola, bienvenido al juego de hundir la flota. \n");
    Sleep(1000);
    printf("¿Que quieres hacer? \n");
    do{
        printf("1.Iniciar nueva partida. \n");
        printf("2.Recuperar partida guardada. \n");
        scanf("%i",&opc);
        if (opc==1){
                auxi=1;
            printf("Ahora se colocará aleatoriamente los barcos en el tablero rival...\n");
            colocacompu();
            Sleep(1000);
            printf("Ahora podrás colocar tus barquitos en tu tablero...\n");
            colocauser();
            Sleep(1000);
            printf("Ahora se va a sortear el turno...\n");
            int aleatorio=sorteaturno();
            if(aleatorio==1){
                printf("Enhorabuena, te toca jugar el primero.\n");
                juegauser();
                Sleep(1500);
                printf("turno terminado, asi ha quedado mi tablero:\n");
                imprimircompu();
                Sleep(1500);
                turno=1;
            }
            else{
                printf("Vaya, la suerte dice que me toca empezar a mi. Preparate!!\n");
                Sleep(1000);
                printf("3\n");
                Sleep(1000);
                printf("2\n");
                Sleep(1000);
                printf("1\n");
                Sleep(1000);
                juegacompu();
                Sleep(1500);
                printf("turno terminado, asi ha quedado tu tablero:\n");
                imprimiruser();
                Sleep(1500);
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
            Sleep(1500);
            printf("turno terminado, asi ha quedado tu tablero:\n");
            imprimiruser();
            Sleep(1500);
            turno=0;
        }
        else {
            juegauser();
            Sleep(1500);
            printf("turno terminado, asi ha quedado mi tablero:\n");
            imprimircompu();
            Sleep(1500);
            turno=1;
        }
   }
   if(hundidosuser==3){
    printf("ENHORABUENA!! ME HAS GANADO :( PREPÁRATE PARA LA PROXIMA \n");
    //¿EMPEZAR OTRA? POR DESARROLLAR
   }
   else if (hundidoscompu==3){
    printf("JAJAJA TE HE GANADO, SUERTE LA PROXIMA VEZ ;) \n");
    //¿EMPEZAR OTRA? POR DESARROLLAR
   }


    return 0;
}
