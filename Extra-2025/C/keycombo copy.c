#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

int main(void);
void menu(void);
void crearmacro(void);
void mostrarmacros(void);
void ejecutarmacro(void);

FILE* abrir_macros(const char *mode) {
    FILE *fp = fopen("macros.txt", mode);
    if (fp == NULL) {
        printf("Error al abrir el archivo de macros.\n");
    }
    return fp;
}

typedef enum{
    EJECUTARO = 1,
    EJECUTART,
    INGRESAR,
    MOSTRAR,
    ELIMINAR,
    EDITAR,
    SALIR
}opciones_t;

void menu (void){
    system("cls");
    opciones_t op;
    do{
        printf("Menu\n");
        printf("1_Iniciar una Macro\n");
        printf("2_Iniciar macros\n");
        printf("3_Crear una Macro\n");
        printf("4_Mostrar Macros\n");
        printf("5_Eliminar Macros\n");
        printf("6_Editar Macro\n");
        printf("7_Salir\n");
        scanf("%d",&op);
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        switch (op){
            case EJECUTARO:
                ejecutarmacro();
                break;
            case EJECUTART:
                break;
            case INGRESAR:
                crearmacro();
                break;
            case MOSTRAR:
                mostrarmacros();
                break;
            case ELIMINAR:
                break;
            case EDITAR:
                break;
        }   
    }while(op!=SALIR);
}

void crearmacro(){
    char nombre[50];
    int ch; 
    FILE *fp = abrir_macros("a+");
    system("cls");
    printf("Defina el nombre de la macro: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0;
    fprintf(fp, "%s:", nombre);
    printf("Las teclas de la macro  se ejecutaran secuencialmente o al mismo tiempo? (S para secuencial, T para simultaneo): ");
    ch = _getch();
    if (ch == 'S' || ch == 's') {
        fprintf(fp, "S\n");
    } else if (ch == 'T' || ch == 't') {
        fprintf(fp, "T\n");
    } else {
        printf("Opción no válida. Saliendo...\n");
        fclose(fp);
        return;
    }
    printf("\nIntroduzca las teclas para la macro (presione ESC para finalizar):\n");
    while (1) {
        ch = _getch(); 
        if (ch == 27) { 
            break;
        }

        if (ch == 224 || ch == 0) { 
            ch = _getch();
            switch (ch) {
                case 72: printf("{UP}"); fprintf(fp, "{UP}"); break;
                case 80: printf("{DOWN}"); fprintf(fp, "{DOWN}"); break;
                case 75: printf("{LEFT}"); fprintf(fp, "{LEFT}"); break;
                case 77: printf("{RIGHT}"); fprintf(fp, "{RIGHT}"); break;
                case 83: printf("{DEL}"); fprintf(fp, "{DEL}"); break;
                case 71: printf("{HOME}"); fprintf(fp, "{HOME}"); break;
                case 79: printf("{END}"); fprintf(fp, "{END}"); break;
                default:
                    break;
            }
        } else { // tecla normal (ASCII)
            printf("%c", ch);
            fputc(ch, fp);
        }
    }
    fprintf(fp, "\n");
    fclose(fp);
    printf("\n\nMacro '%s' guardada correctamente.\n", nombre);
}

void mostrarmacros() {
    char linea[256];
    char* token;
    FILE *fp = abrir_macros("r");
    system("cls");
    printf("Macros guardadas:\n\n");

    while (fgets(linea, sizeof(linea), fp)) {
        linea[strcspn(linea, "\n")] = 0;
        token = strtok(linea, ":");
        if (token != NULL) {
            printf("Macro: %s\n", token);
        }
        if (fgets(linea, sizeof(linea), fp)) {
             linea[strcspn(linea, "\n")] = 0;
             printf("Teclas: %s\n\n", linea);
        }
    }
    fclose(fp);
    printf("\n\nPresione cualquier tecla para continuar...\n");
    _getch();
}

void ejecutarmacro(){
    char linea[256];
    char nombre[50];
    FILE *fp = abrir_macros("r");
    if (fp == NULL) {
        return; 
    }
    system("cls");
    printf("Macros disponibles:\n\n");
    mostraramacros();
    printf("Ingrese el nombre de la macro a ejecutar: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = 0; 
    while (fgets(linea, sizeof(linea), fp)) {
        if (strncmp(linea, nombre, strlen(nombre)) == 0 && linea[strlen(nombre)] == ':') {
            char *teclas = strchr(linea, ':') + 1; 
            if (teclas) {
                teclas[strcspn(teclas, "\n")] = 0; 
                printf("Ejecutando macro: %s\n", nombre);
                printf("Teclas: %s\n", teclas);
            }
            break;
        }
    }
}

int main(void){
    menu();
    return 0;
}