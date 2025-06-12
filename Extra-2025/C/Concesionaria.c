#include <stdio.h>
#define MAXIMOVEHICULOS 15
int PedirDatos(int ganancias[]);
int CalcularGanancias(int ganancias[]);
int i=0;

int main(void){
    int ganancias[MAXIMOVEHICULOS];
    PedirDatos(ganancias);
    CalcularGanancias(ganancias);
    return 0;
}

int PedirDatos(int ganancias[]){
    int terminar;
    do {
        int valor;
        printf("Ingrese el precio del vehiculo vendido: ");
        scanf("%d", &valor);
        ganancias[i] = valor;
        i++;
        printf("0 para continuar, 1 para salir del programa: ");
        scanf("%d", &terminar);
        switch (terminar){
        case 0:
             continue;
        case 1:
             terminar=1;
        }
    }
    while(terminar!=1);
}

int CalcularGanancias(int ganancias[]){
    int valor = 0;
    printf("Ganancias:\n");
    for (int j = 0; j < i; j++) {
        valor += ganancias[j];
    }
    printf("%d", valor);
}