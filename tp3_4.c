#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAXCL 5

char * TiposProductos[] = {"Galletas", "Snacks", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct {
    int ProductoID;
    int Cantidad;
    char * TipoProducto;
    float precioUnitario;
} Producto;

typedef struct {
    int ClienteID;
    char * nombreUsuario;
    int CantidadProductosAPedir;
    Producto * Productos;
} Cliente;

void cargarCL (Cliente * ClienteD, int id);
void generarProducto (Cliente *ClientD, int i);
float costo (Producto * Prod);
void mostrarCL (Cliente * ClientD, int i);


// 4 i)
int main()
{
    srand(time(NULL));

    unsigned int cantcl ;

    do {
        printf("\nIngrese la cantidad de clientes (max %d): ", MAXCL);
        scanf("%u", &cantcl);
        getchar();
    } while (cantcl > MAXCL || cantcl < 1);


    
    Cliente * ClientD = malloc(cantcl * sizeof(Cliente));

    for (int id=0; id<cantcl; id++) {
        cargarCL(ClientD + id, id);
    }

    for (int id=0; id<cantcl; id++) {
        mostrarCL(ClientD + id, id);
    }


    return 0;
}

// 4 ii)

void cargarCL (Cliente * ClientD, int id)
{
    size_t BuffSize = 100;
    char * Buff = malloc(BuffSize * sizeof(char));

    printf("\nCliente N %d\n", id+1);
    printf("Nombre: ");
    getline(&Buff, &BuffSize, stdin);

    ClientD->nombreUsuario = malloc((strlen(Buff)+1) *sizeof(char));
    strcpy(ClientD->nombreUsuario, Buff);

    free(Buff);

    ClientD->ClienteID = id;

    int canti = 1+rand()%5;
    ClientD->CantidadProductosAPedir = canti;

    ClientD->Productos = malloc (canti * sizeof(Producto));

    for (int i=0; i<canti; i++) {
        generarProducto(ClientD, i);
    }

}


//4 iii)

void generarProducto (Cliente *ClientD, int i)
{
    ClientD->Productos[i].ProductoID = i+1;
    ClientD->Productos[i].Cantidad = 1 + rand()%10;
    ClientD->Productos[i].TipoProducto = TiposProductos[rand()%5];
    ClientD->Productos[i].precioUnitario = (float)(100 + rand()%901)/10;

}


// 4 iv)

float costo (Producto * Prod)
{
    return (Prod->Cantidad * Prod->precioUnitario);
}

// 4 v)

void mostrarCL (Cliente * ClientD, int id)
{
    float costoProducto, costoTotal = 0;
    printf("\n-------------------------------\n");
    printf("\nCliente N %d: %s\n", (ClientD->ClienteID)+1, ClientD->nombreUsuario);
    printf("Tiene %d productos \n\n", ClientD->CantidadProductosAPedir);

    for (int i=0; i<ClientD->CantidadProductosAPedir; i++) {
        printf("%d %s - ",ClientD->Productos[i].Cantidad, ClientD->Productos[i].TipoProducto);
        printf("Precio Uni; %.2f - ", ClientD->Productos[i].precioUnitario);
        costoProducto = costo(ClientD->Productos+i);
        printf("Costo: %.2f\n", costoProducto);

        costoTotal += costoProducto;
    }

    printf("\nTotal a pagar: %.2f\n", costoTotal);

}