#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicleta.h"
#include "string.h"
#include "utn.h"
#include "stdio_ext.h"
#include "informes.h"

eBicicleta* bici_new()
{
    eBicicleta* bici;
    bici = (eBicicleta*) malloc(sizeof(eBicicleta));

    return bici;
}

eBicicleta* bici_newParam(char* id, char* nombre, char* tipo, char* tiempo)
{

    eBicicleta* bici = NULL;

    bici = bici_new();

    if( bici != NULL)
    {
        //printf("Entre al primer if\n");
        if((bici_setId(bici, atoi(id)) == -1) ||
           (bici_setNombre(bici, nombre) == -1) ||
           (bici_setTipo(bici, tipo) == -1) ||
           (bici_setTiempo(bici, atoi(tiempo)) == -1))
           {
               printf("Problema al setear los paises.\n");
               free(bici);
               bici = NULL;
           }
    }
    else
    {
        printf("No se pudieron agregar los nuevos parametros.\n");
    }

    return bici;
}

int bici_setId(eBicicleta* bici, int id)
{
    int retorno = -1;

    if (bici != NULL && id >= 0)
    {

        bici->id_bike = id;
        retorno = 0;

    }
    return retorno;
}

int bici_setNombre(eBicicleta* bici, char* nombre)
{
    int retorno = -1;

    if (bici != NULL && nombre != NULL)
    {
        strcpy(bici->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}
int bici_setTipo(eBicicleta* bici, char* tipo)
{
    int retorno = -1;

    if (bici != NULL && tipo != NULL)
    {
        strcpy(bici->tipo, tipo);
        retorno = 0;
   }
    return retorno;
}
int bici_setTiempo(eBicicleta* bici, int tiempo)
{
    int retorno = -1;

    if (bici != NULL && tiempo >= 0)
    {
        bici->tiempo = tiempo;
        retorno = 0;
    }
    return retorno;
}

int bici_getId(eBicicleta* bici, int* id)
{
    int retorno = -1;

    if(bici != NULL && id!= NULL)
    {
        *id = bici->id_bike;
        retorno = 0;
    }

    return retorno;
}

int bici_getTipo(eBicicleta* bici, char* tipo)
{
    int retorno = -1;

    if (bici != NULL && tipo != NULL)
    {
        strcpy(tipo, bici->tipo);
        retorno = 0;
    }
    return retorno;
}

int bici_getTiempo(eBicicleta* bici, int* tiempo)
{
    int retorno = -1;

    if (bici != NULL && tiempo != NULL)
    {
        *tiempo = bici->tiempo;
        retorno = 0;
    }
    return retorno;
}

void* asignarAleatorios(void* bici)
{
    int tiempo;
    int aleatorio;
    eBicicleta* biciAux = (eBicicleta*) bici;

    if(bici != NULL)
    {
        aleatorio = rand()%(120)+50;
        tiempo = aleatorio;
        bici_setTiempo(biciAux, tiempo);
    }

    return biciAux;
}

int guardarArchivo(char* path, LinkedList* lista)
{
    int retorno = -1;
    FILE* f = fopen(path, "w");
    eBicicleta* bici = NULL;

    if( lista != NULL && f != NULL)
    {
        int len = ll_len(lista);

        fprintf(f, "id_bike,nombre,tipo,tiempo\n");

        for (int i = 0; i < len; i++)
        {
            bici = (eBicicleta*) ll_get(lista, i);
            if (bici != NULL)
            {
                fprintf(f, "%d,%s,%s,%d\n", bici->id_bike, bici->nombre, bici->tipo, bici->tiempo);
                retorno = 0;
            }
        }

        fclose(f);
        ll_clear(lista);
    }
    return retorno;
}

int menuFiltrar(LinkedList* lista)
{
    int opcion;
    int retorno = -1;
    LinkedList* listaAux = NULL;
    if ( lista != NULL)
    {
        system("clear");
        printf("***** MENU FILTRADO ****\n\n");
        printf("1. Filtrar por BMX\n");
        printf("2. Filtrar por PLAYERA\n");
        printf("3. Filtrar por MTB\n");
        printf("4. Filtrar por PASEO\n");
        printf("5. Salir\n");
        utn_getNumero(&opcion, "\n\nIngrese el numero de la opcion elegida: ", "Error. Ingreso un numero invalido.", 1, 5, 2);
        __fpurge(stdin);

        switch (opcion)
        {
        case 1:
             listaAux = ll_filter(lista, filtrarTipoBMX);
            if(listaAux != NULL && ll_len(listaAux) > 0)
            {
                if (guardarArchivo("BMX.csv", listaAux) == 0)
                {
                    system("clear");
                    printf("\nSe ha creado el archivo \"BMX.csv\". \n\n");
                    retorno = 0;
                }
            }
            else
            {
                printf("\nNo se pudo crear la lista filtrada\n");
            }

            break;

        case 2:
            listaAux = ll_filter(lista, filtrarTipoPlayera);
            if(listaAux != NULL && ll_len(listaAux) > 0)
            {
                if (guardarArchivo("PLAYERA.csv", listaAux) == 0)
                {
                    system("clear");
                    printf("\nSe ha creado el archivo \"PLAYERA.csv\".\n\n");
                    retorno = 0;
                }
            }
            else
            {
                printf("\nNo se pudo crear la lista filtrada\n");
            }
            break;

        case 3:
            listaAux = ll_filter(lista, filtrarTipoMTB);
            if(listaAux != NULL && ll_len(listaAux) > 0)
            {
                if (guardarArchivo("MTB.csv", listaAux) == 0)
                {
                    system("clear");
                    printf("\nSe ha creado el archivo \"MTB.csv\".\n\n");
                    retorno = 0;
                }
            }
            else
            {
                printf("\nNo se pudo crear la lista filtrada\n");
            }
            break;

        case 4:
            listaAux = ll_filter(lista, filtrarTipoPaseo);
            if(listaAux != NULL && ll_len(listaAux) > 0)
            {
                if (guardarArchivo("PASEO.csv", listaAux) == 0)
                {
                    system("clear");
                    printf("\nSe ha creado el archivo \"PASEO.csv\".\n\n");
                    retorno = 0;
                }
            }
            else
            {
                printf("\nNo se pudo crear la lista filtrada\n");
            }
            break;

        case 5:
            printf("\n\nSe ha cancelado la operacion\n\n");
            break;

        }
    }

    return retorno;
}


