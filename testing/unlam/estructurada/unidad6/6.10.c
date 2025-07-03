#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct {
    int day;
    int month;
    int year;
} Fecha;

typedef struct {
    int dni;
    Fecha fechaPago;
} Cuotas;

typedef struct {
    int dni;
    char nombreCompleto[41];
} Alumno;

int search(FILE*, int);
void cargarAlumnos(FILE*);
void remove_newline(char []);
void mostrarAlumnos(FILE*);
int searchCuotas(FILE*, int);

int main(void)
{
    Alumno alumnos;
    Cuotas cuotas;
    FILE *pCuotas, *pAlumnos;
    char cargar, verAlumnos, cargarPagos, inscribir, nombre[41], realizarPago;
    int dni, posicion, day, month, year, posicionCuotas;
    realizarPago = 'S';

    printf("¿Desea crear el archivo de alumnos? (S/N): ");
    scanf(" %c", &cargar);

    if (cargar == 'S' || cargar == 's') {
        pAlumnos = fopen("ALUMNOS.dat", "w+b");
        cargarAlumnos(pAlumnos);
    } else {
        pAlumnos = fopen("ALUMNOS.dat", "r+b");
    }

    printf("¿Desea ver la lista de alumnos? (S/N): ");
    scanf(" %c", &verAlumnos);

    if (verAlumnos == 'S' || verAlumnos == 's') {
        mostrarAlumnos(pAlumnos);
    }

    printf("¿Desea iniciar el programa para registrar pagos? (S/N): ");
    scanf(" %c", &cargarPagos);

    if (cargarPagos == 'S' || cargarPagos == 's') {
        pCuotas = fopen("CUOTAS.dat", "r+b");
        if (pCuotas == NULL) {
            pCuotas = fopen("CUOTAS.dat", "w+b");
        }

        if (pCuotas == NULL) {
            printf("Error al abrir/crear archivo de cuotas.\n");
            getchar();
            exit(1);
        }

        printf("Ingrese el D.N.I del alumno: ");
        scanf("%d", &dni);
        while (dni < 0) {
            printf("El valor ingresado no es válido. Intente nuevamente: ");
            scanf("%d", &dni);
        }

        while (dni != 0) {
            if ((posicion = search(pAlumnos, dni)) == -1) {
                printf("No se encontró el D.N.I del alumno. ¿Desea inscribirlo? (S/N): ");
                scanf(" %c", &inscribir);

                if (inscribir == 'S' || inscribir == 's') {
                    printf("Ingrese el nombre y apellido del alumno: ");
                    fgets(nombre, 40, stdin);
                    remove_newline(nombre);

                    fseek(pAlumnos, 0, SEEK_END);
                    strcpy(alumnos.nombreCompleto, nombre);
                    alumnos.dni = dni;
                    fwrite(&alumnos, sizeof(Alumno), 1, pAlumnos);
                    fseek(pAlumnos, 0, SEEK_CUR);

                    printf("¿Desea realizar el pago para el nuevo alumno inscripto?: (S/N): ");
                    scanf(" %c", &realizarPago);
                }
            }

            if ((posicion = search(pAlumnos, dni) != -1) && (realizarPago == 'S' || realizarPago == 's')) {
                printf("Ingrese la fecha del pago: ");
                scanf("%d %d %d", &day, &month, &year);

                while (day <= 0 || day > 31) {
                    printf("El día ingresado no es válido. Intente nuevamente: ");
                    scanf("%d", &day);
                }
                while (month <= 0 || month > 12) {
                    printf("El mes ingresado no es válido. Intente nuevamente: ");
                    scanf("%d", &month);
                }
                while(year > 9999 || year < 1900) {
                    printf("El año ingresado no es válido. Intente nuevamente: ");
                    scanf("%d", &year);
                }

                posicionCuotas = searchCuotas(pCuotas, dni);
                if (posicionCuotas == -1) {
                    fseek(pCuotas, 0, SEEK_END);
                    cuotas.dni = dni;
                } else {
                    fseek(pCuotas, sizeof(Cuotas) * posicionCuotas, SEEK_SET);
                }

                cuotas.fechaPago.day = day;
                cuotas.fechaPago.month = month;
                cuotas.fechaPago.year = year;

                fwrite(&cuotas, sizeof(Cuotas), 1, pCuotas);
            }

            printf("Ingrese un nuevo D.N.I o 0 si desea finalizar: ");
            scanf("%d", &dni);
        }
        fclose(pCuotas);
        fclose(pAlumnos);
    }

    printf("¿Desea ver un listado de alumnos que adeudan la última cuota? (S/N): ");
}

int searchCuotas(FILE *pf, int dni)
{
    Cuotas cuotas;
    int i = 0, posicion = -1;

    fread(&cuotas, sizeof(Cuotas), 1, pf);
    while(!feof(pf) && posicion == -1) {
        if (cuotas.dni == dni) {
            posicion = i;
        } else {
            i++;
            fread(&cuotas, sizeof(Cuotas), 1, pf);
        }
    }

    return posicion;
}

int search(FILE *pf, int dni)
{
    Alumno alumnos;
    int posicion = -1, i = 0;

    fread(&alumnos, sizeof(Alumno), 1, pf);
    while (!feof(pf) && posicion == -1) {
        if (alumnos.dni == dni) {
            posicion = i;
        } else {
            i++;
            fread(&alumnos, sizeof(Alumno), 1, pf);
        }
    }

    rewind(pf);

    return posicion;
}

void cargarAlumnos(FILE *pf)
{
    Alumno alumnos;
    int dni;
    char nombre[41];

    printf("Ingrese el D.N.I del alumno: ");
    scanf("%d", &dni);

    while (dni < 0) {
        printf("El D.N.I ingresado no es válido. Intente nuevamente: ");
        scanf("%d", &dni);
    }

    while (dni != 0) {
        getchar();
        printf("Ingrese el nombre y apellido del alumno: ");
        fgets(nombre, 40, stdin);
        remove_newline(nombre);

        alumnos.dni = dni;
        strcpy(alumnos.nombreCompleto, nombre);
        fwrite(&alumnos, sizeof(Alumno), 1, pf);

        printf("Ingrese un nuevo D.N.I o 0 si desea finalizar: ");
        scanf("%d", &dni);
    }
    rewind(pf);
}

void mostrarAlumnos(FILE *pf)
{
    Alumno alumnos;

    fread(&alumnos, sizeof(Alumno), 1, pf);
    while(!feof(pf)) {
        printf("Nombre y apellido: %s\n", alumnos.nombreCompleto);
        printf("D.N.I: %d\n", alumnos.dni);
        fread(&alumnos, sizeof(Alumno), 1, pf);
    }
    rewind(pf);
}

void remove_newline(char str[])
{
    int i = 0, newline = 0;
    int largo = strlen(str);

    while (i < largo && newline == 0) {
        if (str[i] == '\n') {
            str[i] = '\0';
            newline = 1;
        } else {
            i++;
        }
    }
}
