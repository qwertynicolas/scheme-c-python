/* Se ingresan datos de los empleados de una empresa. Por cada empleado se ingresa:  
• Legajo (entero entre 1000 y 5000) 
• Sueldo básico (float mayor a 1000) 
• Antigüedad en años (mayor o igual a 0) 
• Sexo (‘M' o 'F') 
• Categoría (entero entre 1 a 5) 
Por cada empleado ingresado se debe calcular el sueldo final a abonar sabiendo que: 
• Las Categorías 2 y 3 tienen $500 de bonificación. 
• La Categoría 4 tiene 10% de bonificación. 
• La Categoría 5 tiene 30% de bonificación. 
• Si la antigüedad es mayor a 10 años recibe una bonificación del 10% adicional. 
Todos los datos ingresados deben ser validados. El ingreso finaliza con un legajo igual a cero. 
Informar: 
• El sueldo a abonar a cada empleado. 
• Cantidad de empleados de más de 10 años de antigüedad. 
• El mayor sueldo y el legajo del empleado que cobra dicho sueldo. 
• Cantidad de hombres y de mujeres */

#include <stdio.h>

int main() {

    int legajo;
    float sueldo;
    int antiguedad;
    char sexo;
    int categoria;
    int empleados10 = 0; // 10 años de antiguedad;
    int hombres = 0, mujeres = 0; 
    float mayorSueldo = -20000.00;
    int legajoMayor;
    float sueldoFinal;

    do {

        printf("Ingrese el legajo del empleado (1000 a 5000 o 0 si desea finalizar): ");
        scanf("%d", &legajo);

        if (legajo == 0) {
            break;
        }

        if (legajo < 1000 || legajo > 5000) {
            printf("No es un valor válido.\n");
            continue;
        }
 
        printf("Ingrese el sueldo del empleado: ");
        scanf("%f", &sueldo);
        sueldoFinal = sueldo;

        if (sueldo < 1000) {
            printf("No es un valor válido.\n");
            continue;
        }

        printf("Ingrese la antigüedad del empleado: ");
        scanf("%d", &antiguedad);

        if (antiguedad < 0) {
            printf("No es un valor válido.\n");
            break;
        }

        if (antiguedad > 10) {
            ++empleados10;
            sueldoFinal *= 1.10;
        }

        printf("Ingrese el género del empleado (M o F): ");
        scanf(" %c", &sexo);

        if (sexo == 'M' || sexo == 'm') {
            ++hombres;
        } else if (sexo == 'F' || sexo == 'f') {
            ++mujeres;
        } else {
            printf("No es un valor válido.\n");
            continue;
        }


        printf("Ingrese la categoría del empleado (1 a 5): ");
        scanf("%d", &categoria);

        if (categoria < 1 || categoria > 5) {
            printf("No es un valor válido.\n");
            continue;
        }

        if (categoria == 2 || categoria == 3) {
            sueldoFinal += 500;
        } else if (categoria == 4) {
            sueldoFinal *= 1.10;
        } else if (categoria == 5) {
            sueldoFinal *= 1.30;
        }

        if (sueldoFinal > mayorSueldo) {
            mayorSueldo = sueldoFinal;
            legajoMayor = legajo;
        }

        printf("\nEl sueldo a abonar del empleado con legajo %d es %.2f\n", legajo, sueldoFinal);
        printf("\n");
        
    } while (legajo != 0);

    printf("\nCantidad de empleados de 10 años de antiguüedad: %d\n", empleados10);
    printf("Mayor sueldo: %.2f. Legajo del empleado: %d\n", mayorSueldo, legajoMayor);
    printf("Cantidad de hombres: %d. Cantidad de mujeres: %d\n", hombres, mujeres);

    return 0;
}