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
#define SORT_DOWN 0
#define SORT_UP 1

int main()
{
    int opcion;
    char opcionInforme;
    int contadorIdOrquesta=0;
    char lugar;

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
        utn_getUnsignedInt("\nIngrese la opcion deseada:"
        "\n\n   ORQUESTA: \n\t1) Agregar \n\t2) Eliminar \n\t3) Imprimir \n   MUSICO: \n\t4) Agregar"
        "\n\t5) Modificar\n\t6) Eliminar \n\t7) Imprimir\n   INSTRUMENTO: \n\t8) Agregar \n\t"
        "9) Imprimir  \n\n\n   Informes: 10 \n   SALIR: 11\n"
        "\nSu opcion: ",
        "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Agregar
                orquesta_alta(arrayOrquesta,QTY_ARRAY_ORQUESTA,&contadorIdOrquesta);
                break;

            case 2: //Eliminar
                orquesta_baja(arrayOrquesta,QTY_ARRAY_ORQUESTA,arrayMusico,QTY_ARRAY_MUSICO);
                break;

            case 3://Listar
                orquesta_listar(arrayOrquesta,QTY_ARRAY_ORQUESTA);
                break;

            case 4: //Agregar
                musico_alta(arrayMusico,QTY_ARRAY_MUSICO,&contadorIdMusico);
                break;

            case 5: //Modificar
                musico_listar(arrayMusico,QTY_ARRAY_MUSICO);
                musico_modificar(arrayMusico,QTY_ARRAY_MUSICO);

                break;

            case 6: //Eliminar
                musico_baja(arrayMusico,QTY_ARRAY_MUSICO);
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

            case 10:
                while (opcionInforme!='i')
                {
                    utn_getChar("\nIngrese la opcion deseada:"
                    "\n\ta) Listar orquestas por lugar "
                    "\n\tb) Listar musicos menores de 25 años "
                    "\n\tc) Listar orquestas con menos de 6 musicos "
                    "\n\td) Listar todos los instrumentos de una orquesta"
                    "\n\te) Listar Listar las orquestas completas"
                    "\n\tf) Listar orquestas con menos musicos"
                    "\n\tg) Listar el promedio de instrumentos por orquesta"
                    "\n\th) Listar los musicos que no toquen instrumentos de viento"
                    "\nSalir: i"
                    "\nSu opcion: ",
                    "\nError",1,sizeof(char),1,&opcionInforme);
                    switch (opcionInforme)
                    {
                        case 'a':
                            getString("\n\nIngrese el lugar de la orquesta a mostrar: ","\nError",
                            1,10,2,&lugar);
                            orquesta_buscarLugar(arrayOrquesta, sizeof(char), &lugar);
                            break;

                        case 'b':
                            musico_listarEdad(arrayMusico, QTY_ARRAY_MUSICO);

                            break;

                        case 'c':

                            break;
                        case 'd':

                            break;

                        case 'e':

                            break;

                        case 'f':

                            break;

                        case 'g':

                            break;

                        case 'h':
                            musico_listarInstrumento(arrayMusico, QTY_ARRAY_MUSICO);
                            break;

                        case 'i':
                            break;
                            continue;

                        default:
                            printf("\nOpcion no valida");

                        }
                        return 0;
                        }
                        break;

            case 11://Salir
                break;

            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=11);
    return 0;
}
