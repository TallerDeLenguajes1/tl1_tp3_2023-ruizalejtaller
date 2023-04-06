#include <stdio.h>
#include <stdlib.h>
#define anios 5

void cargar (int producc[anios][12]);
void mostrar (int producc[anios][12]);
void promedios(int producc[anios][12]);
void maxymin (int producc[anios][12]);

char meses[12][12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre","Noviembre", "Diciembre"};

int main()
{
    int produccion[anios][12];

    cargar(produccion);
    mostrar(produccion);
    promedios(produccion);
    maxymin(produccion);
}

// 2a)
void cargar (int producc[anios][12])
{
    for (int i=0; i<anios; i++) {
        for (int j=0; j<12; j++) {
        producc[i][j] = 10000 + rand()%40000;
        }
    }
}

// 2b)
void mostrar (int producc[anios][12])
{
    for (int i=0; i<anios; i++) {
        for (int j=0; j<12; j++) {
        printf("Año %d, Mes %s - Producción: %d\n", i+1, meses[j], producc[i][j]);
        }
    }
    printf("\n-----------------------------------------\n");
}
// 2c)
void promedios (int producc[anios][12])
{
    int suma = 0;
    float promedio;

    for (int i=0; i<anios; i++) {
        for (int j=0; j<12; j++) {
            suma = suma + producc[i][j];
        }
        promedio = (float)suma / 12;
        printf("La ganancia promedio del año %d es: %.2f\n", i+1, promedio);
    }

    printf("-----------------------------------------\n");
}

void maxymin (int producc[anios][12])
{
    int aniomin, aniomax, mesmin, mesmax, min = 50001, max = 0;

    for (int i=0; i<anios; i++) {
        for (int j=0; j<12; j++) {
            if (producc[i][j] < min)
            {
                min = producc[i][j];
                aniomin = i;
                mesmin = j;
            }

            if (producc[i][j] > max)
            {
                max = producc[i][j];
                aniomax = i;
                mesmax = j;
            }
        }   
    }

    printf("\nLa menor producción fue %d en el mes de %s del año %d.", min, meses[mesmin], aniomin+1);
    printf("\nLa mayor producción %d se dió en el mes de %s del año %d.\n\n", max, meses[mesmax], aniomax+1);
}