#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day;
    int month;
    int year;
} Fecha;

typedef struct {
    Fecha fecha;
    int codigo;
    float importe;
    float monthYearImporte[12][10];
    int monthYearVentas[12][10];
} Registro;

void mostrar(FILE *);
Registro initializeToZero(Registro);

int main(void)
{
    FILE *pf;
    Registro registro;
    char cargar, modo;
    int codigoTemp;
    int yearTemp;
    int monthTemp;

    printf("¿Desea crear/sobreescribir el archivo ventas.dat? (S/N): ");
    scanf(" %c", &cargar);

    if (cargar == 'S' || cargar == 's') {
        printf("Seleccione el modo (A | W): ");
        scanf(" %c", &modo);

    switch(modo) {
        case 'A':
        case 'a':
            pf = fopen("ventas.dat", "ab");
            if (pf == NULL) {
                printf("Error al abrir el archivo.\n");
                getchar();
                exit(1);
            }
            break;
        case 'W':
        case 'w':
            pf = fopen("ventas.dat", "wb");
            registro = initializeToZero(registro);
            if (pf == NULL) {
                printf("Error al abrir el archivo.\n");
                getchar();
                exit(1);
            }
            break;
        default:
            printf("Modo no válido. Finalizando programa...");
            getchar();
            exit(1);
    }

    printf("Ingrese el código del producto: ");
    scanf("%d", &codigoTemp);

    while (codigoTemp != 0) {
        registro.codigo = codigoTemp;

        printf("Ingrese la fecha de la venta: ");
        scanf("%d %d %d", &registro.fecha.day, &registro.fecha.month, &registro.fecha.year);

        while (registro.fecha.day < 1 || registro.fecha.day > 31) {
            printf("El día ingresado no es válido. Intente nuevamente: ");
            scanf("%d", &registro.fecha.day);
        }

        while (registro.fecha.month < 1 || registro.fecha.month > 12) {
            printf("El mes ingresado no es válido. Intente nuevamente: ");
            scanf("%d", &registro.fecha.month);
        }

        monthTemp = registro.fecha.month - 1;

        while (registro.fecha.year < 2014 || registro.fecha.year > 2023) {
            printf("El año no es válido (de 2014 a 2023). Intente nuevamente: ");
            scanf("%d", &registro.fecha.year);
        }

        yearTemp = registro.fecha.year - 2014;

        printf("Ingrese el importe de la venta: ");
        scanf("%f", &registro.importe);

        while (registro.importe < 0) {
            printf("El importe ingresado no es válido. Intente nuevamente: ");
            scanf("%f", &registro.importe);
        }

        registro.monthYearImporte[monthTemp][yearTemp] += registro.importe;
        registro.monthYearVentas[monthTemp][yearTemp]++;

        fwrite(&registro, sizeof(Registro), 1, pf);

        printf("Ingrese un nuevo código o 0 si desea finalizar: ");
        scanf("%d", &codigoTemp);
    }
    }

    if (cargar == 'S' || cargar == 's') {
        fclose(pf);
    }

    pf = fopen("ventas.dat", "rb");
    if (pf == NULL) {
        printf("Error al abrir el archivo.\n");
        getchar();
        exit(1);
    }

    mostrar(pf);

    return 0;
}

void mostrar(FILE *pf)
{
    Registro registro, temp;
    int vista;
    int year1, year2;
    int i, j;
    int month, year;

    registro = initializeToZero(registro);

    fread(&temp, sizeof(Registro), 1, pf);

    while(!feof(pf)) {
        month = temp.fecha.month - 1;
        year = temp.fecha.year - 2014;

        registro.monthYearImporte[month][year] += temp.importe;
        registro.monthYearVentas[month][year]++;

        fread(&temp, sizeof(Registro), 1, pf);
    }

    printf("Seleccione el intervalo de años: ");
    scanf("%d %d", &year1, &year2);

    while (year1 >= year2 || year1 < 2014 || year1 > 2023 || year2 < 2014 || year2 > 2023) {
        printf("Error al ingresar los años. Intente nuevamente: ");
        scanf("%d %d", &year1, &year2);
    }

    year1 -= 2014;
    year2 -= 2014;

    if (year1 < 0 || year2 > 9 || year1 > year2) {
        printf("Rango no válido. Finalizando programa...\n");
        getchar();
        exit(1);
    }

    printf("Seleccione el modo de vista (1 - Cantidad de ventas | 2 - Importe mes/año): ");
    scanf("%d", &vista);

    while (vista < 0 || vista > 2) {
        printf("El modo ingresado no es válido. Intente de nuevo: ");
        scanf("%d", &vista);
    }

    while(vista != 0) {
        if (vista == 1) {
            printf("\t%5s | %5s | %5s | %5s | %5s | %5s | %5s | %5s | %5s | %5s | %5s | %5s\n", "Mes 1", "Mes 2", "Mes 3", "Mes 4",
                   "Mes 5", "Mes 6", "Mes 7", "Mes 8", "Mes 9", "Mes 10", "Mes 11", "Mes 12");
            for (j = year1; j <= year2; j++) {
                printf("%d\t ", j+2014);
                for (i = 0; i < 12; i++) {
                    printf("%3d  | ", registro.monthYearVentas[i][j]);
                }
                printf("\n");
            }

            printf("\n");
        }

        if (vista == 2) {
            printf("\t%5s | %5s | %5s | %5s | %5s | %5s | %5s | %5s | %5s | %5s | %5s | %5s\n", "Mes 1", "Mes 2", "Mes 3", "Mes 4",
                   "Mes 5", "Mes 6", "Mes 7", "Mes 8", "Mes 9", "Mes 10", "Mes 11", "Mes 12");
            for (j = year1; j <= year2; j++) {
                printf("%d\t ", j+2014);
                for (i = 0; i < 12; i++) {
                    printf("%3.2f | ", registro.monthYearImporte[i][j]);
                }
                printf("\n");
            }

            printf("\n");
        }

        printf("Cambie el modo de vista o 0 si desea finalizar: ");
        scanf("%d", &vista);

        while (vista < 0 || vista > 2) {
            printf("El modo ingresado no es válido. Intente nuevamente: ");
            scanf("%d", &vista);
        }
    }

    fclose(pf);
}

Registro initializeToZero(Registro registro)
{
    int i, j;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 10; j++) {
            registro.monthYearVentas[i][j] = 0;
        }
    }

    for (i = 0; i < 12; i++) {
        for (j = 0; j < 10; j++) {
            registro.monthYearImporte[i][j] = 0.0;
        }
    }

    return registro;
}
