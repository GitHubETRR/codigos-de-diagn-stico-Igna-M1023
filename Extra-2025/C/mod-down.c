#include <stdio.h>
#include <curl/curl.h>
void crearinstancias(void);

int main(void) {
    system("cls");
    FILE *fp;
    fp = fopen("instancias.txt", "a+");
    if (fp == NULL) {
        printf("No se han encontrado instancias\n");
        crearinstancias();
    } else {
        printf("Seleccione una instancia: \n");
    }
    return 0;
}

void crearinstancias(void) {
    char nombre[100];
    FILE *fp = fopen("instancias.txt", "w");
    if (fp == NULL) {
        printf("Error al crear instancias.txt\n");
        return;
    }
    printf("Ingrese un nombre para la instancia: ");
}


