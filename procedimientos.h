#include <stdio.h>
#define sucursales 3
#define prods 10
#define atributos 2

//LOCALIZAR VARIABLES GLOBALES
extern int i, j, k;
extern float matriz[sucursales][prods][atributos];
extern float ventas[sucursales][prods][atributos];
extern char nombresProds[10][30];
extern char nombresSucursal[3][40];





void registro();
void mostrarMatrizEstablecida();
void valorInventarioSucursal(float patrimonioXSucursal[3]);
void prodMasCaro();
void prodMasBarato();
void precioPromedioSucursales();
void buscarProducto(int opcionSucursal);
void venderProductos(int opcionProd, int opcionSucursal);
void reabastecerStock(int opcionProd, int opcionSucursal);
void verVentasGanancias();
void seteoMatriz(int opcionInicial);