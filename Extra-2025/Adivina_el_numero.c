#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define liminf 1
#define limupp 10000
int GenerarNumero();
void Adivina();

int main(void){
    int numrand = GenerarNumero();
    Adivina(numrand);
    return 0;
}

int GenerarNumero(){
    int numrand;
    srand(time(NULL));
    numrand = rand() % (limupp - liminf + 1) + liminf;
    return numrand;
}

void Adivina(int numrand){
    int valor;
    do{ 
        printf("Adivina el numero en que he pensado: ");
        scanf("%d", &valor);
        if(valor > numrand){
            printf("El numero que ingresaste es mas grande al que pense.\n");
        }
        else if(valor < numrand){
            printf("El numero que ingresaste es mas chico al que pense.\n");
        }
        else {
            printf("Has ganado el juego!\n");
        }
    }
    while(valor!=numrand);
}