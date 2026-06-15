#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char codigo[20];
    char nombre[50];
    char marca[30];
    char responsable[50];
    char estado[20];
    float precio;
} Equipo;

void registrarEquipo() {
    FILE *archivo = fopen("equipos.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir archivo\n");
        return;
    }

    Equipo e;

    printf("Codigo: ");
    scanf("%s", e.codigo);

    printf("Nombre: ");
    scanf(" %[^\n]", e.nombre);

    printf("Marca: ");
    scanf(" %[^\n]", e.marca);

    printf("Responsable: ");
    scanf(" %[^\n]", e.responsable);

    printf("Estado: ");
    scanf(" %[^\n]", e.estado);

    printf("Precio: ");
    scanf("%f", &e.precio);

    fprintf(archivo, "%s|%s|%s|%s|%s|%.2f\n",
        e.codigo, e.nombre, e.marca, e.responsable, e.estado, e.precio);

    fclose(archivo);

    printf("Equipo registrado con exito\n");
}

void mostrarEquipos() {
    FILE *archivo = fopen("equipos.txt", "r");

    if (archivo == NULL) {
        printf("No hay equipos registrados\n");
        return;
    }

    Equipo e;

    printf("\n===== LISTA DE EQUIPOS =====\n");

    while (fscanf(archivo, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f\n",
        e.codigo,
        e.nombre,
        e.marca,
        e.responsable,
        e.estado,
        &e.precio) != EOF) {

        printf("\n----------------------\n");
        printf("Codigo: %s\n", e.codigo);
        printf("Nombre: %s\n", e.nombre);
        printf("Marca: %s\n", e.marca);
        printf("Responsable: %s\n", e.responsable);
        printf("Estado: %s\n", e.estado);
        printf("Precio: %.2f\n", e.precio);
    }

    fclose(archivo);
}

void buscarEquipo() {
    FILE *archivo = fopen("equipos.txt", "r");

    if (archivo == NULL) {
        printf("No hay equipos registrados\n");
        return;
    }

    char codigoBuscado[20];
    Equipo e;
    int encontrado = 0;

    printf("Ingrese codigo del equipo: ");
    scanf("%s", codigoBuscado);

    while (fscanf(archivo, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f\n",
        e.codigo,
        e.nombre,
        e.marca,
        e.responsable,
        e.estado,
        &e.precio) != EOF) {

        if (strcmp(e.codigo, codigoBuscado) == 0) {
            printf("\n===== EQUIPO ENCONTRADO =====\n");
            printf("Codigo: %s\n", e.codigo);
            printf("Nombre: %s\n", e.nombre);
            printf("Marca: %s\n", e.marca);
            printf("Responsable: %s\n", e.responsable);
            printf("Estado: %s\n", e.estado);
            printf("Precio: %.2f\n", e.precio);

            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No existe ese equipo\n");
    }

    fclose(archivo);
}

void modificarEquipo() {
    FILE *archivo = fopen("equipos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (archivo == NULL || temp == NULL) {
        printf("Error al abrir archivos\n");
        return;
    }

    char codigoBuscado[20];
    Equipo e;
    int encontrado = 0;

    printf("Ingrese codigo a modificar: ");
    scanf("%s", codigoBuscado);

    while (fscanf(archivo, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f\n",
        e.codigo, e.nombre, e.marca, e.responsable, e.estado, &e.precio) != EOF) {

        if (strcmp(e.codigo, codigoBuscado) == 0) {
            printf("\nNuevo nombre: ");
            scanf(" %[^\n]", e.nombre);

            printf("Nueva marca: ");
            scanf(" %[^\n]", e.marca);

            printf("Nuevo responsable: ");
            scanf(" %[^\n]", e.responsable);

            printf("Nuevo estado: ");
            scanf(" %[^\n]", e.estado);

            printf("Nuevo precio: ");
            scanf("%f", &e.precio);

            encontrado = 1;
        }

        fprintf(temp, "%s|%s|%s|%s|%s|%.2f\n",
            e.codigo, e.nombre, e.marca, e.responsable, e.estado, e.precio);
    }

    fclose(archivo);
    fclose(temp);

    remove("equipos.txt");
    rename("temp.txt", "equipos.txt");

    if (encontrado)
        printf("Equipo modificado\n");
    else
        printf("No se encontró el equipo\n");
}

void eliminarEquipo() {
    FILE *archivo = fopen("equipos.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (archivo == NULL || temp == NULL) {
        printf("Error al abrir archivos\n");
        return;
    }

    char codigoBuscado[20];
    Equipo e;
    int encontrado = 0;

    printf("Ingrese codigo a eliminar: ");
    scanf("%s", codigoBuscado);

    while (fscanf(archivo, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f\n",
        e.codigo, e.nombre, e.marca, e.responsable, e.estado, &e.precio) != EOF) {

        if (strcmp(e.codigo, codigoBuscado) == 0) {
            encontrado = 1;
            continue;
        }

        fprintf(temp, "%s|%s|%s|%s|%s|%.2f\n",
            e.codigo, e.nombre, e.marca, e.responsable, e.estado, e.precio);
    }

    fclose(archivo);
    fclose(temp);

    remove("equipos.txt");
    rename("temp.txt", "equipos.txt");

    if (encontrado)
        printf("Equipo eliminado\n");
    else
        printf("No existe ese equipo\n");
}

int main() {
    int opcion;

    do {
        printf("\n===== SISTEMA CONTROL EQUIPOS =====\n");
        printf("1. Registrar equipo\n");
        printf("2. Mostrar equipos\n");
        printf("3. Buscar equipo\n");
        printf("4. Modificar equipo\n");
        printf("5. Eliminar equipo\n");
        printf("6. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                registrarEquipo();
                break;
            case 2:
                mostrarEquipos();
                break;
            case 3:
                buscarEquipo();
                break;
            case 4:
                modificarEquipo();
                break;
            case 5:
                eliminarEquipo();
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }

    } while(opcion != 6);
    return 0;
}// version final
