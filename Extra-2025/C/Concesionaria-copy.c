#include <stdio.h>
#include <string.h>
#include <unistd.h> 
#define WAIT 3
#define MAX_AUTOS 100
#define PASSWORD "admin123"

typedef struct {
    char marca[50];
    char modelo[50];        
    int kilometros;
    float precio;
    union {
        int vendido; // 0 = en stock, 1 = vendido/no stock
        int flag;   
    } estado;
} Auto;
Auto Autos[MAX_AUTOS];

void AnadirAuto(int *stock);
void MostrarAutos(int *stock);
//void VenderAuto(void);
int menu(int *stock);

////////////////////////////////////////////////////////////////////////

int main(void) {
    int stock = 0;
    menu(&stock);
    return 0;
}

int menu(int *stock) {
    int option;
    char password[20];

    do {
        printf("Bienvenido, En este momento tenemos %d autos en stock\n", *stock);
        printf("1. Agregar auto (requiere contrasena)\n");
        printf("2. Mostrar autos\n");
        printf("3. Vender auto\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Ingrese la contrasena: ");
                scanf("%s", password);
                if (strcmp(password, PASSWORD) == 0) {
                    AnadirAuto(stock);
                } else {
                    printf("Contrasena incorrecta.\n");
                }
                break;
            case 2:
                MostrarAutos(stock);
                break;
            case 3:
                // VenderAuto(stock);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (option != 4);
    return 0;
}

void AnadirAuto(int *stock) {
    if (*stock >= MAX_AUTOS) {
        printf("No se pueden agregar más autos, el stock está lleno.\n");
        return;
    }

    printf("Ingrese la marca del auto: ");
    scanf("%s", Autos[*stock].marca);
    printf("Ingrese el modelo del auto: ");
    scanf("%s", Autos[*stock].modelo);
    printf("Ingrese los kilometros del auto: ");
    scanf("%d", &Autos[*stock].kilometros);
    printf("Ingrese el precio del auto: ");
    scanf("%f", &Autos[*stock].precio);

    Autos[*stock].estado.vendido = 0;
    (*stock)++;
    printf("Auto agregado exitosamente. Ahora hay %d autos en stock.\n", *stock);
    sleep(WAIT);
    system("cls");
}

void MostrarAutos(int *stock){
    if(*stock == 0){
        printf("No se encontraron autos en stock.");
        sleep(WAIT);
        system("cls");
    }
    else{
        for(int i = 0; i < *stock; i++){
            printf("Auto %d\n", i+1);
            printf("Marca: %s\n", Autos[i].marca);
            printf("Modelo: %s\n", Autos[i].modelo);
            printf("Kilometros: %d\n", Autos[i].kilometros);
            printf("Precio: %.2f\n", Autos[i].precio);
            if(Autos[i].estado.vendido == 0){
                printf("Estado: En stock\n");
            }
            else{
                printf("Estado: Vendido\n");
            }
        }
        printf("No hay mas autos para mostrar\n");
        sleep(WAIT);
        system("cls");
    }
}


/*
void VenderAuto(void){
    int i;
    printf("Ingrese el numero de auto que desea vender: ");
    scanf("%d", &i);
    if(i < 1 || i > stock){
        printf("Numero de auto invalido\n");
        return;
    }
    Autos[i-1].estado.vendido = 1;
    printf("Auto vendido exitosamente\n");
}
*/