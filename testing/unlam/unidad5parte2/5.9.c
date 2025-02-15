#include <stdio.h>

int main (void)
{
    float sueldoFinal, sueldoBasico, sueldoPromedio;
    int antiguedad, hijos, numero;
    char estudios, seguir;
    int cantEmpleados = 0;

    sueldoFinal = sueldoBasico = sueldoPromedio = 0.0;

    do {
        printf("Ingrese el número del empleado: ");
        scanf("%d", &numero);

        printf("Ingrese el sueldo básico: ");
        scanf("%f", &sueldoBasico);

        sueldoFinal = sueldoBasico;

        printf("Ingrese la antigüedad del empleado: ");
        scanf("%d", &antiguedad);

        if (antiguedad >= 10) {
            sueldoFinal *= 1.10;
        }

        printf("Ingrese la cantidad de hijos del empleado: ");
        scanf("%d", &hijos);

        switch(hijos) {
            case 0:
                sueldoFinal += 0;
                break;
            case 1:
                sueldoFinal *= 1.05;
                break;
            default:
                sueldoFinal *= 1.10;
        }

        printf("Estudios superiores del empleado (S ó N): ");
        scanf(" %c", &estudios);

        while (estudios != 'S' && estudios != 'N') {
            printf("Valor no válido. Intente nuevamente: ");
            scanf(" %c", &estudios);
        }

        if (estudios == 'S') {
            sueldoFinal *= 1.05;
        }

        printf("Numero de empleado: %d\n", numero);
        printf("Sueldo básico: %.2f\n", sueldoBasico);
        printf("Sueldo final: %.2f\n", sueldoFinal);
        ++cantEmpleados;
        sueldoPromedio += sueldoFinal;

        printf("Desea seguir ingresando más empleados? (S ó N): ");
        scanf(" %c", &seguir);

    } while (seguir != 'N');

    sueldoPromedio /= cantEmpleados;

    printf("Sueldo promedio de la empresa: %.2f", sueldoPromedio);

    return 0;
}
