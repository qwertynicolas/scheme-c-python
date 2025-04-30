#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOURS 10
#define AGENCIAS 15
#define PASAJES 20

int determinarAgenciaMaximo(int matriz[][TOURS])
{
    int i, j, pasajesMaximo = matriz[0][0];

    for (i = 0; i < AGENCIAS; i++) {
        for (j = 0; j < TOURS; j++) {
            if (matriz[i][j] > pasajesMaximo) {
                pasajesMaximo = matriz[i][j];
            }
        }
    }

    return pasajesMaximo;
}

void posicionesMaximo(int matriz[][TOURS], int pasajesMaximo)
{
    int i, j;

    printf("Agencia(s) con el mayor número de pasajes vendidos: ");
    for (i = 0; i < AGENCIAS; i++) {
        for (j = 0; j < TOURS; j++) {
            if (matriz[i][j] == pasajesMaximo)
                printf("%d ", i+1);
        }
    }
}

void randomLoad(int matriz[][TOURS])
{
    int i, j;

    for (i = 0; i < AGENCIAS; i++) {
        for (j = 0; j < TOURS; j++) {
            matriz[i][j] = rand() % (PASAJES + 1);
        }
    }
}

int main(void)
{
  int i, j;
  /* int pasajes, agencia, tour; */
  int agenciasTours[AGENCIAS][TOURS];
  srand((unsigned) time(NULL));

  randomLoad(agenciasTours);

  /* for (i = 0; i < AGENCIAS; i++) { */
  /*     for (j = 0; j < TOURS; j++) { */
  /*         agenciasTours[i][j] = -1; */
  /*     } */
  /* } */

  /* for (i = 0; i < AGENCIAS; i++) { */
  /*     for (j = 0; j < TOURS; j++) { */
  /*         printf("Ingrese el código de agencia (1 a 15): "); */
  /*         scanf("%d", &agencia); */

  /*         while (agencia < 1 || agencia > 15) { */
  /*             printf("El código no es válido. Intente nuevamente: "); */
  /*             scanf("%d", &agencia); */
  /*         } */

  /*         agencia -= 1; */

  /*         printf("Ingrese el código de tour (1 a 10): "); */
  /*         scanf("%d", &tour); */

  /*         while (tour < 1 || tour > 10) { */
  /*             printf("El código no es válido. Intente nuevamente: "); */
  /*             scanf("%d", &tour); */
  /*         } */

  /*         tour -= 1; */

  /*         printf("Ingrese la cantidad de pasajes vendidos (0 a 20): "); */
  /*         scanf("%d", &pasajes); */

  /*         while (pasajes < 0 || pasajes > 20) { */
  /*             printf("La cantidad de pasajes no es válida. Intente nuevamente: "); */
  /*             scanf("%d", &pasajes); */
  /*         } */

  /*         if (agenciasTours[agencia][tour] != -1) { */
  /*             agenciasTours[agencia][tour] += pasajes; */
  /*         } else { */
  /*             agenciasTours[agencia][tour] = pasajes; */

  /*         } */

  /*     } */
  /* } */

  for (i = 0; i < AGENCIAS; i++) {
      for (j = 0; j < TOURS; j++) {
          if (agenciasTours[i][j] != -1)
              printf("\nAgencia: %02d  Tour:%02d  Pasajes vendidos: %02d", i+1, j+1, agenciasTours[i][j]);
      }
  }

  printf("\n");

  int agenciaMaximo;

  agenciaMaximo = determinarAgenciaMaximo(agenciasTours);

  printf("Máxima cantidad de pasajes vendidos: %d\n", agenciaMaximo);

  posicionesMaximo(agenciasTours, agenciaMaximo);

  return 0;
}
