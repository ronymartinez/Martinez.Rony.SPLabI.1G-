#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "parser.h"
#include "bicicleta.h"

int parser_FromText(char* pFile, LinkedList* lista)
{
    eBicicleta* bicicleta = NULL;
    int retorno = -1;
    char buffer[4][20];

    int cant = 0;

    FILE* f = fopen(pFile, "r");

    //printf("Entre al parser\n");

    if (f != NULL && pFile != NULL  && lista != NULL)
    {
        system("clear");

        while(!feof(f))
        {
            if(cant == 0)
            {
                //cant = fscanf(f,"%[^,], %[^,], %[^,], %[^,], %[^\n]");
                cant = fscanf(f,"%[^,], %[^,], %[^,], %[^\n]", buffer[0], buffer[1], buffer[2], buffer[3]);
            }
            //printf("Cant = %d \n", cant);

            //cant = fscanf(f,"%d,%[^,],%d,%d,%d\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            cant = fscanf(f,"%[^,], %[^,], %[^,], %[^\n]", buffer[0], buffer[1], buffer[2], buffer[3]);


                //printf("%4d    %-18s %10d %10d %10d\n", bicicleta->id, bicicleta->nombre, bicicleta->infec,
           if (cant == 4)
            {
              bicicleta = bici_newParam(buffer[0], buffer[1], buffer[2], buffer[3]);

              if(bicicleta != NULL)
              {
                ll_add(lista, bicicleta);
                retorno = 0;
                //printf("%d %s %s %d", atoi(buffer[0]), buffer[1], buffer[2], atoi(buffer[3]));
                //getchar();
                //printf("%d %s", bicicleta->id_bike, bicicleta->nombre);
                //getchar();
              }
              //printf("%d %s", atoi(bicicleta->id), bicicleta->nombre);
                //printf("%d %s %d %d %d\n", atoi(buffer[0]), buffer[1], atoi(buffer[2]), atoi(buffer[3]), atoi(buffer[4]));
            }

            //printf("Cant =%d \n", cant);
        }
    }
    else
    {
        printf("No se pudo cargar el archivo.\n");
    }

    return retorno;
}
