#include "bicicletas.h"
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include <time.h>

int getRandom(void){

	int aleatorio;

	aleatorio = rand()% 71 + 50;
	printf("%d\n", aleatorio);

	return aleatorio;
}

int cargarBicisCSV(LinkedList* lista){

    char buffer[4][30];
    int cant;
    eBicicleta* auxBici;
    int todoOk = 0;

    FILE* f;
    f= fopen("bicicletas.csv", "r");
    if(f!= NULL){


        fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        while(!feof(f)){

            cant= fscanf(f, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if(cant == 4){
                auxBici = new_biciParamString(buffer[0], buffer[1], buffer[2], buffer[3]);

                if(auxBici != NULL){
                    ll_add(lista, auxBici);
                    todoOk = 1;
                }
            }
        }
    }
    return todoOk;

}


eBicicleta* new_biciParamString(char* idBike, char* nombre, char* tipo, char* tiempo){
    eBicicleta* nuevaBici = (eBicicleta*) malloc(sizeof(eBicicleta));
    if(nuevaBici!= NULL){

        nuevaBici->idBike = atoi(idBike);
        strcpy(nuevaBici->nombre, nombre);
        strcpy(nuevaBici->tipo, tipo);
        nuevaBici->tiempo = atoi(tiempo);

    }
    return nuevaBici;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int mostrarBicis(LinkedList* lista)
{
    int todoOk = 0;
    int flag = 0;
    int tam = ll_len(lista);
    eBicicleta* auxBici;

    printf("***** LISTA BICICLETAS ***** \n");
    if(lista != NULL)
    {
        todoOk =1;
        printf("ID                NOMBRE               TIPO         TIEMPO\n");
        for (int i=0; i< tam; i++)
        {
            auxBici = (eBicicleta*) ll_get(lista, i);
            if(auxBici != NULL)
            {
                mostrarBici(auxBici);
                flag =1;
            }
        }
        if(flag == 0)
        {
            printf("No hay bicicletas que mostrar\n");

        }
    }
    return todoOk;
}

/** \brief Muestra una bicicleta
 *
 * \param eBicicleta* bici, puntero a la estructura bicicleta
 * \param -
 * \return 1 si hay un error, 0 si esta todo bien
 *
 */

int mostrarBici(eBicicleta* bici){
    int error=1;

    if(bici != NULL)
    {
        printf("%3d %20s  %20s      %4d\n", bici->idBike, bici->nombre, bici->tipo, bici->tiempo);
        error = 0;
    }
    return error;
}

int filtrarxTipoPLAYERA(void* unaBici){

    int auxReturn = 0;
    eBicicleta* x;

    if(unaBici != NULL)
    {
        x = (eBicicleta*) unaBici;
        if (strcmp(x->tipo, "PLAYERA")== 0){
            auxReturn = 1;
        }
    }

    return auxReturn;
}
int filtrarxTipoBMX(void* unaBici){

    int auxReturn = 0;
    eBicicleta* x;

    if(unaBici != NULL)
    {
        x = (eBicicleta*) unaBici;
        if (strcmp(x->tipo, "BMX")== 0){
            auxReturn = 1;
        }
    }

    return auxReturn;
}
int filtrarxTipoMTB(void* unaBici){

    int auxReturn = 0;
    eBicicleta* x;

    if(unaBici != NULL)
    {
        x = (eBicicleta*) unaBici;
        if (strcmp(x->tipo, "MTB")== 0){
            auxReturn = 1;
        }
    }

    return auxReturn;
}
int filtrarxTipoPASEO(void* unaBici){

    int auxReturn = 0;
    eBicicleta* x;

    if(unaBici != NULL)
    {
        x = (eBicicleta*) unaBici;
        if (strcmp(x->tipo, "PASEO")== 0){
            auxReturn = 1;
        }
    }

    return auxReturn;
}

int preguntaFiltrar(){
    int opcion;

    printf("Que tipo quiere filtrar?\n");
    printf("1) BMX\n");
    printf("2) PLAYERA\n");
    printf("3) MTB\n");
    printf("4) PASEO\n");
    printf("Ingrese el numero de la opcion que desee: ");
    scanf("%d", &opcion);
    while(!(opcion>=1 &&opcion <=4)){
        printf("ERROR. Ingrese una opcion correcta: ");
        scanf("%d", &opcion);
    }

    return opcion;

}

LinkedList* filtrarPorTipoElegido(LinkedList* lista){

    LinkedList* listaFiltrada = ll_newLinkedList();

    switch(preguntaFiltrar()){

    case 1:
        listaFiltrada = ll_filter(lista, filtrarxTipoBMX);
        break;
    case 2:
        listaFiltrada = ll_filter(lista, filtrarxTipoPLAYERA);
        break;
    case 3:
        listaFiltrada = ll_filter(lista, filtrarxTipoMTB);
        break;
    case 4:
        listaFiltrada = ll_filter(lista, filtrarxTipoPASEO);
        break;
    case 5:
        break;
    }


    return listaFiltrada;

}
int menu(){

    int opcion;
    system("cls");

    printf("**** MENU DE OPCIONES *****\n\n");
    printf("1) Cargar archivo\n");
    printf("2) Imprimir lista\n");
    printf("3) Asignar tiempos\n");
    printf("4) Filtrar por tipo\n");
    printf("5) Mostrar posiciones\n");
    printf("6) Guardar posiciones\n");
    printf("7) Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>7){
        printf("ERROR. Ingrese una opcion valida: ");
        scanf("%d", &opcion);
    }
    return opcion;

}



int bici_setTiempo(eBicicleta *bici, int tiempo) {

	int todoOk = 0;

	if (bici != NULL) {
		if (tiempo >= 0) {
			bici->tiempo = tiempo;
			todoOk = 1;
		}
	}
	return todoOk;
}



int bici_ordenarBicis(LinkedList* lista)
{

    int todoOk = 0;

    if(lista != NULL)
    {

        ll_sort(lista, bici_ordenarPorTipo, 1);




        printf("*** LISTA DE BICICLETAS ORDENADAS POR TIPO Y TIEMPO ****\n");
        mostrarBicis(lista);
    }


    return todoOk;
}

int bici_ordenarPorTipo(void* bici1, void* bici2)
{
    char tipoBici1[20];
    char tipoBici2[20];
    int todoOk = 0;

    bici_getTipo(bici1, tipoBici1);
    bici_getTipo(bici2, tipoBici2);

    if(strcmp(tipoBici1, tipoBici2) > 0)
    {
            todoOk = 1;

    }else if(strcmp(tipoBici1, tipoBici2) < 0)
    {
        todoOk = -1;
    }

    return todoOk;
}

int bici_getTipo(eBicicleta* bici,char* tipo){
    int todoOk= 0;

    if(bici != NULL && tipo != NULL)
    {
        strcpy(tipo, bici->tipo);
        todoOk = 1;
    }

    return todoOk;
}

int bici_ordenarPorTiempo(void* bici1, void* bici2)
{
    int tiempoBici1;
    int tiempoBici2;
    int todoOk = 0;

    bici_getTiempo(bici1, &tiempoBici1);
    bici_getTiempo(bici2, &tiempoBici2);

    if(tiempoBici1 > tiempoBici2)
    {
        todoOk = 1;
    }
    else if(tiempoBici1 < tiempoBici2)
    {
        todoOk = -1;
    }

    return todoOk;
}

int bici_getTiempo(eBicicleta* bici, int* tiempo){

    int todoOk = 0;

    if(bici != NULL && tiempo != NULL)
    {
        *tiempo = bici->tiempo;
        todoOk= 1;
    }
    return todoOk;
}

void guardarCSV(LinkedList* lista, char* path){
    FILE* f;
    eBicicleta* auxBici;
    f= fopen(path, "w");
    int tam;
    tam= ll_len(lista);

    if(f!= NULL){

        fprintf(f, "ID,NOMBRE,TIPO,TIEMPO\n");
        for(int i=0; i<tam; i++){
            auxBici = ll_get(lista, i);
            if(auxBici!= NULL){
                fprintf(f, "%d, %s, %s, %d\n", auxBici->idBike, auxBici->nombre, auxBici->tipo, auxBici->tiempo);
            }
        }
        fclose(f);
    }
}
