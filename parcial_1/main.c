#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"

#define QTY_ARRAY_ORQUESTA 50
#define QTY_ARRAY_MUSICO 1000
#define QTY_ARRAY_INSTRUMENTO 20
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
    int opcion;
    int contadorIdOrquesta=0;

    Orquesta arrayOrquesta[QTY_ARRAY_ORQUESTA];
    orquesta_Inicializar(arrayOrquesta,QTY_ARRAY_ORQUESTA);
    orquesta_mock(arrayOrquesta, QTY_ARRAY_ORQUESTA, &contadorIdOrquesta);

    int contadorIdMusico=0;
    Musico arrayMusico[QTY_ARRAY_MUSICO];
    musico_Inicializar(arrayMusico,QTY_ARRAY_MUSICO);
    musico_mock(arrayMusico, QTY_ARRAY_MUSICO, &contadorIdMusico);

    int contadorIdInstrumento=0;
    Instrumento arrayInstrumento[QTY_ARRAY_INSTRUMENTO];
    instrumento_Inicializar(arrayInstrumento,QTY_ARRAY_INSTRUMENTO);
    instrumento_mock(arrayInstrumento, QTY_ARRAY_INSTRUMENTO, &contadorIdInstrumento);



    do
    {
        utn_getUnsignedInt("\n\nORQUESTA: \n\t1) Agregar \n\t2) Eliminar \n\t3) Imprimir \nMUSICO: \n\t4) Agregar"
        "\n\t5) Modificar\n\t6) Eliminar \n\t7) Imprimir\nINSTRUMENTO: \n\t8) Agregar \n\t9) Imprimir  \n\n10) SALIR\n"
        "\nIngrese su opcion: ",
        "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Agregar
                orquesta_alta(arrayOrquesta,QTY_ARRAY_ORQUESTA,&contadorIdOrquesta);
                break;

            case 2: //Eliminar
                orquesta_baja(arrayOrquesta,QTY_ARRAY_ORQUESTA);
                break;

            case 3://Listar
                orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);
                break;

            case 4: //Agregar
                musico_alta(arrayMusico,QTY_ARRAY_MUSICO,&contadorIdMusico);
                break;

            case 5: //Eliminar
                musico_baja(arrayMusico,QTY_ARRAY_MUSICO);
                break;

            case 6: //Modificar
                musico_modificar(arrayMusico,QTY_ARRAY_MUSICO);
                break;

            case 7://Listar
                musico_listar(arrayMusico,QTY_ARRAY_MUSICO);
                break;

            case 8: //Agregar
                instrumento_alta(arrayInstrumento,QTY_ARRAY_INSTRUMENTO,&contadorIdInstrumento);
                break;

            case 9://Listar
                instrumento_listar(arrayInstrumento,QTY_ARRAY_INSTRUMENTO);
                break;

            case 10://Salir
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=6);
    return 0;
}
