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

int main()
{
     FILE *pf;
     Alumnos al;

     pf=fopen("alumnos.dat","rb");
     //pf=fopen("alumnosmasivo.dat","rb");

    if(pf==NULL)
    {
        printf("Error de lectura");
        getch();
        exit(1);
    }

    fread(&al,sizeof(Alumnos),1,pf);

    while(!feof(pf))
    {
        printf("\n%10d %-20s %3d %3d %.2f",al.dni,al.ayn,al.n1,al.n2,al.prom);
        fread(&al,sizeof(Alumnos),1,pf);
    }

    fclose(pf);
}
