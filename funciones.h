#include <stdio.h>
#define sucursales 3
#define prods 10
#define atributos 2

//LOCALIZAR VARIABLES GLOBALES
extern float matriz[sucursales][prods][atributos];
extern char nombresProds[10][30];
extern char nombresSucursal[3][40];
extern int i, j, k;


int menuInicial();
int menuTienda();
int elegirSucursal();
int elegirProducto(int opcionSucursal);
int administrarNegocio();