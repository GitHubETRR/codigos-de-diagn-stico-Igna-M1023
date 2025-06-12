#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/select.h>

#define liminf 1
#define limupp 10000
#define MAX_STOCKS 100

int GenerarNumero();
void ColorDiff(float);
void MostrarStocks();
void IngresarStock();

typedef enum {
    INGRESAR = 1,
    ELIMINAR,
    SALIR
} opciones_t;

typedef struct {
    char nombre[20];
    float valor;
    float diferencia;
} stock_t;

stock_t stocks[MAX_STOCKS];
int num_stocks = 0;

int GenerarNumero() {
    return rand() % (limupp - liminf + 1) + liminf;
}

void ColorDiff(float diferencia) {
    if (diferencia > 0) {
        printf("\033[0;32m%.2f\033[0m\n", diferencia);
    } else if (diferencia < 0) {
        printf("\033[0;31m%.2f\033[0m\n", diferencia);
    } else {
        printf("%.2f\n", diferencia);
    }
}

void MostrarStocks() {
    printf("\nBolsa de valores - C\n\n");
    printf("- S&P 500\n\n");

    for (int i = 0; i < num_stocks; i++) {
        printf("- %s\n", stocks[i].nombre);
        printf("    VALOR: %.2f\n", stocks[i].valor);
        printf("    DIFERENCIA CON EL VALOR ANTERIOR: ");
        ColorDiff(stocks[i].diferencia);
        printf("\n");
    }
}

void IngresarStock() {
    if (num_stocks >= MAX_STOCKS) {
        printf("No se pueden agregar más stocks. Límite alcanzado.\n");
        return;
    }

    stock_t nuevo_stock;
    printf("\nIngrese el nombre del nuevo stock: ");
    scanf("%s", nuevo_stock.nombre);
    nuevo_stock.valor = (float)GenerarNumero();
    nuevo_stock.diferencia = 0.0f;
    stocks[num_stocks++] = nuevo_stock;
    printf("Stock agregado exitosamente.\n");
}

int main(void) {
    srand(time(NULL)); 

    while (1) {
        system("clear"); 
        MostrarStocks();

        printf("\n1. INGRESAR\n2. ELIMINAR\n3. SALIR\n");
        printf("Elige una opción: ");
        fflush(stdout);

        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        struct timeval tv = {5, 0};

        int ret = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

        if (ret == 0) {
            for (int i = 0; i < num_stocks; i++) {
                float old_val = stocks[i].valor;
                stocks[i].valor = (float)GenerarNumero();
                stocks[i].diferencia = stocks[i].valor - old_val;
            }
        } else if (ret == 1)
            int opcion;
            if (scanf("%d", &opcion) != 1) {
                while (getchar() != '\n'); 
                continue;
            }

            switch (opcion) {
                case INGRESAR:
                    IngresarStock();
                    break;
                case ELIMINAR:
                    printf("Eliminar stock (función no implementada aún)\n");
                    break;
                case SALIR:
                    printf("Saliendo del programa...\n");
                    exit(0);
                default:
                    printf("Opción no válida.\n");
            }
        } else {
            perror("select");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}