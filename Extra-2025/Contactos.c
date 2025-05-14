#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 12
#define MAX_CHAR 64

void menu();
void ingresar();
void mostrar();
void eliminar();
void editar();
void llamar();

typedef enum {
    LLAMAR = 1,
    INGRESAR,
    MOSTRAR,
    ELIMINAR,
    EDITAR,
    SALIR
} opciones_t;

typedef struct contacto {
    char nombre[MAX_CHAR];
    int numerocel;
    int numerolinea;
    char descripcion[MAX_CHAR];
    struct contacto *next;
} contacto_t;

contacto_t *_EQUIPO = NULL;

int main(void) {
    menu();
    return 0;
}

void menu() {
    opciones_t op;
    do {
        printf("Menu\n");
        printf("1_Llamar contacto\n");
        printf("2_Ingresar contacto\n");
        printf("3_Mostrar contactos\n");
        printf("4_Eliminar un contacto\n");
        printf("5_Editar un contacto\n");
        printf("6_Salir\n");
        scanf("%d", &op);
        switch (op) {
            case LLAMAR:
                llamar();
                break;
            case INGRESAR:
                ingresar();
                break;
            case MOSTRAR:
                mostrar();
                break;
            case ELIMINAR:
                eliminar();
                break;
            case EDITAR:
                editar();
                break;
        }
    } while (op != SALIR);
}

void imprimir_contacto(contacto_t *contacto) {
    printf("\n--------------------\n");
    printf("Nombre: %s\n", contacto->nombre);
    printf("Numero de celular: %d\n", contacto->numerocel);
    printf("Numero de linea: %d\n", contacto->numerolinea);
    printf("Descripcion: %s\n", contacto->descripcion);
    printf("\n--------------------\n");
}

void ingresar() {
    contacto_t *contacto_ptr = (contacto_t *)malloc(sizeof(contacto_t));
    if (contacto_ptr == NULL) {
        printf("Out of Memory");
        exit(1);
    }

    printf("Nombre: ");
    scanf("%s", contacto_ptr->nombre);
    printf("Numero de celular: ");
    scanf("%d", &contacto_ptr->numerocel);
    printf("Numero de linea: ");
    scanf("%d", &contacto_ptr->numerolinea);
    printf("Descripcion: ");
    scanf(" %[^\n]", contacto_ptr->descripcion); 
    contacto_ptr->next = NULL;

    if (_EQUIPO == NULL) {
        _EQUIPO = contacto_ptr;
    } else {
        contacto_ptr->next = _EQUIPO;
        _EQUIPO = contacto_ptr;
    }
}

void mostrar() {
    contacto_t *current = _EQUIPO;
    if (current == NULL) {
        printf("No hay contactos para mostrar.\n");
        return;
    }
    while (current != NULL) {
        imprimir_contacto(current);
        current = current->next;
    }
}

void eliminar() {
    char nombre[MAX_CHAR];
    printf("Ingrese el nombre del contacto: ");
    scanf("%s", nombre);

    contacto_t *current = _EQUIPO;
    contacto_t *prev = NULL;

    while (current != NULL && strcmp(current->nombre, nombre) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("No se encontro el contacto.\n");
        return;
    }

    if (prev == NULL) {
        _EQUIPO = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Contacto eliminado.\n");
}

void editar() {
    char nombre[MAX_CHAR];
    printf("Ingrese el nombre del contacto: ");
    scanf("%s", nombre);

    contacto_t *current = _EQUIPO;

    while (current != NULL && strcmp(current->nombre, nombre) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("No se encontro el contacto.\n");
        return;
    }

    printf("Editando contacto: %s\n", current->nombre);
    printf("Nuevo numero de celular: ");
    scanf("%d", &current->numerocel);
    printf("Nuevo numero de linea: ");
    scanf("%d", &current->numerolinea);
    printf("Nueva descripcion: ");
    scanf(" %[^\n]", current->descripcion);
    printf("Contacto actualizado.\n");
}

void llamar() {
    char nombre[MAX_CHAR];
    printf("Ingrese el nombre del contacto: ");
    scanf("%s", nombre);

    contacto_t *current = _EQUIPO;

    while (current != NULL && strcmp(current->nombre, nombre) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("No se encontro el contacto.\n");
        return;
    }

    printf("Llamando a %s...\n", current->nombre);
}