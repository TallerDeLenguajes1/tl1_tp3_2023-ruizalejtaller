#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void cargarN (char ** nombres, int);
void mostrarN (char ** nombres, int);
void liberarMem (char ** nombres, int);

int main()
{
    int cantNombres;

    printf("Ingrese la cantidad de nombres a ingresar: ");
    scanf("%d", &cantNombres);
    getchar();

    char ** nombres = malloc(sizeof(char *) * cantNombres);

    cargarN(nombres, cantNombres);
    mostrarN(nombres, cantNombres);
    liberarMem(nombres, cantNombres);

    return 0;
}

void cargarN (char ** nombres, int cantNombres)
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

void mostrarN(char ** nombres, int cantNombres)
{
    for (int i=0; i<cantNombres; i++) {
    printf("\nNombre %d: %s", i+1, nombres[i]);

    }
}

void liberarMem (char ** nombres, int cantNombres)
{
    for (int i=0; i<cantNombres; i++)
    {
        free(nombres[i]);
    }

    free(nombres);
}