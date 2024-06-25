#include <stdio.h>
#include <stdlib.h>

// Función para mostrar el menú y retornar la opción elegida
int mostrar_menu(int num1, int num2) {
    int opcion;
    // Bucle para asegurar que se elija una opción válida
    do {
        // Mostrar el menú con los números actuales
        printf("\nMenú de Opciones\n");
        printf("---- -- --------\n");
        printf("Numero 1: %d Numero 2: %d\n", num1, num2);
        printf("1) Sumar\n");
        printf("2) Restar\n");
        printf("3) Multiplicar\n");
        printf("4) Dividir\n");
        printf("5) Ingresar Nuevos Números\n");
        printf("6) Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        // Validar que la opción esté en el rango correcto
        if (opcion < 1 || opcion > 6) {
            printf("Opción no válida. Por favor, intente de nuevo.\n");
        }
    } while (opcion < 1 || opcion > 6); // Repetir hasta que la opción sea válida

    // Devolver la opción elegida al programa principal
    return opcion;
}

int main() {
    int num1, num2, opcion;
    double resultado;

    // Ingreso inicial de los números
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    while (1) { // Bucle infinito para mantener el programa en ejecución hasta que el usuario elija salir
        opcion = mostrar_menu(num1, num2); // Llamar a la función mostrar_menu y capturar la opción elegida

        // Switch para manejar cada opción del menú
        switch (opcion) {
            case 1:
                resultado = num1 + num2;
                printf("Resultado de la suma: %d + %d = %.2f\n", num1, num2, resultado);
                break;
            case 2:
                resultado = num1 - num2;
                printf("Resultado de la resta: %d - %d = %.2f\n", num1, num2, resultado);
                break;
            case 3:
                resultado = num1 * num2;
                printf("Resultado de la multiplicación: %d * %d = %.2f\n", num1, num2, resultado);
                break;
            case 4:
                if (num2 == 0) {
                    printf("No se puede dividir por cero.\n");
                } else {
                    resultado = (double) num1 / num2;
                    printf("Resultado de la división: %d / %d = %.2f\n", num1, num2, resultado);
                }
                break;
            case 5:
                printf("Ingrese el primer número: ");
                scanf("%d", &num1);
                printf("Ingrese el segundo número: ");
                scanf("%d", &num2);
                break;
            case 6:
                printf("Saliendo del programa...\n");
                return 0;
        }

        // Esperar a que el usuario presione una tecla para continuar
        printf("Presione Enter para continuar...\n");
        getchar(); // Capturar el \n dejado por scanf
        getchar(); // Esperar a que el usuario presione Enter
    }

    return 0;
}
