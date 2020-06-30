
#include "LinkedList.h"
#ifndef bicicletas_H_INCLUDED
#define bicicletas_H_INCLUDED
typedef struct{
    int idBike;
    char nombre[20];
    char tipo[20];
    int tiempo;
}eBicicleta;
#endif // bicicletas_H_INCLUDED

int getRandom(void);
eBicicleta* new_biciParamString(char* idBike, char* nombre, char* tipo, char* tiempo);
int cargarBicisCSV(LinkedList* lista);
int mostrarBici(eBicicleta* bici);
int mostrarBicis(LinkedList* lista);
int menu();
int preguntaFiltrar();
int bici_getTiempo(eBicicleta* bici, int* tiempo);
int bici_ordenarPorTiempo(void* bici1, void* bici2);
int bici_ordenarPorTipo(void* bici1, void* bici2);
int bici_setTiempo(eBicicleta *bici, int tiempo);
int bici_getTipo(eBicicleta* bici,char* tipo);
int bici_ordenarBicis(LinkedList* lista);
int filtrarxTipo(void* unaBici);
void guardarCSV(LinkedList* lista, char* path);

void filtrarPorTipoElegido(LinkedList* lista);
int filtrarxTipoBMX(void* unaBici);
int filtrarxTipoPLAYERA(void* unaBici);
int filtrarxTipoMTB(void* unaBici);
int filtrarxTipoPASEO(void* unaBici);

