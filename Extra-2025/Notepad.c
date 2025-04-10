#include <stdio.h>
#include <stdlib.h> // For system()
#include <string.h> // For strcat()
#include <sys/stat.h> // For mkdir()
#include <sys/types.h> // For mode_t

typedef enum{
    INGRESAR=1,
    MOSTRAR,
    ELIMINAR,
    EDITAR,
    SALIR
}opciones_t;
void crearnota(void);
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
    int opcion;

    struct stat st = {0};
    if (stat("./Notas", &st) == -1) {
        mkdir("./Notas"); 
    }

    printf("Ingrese el nombre de la nota (sin extension): ");
    scanf("%s", nombre);

    strcat(ruta, nombre);
    strcat(ruta, ".txt");

    fp = fopen(ruta, "w");
    if (fp == NULL) {
        printf("Error al crear la nota.\n");
        return;
    }
    fclose(fp);
    printf("Nota '%s' creada exitosamente en './Notas'.\n", nombre);

    printf("Desea editar la nota?\n");
    printf("1. Usar Notepad\n");
    printf("2. Usar otro programa\n");
    printf("3. No editar\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("...\n");
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