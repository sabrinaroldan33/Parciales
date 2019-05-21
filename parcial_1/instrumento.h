#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

#define INSTRUMENTO_SIZE 50

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[INSTRUMENTO_SIZE];
    char tipo[INSTRUMENTO_SIZE];

}Instrumento;


#endif // INSTRUMENTO_H_INCLUDED

int instrumento_Inicializar(Instrumento array[], int size);
int instrumento_buscarEmpty(Instrumento array[], int size, int* posicion);
int instrumento_buscarID(Instrumento array[], int size, int valorBuscado, int* posicion);
int instrumento_buscarString(Instrumento array[], int size, char* valorBuscado, int* indice);
int instrumento_alta(Instrumento array[], int size, int* contadorID);
int instrumento_baja(Instrumento array[], int sizeArray);
int instrumento_bajaValorRepetidoInt(Instrumento array[], int sizeArray, int valorBuscado);
int instrumento_listar(Instrumento array[], int size);
void instrumento_mock(Instrumento arrayInstrumento[], int size,int *contadorIdinstrumento);
