#include <stdio.h>
#include "funciones.h"
int opcion=0;
int opcionSucursal = 0;
int opcionProd =0;
int opcionAdmin= 0;


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
    scanf("%d", &opcion);
    return opcion;

}


int elegirSucursal(){
    
    printf("Seleccione una sucursal: \n");
    printf(" 1. NORTE.\n");
    printf(" 2. CENTRO.\n");
    printf(" 3. SUR.\n");
    printf("-----------------\n");
    printf("Elija una opcion: ");
    
    while(scanf("%d", &opcionSucursal) != 1){
        printf("[ERROR]: Vuelva a seleccionar una opcion: \n");
        scanf("%d", &opcionSucursal);
        while(getchar() != '\n');
    }
    
    return opcionSucursal;

}

int elegirProducto(int opcionSucursal){
    for(i=0; i<prods; i++){
        printf("%d. %s. \n", i+1, nombresProds[i]);
    }
    printf("-----------\n");
    printf("Escoja una opcion: ");
    
    while(scanf("%d", &opcionProd) != 1){
        printf("[ERROR]: Vuelva a seleccionar una opcion: \n");
        scanf("%d", &opcionProd);
        while(getchar() != '\n');
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
    while(scanf("%d", &opcionAdmin) != 1){
        printf("[ERROR]: Vuelva a seleccionar una opcion: \n");
        scanf("%d", &opcionAdmin);
        while(getchar() != '\n');
    }
    return opcionAdmin;

}





