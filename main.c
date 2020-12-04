// PROYECTO REALIZADO EN LINUX 64 BITS
// AUTOR: RONY MARTINEZ CASTILLO
//_______________________________________

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "parser.h"
#include "bicicleta.h"
#include "informes.h"
#include "stdio_ext.h"
#include "string.h"
 #include <time.h>


int main()
{
    srand (time(NULL));  // esta linea va al inicio de main

    char archivo[20];;
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaAux = ll_newLinkedList();
    LinkedList* listaOrdenada = ll_newLinkedList();
    int llaveCarga = 0;
    int llaveTiempo = 0;
    int llavePosicion = 0;
    char seguir = 's';
    char confirma;

    do
    {
        switch(menu())
        {
        case 1:
            system("clear");
            printf("***** CARGAR ARCHIVO ******\n\n");
            utn_getNombre(archivo, 20, "\nIngrese el nombre del archivo (ejemplo: bicicletas): ", "Error. Ingreso un nombre invalido\n", 2);
            __fpurge(stdin);

            //VERIFICO SI SE INGRESO CORRECTAMENTE EL NOMBRE DEL ARCHIVO ANTES DEL PARSEO
            if(strcmp(archivo, "bicicletas") == 0)
            {
                if (!parser_FromText("bicicletas.csv", lista))
                {
                    printf("Se ha cargado la lista correctamente.\n\n");
                    llaveCarga = 1;
                }
            }
            else
            {
                printf("\nNo se ha encontrado el archivo con los datos ingresados.\n\n");
            }

            break;

        case 2:
            if (llaveCarga == 1) // MUESTRO POR PARTALLA SI SE HIZO EL PARSEO CORRECTAMENTE
            {
                listarBicicletas(lista);
            }
            else
            {
                printf("\n\nNo se puede listar si no se cargo el archivo.\n\n");
            }
            break;

        case 3:
            if (llaveCarga == 1)
            {
                lista = ll_map(lista, asignarAleatorios);
                if(lista != NULL)
                {
                    system("clear");
                    printf("Se han asignado los tiempos aleatorios.\n\n");
                    llaveTiempo = 1;
                }

            }
            else
            {
                printf("\n\nNo se puede listar si no se cargo el archivo.\n\n");
            }
            break;

        case 4:
            if(llaveTiempo == 1)
            {
                if (menuFiltrar(lista))
                {
                    printf("\n\nNo se pudo realizar el filtrado.\n\n");
                }

            }
            else
            {
                printf("\n\nNo se puede filtrar si no asigno los tiempos o no cargo el archivo.\n\n");
            }

            break;

        case 5:
            if(llaveTiempo == 1)
            {
               if(!listarOrdenado(lista))
               {
                   llavePosicion = 1;
               }
            }
            else
            {
                printf("\n\nNo se puede ordenar si no asigno los tiempos.\n\n");
            }
            break;

        case 6:
                if(llavePosicion == 1)
                {
                    listaOrdenada = ll_filter(lista, filtrarOrdenado);
                    guardarArchivo("listaOrdenada.csv", listaOrdenada);
                    printf("\n\nSe ha creado el archivo \"listaOrdenada.csv\".\n\n");
                }
                else
                {
                    printf("\n\nNo se puede guardar si no ordeno las posiciones.\n\n");
                }

            break;


        case 7:
            printf("\nIngrese 's' para confirmar salida: ");
            __fpurge(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                seguir = 'n';
                printf("\nHa finalizado el programa\n");
            }
            break;
        }
        printf("\n\n");
        system("read -p'Presiona Enter para continuar...' var");

    }
    while(seguir == 's');

    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(listaAux);
    ll_deleteLinkedList(listaOrdenada);

    return 0;
}
