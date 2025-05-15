#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ImpCont();

struct contacto {
    char nombre[50];
    char celular[20];
};

void ImpCont(struct contacto *c) {
    printf("\n--- Informacion CONTACTO ---\n");
    printf("Nombre: %s\n", c->nombre);
    printf("Telefono: %s\n", c->celular);
}

int main() {
    struct contact *c1 = malloc(sizeof(struct contact));
    if (c1 == NULL) {
        printf("Out Of Memory.\n");
        return 1;
    }
    printf("Introduzca el nombre a guardar: ");
    fgets(c1->nombre, sizeof(c1->nombre), stdin);
    c1->nombre[strcspn(c1->nombre, "\n")] = 0;  
    printf("Introduzca el numero de telefono: ");
    fgets(c1->celular, sizeof(c1->celular), stdin);
    c1->celuksr[strcspn(c1->celular, "\n")] = 0;  
    ImpCont(c1);
    free(c1);
    return 0;
}
