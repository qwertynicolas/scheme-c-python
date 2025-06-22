#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[21];
    char apellido[21];
} Datos;

int main(void)
{
    FILE *fp;
    float var;
    float num = 12.76;

    if ((fp = fopen("prueba.dat", "wb")) == NULL) {
        printf("No se puede abrir.\n");
        getchar();
        exit(1);
    }

    fwrite(&num, sizeof(float), 1, fp);
    fclose(fp);

    if ((fp = fopen("prueba.dat", "rb")) == NULL) {
        printf("No se puede abrir.\n");
        getchar();
        exit(1);
    }

    fread(&var, sizeof(float), 1, fp);
    fclose(fp);

    printf("var: %.2f\n", var);

    return 0;
}
