// ============================================================
// CABECERA DE FUNCIONES
// Declara variables externas compartidas y los prototipos de
// todas las funciones que retornan un valor entero (menús y selección).
// ============================================================

#include <stdio.h>
#define sucursales 3
#define prods 10
#define atributos 2

// ---- VARIABLES GLOBALES EXTERNAS ----
// Definidas en main.c; accesibles desde cualquier módulo que incluya esta cabecera
extern float matriz[sucursales][prods][atributos]; // Inventario: [sucursal][producto][stock/precio]
extern char  nombresProds[10][30];                 // Nombres de los 10 productos
extern char  nombresSucursal[3][40];               // Nombres de las 3 sucursales
extern int   i, j, k;                             // Índices globales de iteración

// ---- PROTOTIPOS DE FUNCIONES ----
int menuInicial();                    // Menú de bienvenida: elegir carga automática o manual
int menuTienda();                     // Menú principal de opciones de la tienda
int elegirSucursal();                 // Submenú para seleccionar una sucursal (1-3)
int elegirProducto(int opcionSucursal); // Submenú para seleccionar un producto (1-10)
int administrarNegocio();             // Submenú del panel de administración