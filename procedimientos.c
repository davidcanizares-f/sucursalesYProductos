#include <stdio.h>
#include "procedimientos.h"
#include <string.h>
float patrimonioXProd=0;
float suma[3]={0};
float stock=0;
float patrimonioXSucursal[3]={0};
float mayor = 0;
char nombreMayor[10][20]={0};
float productoMasCaro=0;
int indice =0;


void registroTemporal(){
    
    for(int i=0; i<3; i++){
            printf(">>>> Sucursal: %d || %s \n", i+1, nombresSucursal[i]);
            for(int j=0; j<10; j++){
                printf("====== %s ======\n", nombresProds[j]);
                for(int k=0; k<2; k++){
                    switch(k){
                        case 0:
                            printf("- Stock: ");
                            printf("%.2f", matriz[i][j][k]);
                            printf("\n");
                            break;

                        case 1:
                            printf("- Precio: ");
                            printf("%.2f", matriz[i][j][k]);
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
    for(i=0; i<3; i++){
        suma[i]=0;
        
        for(j=0; j<10; j++){
            for(k=0; k<2; k++){
                switch(k){
                    case 0:
                        stock = matriz[i][j][k]; //matriz es la cantidad
                        break;
                    case 1:
                        patrimonioXProd = stock*matriz[i][j][k]; //matriz es el precio
                        break;
                }
            }
            suma[i] += patrimonioXProd;
        }
        patrimonioXSucursal[i] = suma[i];
        printf(">>> %s: %.2f\n", nombresSucursal[i], patrimonioXSucursal[i]);
         
        
    }
    
}


void prodMasCaro(){

    for(i = 0; i < 3; i++){

        mayor = matriz[i][0][1];
        indice = 0;

        for(j = 0; j < 10; j++){

            if(matriz[i][j][1] > mayor){
                mayor = matriz[i][j][1];
                indice = j;
            }
        }

        printf(">>>> %s\n", nombresSucursal[i]);
        printf("%s : %.2f\n", nombresProds[indice], mayor);
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