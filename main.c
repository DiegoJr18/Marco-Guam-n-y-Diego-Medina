#include <stdio.h>
#include "lectu.h"
#include "menu.h"
#include "func.h"

#define MAX_PRODUCTS 100

int main() {
    int numProducts = 0;
    char productos[MAX_PRODUCTS][4][MAX_NAME_LENGTH];

    int opt;
    do {
        opt = menuOpcion(&numProducts, productos);
        switch (opt) {
            case 1:
                createProduct(&numProducts, productos);
                saveDataToFile(numProducts, productos);
                break;
            case 2:
                updateProduct(numProducts, productos);
                break;
            case 3:
                deleteProduct(&numProducts, productos);
                saveDataToFile(numProducts, productos);
                break;
            case 4:
                readProducts(numProducts, productos);
                break;
            case 5:
                printf("Hasta luego !!\n");
                break;
            default:
                printf("Opcion no valida. Por favor, ingrese una opcion correcta.\n");
                break;
        }
    } while (opt != 5);

    return 0;
}