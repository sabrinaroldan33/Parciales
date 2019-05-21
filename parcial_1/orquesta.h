#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED
#include "musico.h"

#define ORQUESTA_SIZE 50

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[ORQUESTA_SIZE];
    char lugar[ORQUESTA_SIZE];
    int tipo;

}Orquesta;


#endif // ORQUESTA_H_INCLUDED

int orquesta_Inicializar(Orquesta array[], int size);
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion);
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion);
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion);
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice);
int orquesta_alta(Orquesta array[], int size, int* contadorID);
int orquesta_baja(Orquesta array[], int sizeArray, Musico arrayMusico[], int sizeMusico);
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado);
int orquesta_ordenarPorDobleCriterio(Orquesta array[],int size, int orderFirst, int orderSecond);                                  //cambiar orquesta
int orquesta_listar(Orquesta array[], int size);
void orquesta_mock(Orquesta arrayOrquesta[], int size,int *contadorIdorquesta);
int orquesta_buscarLugar(Orquesta array[], int size, char* valorBuscado);
