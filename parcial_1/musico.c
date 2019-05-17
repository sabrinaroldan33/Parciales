#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "musico.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array musico Array of musico
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int musico_Inicializar(Musico array[], int size)                                    //cambiar musico
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
/** \brief Busca el primer apellido vacio en un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un apellido vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int musico_buscarEmpty(Musico array[], int size, int* posicion)                    //cambiar musico
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].edad==valorBuscado)                                                   //cambiar campo edad
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice)                    //cambiar musico
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
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
* \param array musico Array de musico
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int musico_alta(Musico array[], int size, int* contadorID)
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(musico_buscarEmpty(array,size,&posicion)==-1)
        {
            printf("\nNo hay apellidoes vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;
            array[posicion].isEmpty=0;
            printf("\nAgregar Musico:\n");
            utn_getName("\n\tNombre: ","\nError",1,MUSICO_SIZE,1,array[posicion].nombre);
            utn_getTexto("\tApellido: ","\nError",1,MUSICO_SIZE,1,array[posicion].apellido);
            utn_getUnsignedInt("\tEdad: ","\nError",1,sizeof(int),1,10,1,&array[posicion].edad);
            printf("\nTipo de instrumento:\n\t1: Cuerdas\n\t2: Viento-Madera\n\t3: Viento-Metal\n\t4: Percusion\n");
            utn_getUnsignedInt("\n\tInstrumento: ","\nError",1,sizeof(int),1,10,1,&array[posicion].instrumento);
            printf("\nID: %d\nNombre: %s\nApellido: %s\nEdad: %d\nInstrumento: %d\n",
                   array[posicion].idUnico,array[posicion].nombre,array[posicion].apellido,array[posicion].edad,array[posicion].instrumento);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_baja(Musico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID\n");
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;
            strcpy(array[posicion].nombre,"");
            strcpy(array[posicion].apellido,"");
            array[posicion].edad=0;
            array[posicion].instrumento=0;
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array musico Array de musico
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
            array[i].isEmpty=1;
            array[i].idUnico=0;                                                                //cambiar campo varFloat
            strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[i].apellido,"");
            array[i].edad=0;
            array[i].instrumento=0;                                                //cambiar campo apellido
            retorno=0;
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int musico_modificar(Musico array[], int sizeArray)
{
    int retorno=-1;
    int posicion;
    int id;
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);
        if(musico_buscarID(array,sizeArray,id,&posicion)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\nID: %d\nEdad: %d\n",
                   array[posicion].idUnico,array[posicion].edad);
                utn_getChar("\n\nModificar: \n\tA: ID\n\tB: Edad\n\tS: Salir\n","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].idUnico);
                        break;
                    case 'B':
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].edad);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida\n");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}


//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array musico Array de musico
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int musico_listar(Musico array[], int size)
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        printf("\nMUSICOS:\n");
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n\tID: %d\n\tNombre: %s\n\tApellido: %s\n\tEdad: %d\n\tInstrumento: %d\n",
                   array[i].idUnico,array[i].nombre,array[i].apellido,array[i].edad,array[i].instrumento);
        }
        retorno=0;
    }
    return retorno;
}

void musico_mock(Musico arrayMusico[], int size,int *contadorIdmusico)
{
    //*******************************************************************
    arrayMusico[0].idUnico=0;
    arrayMusico[0].isEmpty=0;
    strcpy(arrayMusico[0].nombre,"CCCCC");
    strcpy(arrayMusico[0].apellido,"CCCCC");
    arrayMusico[0].instrumento=0;
    contadorIdmusico++;

    arrayMusico[1].idUnico=1;
    arrayMusico[1].isEmpty=0;
    strcpy(arrayMusico[1].nombre,"AAAAA");
    strcpy(arrayMusico[1].apellido,"AAAAA");
    arrayMusico[1].instrumento=0;
    contadorIdmusico++;

    arrayMusico[2].idUnico=2;
    arrayMusico[2].isEmpty=0;
    strcpy(arrayMusico[2].nombre,"AAAAA");
    strcpy(arrayMusico[2].apellido,"AAAAA");
    arrayMusico[2].instrumento=0;
    contadorIdmusico++;

}
