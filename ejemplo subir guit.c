#include <stdio.h>

#define MAX_LONGITUD_FRASE 1000

// Función para contar palabras y determinar longitudes máximas y mínimas
void procesarFrase(const char *frase, int *num_palabras, int *max_longitud, int *min_longitud) {
    int longitud_actual = 0;
    *num_palabras = 0;
    *max_longitud = 0;
    *min_longitud = MAX_LONGITUD_FRASE;

    for (int i = 0; frase[i] != '\0'; i++) {
        if (frase[i] != ' ' && frase[i] != '\n') {
            longitud_actual++;
        } else if (longitud_actual > 0) {
            (*num_palabras)++;
            if (longitud_actual > *max_longitud) {
                *max_longitud = longitud_actual;
            }
            if (longitud_actual < *min_longitud) {
                *min_longitud = longitud_actual;
            }
            longitud_actual = 0;
        }
    }

    if (longitud_actual > 0) {
        (*num_palabras)++;
        if (longitud_actual > *max_longitud) {
            *max_longitud = longitud_actual;
        }
        if (longitud_actual < *min_longitud) {
            *min_longitud = longitud_actual;
        }
    }
}

// Función para imprimir resultados
void imprimirResultados(int num_palabras, int max_longitud, int min_longitud) {
    printf("\nResultados:\n");
    printf("Numero de palabras: %d\n", num_palabras);
    if (num_palabras > 0) {
        printf("Longitud de la palabra mas larga: %d\n", max_longitud);
        printf("Longitud de la palabra mas corta: %d\n", min_longitud);
    } else {
        printf("No se encontraron palabras.\n");
    }
}

int main() {
    char frase[MAX_LONGITUD_FRASE];
    int num_palabras, max_longitud, min_longitud;

    // Solicitar al usuario ingresar una frase
    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Procesar la frase
    procesarFrase(frase, &num_palabras, &max_longitud, &min_longitud);

    // Imprimir resultados
    imprimirResultados(num_palabras, max_longitud, min_longitud);

    return 0;
}
