#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    int *arr, *arr2;

    // Paso 1: malloc
    printf("¿Cuántos enteros quiere almacenar con malloc? ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error al reservar memoria con malloc.\n");
        return 1;
    }

    printf("\nValores iniciales con malloc (basura):\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Paso 2: calloc
    printf("\n¿Cuántos enteros quiere almacenar con calloc? ");
    scanf("%d", &n);

    arr2 = (int *)calloc(n, sizeof(int));
    if (arr2 == NULL) {
        printf("Error al reservar memoria con calloc.\n");
        free(arr);
        return 1;
    }

    printf("\nValores iniciales con calloc (ceros):\n");
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // Paso 3: llenar el arreglo arr2
    printf("\nIngrese %d valores para arr2:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("\nValores ingresados en arr2:\n");
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // Paso 4: realloc
    printf("\nIngrese el nuevo tamaño para arr2: ");
    scanf("%d", &m);

    arr2 = (int *)realloc(arr2, m * sizeof(int));
    if (arr2 == NULL) {
        printf("Error al redimensionar memoria con realloc.\n");
        free(arr);
        return 1;
    }

    if (m > n) {
        printf("\nIngrese %d valores adicionales:\n", m - n);
        for (i = n; i < m; i++) {
            scanf("%d", &arr2[i]);
        }
    }

    printf("\nValores finales en arr2:\n");
    for (i = 0; i < m; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    // Paso 5: liberar memoria
    free(arr);
    free(arr2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
