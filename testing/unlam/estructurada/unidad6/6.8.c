#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct {
    char codigo[11];
    int dia;
    int numeroVuelo;
    float costoPasaje;
    int pasajeros;
} Vuelo;

typedef struct {
    int dni;
    int numeroVuelo;
    int pasajeros;
} Aero1;

void exportarCSV();

// no se entiende nada la consigna

int main(void)
{
    FILE *pVuelo, *pAero1;
    Vuelo vuelos;
    Aero1 vuelosA1;
    char exportar;

    pVuelo = fopen("VUELOS.dat", "r+b");
    pAero1 = fopen("PASAJEROS.dat", "r+b");

    if (pVuelo == NULL) {
        printf("Error al abrir el archivo de vuelos.\n");
        getchar();
        exit(1);
    }

    if (pAero1 == NULL) {
        printf("Error al abrir el archivo de pasajeros.\n");
        getchar();
        exit(1);
    }

    fread(&vuelos, sizeof(Vuelo), 1, pVuelo);
    fread(&vuelosA1, sizeof(Aero1), 1, pAero1);

    while (!feof(pVuelo)) {
        if ((strcasecmp(vuelos.codigo, "Aero1")) == 0) {
            vuelos.pasajeros++;
            vuelosA1.pasajeros++;
        } else {
            vuelosA1.pasajeros++;
        }
    }
}
