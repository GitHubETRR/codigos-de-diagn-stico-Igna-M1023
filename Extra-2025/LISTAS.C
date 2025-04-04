#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 30

typedef struct alumno{
    char nombre[CANT];
    char apellido[CANT];
    struct alumno *next;
}alumno_t;

void imprimir(alumno_t *alumno);

/*
int main(void){
    alumno_t alumno1={"Israel", "Pavelek"};
    alumno_t alumno2={"Juan", "Pereyra"};
    printf("El nombre es: %s\n", alumno1.nombre);
    printf("El apellido es: %s\n", alumno1.apellido);
    printf("El nombre es: %s\n", alumno2.nombre);
    printf("El apellido es: %s\n", alumno2.apellido);
}
*/

int main(void){
    alumno_t *_6TEL=NULL;
    // AL 1
    alumno_t *alu_ptr=( alumno_t *)malloc(sizeof(alumno_t)); //malloc devuelve un puntero a void, por eso se hace el cast a alumno_t
    _6TEL=alu_ptr; //asigna la direccion de memoria de alu_ptr a _6TEL
    alu_ptr->next=NULL; //inicializa el siguiente puntero a NULL
    strcpy(alu_ptr->nombre,"Jorge");
    strcpy(alu_ptr->apellido,"Pereyra");
    // AL 2
    _6TEL->next=alu_ptr; //inicializa el siguiente puntero a NULL
    alu_ptr=( alumno_t *)malloc(sizeof(alumno_t)); //malloc devuelve un puntero a void, por eso se hace el cast a alumno_t
    alu_ptr->next=NULL; //inicializa el siguiente puntero a NULL
    strcpy(alu_ptr->nombre,"Mabel");
    strcpy(alu_ptr->apellido,"Pepe");
    imprimir(_6TEL);
}   

void imprimir(alumno_t *alumno){
    while(alumno!=NULL){
        printf("Nombre: %s\n", alumno->nombre);
        printf("Apellido: %s\n", alumno->apellido);
        alumno=alumno->next;
    }
}