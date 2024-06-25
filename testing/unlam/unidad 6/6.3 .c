/* Se realizó un concurso de tiro al blanco. Por cada participante se ingresa un número que lo identifica y el
resultado de los disparos efectuados. El ingreso finaliza con un número de participante negativo.
Cada participante efectúa 5 disparos, registrándose las coordenadas X-Y de cada disparo.

No considere disparos sobre los ejes, pero sí en el centro (si es sobre los ejes las coordenadas
deberán volver a ingresarse).
• Para determinar el cuadrante utilizar la función CUADRANTE que reciba las dos coordenadas y
retorne el cuadrante al cual pertenece (1 a 4) y 0 para indicar un tiro en el centro.
Para calcular el puntaje utilizar la función PUNTAJE que reciba 5 parámetros que representan la cantidad
disparos en cada cuadrante y en el centro. La función debe retornar el puntaje obtenido según la siguiente
escala:
✓ Cuadrantes 1 y 2: 50 puntos
✓ Cuadrantes 3 y 4: 40 puntos
✓ Centro: 100 puntos
Determinar:
a. El puntaje obtenido por cada participante, detallando cuantos disparos realizó en cada cuadrante.
b. Mostrar el número del participante ganador y el puntaje obtenido.
c. Calcular y mostrar la cantidad total de disparos en el centro (de todos los participantes)

cuadrante I = x > 0 && y > 0
cuadrante II = x < 0 && y > 0
cuadrante III = x < 0 && y < 0
cuadrante IV = x > 0 && y < 0

 */

// int participante, numero, resultado_disparos
// int cant_disparos = 5
// int coordX, coordY
// int centro
// int ejeX, ejeY

#include <stdio.h>

int CUADRANTE (double coordX, double coordY); // retornar el cuadrante al cual pertenece el tiro o si fue al centro
int PUNTAJE (int disparoI, int disparoII, int disparoIII, int disparoIV, int disparoCentro); // retornar el puntaje

int main () {

    int participante;
    int ganador;
    int puntaje_ganador = 0;
    int disparos_centro = 0;
    int disparos = 5;

    while (1) {
        printf("Ingrese el número del participante (-1 para finalizar): ");
        scanf("%d", &participante);

        if (participante < 0) {
            break;
        }

        int disparoI = 0, disparoII = 0, disparoIII = 0, disparoIV = 0, disparoCentro = 0;

    

    for (int i = 0; i < disparos; ++i) {
        double coordX, coordY;
        printf("Ingrese las coordenadas X e Y del disparo %d: ", i+1);
        scanf("%lf %lf", coordX, coordY);

        while (coordX == 0 && (coordY > 0 || coordY < 0) || coordY == 0 && (coordX > 0 || coordX < 0)) {
            printf("El tiro se realizó sobre los ejes. Intente nuevamente.\n");
            printf("Ingrese las coordenadas X e Y del disparo %d: ", i + 1);
            scanf("%lf %lf", coordX, coordY);
        }

        int cuadrante = CUADRANTE(coordX, coordY);
        switch (cuadrante) {
            case 0 :
            ++disparos_centro;
            break;
            case 1 :
            ++disparoI;
            break;
            case 2 :
            ++disparoII;
            break;
            case 3 : 
            ++disparoIII;
            break;
            case 4 :
            ++disparoIV;
            break;
        }
    }

    int puntaje = PUNTAJE(disparoI, disparoII, disparoIII, disparoIV, disparoCentro);
    disparos_centro += disparoCentro;
    
    printf("Participante %d: Puntaje %d\n", participante, puntaje);
    printf("Cuadrante I: %d. Cuadrante II: %d. Cuadrante III: %d. Cuadrante IV: %d. Centro: %d", disparoI, disparoII, disparoIII, disparoIV, disparoCentro);

    if (puntaje > puntaje_ganador) {
        puntaje_ganador += puntaje;
        ganador = participante;
    }

    printf("Ganador: Participante Nº%d", ganador);
    printf("Puntuacion: %d", puntaje_ganador);
    printf("Se realizaron %d disparos en el centro", disparos_centro);

    }

    return 0;
}

int CUADRANTE(double coordX, double coordY) {

        if (coordX > 0 && coordY > 0) {
            return 1;
        } else if (coordX < 0 && coordY > 0) {
            return 2;
        } else if (coordX < 0 && coordY < 0) {
            return 3;
        } else if (coordX > 0 && coordY < 0) {
            return 4;
        } else if (coordX == 0 && coordY == 0) {
            return 0;
        } else {
            return -1;
        }
}

int PUNTAJE (int disparoI, int disparoII, int disparoIII, int disparoIV, int disparoCentro) {

    int puntaje = 0;
    puntaje += disparoI * 50;
    puntaje += disparoII * 50;
    puntaje += disparoIII * 40;
    puntaje += disparoIV * 40;
    puntaje += disparoCentro * 100;

    return puntaje;

}
