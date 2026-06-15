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
                printf("Mostrar equipos (fase siguiente)\n");
                break;
            case 3:
                printf("Buscar equipo (fase siguiente)\n");
                break;
            case 4:
                printf("Modificar equipo (fase siguiente)\n");
                break;
            case 5:
                printf("Eliminar equipo (fase siguiente)\n");
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }

    } while(opcion != 6);
    return 0;
}