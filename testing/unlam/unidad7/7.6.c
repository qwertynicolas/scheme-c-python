#include <stdio.h>
#define EMPLEADOS 100
#define SECTORES 5
#define TERMINAR 99

void sueldoEmpresa (float sueldo) {
    if (sueldo < 0) {
        printf("No se ingresaron sueldos válidos.\n");
    } else {
        printf("\nImporte total a pagar de sueldos: %.2f\n", sueldo);
    }
}
void cuentaSector (int empleados[])
{
    int i;

    for (i = 0; i < SECTORES; ++i) {
        printf("Sector: %d. Empleados: %d.\n", i+1, empleados[i]);
    }
}

void cargaEmpleados (int empleados[])
{
    int sector;
    float sueldo, sueldoTotal = 0.0;
    int dni, limite = 0;

    printf("Ingrese el D.N.I del empleado: ");
    scanf("%d", &dni);

    while (dni != TERMINAR && limite != EMPLEADOS) {

        printf("Código del sector (1 - %d): ", SECTORES);
        scanf("%d", &sector);

        while (sector < 0 || sector > 5) {
            printf("El código del sector no es válido. Intente nuevamente: ");
            scanf("%d", &sector);
        }

        printf("Ingrese el sueldo del empleado: ");
        scanf("%f", &sueldo);

        sueldoTotal += sueldo;
        ++limite;
        ++empleados[sector-1];

        printf("Ingrese el D.N.I de un nuevo empleado o %d si desea finalizar: ", TERMINAR);
        scanf("%d", &dni);
    }

    printf("\n");
    cuentaSector(empleados);
    sueldoEmpresa(sueldoTotal);
}



int main (void)
{
    int empleados [SECTORES] = {0, 0, 0, 0, 0};

    cargaEmpleados(empleados);

    return 0;
}
