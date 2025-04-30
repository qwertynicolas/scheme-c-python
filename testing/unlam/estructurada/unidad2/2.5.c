#include <stdio.h>
#define FILAS 12
#define BUTACAS 9

/* mostrar:
 * -cantidad de asientos disponibles y cantidad de asientos reservados
 * -filas que quedaron vacías
 * -fila(s) con mayor cantidad de espectadores
 * -listado de personas que se sentaron en los mismos numeros de butacas, de mayor a menor */

void mostrarDisponibilidad(int filasButacas[][BUTACAS])
{
    int i, j;

    printf("Butacas disponibles:\n");
    for (i = 0; i < FILAS; i++) {
        j = 8;
        while (j >= 0 && j <= BUTACAS) {
            if (filasButacas[i][j] == 0) {
                printf("%d (D) ", j);
            } else {
                printf("%d (R) ", j);
            }

            if (j == 2) {
                --j;
            } else if (j % 2 == 0) {
                j -= 2;
            } else {
                j += 2;
            }
        }
        printf("- Fila %d", i+1);

        printf("\n");
    }
}

int verificarDisponibilidad(int matriz[][BUTACAS], int butaca)
{
    int sumatoriaDisponibles = 0;
    int i, j = butaca;

    for (i = 0; i < FILAS; i++) {
        while (j >= 0 && j <= BUTACAS) {
            if (matriz[i][j] == 0)
                sumatoriaDisponibles++;

            if (j == 2) {
                --j;
            } else if (j % 2 == 0) {
                j -= 2;
            } else {
                j += 2;
            }
        }
    }

    return sumatoriaDisponibles;
}

void listadoButacas(int butacas[])
{
    int i, j;
    int listado[BUTACAS] = {0};
    int maxIndex, maximo;

    printf("Butaca   Cantidad\n");

    do {
        for (i = 0; i < BUTACAS; i++) {
            maxIndex = -1;
            maximo = -1;

            for (j = 0; j < BUTACAS; j++) {
                if (!listado[j] && butacas[j] > maximo) {
                    maximo = butacas[j];
                    maxIndex = j;
                }
            }

            if (maxIndex != -1) {
                printf("  %02d \t\t%02d\n", maxIndex, maximo);
                listado[maxIndex] = 1;
            }
        }
    } while (maxIndex != -1);

    printf("\n");
}

void cantidadReservada(int filasButacas[][BUTACAS])
{
    int i, j, reservados = 0, disponibles = 0; // punto a
    int filasVacias[FILAS] = {0}, vacio; // usados para el punto b
    int mayorEspectadores = 0, mayoresEspectadores[FILAS] = {0}; // punto c
    int mismaButaca[BUTACAS] = {0}; // punto c

    for (i = 0; i < FILAS; i++) {
        vacio = 0;
        for (j = 0; j < BUTACAS; j++) {
            if (filasButacas[i][j] == 0) {
                disponibles++;
            } else {
                reservados++;
                vacio++;
                mayoresEspectadores[i]++;
                mismaButaca[j]++;
            }
        }

        if (vacio > mayorEspectadores)
            mayorEspectadores = vacio;

        if (vacio == 0)
            filasVacias[i] = 1;
    }

    printf("Asientos disponibles: %d. Asientos reservados: %d\n", disponibles, reservados);

    int cantidadVacias = 0;
    for (i = 0; i < FILAS; i++) {
        cantidadVacias += filasVacias[i];
    }

    if (cantidadVacias == 0) {
        printf("No hubo filas vacías.\n");
    } else {
        printf("Filas vacías: ");
        for (i = 0; i < FILAS; i++) {
            if (filasVacias[i] == 1) {
                printf("%d ", i+1);
            }
        }
    }

    printf("\n");
    printf("Fila(s) con la mayor cantidad de espectadores (%d): ", mayorEspectadores);
    for (i = 0; i < FILAS; i++) {
        if (mayoresEspectadores[i] == mayorEspectadores)
            printf("%d ", i+1);
    }
    printf("\n");
    listadoButacas(mismaButaca);
}

int main(void)
{
    int fila = 0;
    int butaca, butacasReserva, butacasDisponibles;
    int filasButacas[FILAS][BUTACAS] = {{0}};

    mostrarDisponibilidad(filasButacas);

    printf("Seleccione fila: ");
    scanf("%d", &fila);

    while (fila != -1) {

        while (fila < 1 || fila > 12) {
            printf("La fila no es válida. Intente nuevamente: ");
            scanf("%d", &fila);
        }

        printf("Seleccione butaca: ");
        scanf("%d", &butaca);

        while (butaca < 1 || butaca > 9) {
            printf("La butaca no es válida. Intente nuevamente: ");
            scanf("%d", &butaca);
        }

        printf("Ingrese cantidad de butacas a reservar: ");
        scanf("%d", &butacasReserva);

        butacasDisponibles = verificarDisponibilidad(filasButacas, butacasReserva);

        if (filasButacas[fila-1][butaca] == 0 && (butacasDisponibles == butacasReserva || butacasDisponibles > butacasReserva)) {
            printf("Reserva exitosa.\n");

            while (butacasReserva > 0) {
                filasButacas[fila-1][butaca] = 1;
                butacasReserva--;

                if (butaca == 2) {
                    butaca--;
                } else if (butaca % 2 == 0) {
                    butaca -= 2;
                } else {
                    butaca += 2;
                }
            }

        } else {
            printf("La fila y butaca(s) no están disponibles. Revise disponibilidad.\n");
        }

        mostrarDisponibilidad(filasButacas);
        printf("Seleccione fila (-1 para finalizar): ");
        scanf("%d", &fila);
    }

    cantidadReservada(filasButacas);

    return 0;
}
