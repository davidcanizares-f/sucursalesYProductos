// ============================================================
// PROCEDIMIENTOS.H - CABECERA DE PROCEDIMIENTOS
// Declara variables externas compartidas y los prototipos de
// todos los procedimientos (funciones void) del sistema.
// ============================================================

#include <stdio.h>
#define sucursales 3
#define prods 10
#define atributos 2

// ---- VARIABLES GLOBALES EXTERNAS ----
// Definidas en main.c; accesibles desde procedimientos.c
extern int   i, j, k;                              // Índices globales de iteración
extern float matriz[sucursales][prods][atributos];  // Inventario principal
extern float ventas[sucursales][prods][atributos];  // Registro acumulado de ventas
extern char  nombresProds[10][30];                  // Nombres de los productos
extern char  nombresSucursal[3][40];                // Nombres de las sucursales

// ---- PROTOTIPOS DE PROCEDIMIENTOS ----
void registro();                                    // Carga manual de inventario
void mostrarMatrizEstablecida();                    // Imprime inventario completo
void valorInventarioSucursal(float patrimonioXSucursal[3]); // Calcula patrimonio por sucursal
void prodMasCaro();                                 // Producto más caro por sucursal
void prodMasBarato();                               // Producto más barato por sucursal
void precioPromedioSucursales();                    // Precio promedio por sucursal
void buscarProducto(int opcionSucursal);            // Busca producto por nombre
void venderProductos(int opcionProd, int opcionSucursal);   // Registra una venta
void reabastecerStock(int opcionProd, int opcionSucursal);  // Agrega unidades al stock
void verVentasGanancias();                          // Reporte de ventas y ganancias
void seteoMatriz(int opcionInicial);                // Inicializa la matriz según modo elegido