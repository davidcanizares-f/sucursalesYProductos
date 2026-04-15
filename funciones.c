#include <stdio.h>
#include "funciones.h"
int opcion=0;


int menuTienda(){
    printf("====== MENU ======\n");
    printf("1. Calcular el precio total del inventario por sucursal.\n");
    printf("2. Encontrar el producto más caro y el más barato de cada sucursal.\n");
    printf("3. Calcular el precio promedio de todos los productos por sucursal\n");
    printf("4. Buscar un producto por su nombre y mostrar su precio.\n");
    printf("5. Total de unidades vendidas de todos los productos por sucursal.\n");
    printf("6. Salir\n");
    printf("---------------------\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);
    return opcion;

}

