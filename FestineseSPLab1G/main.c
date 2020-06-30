#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include <time.h>
#include "bicicletas.h"




int main()
{
    srand(time(NULL));
    //printf("Numero: %d\n", getRandom());

    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaFiltrada = ll_newLinkedList();

    if(lista == NULL || listaFiltrada == NULL){
        printf("No se pudo conseguir memoria\n");
        exit(EXIT_FAILURE);
    }

    int opcion = 0;

    do{
        switch(menu()){


            case 1:
                if(cargarBicisCSV(lista)){
                    printf("Se cargo la lista con exito!\n");
                    system("pause");
                }
                break;
            case 2:
                mostrarBicis(lista);
                system("pause");
                break;
            case 3:
                ll_map(lista, getRandom);
                printf("Se asignaron los tiempos con exito!\n");
                system("pause");
                break;
            case 4:
                filtrarPorTipoElegido(lista);
                system("pause");
                break;

            case 5:
                bici_ordenarBicis(lista);
                system("pause");
                break;
            case 6:
                guardarCSV(lista, "listaTiempos.csv");
                printf("Lista guardada con exito!\n");
                system("pause");
                break;
            case 7:
                printf("Programa finalizado\n");
                system("pause");
                opcion= 7;
                break;

        }

    }while(opcion!=7);


    ll_deleteLinkedList(lista);
    ll_deleteLinkedList(listaFiltrada);

    return 0;
}
