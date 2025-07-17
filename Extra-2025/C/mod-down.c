#include <stdio.h>
#include <curl/curl.h>
#include <json-c/json.h>
void crearinstancias(void);
void mostrarinstancias(FILE *fp);

int main(void) {
    system("cls");
    FILE *fp;
    fp = fopen("instancias.json", "r");
    if (fp == NULL) {
        printf("No se han encontrado instancias\n");
        crearinstancias();
    } else {
        printf("Seleccione una instancia: \n");
        mostrarinstancias(fp);
    }
    return 0;
}

void crearinstancias(void) {
    char nombre[100];
    char version[20];
    int modloader;
    FILE *fp = fopen("instancias.json", "w");
    if (fp == NULL) {
        printf("Error al crear instancias.txt\n");
        return;
    }
    printf("Ingrese un nombre para la instancia: ");
    scanf("%99s", nombre);
    printf("Ingrese la version: ");
    scanf("%99s", version);
    printf("Seleccione el modloader (si es necesario):\n");
    printf("1. Fabric\n");
    printf("2. Forge\n");
    printf("3. Quilt\n");
    printf("4. No usar modloader\n");
    scanf("%d", &modloader);
    if (modloader < 1 || modloader > 4) {
        printf("Opción inválida.\n");
        fclose(fp);
        return;
    }
    struct json_object *root_obj = json_object_new_object();
    if (root_obj == NULL) {
        printf("Error al crear el objeto JSON raíz\n");
        fclose(fp);
        return;
    }
    struct json_object *details_obj = json_object_new_object();
    json_object_object_add(details_obj, "version_mc", json_object_new_string(version));
    json_object_object_add(details_obj, "modloader", json_object_new_int(modloader));
    json_object_object_add(root_obj, nombre, details_obj);
    const char *json_string = json_object_to_json_string_ext(root_obj, JSON_C_TO_STRING_PRETTY);
    fprintf(fp, "%s\n", json_string);
    fclose(fp);
    json_object_put(root_obj); 
    printf("Instancia creada exitosamente.\n");
}

void mostrarinstancias(FILE *fp) {
    char buffer[1024];
    struct json_object *root_obj;
    fread(buffer, sizeof(buffer), 1, fp);
    fclose(fp);
    struct json_object *root = json_tokener_parse(buffer);
    if (root == NULL) {
        fprintf(stderr, "Error: El archivo no contiene un JSON valido.\n");
        return;
    }
    printf("Instancias encontradas:\n");
    printf("----------------------\n");
    json_object_object_foreach(root, key, val) {
        printf(" - %s\n", key);
    }
    printf("----------------------\n");
    json_object_put(root);
}