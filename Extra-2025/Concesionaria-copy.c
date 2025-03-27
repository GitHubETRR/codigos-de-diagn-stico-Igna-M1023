#include <stdio.h>
#include <string.h>
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
int stock = 0;

void AnadirAuto(void);
void MostrarAutos(void);
int menu(void);

////////////////////////////////////////////////////////////////////////

int main(void) {
    menu();
    return 0;
}

int menu(void) {
    int option;
    char password[20];

    do {
        printf("Bienvenido, En este momento tenemos %d autos en stock\n", stock);
        printf("1. Agregar auto (requiere contrasena)\n");
        printf("2. Mostrar autos\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Ingrese la contrasena: ");
                scanf("%s", password);
                if (strcmp(password, PASSWORD) == 0) {
                    AnadirAuto();
                } else {
                    printf("Contrasena incorrecta.\n");
                }
                break;
            case 2:
                MostrarAutos();
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (option != 2);

    return 0;
}

void AnadirAuto(void) {
    if (stock >= MAX_AUTOS) {
        printf("No se pueden agregar más autos, el stock está lleno.\n");
        return;
    }

    printf("Ingrese la marca del auto: ");
    scanf("%s", Autos[stock].marca);
    printf("Ingrese el modelo del auto: ");
    scanf("%s", Autos[stock].modelo);
    printf("Ingrese los kilometros del auto: ");
    scanf("%d", &Autos[stock].kilometros);
    printf("Ingrese el precio del auto: ");
    scanf("%f", &Autos[stock].precio);

    stock++;
    printf("Auto agregado exitosamente. Ahora hay %d autos en stock.\n", stock);
}

void MostrarAutos(void){
    int opcion;
    do{
        for(int i = 0; i < stock; i++){
            printf("Auto %d\n", i+1);
            printf("Marca: %s\n", Autos[i].marca);
            printf("Modelo: %s\n", Autos[i].modelo);
            printf("Kilometros: %d\n", Autos[i].kilometros);
            printf("Precio: %.2f\n", Autos[i].precio);
            if(i != stock-1){
                printf("Desea mostrar el siguiente? 1-Si 2-No\n");
                scanf("%d", &opcion);
            }
            else{
                printf("No hay mas autos para mostrar\n");
                opcion = 2;
            }
        }
    } while (opcion != 2);
}