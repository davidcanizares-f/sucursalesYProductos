// ============================================================
// IMPLEMENTACIÓN DE FUNCIONES DE MENÚ
// Contiene todos los menús interactivos del sistema. Cada función
// valida la entrada del usuario y retorna la opción seleccionada.
// ============================================================

#include <stdio.h>
#include "funciones.h"

// ---- VARIABLES LOCALES DEL MÓDULO ----
int opcion = 0; // Opción del menú principal
int opcionSucursal = 0; // Sucursal seleccionada
int opcionProd = 0; // Producto seleccionado
int opcionAdmin = 0; // Opción del panel de administración
int opcionInicial = 0; // Modo de carga inicial (predefinido o manual)
int confirmacionManual = 0; // Confirmación del usuario para ingreso manual


// ------------------------------------------------------------
// menuInicial
// Muestra la pantalla de bienvenida de ORBSTORE y permite elegir:
//   1 .- Usar inventario predefinido
//   2 .- Ingresar datos manualmente (pide confirmación antes)
// Retorna la opción elegida (1 o 2).
// ------------------------------------------------------------
int menuInicial(){
    do{
        printf("\n======== ORBSTORE =======\n");
        printf("1. Usar valores de inventario ya establecidos.\n");
        printf("2. Ingresar datos de stock y precios manualmente.\n");
        printf("----------------------\n");
        printf("Ingrese una opcion: ");

        // Validar que sea 1 o 2
        while(scanf("%d", &opcionInicial) != 1 || opcionInicial < 1 || opcionInicial > 2){
            while(getchar() != '\n');
            printf("[ERROR]: Ingrese un numero entre 1 y 2: ");
        }

        // Si elige ingreso manual, pedir confirmación (son 30 registros)
        if(opcionInicial == 2){
            printf("Esta seguro de que desea registrar los 30 productos manualmente?\n ");
            printf("1. Si / 2. No || Escoja: ");
            while(scanf("%d", &confirmacionManual) != 1 || confirmacionManual < 1 || confirmacionManual > 2){
                while(getchar() != '\n');
                printf("[ERROR]: Ingrese un numero entre 1 y 2:");
            }
        } else {
            break; // Si eligió opción 1, salir del bucle directamente
        }

    }while(confirmacionManual != 1); // Repetir si el usuario no confirma el ingreso manual

    return opcionInicial;
}


// ------------------------------------------------------------
// menuTienda
// Muestra el menú principal de la tienda con 6 opciones.
// Valida que la entrada esté en el rango [1-6].
// Retorna la opción seleccionada.
// ------------------------------------------------------------
int menuTienda(){
    printf("\n=============== MENU ==============\n");
    printf("1. Calcular el precio total del inventario por sucursal.\n");
    printf("2. Encontrar el producto mas caro y el mas barato de cada sucursal.\n");
    printf("3. Calcular el precio promedio de todos los productos por sucursal.\n");
    printf("4. Buscar un producto por su nombre y mostrar su precio.\n");
    printf("5. Administrar Negocio.\n");
    printf("6. Salir\n");
    printf("---------------------\n");
    printf("Seleccione una opcion: ");

    while(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6){
        while(getchar() != '\n');
        printf("[ERROR]: Ingrese una opcion valida: ");
    }

    return opcion; 
}


// ------------------------------------------------------------
// elegirSucursal
// Muestra las 3 sucursales disponibles y solicita al usuario
// que elija una. Valida rango [1-3].
// Retorna el número de sucursal seleccionado.
// ------------------------------------------------------------
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


// ------------------------------------------------------------
// elegirProducto
// Lista los 10 productos disponibles y solicita al usuario elegir uno.
// El parámetro opcionSucursal se recibe pero actualmente no se usa
// (podría servir para filtrar por sucursal en el futuro).
// Valida rango [1-10]. Retorna el número de producto seleccionado.
// ------------------------------------------------------------
int elegirProducto(int opcionSucursal){
    for(i = 0; i < prods; i++){
        printf("%d. %s.\n", i+1, nombresProds[i]);
    }
    printf("-----------\n");
    printf("Escoja una opcion: ");

    while(scanf("%d", &opcionProd) != 1 || opcionProd < 1 || opcionProd > prods){
        while(getchar() != '\n');
        printf("[ERROR]: Ingrese un numero entre 1 y %d: ", prods);
    }

    return opcionProd;
}


// ------------------------------------------------------------
// administrarNegocio
// Muestra el submenú de administración con 4 opciones:
//   1 → Vender productos
//   2 → Reabastecer stock
//   3 → Ver ventas y ganancias
//   4 → Salir del panel
// Valida rango [1-4]. Retorna la opción seleccionada.
// ------------------------------------------------------------
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