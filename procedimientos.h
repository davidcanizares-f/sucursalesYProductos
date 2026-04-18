#include <stdio.h>
#define sucursales 3
#define prods 10
#define atributos 2
extern float matriz[sucursales][prods][atributos];
extern char nombresProds[10][30];
extern char nombresSucursal[3][40];
extern float ventas[sucursales][prods][atributos];
extern int i, j, k;




void mostrarMatrizEstablecida();
void valorInventarioSucursal();
void prodMasCaro();
void prodMasBarato();
void precioPromedioSucursales();
void buscarProducto();
void venderProductos();
void reabastecerStock();
void verVentasGanancias();
void registro();