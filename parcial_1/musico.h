#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

#define MUSICO_SIZE 51

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[MUSICO_SIZE];
    char apellido[MUSICO_SIZE];
    int edad;
    int instrumento;

}Musico;


#endif // MUSICO_H_INCLUDED

int musico_Inicializar(Musico array[], int size);
int musico_buscarEmpty(Musico array[], int size, int* posicion);
int musico_buscarID(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarInt(Musico array[], int size, int valorBuscado, int* posicion);
int musico_buscarString(Musico array[], int size, char* valorBuscado, int* indice);
int musico_alta(Musico array[], int size, int* contadorID);
int musico_baja(Musico array[], int sizeArray);
int musico_bajaValorRepetidoInt(Musico array[], int sizeArray, int valorBuscado);
int musico_modificar(Musico array[], int sizeArray);
int musico_listar(Musico array[], int size);
void musico_mock(Musico arrayMusico[], int size,int *contadorIdmusico);
