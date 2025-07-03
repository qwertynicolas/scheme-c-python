#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CUPO 60

typedef struct {
    int dni;
    char nombreCompleto[21];
    int pagado;
} Inscriptos;

typedef struct {
    int telefono;
    char nombreCompleto[21];
    int dni;
} Interesados;

void remove_newline(char []);
int search(FILE*, int);
int cantidadRegistros(FILE*);

int main(void)
{
    FILE *pInscriptos, *pInteresados;
    Inscriptos inscriptos;
    Interesados interesados;
    int posicion, dni, cantidadCupos;
    char registrarPago, registrarInscripcion, iniciar, iniciarInteresados, primeraVezInteresados;
    char nombreCompleto[21];

    pInscriptos = fopen("INSCRIPTOS.dat", "r+b");
    if (pInscriptos == NULL) {
        printf("Error al abrir el archivo de inscriptos.\n");
        getchar();
        exit(1);
    }

    cantidadCupos = cantidadRegistros(pInscriptos);

    printf("Actualmente hay %d inscriptos.\n", cantidadCupos);
    getchar();

    printf("¿Desea iniciar el programa de inscripción? (S/N): ");
    scanf(" %c", &iniciar);

    if (iniciar == 'S' || iniciar == 's') {
        fread(&inscriptos, sizeof(Inscriptos), 1, pInscriptos);

        printf("Ingrese un D.N.I: ");
        scanf("%d", &dni);

        while (dni > 0 && cantidadCupos <= MAX_CUPO) {
            posicion = search(pInscriptos, dni);

            if (posicion != -1) {
                fseek(pInscriptos, sizeof(Inscriptos) * posicion, SEEK_SET);
                fread(&inscriptos, sizeof(Inscriptos), 1, pInscriptos);
            }
            if (posicion == -1) {
                printf("La persona con D.N.I %d no está inscripta. ¿Desea inscribirla? (S/N): ", dni);
                scanf(" %c", &registrarInscripcion);

                if (registrarInscripcion == 'S' || registrarInscripcion == 's') {
                    getchar();
                    printf("Ingrese el nombre completo: ");
                    fgets(nombreCompleto, 20, stdin);
                    remove_newline(nombreCompleto);

                    cantidadCupos++;
                    fseek(pInscriptos, 0, SEEK_END);
                    strcpy(inscriptos.nombreCompleto, nombreCompleto);
                    inscriptos.dni = dni;
                    fwrite(&inscriptos, sizeof(Inscriptos), 1, pInscriptos);
                    fseek(pInscriptos, 0, SEEK_CUR);
                }
            }
            if (inscriptos.pagado == 0 && posicion != -1) {
                printf("La persona con D.N.I %d aún adeuda la matrícula. ¿Desea registrar el pago? (S/N): ", dni);
                scanf(" %c", &registrarPago);

                if (registrarPago == 'S' || registrarPago == 's') {
                    fseek(pInscriptos, sizeof(Inscriptos) * posicion, SEEK_SET);
                    inscriptos.pagado = 1;
                    fwrite(&inscriptos, sizeof(Inscriptos), 1, pInscriptos);
                    fseek(pInscriptos, 0, SEEK_CUR);
                }
            }

            printf("Ingrese un nuevo D.N.I o -1 si desea finalizar: ");
            scanf("%d", &dni);
        }
    }
    fclose(pInscriptos);

    if (cantidadCupos > MAX_CUPO) {
        printf("\nSe ha alcanzado la cantidad máxima de cupos. ¿Desea iniciar el programa para anotar interesados? (S/N): ");
        scanf(" %c", &iniciarInteresados);

        if (iniciarInteresados == 'S' || iniciarInteresados == 's') {
            printf("¿Es está la primera vez que se ejecúta el programa de interesados? (S/N): ");
            scanf(" %c", &primeraVezInteresados);

            if (primeraVezInteresados == 'S' || primeraVezInteresados == 's')
                pInteresados = fopen("INTERESADOS.dat", "wb");
            else
                pInteresados = fopen("INTERESADOS.dat", "ab");

            if (pInteresados == NULL) {
                printf("Error al crear/abrir el archivo de interesados.\n");
                getchar();
                exit(1);
            }

            printf("Ingrese el D.N.I: ");
            scanf("%d", &dni);

            while (dni > 0) {
                getchar();
                interesados.dni = dni;
                printf("Ingrese su nombre y apellido: ");
                fgets(interesados.nombreCompleto, 20, stdin);
                remove_newline(interesados.nombreCompleto);

                printf("Ingrese su número de teléfono: ");
                scanf("%d", &interesados.telefono);

                while(interesados.telefono <= 0) {
                    printf("El número de teléfono ingresado no es válido. Intente nuevamente: ");
                    scanf("%d", &interesados.telefono);
                }
                fwrite(&interesados, sizeof(Interesados), 1, pInteresados);

                printf("Ingrese un nuevo D.N.I o -1 si desea finalizar: ");
                scanf("%d", &dni);
            }
        }
        fclose(pInteresados);
    }

    return 0;
}

void remove_newline(char str[])
{
    int newline = 0, i = 0;
    int len = strlen(str);

    while(i < len && newline == 0) {
        if (str[i] == '\n') {
            str[i] = '\0';
            newline = 1;
        } else {
            i++;
        }
    }
}

int search(FILE *pf, int dni)
{
    Inscriptos inscriptos;
    int posicion = -1, i = 0;
    rewind(pf);

    fread(&inscriptos, sizeof(Inscriptos), 1, pf);

    while(!feof(pf) && posicion == -1) {
        if (inscriptos.dni == dni) {
            posicion = i;
        } else {
            i++;
            fread(&inscriptos, sizeof(Inscriptos), 1, pf);
        }
    }

    return posicion;
}

int cantidadRegistros(FILE *pf)
{
    int registroActual;

    fseek(pf, 0, SEEK_END);

    registroActual = ftell(pf) / sizeof(Inscriptos);

    return registroActual;
}
