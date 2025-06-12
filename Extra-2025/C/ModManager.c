#include <stdio.h>
#include <dirent.h>
#include <string.h>

void configft(void);
void save_basegame_files(const char *);

int main(void){
    FILE *fp;
    fp = fopen("config.txt", "r");
    if (fp == NULL) {
        configft();
    } else {
        fclose(fp);
    }
    return 0;
}

void configft(void){
    char ruta[260];
    printf("No se ha encontrado el archivo de configuracion\nIntroduzca la ruta al juego (Ej: C:/Games/GtaV): ");
    scanf("%259s", ruta);
    getchar();
    printf("Ruta ingresada: %s\n", ruta);
    FILE *fp = fopen("config.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "%s\n", ruta);
        fclose(fp);
        printf("Ruta guardada en config.txt\n");
        printf("Para el siguiente paso, debera remover los mods instalados (Si no tiene ninguno instalado prosiga)\nEste programa recordara los archivos principales del Juego\n");
        getchar();    
        save_basegame_files(ruta); 
    } else {
        printf("Error al guardar la ruta en config.txt\n");
    }
    printf("Para el siguiente paso, debera remover los mods instalados (Si no tiene ninguno instalado prosiga)\nEste programa recordara los archivos principales del Juego");
}

void save_basegame_files(const char *ruta) {
    DIR *dir;
    struct dirent *entry;
    char fullpath[512];

    FILE *out = fopen("basegame.bin", "wb");
    if (!out) {
        printf("No se pudo crear basegame.bin\n");
        return;
    }

    dir = opendir(ruta);
    if (!dir) {
        printf("No se pudo abrir el directorio: %s\n", ruta);
        fclose(out);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        snprintf(fullpath, sizeof(fullpath), "%s/%s", ruta, entry->d_name);
        fprintf(out, "%s\n", fullpath);
    }

    closedir(dir);
    fclose(out);
    printf("Archivos base guardados en basegame.bin\n");
}