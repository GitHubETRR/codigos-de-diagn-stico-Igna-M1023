#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 10
#define MAX_CHAR 32

void menu();

typedef enum{
    INGRESAR=1,
    MOSTRAR,
    ELIMINAR,
    EDITAR,
    SALIR
}opciones_t;
typedef struct contacto{
    char nombre[MAX_CHAR];
    int numerocel[MAX_NUM];
    int numerolinea[MAX_NUM];
    struct contacto * next;
}contacto_t;

contacto_t *_EQUIPO=NULL;

int main(void){
    menu();
    return 0;
}

void menu(){
    opciones_t op;
    do{
        printf("Menu\n");
        printf("1_Ingresar contacto\n");
        printf("2_Mostrar contacto\n");
        printf("3_Eliminar un contacto\n");
        printf("4_Editar un contacto\n");
        printf("5_Salir\n");
        scanf("%d",&op);
        switch (op){
            case INGRESAR:
                break;
            case MOSTRAR:
                break;
            case ELIMINAR:
                break;
            case EDITAR:
                break;
        }   
    }while(op!=SALIR);
}

void imprimir_alumno(contacto_t * contacto){
    printf("\n--------------------\n");
    printf("Nombre: %s\n",contacto->nombre);
    printf("Numero de celular: %d\n", contacto->numerocel);
    printf("Numero de linea: %d\n", contacto->numerolinea);
    printf("\n--------------------\n");
}

void ingresar(void){
    contacto_t * contacto_ptr= (contacto_t *)malloc(sizeof(contacto_t));
    if(contacto_ptr==NULL){
        printf("Out of Memory");
        exit(1);
    }

    printf("Nombre:");
    scanf("%s", contacto_ptr->nombre);
    printf("Numero de celular:");
    scanf("%d", &contacto_ptr->numerocel);
    printf("Numero de linea:");
    scanf("%d", &contacto_ptr->numerolinea);
    contacto_ptr->next=NULL;
    printf("\n");
    if(_EQUIPO==NULL){
        _EQUIPO=contacto_ptr;
    }
    else{
        contacto_ptr->next=_EQUIPO;
        _EQUIPO=contacto_ptr;
    }

}