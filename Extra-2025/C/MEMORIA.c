#include <stdio.h>
#include <stdlib.h>
// void *malloc(size_t size);
/*
int main(void){
    int *p=(int *) malloc(sizeof(int)); //pide la memoria al sistema para un entero, al principio adapata el void al int
    if(p==NULL){ //si no hay memoria disponible, devuelve NULL
        printf("No hay memoria disponible\n");
        return 1;
    }
    *p=5; //asigna el valor 5 a la memoria que apunta p
    printf("El valor de p es: %d\n", *p); //imprime el valor de la memoria que apunta p
    free(p);
    return 0;
}
*/