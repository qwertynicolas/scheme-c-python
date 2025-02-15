#include <stdio.h>

int main (void)
{
    int ternas = 1;
    int n1, n2, n3;

    int mayor = -500000000;
    int mult7 = 0;
    int m1, m2, m3;
    int posicion;

    m1 = m2 = m3 = 0;

    float promedioPrimeros = 0.0;

    int i = 1;

    do {
        mult7 = 0;
        m1 = m2 = m3 = 0;
        posicion = 0;
        mayor = -500000000;

        printf("Ingrese el valor Nº%d de la terna Nº%d: ", i, ternas);
        scanf("%d", &n1);

        if (n1 % 7 == 0) {
            ++mult7;
            m1 = n1;
        }

        if (n1 > mayor) {
            mayor = n1;
            posicion = 1;
        }

        promedioPrimeros += n1;

        printf("Ingrese el valor Nº%d de la terna Nº%d: ", i+1, ternas);
        scanf("%d", &n2);

        if (n2 % 7 == 0) {
            ++mult7;
            if (m1 == 0) {
                m1 = n2;
            } else {
                m2 = n2;
            }
        }

        if (n2 > mayor) {
            mayor = n2;
            posicion = 2;
        }

        printf("Ingrese el valor Nº%d de la terna Nº%d: ", i+2, ternas);
        scanf("%d", &n3);

        if (n3 > mayor) {
            mayor = n3;
            posicion = 3;
        }

        if (n3 % 7 == 0) {
            ++mult7;
            if (m1 == 0) {
                m1 = n3;
            } else if (m2 == 0) {
                m2 = n3;
            } else {
                m3 = n3;
            }
        }

        if (mult7 == 3) {
            printf("Múltiplos de 7: %d, %d, %d\n", m1, m2, m3);
        } else if (mult7 == 2) {
            printf("Múltiplos de 7: %d, %d\n", m1, m2);
        } else if (mult7 == 1) {
            printf("Múltiplos de 7: %d\n", m1);
        }

        printf("Mayor: %d. Posicion: %d\n", mayor, posicion);

        ++ternas;

    } while (ternas <= 6);

    promedioPrimeros /= 6;

    printf("Promedio de los primeros: %.2f", promedioPrimeros);

    return 0;
}
