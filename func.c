#include <stdio.h>
#include <string.h>
#include "func.h"
#include "lectu.h"
#include "menu.h"

void createProduct(int* numProducts, char(*productos)[4][50]) {
    static int id = 1;
    int numOfProductsToAdd;
    printf("¿Cuántos productos desea ingresar?: ");
    scanf("%d", &numOfProductsToAdd);

    for (int n = 0; n < numOfProductsToAdd; n++) {
        if (*numProducts < MAX_PRODUCTS) {
            char (*currentProduct)[4][50] = &productos[*numProducts];
            sprintf((*currentProduct)[0], "%d", id);
            printf("Ingrese el nombre del producto: ");
            getchar();
            fgets((*currentProduct)[1], sizeof((*currentProduct)[1]), stdin);
            (*currentProduct)[1][strcspn((*currentProduct)[1], "\n")] = '\0';
            printf("Ingrese la cantidad del producto: ");
            scanf("%s", (*currentProduct)[2]);
            printf("Ingrese el precio del producto: ");
            scanf("%s", (*currentProduct)[3]);
            id++;
            (*numProducts)++;
            printf("Producto agregado correctamente.\n");
        } else {
            printf("No se pueden agregar más productos, límite alcanzado.\n");
            break;
        }
    }
}

void readProducts(int numProducts, char(*productos)[4][50]) {
    if (numProducts == 0) {
        printf("No hay productos para mostrar.\n");
    } else {
        printf("     Listado de productos:\n");
        printf("ID\tNombre\t\t\tCantidad\tPrecio\n");

        char (*currentProduct)[4][50] = productos;

        for (int i = 0; i < numProducts; i++) {
            printf("%s\t%-20s\t%s\t\t$%s\n", (*currentProduct)[0], (*currentProduct)[1], (*currentProduct)[2], (*currentProduct)[3]);
            currentProduct++;
        }
    }
}

void updateProduct(int numProducts, char(*productos)[4][50]) {
    char id[50];
    printf("Ingrese el ID del producto a editar: ");
    scanf("%s", id);

    int indice = -1;
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(productos[i][0], id) == 0) {
            int opcion;
            opcion = menuEdit();
            switch (opcion) {
                case 1:
                    printf("Ingrese el nuevo nombre del producto: ");
                    getchar();
                    fgets(productos[i][1], sizeof(productos[i][1]), stdin);
                    productos[i][1][strcspn(productos[i][1], "\n")] = '\0';
                    printf("Nombre actualizado correctamente.\n");
                    break;
                case 2:
                    printf("Ingrese la nueva cantidad del producto: ");
                    scanf("%s", productos[i][2]);
                    printf("Cantidad actualizada correctamente.\n");
                    break;
                case 3:
                    printf("Ingrese el nuevo precio del producto: ");
                    scanf("%s", productos[i][3]);
                    printf("Precio actualizado correctamente.\n");
                    break;
                default:
                    printf("Opción no válida.\n");
                    break;
            }
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void deleteProduct(int* numProducts, char(*productos)[4][50]) {
    char id[50];
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%s", id);

    int indice = -1;
    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(productos[i][0], id) == 0) {
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        for (int i = indice; i < *numProducts - 1; i++) {
            strcpy(productos[i][0], productos[i + 1][0]);
            strcpy(productos[i][1], productos[i + 1][1]);
            strcpy(productos[i][2], productos[i + 1][2]);
            strcpy(productos[i][3], productos[i + 1][3]);
        }
        (*numProducts)--;
        printf("Producto eliminado correctamente.\n");
    } else {
        printf("Producto no encontrado.\n");
    }
}

void saveDataToFile(int numProducts, char(*productos)[4][50]) {
    FILE* file = fopen("products.txt", "w");
    if (file != NULL) {
        for (int i = 0; i < numProducts; i++) {
            fprintf(file, "%s %s %s %s\n", productos[i][0], productos[i][1], productos[i][2], productos[i][3]);
        }
        fclose(file);
        printf("Datos de producto guardados correctamente en el archivo.\n");
    } else {
        printf("Error al abrir el archivo para escribir.\n");
    }
}

