#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "stdio_ext.h"
#include "LinkedList.h"
#include "utn.h"
#include "parser.h"
#include "bicicleta.h"
#include "informes.h"


int menu()
{
    int opcion;

    system("clear");
    printf("***** MENU DE OPCIONES *****\n\n");
    printf("1. Cargar un archivo.\n");
    printf("2. Imprimir lista.\n");
    printf("3. Asignar tiempos.\n");
    printf("4. Filtrar por tipo.\n");
    printf("5. Mostrar posiciones\n");
    printf("6. Guardar posiciones.\n");
    printf("7. Salir.\n\n");
    __fpurge(stdin);
    utn_getNumero(&opcion, "\nIngrese una opcion: ", "Error: Ingreso una opcion invalida.\n", 1, 7,3);

    return opcion;
}

int listarBicicletas(LinkedList* lista)
{
    int retorno = -1;
    eBicicleta* bici = NULL;
    //printf("%d\n", ll_len(lista));
    //getchar();
    int len = ll_len(lista);
    system("clear");
    printf(" _________________________________________\n");
    printf("│     │             │            │        │\n");
    printf("│ ID  │   NOMBRE    │    TIPO    │ TIEMPO │\n");
    printf("│_____│_____________│____________│________│\n");

    if (lista != NULL)
    {
        for (int i = 0; i < len; i++)
        {

            bici = ll_get(lista, i);
            //printf("%d \n", bici->id_bike);

            if(bici != NULL)
            {
            listarBici(bici);
            retorno = 0;
            }
            else
            {
                printf("\n\nProblema al intentar listar: lista = null\n\n");
            }

        }
    }
    printf("│_____│_____________│____________│________│\n");

    return retorno;
}

int listarBici(eBicicleta* bici)
{
    int retorno = -1;
                 //printf("%d: Entre a listarBici \n");
              //getchar();
    if(bici != NULL)
    {
    //    printf("Entre a ListarBici\n");
      //  printf("%s\n", bici->nombre);
        //getchar();
    printf("│ %-4d│ %-10s  │ %-10s │ %-7d│\n", bici->id_bike, bici->nombre, bici->tipo, bici->tiempo);
    retorno = 0;
    }
    return retorno;
}

int filtrarTipoBMX(void* elemento)
{
    int retorno = 0;

    eBicicleta* bici = (eBicicleta*) elemento;
    if(strcmp(bici->tipo, "BMX") == 0)
    {
        retorno = 1;
    }
    return retorno;
}

int filtrarTipoPlayera(void* elemento)
{
    int retorno = 0;

    eBicicleta* bici = (eBicicleta*) elemento;
    if(strcmp(bici->tipo, "PLAYERA") == 0)
    {
        retorno = 1;
    }
    return retorno;
}

int filtrarTipoMTB(void* elemento)
{
    int retorno = 0;

    eBicicleta* bici = (eBicicleta*) elemento;
    if(strcmp(bici->tipo, "MTB") == 0)
    {
        retorno = 1;
    }
    return retorno;
}

int filtrarTipoPaseo(void* elemento)
{
    int retorno = 0;

    eBicicleta* bici = (eBicicleta*) elemento;
    if(strcmp(bici->tipo, "PASEO") == 0)
    {
        retorno = 1;
    }
    return retorno;
}

int filtrarOrdenado(void* elemento)
{
    int retorno = 0;

    if(1)
    {
        retorno = 1;
    }
    return retorno;
}
int funcionOrdenar1(void* bici1, void* bici2)
{
    int retorno = 0;
    char tipo1[20];
    char tipo2[20];
    int tiempo1;
    int tiempo2;

    if(bici1 != NULL && bici2 != NULL)
    {
        eBicicleta* biciAux1 = (eBicicleta*) bici1;
        eBicicleta* biciAux2 = (eBicicleta*) bici2;

        bici_getTipo(biciAux1, tipo1);
        bici_getTipo(biciAux2, tipo2);
        bici_getTiempo(biciAux1, &tiempo1);
        bici_getTiempo(biciAux2, &tiempo2);
        //printf("Entre al if de funcionOrdenar.\n\n");
        //getchar();
        if(strcmp(tipo1, tipo2) > 0)
        {
            retorno = 1;
        }
        else if (strcmp(tipo1, tipo2)==0)
        {
            if(tiempo1 > tiempo2)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}

int funcionOrdenar2(void* bici1, void* bici2)
{
    int retorno = 0;
    char tipo1[20];
    char tipo2[20];
    int tiempo1;
    int tiempo2;

    if(bici1 != NULL && bici2 != NULL)
    {
        eBicicleta* biciAux1 = (eBicicleta*) bici1;
        eBicicleta* biciAux2 = (eBicicleta*) bici2;

        bici_getTipo(biciAux1, tipo1);
        bici_getTipo(biciAux2, tipo2);
        bici_getTiempo(biciAux1, &tiempo1);
        bici_getTiempo(biciAux2, &tiempo2);
        //printf("Entre al if de funcionOrdenar.\n\n");
        //getchar();
        if(strcmp(tipo1, tipo2) < 0)
        {
            retorno = 1;
        }
        else if (strcmp(tipo1, tipo2)==0)
        {
            if(tiempo1 < tiempo2)
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
            }
        }
    }

    return retorno;
}

int listarOrdenado(LinkedList* lista)
{
    int retorno = -1;
    int orden;

    if(lista != NULL)
    {
        system("clear");
        printf("**** MENU DE ORDENAMIENTO ****\n\n");
        printf("1. Orden ascendente\n");
        printf("2. Orden descendente\n");
        printf("3. Cancelar\n\n");
        __fpurge(stdin);
        utn_getNumero(&orden, "\nIngrese la opcion elegida: ", "Error. Ingreso un dato invalido\n", 1, 3, 2);

        switch (orden)
        {
            case 1:
            if (!ll_sort(lista, funcionOrdenar1, 1))
            {
                listarBicicletas(lista);
                retorno = 0;
            }
            else
            {
                printf("\nNo se pudo realizar el ordenamiento.\n");
            }
            break;

            case 2:
             if (!ll_sort(lista, funcionOrdenar2, 1))
            {
                listarBicicletas(lista);
                retorno = 0;
            }
            else
                {
                    printf("\nNo se pudo realizar el ordenamiento.\n");
                }
            break;

            case 3:
            default:
                printf("\nSe ha cancelado la operacion.\n\n");
                break;
        }
    }

   return retorno;
}



