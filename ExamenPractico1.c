#include <stdio.h>
#include <stdlib.h>

int main() {
    float *calificacion = NULL;
    int n = 0;               // Número de estudiantes
    int nuevo_tamano = 0;    // Nuevo tamaño en caso de añadir más estudiantes
    float suma = 0.0;
    char continuar = 's';

    // Ciclo principal del programa
    while (continuar == 's' || continuar == 'S') {
        printf("¿Cuántos estudiantes deseas registrar? ");
        int nt;
        scanf("%d", &nt);
        nuevo_tamano = nt;

        // si hay estudiantes registrados, ampliar el arreglo con realloc
        if (n > 0) {
            float *temp = realloc(calificacion, (n + nt) * sizeof(float));
            if (temp == NULL) {
                printf("Error al ampliar la memoria.\n");
                free(calificacion);
                return 1;
            }
            calificacion = temp;
        } else {
            // Primer registro con malloc
            calificacion = (float *)malloc(nt * sizeof(float));
            if (calificacion == NULL) {
                printf("Error al asignar memoria.\n");
                return 1;
            }
        }

        // Capturar nuevas calificaciones
        for (int i = 0; i < nt; i++) {
            printf("Calificación del estudiante %d: ", n + i + 1);
            scanf("%f", &calificacion[n + i]);
            suma += calificacion[n + i];
        }

        n += nt; // Actualizar el numero de estudiantes

        // Mostrar todas las calificaciones
        printf("\nCalificaciones registradas:\n");
        for (int i = 0; i < n; i++) {
            printf("Estudiante %d: %.2f\n", i + 1, calificacion[i]);
        }

        // Calcular del promedio general y preguntar si desea continuar
        printf("Promedio general: %.2f\n", suma / n);

        printf("\n¿Deseas agregar más estudiantes? (s/n): ");
        scanf(" %c", &continuar);
    }

    // Liberar memoria al final
    free(calificacion);
    printf("\nPrograma finalizado. Memoria liberada correctamente.\n");
    return 0;
}
