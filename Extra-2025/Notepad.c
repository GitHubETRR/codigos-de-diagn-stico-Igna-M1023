#include <stdio.h>     // P
#include <windows.h>
#include <stdlib.h>    // S
#include <string.h>    // ST
#include <sys/stat.h>  // MK
#include <sys/types.h> // M

typedef enum{
    INGRESAR=1,
    MOSTRAR,
    ELIMINAR,
    EDITAR,
    SALIR
}opciones_t;
void crearnota(void);
void editarnota(void);
void mostrar(void);
void menu(void);

//

int main(void){
    menu();
    return 0;
}

void menu (void){
    opciones_t op;
    do{
        printf("Menu\n");
        printf("1_Crear una nota\n");
        printf("2_Mostrar notas\n");
        printf("3_Eliminar una nota\n");
        printf("4_Editar una nota\n");
        printf("5_Salir\n");
        scanf("%d",&op);
        switch (op){
            case INGRESAR:
                crearnota();
                break;
            case MOSTRAR:
                editarnota();
                break;
            case ELIMINAR:
                break;
            case EDITAR:
                break;
        }   
    }while(op!=SALIR);
}

void crearnota(){
    FILE *fp;
    char nombre[50];
    char ruta[100] = "./Notas/"; 
    char abs_ruta[_MAX_PATH]; 

    struct stat st = {0};
    if (stat("./Notas", &st) == -1) {
        mkdir("./Notas"); 
    }

    printf("Ingrese el nombre (sin extension): ");
    scanf("%s", nombre);

    strcat(ruta, nombre);
    strcat(ruta, ".txt");

    if (_fullpath(abs_ruta, ruta, _MAX_PATH) == NULL) {
        printf("Error obteniendo ruta absoluta\n");
        return;
    }
    
    fp = fopen(ruta, "w");
    if (fp == NULL) {
        printf("Error al crear la nota.\n");
        return;
    }
    fclose(fp);
    printf("Nota '%s' creada exitosamente en './Notas'.\n", nombre);
}

void editarnota(){
    char nombre[50];
    char ruta[100] = "./Notas/"; 
    char abs_ruta[_MAX_PATH]; 
    int opcion;
    struct stat st = {0};
    if (stat("./Notas", &st) == -1) {
        printf("Primero crea una nota!\n");
    }

    printf("Introduzca el nombre de la nota: ");
    scanf("%s", nombre);
    strcat(ruta, nombre);
    strcat(ruta, ".txt");

    if (stat(ruta, &st) == -1) {
        printf("La nota '%s' no existe\n", nombre);
        return;
    }

    if (_fullpath(abs_ruta, ruta, _MAX_PATH) == NULL) {
        printf("Error obteniendo ruta absoluta\n");
        return;
    }

    printf("1. Usar Notepad\n");
    printf("2. Usar otro programa\n");
    printf("3. No editar\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1: 
            system(abs_ruta); //  ruta completa y no relativa
            break;
        case 2:
            printf("...\n");
            break;
        case 3:
            printf("...\n");
            break;
        default:
            printf("Opcion invalida.\n");
            break;
    }
}