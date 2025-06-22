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

Alumnos buscar(FILE*,int);

int main()
{
    FILE *pf;
    int dni;
    Alumnos al;

    pf=fopen("alumnos.dat","r+b");


    if(pf==NULL)
    {
        printf("Error de lectura");
        getch();
        exit(1);
    }

    printf("\nIngrese DNI a modificar: ");
    scanf("%d",&dni);

    al=buscar(pf,dni);

    printf("\nIngrese nota 1: ");
    scanf("%d",&al.n1);

    printf("\nIngrese nota 2: ");
    scanf("%d",&al.n2);

    al.prom=(al.n1+al.n2)/2.0;

    fseek(pf,(long)sizeof(al)*(-1),SEEK_CUR);
    fwrite(&al,sizeof(Alumnos),1,pf);
    //fflush() o fseek() recuerde usar estas instrucciones si es repetitiva
    //la modificación

    return 0;
}

Alumnos buscar(FILE *arch,int dato)
{
    Alumnos a;
    int band=0;

    fread(&a,sizeof(a),1,arch);

    while(!feof(arch) && band==0)
    {
        if(dato==a.dni)
            band=1;
        else
            fread(&a,sizeof(a),1,arch);
    }

    if(band==0)
        a.dni=-1;

    return a;

}
