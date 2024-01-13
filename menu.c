#include <stdio.h>
#include "lectu.h"
#include "menu.h"

int menuOpcion(int* numProducts, char(*productos)[4][50]) {
    printf("Bienvenido a LIBSTOCK\nMenú:\n1. Registro de Productos\n2. Actualizar Productos\n3. Eliminar Productos\n4. Listar Productos\n5. Salir\n");
    int opt = leerEnteroEntre("Ingrese Opcion: ", 1, 5);
    return opt;
}

int menuEdit() {
    printf("Sel el campo a editar:\n1. Nombre\n2. Cantidad\n3. Precio\n4. Cancelar\n");
    int opt = leerEnteroEntre("Ingrese Opcion: ", 1, 4);
    return opt;
}