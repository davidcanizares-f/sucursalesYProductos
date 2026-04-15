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

============== SISTEMA DE CALIFICACIONES =============
*/

// INCLUSIÓN DE LIBRERÍAS Y ARCHIVOS CABECERA //
#include <stdio.h>
#include "funciones.h" //LIBRERÍA CON FUNCIONES
#include "procedimientos.h" //LIBRERÍA CON PROCEDIMIENTOS
#include "procedimientos.c"
#include "funciones.c"

#define sucursales 3
#define prods 10
#define atributos 2

float matriz[sucursales][prods][atributos] = {
    {   // Sucursal 1
        {15, 30.5}, {20, 1.2}, {12, 0.8}, {8, 2.5}, {30, 1.0},
        {18, 4.2}, {25, 2.0}, {10, 5.5}, {14, 3.0}, {22, 6.8}
    },
    {   // Sucursal 2
        {10, 3.6}, {18, 10.1}, {15, 0.9}, {12, 2.4}, {28, 1.2},
        {20, 4.0}, {30, 2.1}, {9, 5.8}, {16, 3.2}, {24, 6.5}
    },
    {   // Sucursal 3
        {13, 3.4}, {22, 1.3}, {14, 0.7}, {11, 2.6}, {35, 1.1},
        {16, 4.5}, {27, 2.2}, {7, 5.6}, {19, 3.1}, {21, 6.9}
    }
};
char nombresProds[10][30]={"Pan", "Six", "Seven", "Vino", "Cris", "Epstein", "Diddy", "Deivid", "Tensor", "Orbey"};
char nombresSucursal[3][40]={"Montufar", "Montaditos Sandwich", "Cafe Rojo"};
float patrimoniosXSucursal[3]={0};
int i, j, k;


void registroTemporal();
int menuTienda();
void valorInventarioSucursal();
void prodMasCaro();


int main(){
    
    
    

    registroTemporal();
    do{
        opcion = menuTienda();
        switch(opcion){

            case 1: //Calcular el precio total del inventario por sucursal
                valorInventarioSucursal(patrimonioXSucursal); 
                printf("\n");
                break;

            case 2:
                prodMasCaro();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }
    }while(opcion!=6);
    
    
    
    return 0;
}