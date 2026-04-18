#include <stdio.h>
#include <stdbool.h>
#include "procedimientos.h"
#include <string.h>
float patrimonioXProd=0;
float suma[3]={0};
float promedio[3]={0};
float inventario=0;
float patrimonioXSucursal[3]={0};
float mayor = 0;
float menor = 0;
char nombreMayor[10][20]={0};
float productoMasCaro=0;
int indice =0;
char buscado[20];
bool encontrado;
int prodsVender = 0;
int stock;
int prodsReabastecer = 0;
int ventas[3][10];






void registroTemporal(){
    
    for(int i=0; i<sucursales; i++){
            printf(">>>> Sucursal: %d || %s \n", i+1, nombresSucursal[i]);
            for(int j=0; j<prods; j++){
                printf("====== %s ======\n", nombresProds[j]);
                for(int k=0; k<atributos; k++){
                    switch(k){
                        case 0:
                            printf("- Stock: ");
                            printf("%.0f", matriz[i][j][k]);
                            printf("\n");
                            break;

                        case 1:
                            printf("- Precio: ");
                            printf("$%.2f", matriz[i][j][k]);
                            break;
                    }
                    
                }
                printf("\n");
                printf("\n");
            }
            printf("\n");
        }
}

void valorInventarioSucursal(float patrimonioXSucursal[3]){
    printf("======== VALOR DE INVENTARIOS POR SUCURSAL =========\n");
    for(i=0; i<sucursales; i++){
        suma[i]=0;
        
        for(j=0; j<prods; j++){
            for(k=0; k<atributos; k++){
                switch(k){
                    case 0:
                        inventario = matriz[i][j][k]; //matriz es la cantidad
                        break;
                    case 1:
                        patrimonioXProd = inventario*matriz[i][j][k]; //matriz es el precio
                        break;
                }
            }
            suma[i] += patrimonioXProd;
        }
        patrimonioXSucursal[i] = suma[i];
        printf(">>> %s: $%.2f\n", nombresSucursal[i], patrimonioXSucursal[i]);
         
        
    }
    
}


void prodMasCaro(){
    printf("\n======== PRODUCTO MAS CARO POR SUCURSAL ========\n");
    for(i = 0; i < sucursales; i++){

        mayor = matriz[i][0][1];
        indice = 0;

        for(j = 0; j < prods; j++){

            if(matriz[i][j][1] > mayor){
                mayor = matriz[i][j][1];
                indice = j;
            }
        }

        printf(">>>> %s\n", nombresSucursal[i]);
        printf("%s : %.2f\n", nombresProds[indice], mayor);
    }
}

void prodMasBarato(){
    printf("\n========== PRODUCTO MAS BARATO POR SUCURSAL ===========\n");
    for(i=0; i<sucursales; i++){
        menor = matriz[i][0][1];
        for(j=0; j<prods; j++){
            
            if(matriz[i][j][1] <= menor){
                menor = matriz[i][j][1];
                indice = j;
            }

        }
        printf(">>>> %s: <<<<\n", nombresSucursal[i]);
        printf("-%s: $%.2f\n", nombresProds[indice], menor);
    }

}

void precioPromedioSucursales(){
    printf("\n========= PRECIO PROMEDIO POR SUCURSAL ===========\n");
    for(i=0; i<sucursales; i++){
        float suma[sucursales]={0};

        for(j=0; j<prods; j++){
            suma[i] += matriz[i][j][1];
        }

        promedio[i] = suma[i] / prods;
        printf(">>>>> %s <<<<<\n", nombresSucursal[i]);
        printf("-Promedio: %.2f\n", promedio[i]);
        printf("\n");
    }
}

void buscarProducto(int opcionSucursal){
    encontrado = false;
    printf("Escriba el nombre del producto: ");
    while(getchar() != '\n');

    fgets(buscado, 20, stdin);
    buscado[strcspn(buscado, "\n")] = '\0';

    for(j=0; j<prods; j++){
        if(strcmp(buscado, nombresProds[j])==0){
            encontrado = true;
            indice = j;
            break;
        }
        
    }
    if(encontrado == true){
        printf("====== PRODUCTO ENCONTRADO ====\n");
        printf(">>>> %s <<<<<\n", nombresProds[indice]);
        printf("-Precio: $%.2f\n", matriz[opcionSucursal-1][indice][1]);
        printf("-Cantidad: %.0f\n", matriz[opcionSucursal-1][indice][0]);
    } else{
        printf("\n====== PRODUCTO NO ENCONTRADO ====\n");
    }
    printf("\n");

}


void venderProductos(int opcionProd, int opcionSucursal){
    printf("\n========= VENDER PRODUCTOS ==========\n");
    stock = matriz[opcionSucursal-1][opcionProd-1][0];
    printf("Stock actual: %d\n", stock);

    do { //Validacion para que el usuario no ingrese 0 ni valores negativos
        printf("Cantidad a vender: ");
        while(scanf("%d", &prodsVender) != 1){ while(getchar() != '\n'); }
            if(prodsVender <= 0){
                printf("[ERROR]: Debe ser un numero positivo.\n");
            }else if(prodsVender > stock){
                printf("[ERROR]: No hay suficiente stock (disponible: %d).\n", stock);}
    } while(prodsVender <= 0 || prodsVender > stock);

    stock -= prodsVender;
    matriz[opcionSucursal-1][opcionProd-1][0] = stock;
    printf("%d UNIDADES VENDIDAS DE %s\n", prodsVender, nombresProds[opcionProd-1]);
    printf("Stock actual: %d\n", stock);
    ventas[opcionSucursal-1][opcionProd-1] += prodsVender;
}

void reabastecerStock(int opcionProd, int opcionSucursal){
    printf("\n========= REABASTECER STOCK ==========\n");
    stock = matriz[opcionSucursal-1][opcionProd-1][0];
    printf("Stock actual: %d\n", stock);
    printf("Cantidad a reabastecer: ");
    
    do {
        printf("Cantidad a reabastecer: ");
        while(scanf("%d", &prodsReabastecer) != 1){ while(getchar() != '\n'); }
        if(prodsReabastecer <= 0){
            printf("[ERROR]: Debe ser un numero positivo.\n");}
    } while(prodsReabastecer <= 0);

    stock += prodsReabastecer;
    matriz[opcionSucursal-1][opcionProd-1][0] = stock;
    printf("%d UNIDADES REABASTECIDAS DE %s\n", prodsReabastecer, nombresProds[opcionProd-1]);
    printf("Stock actual: %d\n", stock);
}

void verVentasGanancias(){
    printf("\n========== VENTAS Y GANANCIAS =========\n");
    for(i=0; i<sucursales; i++){
        printf(">>>>> %s <<<<<\n", nombresSucursal[i]);
        for(j=0; j<prods; j++){
            printf("-- %s: ", nombresProds[j]);
            printf("%d\n", ventas[i][j]);
            
        }
    }    

}












/*void registro()
{
    float matriz[sucursales][prods][atributos];
    char nombresProds[10][30]={"Pan", "Six", "Seven", "Vino", "Cris", "Epstein", "Diddy", "Deivid", "Tensor", "Orbey"};
    char nombresSucursal[3][40]={"Montufar", "Montaditos Sandwich", "Cafe Rojo"};

    for(int i=0; i<3; i++){
        printf(">>>> Sucursal: %d || %s \n", i+1, nombresSucursal[i]);
        for(int j=0; j<10; j++){
            printf("====== %s ======\n", nombresProds[j]);
            for(int k=0; k<2; k++){
                switch(k){
                    case 0:
                        printf("- Stock: ");
                        scanf("%f", &matriz[i][j][k]);
                        break;

                    case 1:
                        printf("- Precio: ");
                        scanf("%f", &matriz[i][j][k]);
                        break;
                }
                
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");



}*/

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