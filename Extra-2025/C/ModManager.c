#include <stdio.h>
#include <dirent.h>
#include <string.h>

void configft(void);
void save_basegame_files(const char *);
void menu(void);

int main(void){
    FILE *fp;
    fp = fopen("config.txt", "r");
    if (fp == NULL) {
        printf("No se ha encontrado el archivo de configuracion\n");
        Configft();
    } else {
        fclose(fp);
    }
    menu();
    return 0;
}

typedef enum {
    CONFIGURAR = 1,
    INSTALAR_MODS,
    DESINSTALAR_MODS,
    VER_MODS,
    SALIR
} opciones_t;

void menu() {
    int opcion_temp;
    opciones_t op;
    do {
        printf("Menu\n");
        printf("1_Configurar ModManager\n");
        printf("2_Habilitar Mods\n");
        printf("3_Desabilitar Mods\n");
        printf("4_Ver Mods\n");
        printf("5_Salir\n");
        scanf("%d", &opcion_temp);
        op = (opciones_t)opcion_temp;
        while (getchar() != '\n'); 
        switch (op) {
            case CONFIGURAR:
                Configft();
                break;
            case INSTALAR_MODS:
                break;
            case DESINSTALAR_MODS:
                DesactivarMods();
                break;
            case VER_MODS:
                break;
            case SALIR:
                break;
        }
    } while (op != SALIR);
}

void Configft(void){
    char ruta[260];
    printf("Introduzca la ruta al juego (Ej: C:/Games/GtaV): ");
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
        ArchivosJuegoBase(ruta); 
    } else {
        printf("Error al guardar la ruta en config.txt\n");
    }
}

void ArchivosJuegoBase(const char *ruta) {
    DIR *dir;
    struct dirent *entry;
    char fullpath[512];

    FILE *out = fopen("basegame.bin", "ab"); 
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

        DIR *subdir = opendir(fullpath);
        if (subdir) {
            closedir(subdir);
            ArchivosJuegoBase(fullpath);
        } else {
            fprintf(out, "%s\n", fullpath);
        }
    }

    closedir(dir);
    fclose(out);
    printf("Archivos base guardados en basegame.bin\n");
}

void DesactivarMods(void) {
    FILE *fp = fopen("basegame.bin", "rb");
    if (fp == NULL) {
        printf("No se pudo abrir basegame.bin\n");
        return;
    }

    fclose(fp);
    printf("Mods desactivados.\n");
}
