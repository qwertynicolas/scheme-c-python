#include <stdio.h>
#include <strings.h>
#include <string.h>

void sort(char codigos[][4], float precioUnitario[], int size)
{
    int i;
    char codigoTemp[4];
    int swap;
    float temp;

    do {
        swap = 0;
        for (i = 0; i < size-1; i++) {
                if (strcasecmp(codigos[i], codigos[i+1]) > 0) {
                    strcpy(codigoTemp, codigos[i]);
                    strcpy(codigos[i], codigos[i+1]);
                    strcpy(codigos[i+1], codigoTemp);

                    temp = precioUnitario[i];
                    precioUnitario[i] = precioUnitario[i+1];
                    precioUnitario[i+1] = temp;

                    swap = 1;
            }
        }
    } while (swap != 0);
}

int search(char codigos[][4], char codigoBuscado[], int size)
{
    int i, pos = -1;

    for (i = 0; i < size-1; ++i) {
        if (strcasecmp(codigos[i], codigoBuscado) == 0)
            return i;
    }

    return pos;
}

void carga(char codigos[][4], float precioUnitario[], int size)
{
    float recaudacionTotal = 0.0;
    int ventas[50] = {0};
    char menorVendido[4];
    int posicionCodigo;
    int unidadesVendidas;
    char codigo[4];

    printf("Ingrese el código del producto: ");
    fgets(codigo, 4, stdin);

    size_t len = strlen(codigo);

    if (len > 0 && codigo[len-1] == '\n')
        codigo[len-1] = '\0';

    while (getchar() != '\n' && getchar() != EOF);

    posicionCodigo = search(codigos, codigo, size);

    while (posicionCodigo == -1) {
        printf("El código ingresado no es válido. Intente nuevamente: ");
        fgets(codigo, 4, stdin);

        if (len > 0 && codigo[len-1] == '\n')
            codigo[len-1] = '\0';

        while(getchar() != '\n');

        posicionCodigo = search(codigos, codigo, size+1);
    }

    while (getchar() != '\n');

    printf("Ingrese la cantidad de unidades vendidas: ");
    scanf("%d", &unidadesVendidas);

    while (unidadesVendidas != 0) {
        while (unidadesVendidas < 0) {
            printf("La cantidad ingresa no es válida. Intente nuevamente: ");
            scanf("%d", &unidadesVendidas);
        }

        recaudacionTotal += precioUnitario[posicionCodigo] * unidadesVendidas;
        ventas[posicionCodigo] += unidadesVendidas;

        while(getchar() != '\n');

        printf("Ingrese el código del producto: ");
        fgets(codigo, 4, stdin);

        if (len > 0 && codigo[len-1] == '\n')
            codigo[len-1] = '\0';

        posicionCodigo = search(codigos, codigo, size);

        while(posicionCodigo == -1) {
            printf("El código ingresado no es válido. Intente nuevamente: ");
            fgets(codigo, 4, stdin);

            if (len > 0 && codigo[len-1] == '\n')
                codigo[len-1] = '\0';

            while (getchar() != '\n');
            posicionCodigo = search(codigos, codigo, size);
        }

        printf("Ingrese la cantidad vendida o 0 si desea finalizar: ");
        scanf("%d", &unidadesVendidas);
    }

    int i;
    int menorVenta = ventas[0];
    strcpy(menorVendido, codigos[0]);

    for (i = 1; i < size; i++) {
        if (ventas[i] < menorVenta) {
            menorVenta = ventas[i];
            strcpy(menorVendido, codigos[i]);
        }
    }

    printf("Producto menor vendido (%d unidades): %s\n", menorVenta, menorVendido);

}

void mostrarListado(char codigos[][4], float precioUnitario[], int size)
{
    sort(codigos, precioUnitario, size);

    int i;

    printf("Listado de productos:\n");
    for (i = 0; i < size; ++i) {
        printf("Codigo: %s - Precio: %.2f\n", codigos[i], precioUnitario[i]);
    }
}

int main(void)
{
    char codigos[50][4];
    char codigo[4];
    float precioUnitario[50] = {0};
    int i = 0;

    printf("Ingrese el código del producto: ");
    fgets(codigos[i], 4, stdin);

    size_t len = strlen(codigos[i]);

    if (len > 0 && codigos[i][len-1] == '\n')
        codigos[i][len-1] = '\0';

    while (i < 50 && strcasecmp(codigos[i], "FIN") != 0) {
        printf("Ingrese el precio unitario del producto: ");
        scanf("%f", &precioUnitario[i]);

        while (precioUnitario[i] <= 0.0) {
            printf("El precio ingresado no es válido. Intente nuevamente: ");
            scanf("%f", &precioUnitario[i]);
        }

        while (getchar() != '\n')
        ++i;

        printf("Ingrese un nuevo código o FIN para finalizar: ");
        fgets(codigo, 4, stdin);

        len = strlen(codigo);

        if (len > 0 && codigo[len-1] == '\n')
            codigo[len-1] = '\0';

        while (getchar() != '\n');

        while (search(codigos, codigo, i+1) != -1) {
            printf("El código ya está en uso. Intente nuevamente: ");
            fgets(codigo, 4, stdin);

            len = strlen(codigo);

            if (len > 0 && codigo[len-1] == '\n')
                codigo[len-1] = '\0';

            while (getchar() != '\n');
        }

        if (i < 50)
            strcpy(codigos[i], codigo);
        else
            printf("Se alcanzó el máximo número de productos.\n");
    }

    carga(codigos, precioUnitario, i);
    mostrarListado(codigos, precioUnitario, i);

    return 0;

}
