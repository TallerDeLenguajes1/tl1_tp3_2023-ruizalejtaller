#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cantNombres 5

void cargarN (char ** nombres);
void mostrarN (char ** nombres);
void liberarMem (char ** nombres);

int main()
{
    char ** nombres = malloc(sizeof(char *) * cantNombres);

    cargarN(nombres);
    mostrarN(nombres);
    liberarMem(nombres);

    return 0;
}

void cargarN (char ** nombres)
{
    size_t buffSize = 100; 
    char * Buff = malloc(sizeof(char) * buffSize);

    for (int i=0; i<cantNombres; i++) {
    printf("\nIngrese el nombre %d: ", i+1);
    getline(&Buff, &buffSize, stdin);

    nombres[i] = malloc(sizeof(char) * (strlen(Buff)+1));
    strcpy(nombres[i], Buff);
    }

    free(Buff);

}

void mostrarN(char ** nombres)
{
    for (int i=0; i<cantNombres; i++) {
    printf("\nNombre %d: %s", i+1, nombres[i]);

    }
}

void liberarMem (char ** nombres)
{
    for (int i=0; i<cantNombres; i++)
    {
        free(nombres[i]);
    }

    free(nombres);
}