#include <stdio.h>
#include "funciones.h"
int opcion=0;
int opcionSucursal = 0;
int opcionProd =0;
int opcionAdmin= 0;
int opcionInicial=0;


int menuInicial(){
    printf("\n======== ORBSTORE =======\n");
    printf("1. Usar valores de inventario ya establecidos.\n");
    printf("2. Ingresar datos de stock y precios manualmente.\n");
    printf("----------------------\n");
    printf("Ingrese una opcion: ");

    while(scanf("%d", &opcionInicial) != 1 || opcionInicial < 1 || opcionInicial > 2){
        while(getchar() != '\n');
        printf("[ERROR]: Ingrese un numero entre 1 y 2\n");
    }
    return opcionInicial;
}

int menuTienda(){
    printf("=============== MENU ==============\n");
    printf("1. Calcular el precio total del inventario por sucursal.\n");
    printf("2. Encontrar el producto mas caro y el mas barato de cada sucursal.\n");
    printf("3. Calcular el precio promedio de todos los productos por sucursal\n");
    printf("4. Buscar un producto por su nombre y mostrar su precio.\n");
    printf("5. Administrar Negocio.\n");
    printf("6. Salir\n");
    printf("---------------------\n");
    printf("Seleccione una opcion: ");

    while(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6){
        while(getchar() != '\n');
        printf("[ERROR]: Ingrese una opcion valida: ");
    }
}


int elegirSucursal(){
    
    printf("Seleccione una sucursal: \n");
    printf(" 1. NORTE.\n");
    printf(" 2. CENTRO.\n");
    printf(" 3. SUR.\n");
    printf("-----------------\n");
    printf("Elija una opcion: ");
    
    while(scanf("%d", &opcionSucursal) != 1 || opcionSucursal < 1 || opcionSucursal > 3){
        while(getchar() != '\n');
        printf("[ERROR]: Ingrese 1, 2 o 3: ");
    }
    
    return opcionSucursal;

}

int elegirProducto(int opcionSucursal){
    for(i=0; i<prods; i++){
        printf("%d. %s. \n", i+1, nombresProds[i]);
    }
    printf("-----------\n");
    printf("Escoja una opcion: ");
    
    while(scanf("%d", &opcionProd) != 1 || opcionProd < 1 || opcionProd > prods){
        while(getchar() != '\n');
        printf("[ERROR]: Ingrese un numero entre 1 y %d: ", prods);
    }

    return opcionProd;
    

}

int administrarNegocio(){
    printf("\n======= ADMINISTRAR NEGOCIO =====\n");
    printf("1. Vender Productos.\n");
    printf("2. Reabastecer Stock.\n");
    printf("3. Visualizar ventas y ganancias.\n");
    printf("4. Salir del panel de administrador.\n");
    printf("---------------\n");
    printf("Elija una opcion: ");
    while(scanf("%d", &opcionAdmin) != 1 || opcionAdmin < 1 || opcionAdmin > 4){
        while(getchar() != '\n');
        printf("[ERROR]: Ingrese una opcion valida: ");
    }
    return opcionAdmin;

}