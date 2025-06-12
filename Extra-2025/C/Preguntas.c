#include <stdio.h>
#include <string.h>

// todavia no se puede responder (sssssssssssssss)

int main(void) {
    FILE *file = fopen("questions.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    // mientras que fgets no devuelva NULL, es decir, haya líneas en el archivo
    // fgets lee una línea del archivo y la guarda en la variable line
    // si no hay más líneas, fgets devuelve NULL
    while (fgets(line, sizeof(line), file)) {
        // esto divide la linea que se lee en partes, cada parte esta delimitada por los /.
        char *token = strtok(line, "/");
        int option_number = 1;
        // hasta que token se quede sin partes delimitadas, hace lo del while.
        while (token != NULL) {
            if (option_number == 1) {
                printf("Pregunta: %s\n", token);
            } else {
                printf("%d - %s\n", option_number - 1, token);
            }
            token = strtok(NULL, "/");
            option_number++;
        }
    }

    fclose(file);
    return 0;
}