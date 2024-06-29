/* Se desea realizar un programa para calcular el sueldo final a pagar a cada empleado de una empresa. De
cada uno se tiene, sueldo básico, antigüedad, cantidad de hijos y estudios superiores (‘S’ o ‘N’). Además, se
conocen los porcentajes de aumento del sueldo que dependen de los siguientes factores:
• Si el empleado tiene más de 10 años de antigüedad: aumento del 10%
• Si el empleado tiene más de 2 hijos: aumento del 10%, si solo tiene uno 5%
• Si el empleado posee estudios superiores: aumento del 5%
Luego de ingresar los datos de un empleado se debe preguntar si se desea ingresar otro empleado o no. Se
termina la carga cuando no se deseen ingresar más empleados.
Determinar:
a. Por cada empleado: número de empleado, el sueldo básico y el nuevo sueldo.
b. Sueldo nuevo promedio de la empresa. */

#include <stdio.h>

int main() {

  double sueldo_final = 0.00;
  double sueldo_basico;
  int antiguedad;
  int hijos;
  char estudios;
  char indicacion;
  int num_empleado;
  double sueldo_promedio = 0.00;
  int cant_empleados = 0;
  double sueldo_empresa = 0.00;

  // antiguedad > 10 = 1.10
  // hijos > 2 = 1.05
  // estudios S = 1.05 

  do {

    sueldo_final = 0.00;

    printf("Ingrese el número del empleado: ");
    scanf("%d", &num_empleado);
    
    if (num_empleado != 0) {
      ++cant_empleados;
    }

    printf("Ingrese el sueldo básico: ");
    scanf("%lf", &sueldo_basico);
    sueldo_final = sueldo_basico;

    printf("Ingrese la antigüedad en la empresa: ");
    scanf("%d", &antiguedad);

    if (antiguedad > 10) {
      sueldo_final *= 1.10;
    }

    printf("Ingrese la cantidad de hijos que tiene: ");
    scanf("%d", &hijos);

    if (hijos > 2) {
      sueldo_final *= 1.10; 
    } else if (hijos == 1) {
      sueldo_final *= 1.05;
    }

    printf("Indique si cuenta con estudios superiores (S/N): ");
    scanf(" %c", &estudios);

    if (estudios == 'S' || estudios == 's') {
      sueldo_final *= 1.05;
    }

    sueldo_empresa += sueldo_final;

    printf("Datos del empleado Nº%d. Número: %d Sueldo básico: %.2f Sueldo final: %.2f\n", cant_empleados, num_empleado, sueldo_basico, sueldo_final);

    printf("Indique si quiere continuar con el ingreso (S/N): ");
    scanf(" %c", &indicacion);

  } while (indicacion == 'S' || indicacion == 's');   
  
  if (cant_empleados > 0) {
    sueldo_promedio = sueldo_empresa / cant_empleados;
    printf("Sueldo promedio de la empresa: %.2f\n", sueldo_promedio);
  }  else {
    printf("No se ingresaron empleados.\n");
  }

  return 0;
} 
