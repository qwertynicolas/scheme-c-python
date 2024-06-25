/* Ejercicio 1: Calculadora de Área y Perímetro

Crea un programa que calcule el área y el perímetro de diferentes figuras geométricas. El programa debe mostrar un menú para que el usuario elija la figura (círculo, rectángulo, triángulo) y luego ingresar las dimensiones necesarias.
Requisitos:

    Crear una función para mostrar el menú y retornar la opción elegida.
    Crear funciones para calcular el área y el perímetro de cada figura.
    Validar la entrada del usuario para asegurarse de que las dimensiones sean positivas. */

#include <stdio.h>
#include <math.h>

int mostar_menu() {
    int opcion;

    do {
        printf("Menú de Figuras\n");
        printf("----- -- -----\n");
        printf("1) Círculo\n");
        printf("2) Rectángulo\n");
        printf("3) Triángulo\n");
        printf("4) Salir del menú\n");
        printf("----- -- -----\n");
        printf("Ingrese la opción deseada: ");
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 4) {
            printf("La opción no es válida.\n");
        }

    } while (opcion < 1 || opcion > 4);

    return opcion;
}
// funciones de cálculo
double perimetroCirculo (double radio) { 
    return 2 * M_PI * radio;
}

double areaCirculo (double radio) {
    return M_PI * radio * radio;
}

double perimetroRectangulo (double base, double altura) {
    return 2 * (base + altura);
}

double areaRectangulo (double base, double altura) {
    return base * altura;
}

double areaTriangulo (double base, double altura) {
    return (base * altura) / 2;
}

double perimetroTriangulo (double lado1, double lado2, double lado3) {
    return lado1 + lado2 + lado3;
}

int main() {

    int opcion;
    double radio, base, altura, lado1, lado2, lado3;
 
    while(1) { // bucle infinito

    opcion = mostar_menu();

    switch(opcion) { //switch case para todas las figuras geométricas posibles
        case 1 :
        printf("Ingrese el radio de la circunferencia: ");
        scanf("%lf", &radio);
        printf("Área del círculo: %.2f\n", areaCirculo(radio));
        printf("Perímetro del círculo: %.2f\n", perimetroCirculo(radio));
        break;
        case 2 : 
        printf("Ingrese la base del rectángulo: ");
        scanf("%lf", &base);
        printf("Ingrese la alutra del rectángulo: ");
        scanf("%lf", &altura);
        printf("Área del rectángulo: %.2f\n", areaRectangulo(base, altura));
        printf("Perímetro del rectángulo: %.2f\n", perimetroRectangulo(base, altura));
        break;
        case 3 : 
        printf("Ingrese la base del triángulo: ");
        scanf("%lf", &base);
        printf("Ingrese la altura del triángulo: ");
        scanf("%lf", &altura);
        printf("Ingrese el primer lado del triángulo: ");
        scanf("%lf", &lado1);
        printf("Ingrese el segundo lado del triángulo: ");
        scanf("%lf", &lado2);
        printf("Ingrese el tercer lado del triángulo: ");
        scanf("%lf", &lado3);
        printf("Perímetro del triángulo: %.2f\n", perimetroTriangulo(lado1, lado2, lado3));
        printf("Área del triángulo: %.2f\n", areaTriangulo(base, altura));
        break;
        case 4 :
        printf("Saliendo del menu...\n");
        return 0;

    } 

    printf("Presione Enter para continuar...\n");
    getchar();
    getchar();

    }

    return 0;
}