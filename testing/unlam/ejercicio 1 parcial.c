#include <stdio.h>

// Prototipos de funciones
int validarIngreso(int numero);
int esNegativo(int numero);
float promedioPositivos(int sumaPositivos, int contadorPositivos);
int menorValor(int valores[], int cantidadValores);

int main() {
    int numero;
    int cantidadNegativos = 0;
    int sumaPositivos = 0;
    int contadorPositivos = 0;
    int cantidadTotal = 0;
    int valores[100]; // Arreglo para almacenar todos los valores
    int contadorValores = 0;

    // Lectura de números y procesamiento
    printf("Ingrese un número entre -50 y 50 (-100 para terminar):\n");
    while (1) {
        scanf("%d", &numero);
        if (numero == -100) {
            break;
        }

        // Validar el ingreso
        if (!validarIngreso(numero)) {
            printf("Número fuera de rango. Ingrese otro número:\n");
            continue;
        }

        // Conteo de números negativos
        if (esNegativo(numero)) {
            cantidadNegativos++;
        }

        // Suma y conteo de números positivos
        if (numero > 0) {
            sumaPositivos += numero;
            contadorPositivos++;
        }

        // Almacenar el número en el arreglo
        valores[contadorValores] = numero;
        contadorValores++;
    }

    // Calcular promedio de números positivos
    float promedioPos = promedioPositivos(sumaPositivos, contadorPositivos);

    // Calcular promedio de todos los números ingresados sin incluir -100
    float promedioTotal = promedioPositivos(sumaPositivos, contadorValores);

    // Encontrar el menor valor ingresado y su orden de ingreso
    int menor = menorValor(valores, contadorValores);

    // Mostrar resultados
    printf("\nCantidad de números negativos: %d\n", cantidadNegativos);
    printf("Promedio de números positivos: %.2f\n", promedioPos);
    printf("Promedio de todos los números ingresados sin incluir -100: %.2f\n", promedioTotal);
    printf("Menor valor ingresado: %d\n", menor);

    return 0;
}

// Función para validar el ingreso dentro del rango permitido (-50 a 50)
int validarIngreso(int numero) {
    return (numero >= -50 && numero <= 50);
}

// Función para determinar si un número es negativo
int esNegativo(int numero) {
    return (numero < 0);
}

// Función para calcular el promedio de los números positivos
float promedioPositivos(int sumaPositivos, int contadorPositivos) {
    if (contadorPositivos > 0) {
        return (float) sumaPositivos / contadorPositivos;
    } else {
        return 0; // En caso de que no haya números positivos
    }
}

// Función para encontrar el menor valor ingresado y su orden de ingreso
int menorValor(int valores[], int cantidadValores) {
    int menor = valores[0];
    for (int i = 1; i < cantidadValores; i++) {
        if (valores[i] < menor) {
            menor = valores[i];
        }
    }
    return menor;
}
