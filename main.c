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

// INCLUSIÓN DE LIBRERÍAS Y ARCHIVOS CABECERA //
#include <stdio.h>
#include "funciones.h" //CABECERA CON FUNCIONES
#include "procedimientos.h" //CABECERA CON PROCEDIMIENTOS
#include "procedimientos.c" //LIBRERÍA CON PROCEDIMIENTOS
#include "funciones.c" //LIBRERÍA CON FUNCIONES

//Definir constantes necesarias para el barrido de la matriz cubo.
#define sucursales 3
#define prods 10
#define atributos 2

//Matriz predefinida en caso de elección por parte del usuario.
float matriz[sucursales][prods][atributos] = {
    { // Sucursal 1
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
    { // Sucursal 2
        {40, 0.55},   // Pan
        {25, 0.75},   // Sal
        {15, 3.80},   // Miel
        {30, 2.20},   // Cafe
        {20, 1.60},   // Atun
        {50, 1.10},   // Arroz
        {35, 0.25},   // Huevos
        {30, 1.00},   // Leche
        {10, 2.70},   // Pasta Dental
        {8, 6.50}     // Vino
    },
    { // Sucursal 3
        {60, 0.45},   // Pan
        {35, 0.85},   // Sal
        {18, 3.60},   // Miel
        {45, 2.10},   // Cafe
        {22, 1.55},   // Atun
        {70, 0.95},   // Arroz
        {50, 0.22},   // Huevos
        {40, 0.95},   // Leche
        {12, 2.60},   // Pasta Dental
        {9, 6.20}     // Vino
    }
};

//VARIABLES GLOBALES
char nombresProds[10][30]={"Pan", "Sal", "Miel", "Cafe", "Atun", "Arroz", "Huevos", "Leche", "Pasta Dental", "Vino"};
char nombresSucursal[3][40]={"NORTE", "CENTRO", "SUR"};
float ventas[sucursales][prods][atributos];
float patrimoniosPorSucursal[3]={0};
int i, j, k;



// ---------- PROTOTIPOS DE MODULARIZACIÓN -------
// PROCEDIMIENTOS
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

//FUNCIONES
int menuTienda();
int elegirSucursal();
int elegirProducto(int opcionSucursal);
int menuIncial();

/////////////////////////////////////////// FUNCIÓN PRINCIPAL CON EL FLUJO //////////////////////

int main(){
    //Declarar variables usadas para parametros.
    int opcionSucursalMain;
    int opcionAdministrarNegocio;
    int producto;
    int opcionInicialMain;


    opcionInicialMain = menuInicial();
    seteoMatriz(opcionInicialMain);

    do{
        opcion = menuTienda();
        switch(opcion){

            case 1: //Calcular el precio total del inventario por sucursal
                valorInventarioSucursal(patrimoniosPorSucursal); 
                printf("\n");
                break;

            case 2:
                prodMasCaro();
                prodMasBarato();
                break;

            case 3:
                precioPromedioSucursales();
                break;
            case 4:
                printf("\n =========== BUSCAR PRODUCTO ==========\n");
                opcionSucursalMain = elegirSucursal();
                buscarProducto(opcionSucursalMain);
                
                break;
            case 5:
                printf("\n =========== ADMINISTRAR NEGOCIO ==========\n");
                do{
                    opcionAdministrarNegocio = administrarNegocio();
                    switch(opcionAdministrarNegocio){
                        case 1:
                            opcionSucursalMain = elegirSucursal();
                            producto = elegirProducto(opcionSucursalMain);
                            venderProductos(producto, opcionSucursalMain);
                            break;
                        case 2:
                            opcionSucursalMain = elegirSucursal();
                            producto = elegirProducto(opcionSucursalMain);
                            reabastecerStock(producto, opcionSucursalMain);
                            break;
                        case 3:
                            verVentasGanancias();
                            break;
                        case 4:
                            break;
                    }
                }while(opcionAdministrarNegocio!=4);
                
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
        }
    }while(opcion!=6);
    
    
    
    return 0;
}