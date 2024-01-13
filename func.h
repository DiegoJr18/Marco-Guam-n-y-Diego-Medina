#ifndef FUNC_H
#define FUNC_H

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50 
#define MAX_CARACTERS 50

void createProduct(int*, char(*)[4][MAX_NAME_LENGTH]);
void updateProduct(int, char(*)[4][MAX_NAME_LENGTH]);
void deleteProduct(int*, char(*)[4][MAX_NAME_LENGTH]);
void readProducts(int, char(*)[4][MAX_NAME_LENGTH]);
void saveDataToFile(int, char(*)[4][MAX_NAME_LENGTH]);


#endif