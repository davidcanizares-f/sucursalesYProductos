/*
            UNIVERSIDAD DE LAS AMÉRICAS
    FACULTAD DE INGENIERÍA Y CIENCIAS APLICADAS
            INGENIERÍA DE SOFTWARE
                PROGRAMACIÓN I
Autores: 
    -David Cañizares
    -Sebastián Orbe
    -Jean Pierre Rosas
    -Derek Yépez

============== SISTEMA DE GESTIÓN DE INVENTARIOS =============
*/

// ============================================================
// ARCHIVO PRINCIPAL - ORBSTORE
// Punto de entrada del programa. Define la estructura de datos
// principal (matriz 3D de inventario) y controla el flujo general.
// ============================================================

#include <stdio.h>
#include "funciones.h"      // Prototipos de funciones que retornan valores
#include "procedimientos.h" // Prototipos de procedimientos (void)
#include "procedimientos.c" // Implementación de procedimientos
#include "funciones.c"      // Implementación de funciones

// ---- CONSTANTES GLOBALES ----
// Dimensiones de la matriz cubo de inventario
#define sucursales 3   // Número de sucursales
#define prods 10       // Número de productos por sucursal
#define atributos 2    // Atributos por producto: [0]=stock, [1]=precio

// ---- MATRIZ DE INVENTARIO PREDEFINIDA ----
// Usada cuando el usuario elige cargar datos automáticamente (opción 1)
// Estructura: matriz[sucursal][producto][atributo]
//             atributo 0 = stock, atributo 1 = precio unitario
float matriz[sucursales][prods][atributos] = {
    { // Sucursal 1 - NORTE
        {50, 0.50},   // Pan
        {30, 0.80},   // Sal
        {20, 3.50},   // Miel
        {40, 2.00},   // Cafe
        {25, 1.50},   // Atun
        {60, 1.00},   // Arroz
        {45, 0.20},   // Huevos
        {35, 0.90},   // Leche
        {15, 2.50},   // Pasta Dental
        {10, 6.00}    // Vino
    },
    { // Sucursal 2 - CENTRO
        {40, 0.55},   // Pan
        {25, 0.75},   // Sal
        {15, 3.80},   // Miel
        {30, 2.20},   // Cafe
        {20, 1.60},   // Atun
        {50, 1.10},   // Arroz
        {35, 0.25},   // Huevos
        {30, 1.00},   // Leche
        {10, 2.70},   // Pasta Dental
        {8,  6.50}    // Vino
    },
    { // Sucursal 3 - SUR
        {60, 0.45},   // Pan
        {35, 0.85},   // Sal
        {18, 3.60},   // Miel
        {45, 2.10},   // Cafe
        {22, 1.55},   // Atun
        {70, 0.95},   // Arroz
        {50, 0.22},   // Huevos
        {40, 0.95},   // Leche
        {12, 2.60},   // Pasta Dental
        {9,  6.20}    // Vino
    }
};

// ---- VARIABLES GLOBALES ----
char nombresProds[10][30]    = {"Pan", "Sal", "Miel", "Cafe", "Atun", "Arroz", "Huevos", "Leche", "Pasta Dental", "Vino"};
char nombresSucursal[3][40]  = {"NORTE", "CENTRO", "SUR"};
float ventas[sucursales][prods][atributos]; // Registro acumulado de ventas: [0]=unidades, [1]=ganancias
float patrimoniosPorSucursal[3] = {0};     // Valor total del inventario por sucursal
int i, j, k;                               // Índices globales para recorrer la matriz

// ---- PROTOTIPOS ----
// Procedimientos (no retornan valor)
void seteoMatriz(int opcionInicial);
void registro();
void mostrarMatrizEstablecida();
void valorInventarioSucursal(float patrimonioXSucursal[3]);
void prodMasCaro();
void precioPromedioSucursales();
void buscarProducto(int opcionSucursal);
void venderProductos(int opcionProd, int opcionSucursal);
void reabastecerStock(int opcionProd, int opcionSucursal);
void verVentasGanancias();

// Funciones (retornan un entero con la opción elegida)
int menuTienda();
int elegirSucursal();
int elegirProducto(int opcionSucursal);
int menuIncial();

// ============================================================
// FUNCIÓN PRINCIPAL
// ============================================================
int main(){
    // Variables locales para capturar opciones del menú
    int opcionSucursalMain;
    int opcionAdministrarNegocio;
    int producto;
    int opcionInicialMain;

    // Mostrar menú de bienvenida y configurar la matriz según la elección
    opcionInicialMain = menuInicial();
    seteoMatriz(opcionInicialMain);

    // Bucle principal: permanece activo hasta que el usuario elija "Salir" (opción 6)
    do{
        opcion = menuTienda();
        switch(opcion){

            case 1: // Calcular el valor total del inventario por sucursal
                valorInventarioSucursal(patrimoniosPorSucursal);
                printf("\n");
                break;

            case 2: // Mostrar el producto más caro y más barato de cada sucursal
                prodMasCaro();
                prodMasBarato();
                break;

            case 3: // Calcular el precio promedio de productos por sucursal
                precioPromedioSucursales();
                break;

            case 4: // Buscar un producto por nombre en una sucursal específica
                printf("\n =========== BUSCAR PRODUCTO ==========\n");
                opcionSucursalMain = elegirSucursal();
                buscarProducto(opcionSucursalMain);
                break;

            case 5: // Acceder al panel de administración del negocio
                printf("\n =========== ADMINISTRAR NEGOCIO ==========\n");

                // Submenú de administración; se repite hasta elegir "Salir" (opción 4)
                do{
                    opcionAdministrarNegocio = administrarNegocio();
                    switch(opcionAdministrarNegocio){

                        case 1: // Registrar una venta de un producto
                            opcionSucursalMain = elegirSucursal();
                            producto = elegirProducto(opcionSucursalMain);
                            venderProductos(producto, opcionSucursalMain);
                            break;

                        case 2: // Reabastecer el stock de un producto
                            opcionSucursalMain = elegirSucursal();
                            producto = elegirProducto(opcionSucursalMain);
                            reabastecerStock(producto, opcionSucursalMain);
                            break;

                        case 3: // Ver resumen de ventas y ganancias por sucursal
                            verVentasGanancias();
                            break;

                        case 4: // Salir del panel de administración
                            break;
                    }
                }while(opcionAdministrarNegocio != 4);
                break;

            case 6: // Salir del programa
                printf("Saliendo del programa...\n");
                break;
        }
    }while(opcion != 6);

    return 0;
}