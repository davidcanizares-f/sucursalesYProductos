// ============================================================
// PROCEDIMIENTOS - ORBSTORE
// Implementación de todas las operaciones sobre el inventario:
// visualización, búsqueda, ventas, reabastecimiento y reportes.
// ============================================================

#include <stdio.h>
#include <stdbool.h>
#include "procedimientos.h"
#include <string.h>

// ---- VARIABLES LOCALES DEL MÓDULO ----
int prodsVender = 0;   // Cantidad de unidades a vender
int stock = 0;   // Stock temporal del producto seleccionado
int prodsReabastecer = 0;   // Cantidad de unidades a reabastecer
int indice = 0;   // Índice del producto encontrado o comparado
float patrimonioXProd = 0; // Valor (stock × precio) de un producto individual
float suma[3] = {0}; // Acumulador de precios/patrimonios por sucursal
float promedio[3] = {0}; // Precio promedio por sucursal
float inventario = 0;   // Stock temporal para cálculo de patrimonio
float patrimonioXSucursal[3] = {0}; // Valor total del inventario por sucursal
float mayor = 0;           // Precio más alto encontrado
float menor = 0;           // Precio más bajo encontrado
float numeroVentasXSucursal[3] = {0}; // Total de unidades vendidas por sucursal
float gananciaVentasXSucursal[3] = {0}; // Total de ganancias por sucursal
float numeroVentasTotales = 0; // Unidades vendidas en todas las sucursales
float gananciaVentasTotales = 0; // Ganancias totales de todas las sucursales
float productoMasCaro = 0;      // Precio máximo global (auxiliar)
char nombreMayor[10][20] = {0}; // Nombre del producto más caro (auxiliar)
char buscado[20];               // Nombre del producto ingresado por el usuario
bool encontrado;                // Indica si el producto buscado fue hallado


// ------------------------------------------------------------
// seteoMatriz
// Inicializa la matriz de inventario según la opción del usuario:
//   1 . Usar datos predefinidos (los muestra en pantalla)
//   2 . Ingresar datos manualmente mediante registro()
// ------------------------------------------------------------
void seteoMatriz(int opcionInicial){
    switch(opcionInicial){
        case 1:
            printf("Puede continuar!\n");
            printf("\n========== VALORES ESTABLECIDOS ========\n\n");
            mostrarMatrizEstablecida();
            break;
        case 2:
            registro();
            break;
    }
}


// ------------------------------------------------------------
// registro
// Solicita al usuario ingresar el stock y precio de cada producto
// en cada sucursal. Incluye validación de entrada en ambos campos.
// ------------------------------------------------------------
void registro(){
    for(int i = 0; i < sucursales; i++){
        printf(">>>> Sucursal: %d || %s \n", i+1, nombresSucursal[i]);
        for(int j = 0; j < prods; j++){
            printf("====== %s ======\n", nombresProds[j]);
            for(int k = 0; k < atributos; k++){
                switch(k){
                    case 0: // Atributo stock: debe ser >= 0
                        printf("- Stock: ");
                        while(scanf("%f", &matriz[i][j][k]) != 1 || matriz[i][j][k] < 0){
                            while(getchar() != '\n');
                            printf("[ERROR]: Ingrese un valor apropiado: ");
                        }
                        break;

                    case 1: // Atributo precio: debe ser > 0
                        printf("- Precio: ");
                        while(scanf("%f", &matriz[i][j][k]) != 1 || matriz[i][j][k] <= 0){
                            while(getchar() != '\n');
                            printf("[ERROR]: Ingrese un valor apropiado: ");
                        }
                        break;
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
}


// ------------------------------------------------------------
// mostrarMatrizEstablecida
// Imprime en pantalla el inventario completo (todas las sucursales,
// productos, stock y precios) usando los datos actuales de la matriz.
// ------------------------------------------------------------
void mostrarMatrizEstablecida(){
    for(int i = 0; i < sucursales; i++){
        printf(">>>> Sucursal: %d || %s \n", i+1, nombresSucursal[i]);
        for(int j = 0; j < prods; j++){
            printf("====== %s ======\n", nombresProds[j]);
            for(int k = 0; k < atributos; k++){
                switch(k){
                    case 0:
                        printf("- Stock: %.0f\n", matriz[i][j][k]);
                        break;
                    case 1:
                        printf("- Precio: $%.2f\n", matriz[i][j][k]);
                        break;
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}


// ------------------------------------------------------------
// valorInventarioSucursal
// Calcula el patrimonio total de cada sucursal (suma de stock × precio
// por cada producto) y lo almacena en el arreglo recibido por parámetro.
// También imprime los resultados en pantalla.
// ------------------------------------------------------------
void valorInventarioSucursal(float patrimonioXSucursal[3]){
    printf("======== VALOR DE INVENTARIOS POR SUCURSAL =========\n");
    for(i = 0; i < sucursales; i++){
        suma[i] = 0;
        for(j = 0; j < prods; j++){
            for(k = 0; k < atributos; k++){
                switch(k){
                    case 0:
                        inventario = matriz[i][j][k];           // Guardamos el stock
                        break;
                    case 1:
                        patrimonioXProd = inventario * matriz[i][j][k]; // stock × precio
                        break;
                }
            }
            suma[i] += patrimonioXProd; // Acumulamos el valor de cada producto
        }
        patrimonioXSucursal[i] = suma[i];
        printf(">>> %s: $%.2f\n", nombresSucursal[i], patrimonioXSucursal[i]);
    }
}


// ------------------------------------------------------------
// prodMasCaro
// Recorre cada sucursal y encuentra el producto con mayor precio,
// mostrando su nombre y valor.
// ------------------------------------------------------------
void prodMasCaro(){
    printf("\n======== PRODUCTO MAS CARO POR SUCURSAL ========\n");
    for(i = 0; i < sucursales; i++){
        mayor  = matriz[i][0][1]; // Inicializar con el primer producto
        indice = 0;

        for(j = 0; j < prods; j++){
            if(matriz[i][j][1] > mayor){
                mayor  = matriz[i][j][1];
                indice = j;
            }
        }
        printf(">>>> %s\n", nombresSucursal[i]);
        printf("%s : $%.2f\n", nombresProds[indice], mayor);
    }
}


// ------------------------------------------------------------
// prodMasBarato
// Recorre cada sucursal y encuentra el producto con menor precio,
// mostrando su nombre y valor.
// ------------------------------------------------------------
void prodMasBarato(){
    printf("\n========== PRODUCTO MAS BARATO POR SUCURSAL ===========\n");
    for(i = 0; i < sucursales; i++){
        menor  = matriz[i][0][1]; // Inicializar con el primer producto
        indice = 0;

        for(j = 0; j < prods; j++){
            if(matriz[i][j][1] <= menor){
                menor  = matriz[i][j][1];
                indice = j;
            }
        }
        printf(">>>> %s: <<<<\n", nombresSucursal[i]);
        printf("-%s: $%.2f\n", nombresProds[indice], menor);
    }
}


// ------------------------------------------------------------
// precioPromedioSucursales
// Calcula el precio promedio de todos los productos en cada sucursal
// (suma de precios dividida entre el número de productos).
// ------------------------------------------------------------
void precioPromedioSucursales(){
    printf("\n========= PRECIO PROMEDIO POR SUCURSAL ===========\n");
    for(i = 0; i < sucursales; i++){
        float suma[sucursales] = {0}; // Suma local para no afectar la global

        for(j = 0; j < prods; j++){
            suma[i] += matriz[i][j][1]; // Sumar solo precios (atributo 1)
        }

        promedio[i] = suma[i] / prods;
        printf(">>>>> %s <<<<<\n", nombresSucursal[i]);
        printf("-Promedio: %.2f\n\n", promedio[i]);
    }
}


// ------------------------------------------------------------
// buscarProducto
// Solicita al usuario un nombre de producto y lo busca en la sucursal
// indicada. Si lo encuentra, muestra precio y stock; si no, lo informa.
// ------------------------------------------------------------
void buscarProducto(int opcionSucursal){
    encontrado = false;
    printf("Escriba el nombre del producto: ");
    while(getchar() != '\n'); // Limpiar buffer antes de leer texto
    fgets(buscado, 20, stdin);
    buscado[strcspn(buscado, "\n")] = '\0'; // Eliminar el salto de línea de fgets

    // Comparar el nombre ingresado contra todos los productos
    for(j = 0; j < prods; j++){
        if(strcmp(buscado, nombresProds[j]) == 0){
            encontrado = true;
            indice = j;
            break;
        }
    }

    if(encontrado){
        printf("====== PRODUCTO ENCONTRADO ====\n");
        printf(">>>> %s <<<<<\n", nombresProds[indice]);
        printf("-Precio: $%.2f\n",  matriz[opcionSucursal-1][indice][1]);
        printf("-Cantidad: %.0f\n", matriz[opcionSucursal-1][indice][0]);
    } else {
        printf("\n====== PRODUCTO NO ENCONTRADO ====\n");
    }
    printf("\n");
}


// ------------------------------------------------------------
// venderProductos
// Permite registrar la venta de un producto en una sucursal.
// Valida que la cantidad sea positiva y no supere el stock disponible.
// Actualiza la matriz de inventario y acumula ventas y ganancias.
// ------------------------------------------------------------
void venderProductos(int opcionProd, int opcionSucursal){
    printf("\n========= VENDER PRODUCTOS ==========\n");
    stock = matriz[opcionSucursal-1][opcionProd-1][0];
    printf("Stock actual: %d\n", stock);

    // Solicitar cantidad con validación de rango
    do {
        printf("Cantidad a vender: ");
        while(scanf("%d", &prodsVender) != 1){ 
            while(getchar() != '\n'); }
        if(prodsVender <= 0)
            printf("[ERROR]: Debe ser un numero positivo.\n");
        else if(prodsVender > stock)
            printf("[ERROR]: No hay suficiente stock (disponible: %d).\n", stock);
    } while(prodsVender <= 0 || prodsVender > stock);

    // Descontar del inventario y registrar la venta
    stock -= prodsVender;
    matriz[opcionSucursal-1][opcionProd-1][0]  = stock;
    ventas[opcionSucursal-1][opcionProd-1][0] += prodsVender;                                   // Unidades vendidas
    ventas[opcionSucursal-1][opcionProd-1][1] += prodsVender * matriz[opcionSucursal-1][opcionProd-1][1]; // Ganancia

    printf("%d UNIDADES VENDIDAS DE %s\n", prodsVender, nombresProds[opcionProd-1]);
    printf("Stock actual: %d\n", stock);
}


// ------------------------------------------------------------
// reabastecerStock
// Permite agregar unidades al stock de un producto en una sucursal.
// Valida que la cantidad ingresada sea un número no negativo.
// ------------------------------------------------------------
void reabastecerStock(int opcionProd, int opcionSucursal){
    printf("\n========= REABASTECER STOCK ==========\n");
    stock = matriz[opcionSucursal-1][opcionProd-1][0];
    printf("Stock actual: %d\n", stock);

    do {
        printf("Cantidad a reabastecer: ");
        while(scanf("%d", &prodsReabastecer) != 1){
            while(getchar() != '\n'); }
        if(prodsReabastecer < 0)
            printf("[ERROR]: Debe ser un numero positivo.\n");
    } while(prodsReabastecer < 0);

    // Sumar al stock actual
    stock += prodsReabastecer;
    matriz[opcionSucursal-1][opcionProd-1][0] = stock;
    printf("%d UNIDADES REABASTECIDAS DE %s\n", prodsReabastecer, nombresProds[opcionProd-1]);
    printf("Stock actual: %d\n", stock);
}


// ------------------------------------------------------------
// verVentasGanancias
// Genera un reporte completo de ventas y ganancias:
//   - Por producto dentro de cada sucursal
//   - Totales por sucursal
//   - Totales globales de todas las sucursales
// ------------------------------------------------------------
void verVentasGanancias(){
    // Variables locales para no acumular entre llamadas sucesivas
    float numeroVentasXSucursal[3]   = {0};
    float gananciaVentasXSucursal[3] = {0};
    numeroVentasTotales   = 0;
    gananciaVentasTotales = 0;

    printf("\n========== VENTAS Y GANANCIAS =========\n");
    for(i = 0; i < sucursales; i++){
        printf(">>>>> %s <<<<<\n", nombresSucursal[i]);
        for(j = 0; j < prods; j++){
            printf("-- %s:\n", nombresProds[j]);
            printf(" Stock vendido: %.0f\n",    ventas[i][j][0]);
            printf(" Ganancia obtenida: $%.2f\n", ventas[i][j][1]);
            numeroVentasXSucursal[i]   += ventas[i][j][0];
            gananciaVentasXSucursal[i] += ventas[i][j][1];
        }
        printf("\nNumero de productos vendidos en la sucursal: %.0f\n",  numeroVentasXSucursal[i]);
        printf("Ganancia obtenida en la sucursal: $%.2f\n", gananciaVentasXSucursal[i]);

        // Acumular en totales globales
        numeroVentasTotales   += numeroVentasXSucursal[i];
        gananciaVentasTotales += gananciaVentasXSucursal[i];
        printf("\n");
    }
    printf("\n------------------------------------------------\n");
    printf("Numero de productos vendidos en total (TODAS LAS SUCURSALES): %.0f\n", numeroVentasTotales);
    printf("Ganancia total obtenida: $%.2f\n", gananciaVentasTotales);
}
    /*for(int i=0; i<3; i++){
            printf(">>>> Sucursal: %d\n", i+1);
            for(int j=0; j<10; j++){
                printf("====== %s ======\n", nombresProds[j]);
                for(int k=0; k<2; k++){
                    switch(k){
                        case 0:
                            printf("- Stock: ");
                            printf("%f", matriz[i][j][k]);
                            break;

                        case 1:
                            printf("- Precio: ");
                            printf("%f", matriz[i][j][k]);
                            break;
                    }
                    
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");*/