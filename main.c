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
                printf("Registrar equipo (fase siguiente)\n");
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