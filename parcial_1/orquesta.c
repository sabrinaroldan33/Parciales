#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "orquesta.h"
#include "musico.h"


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array orquesta Array of orquesta
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int orquesta_Inicializar(Orquesta array[], int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int orquesta_buscarEmpty(Orquesta array[], int size, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarID(Orquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarInt(Orquesta array[], int size, int valorBuscado, int* posicion)
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].tipo==valorBuscado)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int orquesta_buscarString(Orquesta array[], int size, char* valorBuscado, int* indice)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].lugar,valorBuscado)==0)
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int orquesta_alta(Orquesta array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(orquesta_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            printf("\nAgregar Orquesta:\n");
            utn_getName("\n\tIngrese el nombre: ","\nError",1,ORQUESTA_SIZE,1,array[posicion].nombre);
            utn_getTexto("\tIngrese el lugar: ","\nError",1,ORQUESTA_SIZE,1,array[posicion].lugar);
            printf("\nTipo de orquesta:\n\t1: Sinfonica\n\t2: Filarmonica\n\t3: Camara\n");
            utn_getUnsignedInt("\n\tIngrese el tipo: ","\nError",1,sizeof(int),1,10,1,&array[posicion].tipo);
            /*printf("\nID: %d\nNombre: %s\nLugar: %s\nTipo: %d\n",
                   array[posicion].idUnico,array[posicion].nombre,array[posicion].lugar,array[posicion].tipo);*/
            retorno=0;
        }
            printf("\nOrquesta agreadida exitosamente! El ID de la Orquesta es: %d\n",array[posicion].idUnico);
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_baja(Orquesta array[], int sizeArray, Musico arrayMusico[], int sizeMusico)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(orquesta_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].lugar,"");
            array[posicion].tipo=0;
            retorno=0;

            musico_bajaValorRepetidoInt(arrayMusico,sizeMusico,id);
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int orquesta_bajaValorRepetidoInt(Orquesta array[], int sizeArray, int valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;
                array[i].tipo=0;
                strcpy(array[i].nombre,"");
                strcpy(array[i].lugar,"");
            }
        }
        retorno=0;
    }
    return retorno;
}


//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int orquesta_ordenarPorDobleCriterio(Orquesta array[],int size, int orderFirst, int orderSecond)
{
    int retorno=-1;
    int i;
    Orquesta buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array orquesta Array de orquesta
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int orquesta_listar(Orquesta array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        printf("\nORQUESTAS:\n");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;

            else
                printf("\n\tID: %d\n\tNombre: %s\n\tLugar: %s\n\tTipo: %d - ",
                   array[i].idUnico,array[i].nombre,array[i].lugar,array[i].tipo);

                if(array[i].tipo==1)
                {
                    printf("Sinfonica\n");
                }
                    else if(array[i].tipo==2)
                        {
                            printf("Filarmonica\n");
                        }
                    else if(array[i].tipo==3)
                        {
                            printf("Camara\n");
                        }
                    else
                        {
                            printf("Tipo desconocido");
                        }

        }
        retorno=0;
    }
    return retorno;
}

void orquesta_mock(Orquesta arrayOrquesta[], int size,int *contadorIdorquesta)
{
    //*******************************************************************
    arrayOrquesta[0].idUnico=0;
    arrayOrquesta[0].isEmpty=0;
    strcpy(arrayOrquesta[0].nombre,"CCCCC");
    strcpy(arrayOrquesta[0].lugar,"CCCCC");
    arrayOrquesta[0].tipo=1;
    contadorIdorquesta++;

    arrayOrquesta[1].idUnico=1;
    arrayOrquesta[1].isEmpty=0;
    strcpy(arrayOrquesta[1].nombre,"AAAAA");
    strcpy(arrayOrquesta[1].lugar,"AAAAA");
    arrayOrquesta[1].tipo=2;
    contadorIdorquesta++;

    arrayOrquesta[2].idUnico=2;
    arrayOrquesta[2].isEmpty=0;
    strcpy(arrayOrquesta[2].nombre,"AAAAA");
    strcpy(arrayOrquesta[2].lugar,"AAAAA");
    arrayOrquesta[2].tipo=3;
    contadorIdorquesta++;

}

int orquesta_buscarLugar(Orquesta array[], int size, char* valorBuscado)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].lugar,valorBuscado)==0)
            {
                printf("\n\tID: %d\n\tNombre: %s\n\tLugar: %s\n\tTipo: %d\n",
                   array[i].idUnico,array[i].nombre,array[i].lugar,array[i].tipo);

                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
