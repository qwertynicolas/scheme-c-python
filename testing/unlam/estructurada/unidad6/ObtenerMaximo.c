#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
    int dni;
    char ayn[81];
    int n1;
    int n2;
    float prom;
}Alumnos;

float obterner_promedio(FILE*);
void mostrar_max_promedios(FILE*,float);

int main()
{
     FILE *pf;
     float max_prom;

     pf=fopen("alumnos.dat","rb");


    if(pf==NULL)
    {
        printf("Error de lectura");
        getch();
        exit(1);
    }

    max_prom=obterner_promedio(pf);

    printf("\nEl maximo promedio es: %.2f",max_prom);

    mostrar_max_promedios(pf,max_prom);

    fclose(pf);

    return 0;
}

float obterner_promedio(FILE *arch)
{
    Alumnos a;
    int band=0;
    float pm;

    fread(&a,sizeof(a),1,arch);

    while(!feof(arch))
    {
        if(band==0 || a.prom>pm)
        {
            band=1;
            pm=a.prom;
        }

        fread(&a,sizeof(a),1,arch);
    }

    return pm;
}

void mostrar_max_promedios(FILE *arch,float mp)
{
    Alumnos al;

    rewind(arch);

    fread(&al,sizeof(Alumnos),1,arch);

    while(!feof(arch))
    {
        if(al.prom==mp)
            printf("\nNOMBRE: %s PROMEDIO: %.2f",al.ayn,al.prom);

        fread(&al,sizeof(Alumnos),1,arch);
    }
}
