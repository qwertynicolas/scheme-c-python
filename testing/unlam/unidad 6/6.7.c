/* Confeccionar  un  programa  que  permita  ingresar  diversas  ternas  de  valores  enteros  mayores  que  0  y 
menores  que  99.  Finalizar  el  ingreso  cuando  se  informen  3  valores  iguales  a  96,  97  y  98.  Determinar  e 
informar  para  cada  terna,  el  mayor  y  el  menor  de  los  valores.  Confeccionar  y  utilizar  una  función  con 
parámetros  llamada  MayorMenor,  que  permita  calcular  el  menor  o  el  mayor  valor  de  la  terna  según  un 
parámetro de configuración. */

int MayorMenor (int n1, int n2, int n3);
int main() {

    int n1, n2, n3;
    int mayor, menor;
    int contador = 0;
    // una terna es un conjunto de 3 valores

    do {

        printf("Ingrese el primer valor de la terna (de 1 a 98): ");
        scanf("%d", &n1);
        if (n1 == 96 || n1 == 97 || n1 == 98) {
            ++contador;
        } else if (n1 > 99 || n1 < 0) {
            printf("No es un valor válido.\n");
            continue;
        }

        printf("Ingrese el segundo valor de la terna (de 1 a 98): ");
        scanf("%d", &n2);

        if (n2 == 96 || n2 == 97 || n2 == 98) {
            ++contador;
        } else if (n2 > 99 || n2 < 0) {
            printf("No es un valor válido.\n");
            continue;
        }

        printf("Ingrese el tercer valor de la terna (de 1 a 98): ");
        scanf("%d", &n3);
        if (n3 == 96 || n3 == 97 || n3 == 98) {
            ++contador;
        } else if (n3 > 99 || n3 < 0) {
            printf("No es un valor válido.\n");
            continue;
        }

        if (contador == 3) {
            printf("Finalizando programa.\n");
            break;
        }







    } while (contador != 3);

    return 0;   
}