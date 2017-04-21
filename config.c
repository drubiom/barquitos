#include "cabecera.h"
void main2()
{
    INFBOLETO cfg;
    char respuesta;
    FILE * config;
    if(!(config=fopen("config.dat","wb")))
    {
        printf("Error en la apertura del fichero");
    }
    strcpy(cfg.cpostal, "28220-");
    strcpy(cfg.cadmin, "12-");
    cfg.nboleto=0;
    cfg.precio=10;
    fwrite(&cfg, sizeof(INFBOLETO), 1, config);
    fclose(config);
}
