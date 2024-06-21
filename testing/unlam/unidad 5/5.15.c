/* Se realizó un concurso de tiro al blanco. Existen 5 participantes y cada uno de ellos efectúa 3 disparos,
registrándose las coordenadas X-Y de cada disparo. Determinar:
a. Cuantos disparos se efectuaron en cada cuadrante por cada participante
b. Cuantos disparos se efectuaron en total en el centro.
NOTA: no considere disparos sobre los ejes. */


#include <stdio.h>
#include <stdlib.h>

int main() {

    int participantes = 5;
    int tiros = 3;
    double coordsX, coordsY;
    int primerCuadrante = 0;
    int segundoCuadrante = 0;
    int tercerCuadrante = 0;
    int cuartoCuadrante = 0;
    int centro = 0;
    int ejeX = 0;
    int ejeY = 0;

    for (int i = 0; i < participantes; ++i) {
        for (int j = 0; j < tiros; ++j) {
            printf("Ingrese la coordenada X del tiro Nº%d del participante Nº%d: ", j + 1, i + 1);
            scanf("%lf", &coordsX);
            printf("Ingrese la coordenada Y del tiro Nº%d del participante Nº%d: ", j + 1, i + 1);
            scanf("%lf", &coordsY);

            if (coordsX > 0 && coordsY > 0) {
                ++primerCuadrante;
            } 

            if (coordsX < 0 && coordsY > 0) {
                ++segundoCuadrante;
            }

            if (coordsX < 0 && coordsY < 0) {
                ++tercerCuadrante;
            }

            if (coordsX > 0 && coordsY < 0) {
                ++cuartoCuadrante;
            }

            if (coordsX == 0 && coordsY == 0) {
                ++centro;
            }

            if (coordsX == 0 && (coordsY < 0 || coordsY > 0)) {
                ++ejeX;
            }

            if ((coordsX > 0 || coordsX < 0) && coordsY == 0) {
                ++ejeY;
            }
        }        
    }

    printf("Tiros totales en el primer cuadrante: %d\n", primerCuadrante);
    printf("Tiros totales en el segundo cuadrante: %d\n", segundoCuadrante);
    printf("Tiros totales en el tercer cuadrante: %d\n", tercerCuadrante);
    printf("Tiros totales en el cuarto cuadrante: %d\n", cuartoCuadrante);
    printf("Tiros totales en el centro: %d\n", centro);

    return 0;
}