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
    Alumnos al[2]={{11222333,"Perez, Lautaro",7,7,7.00},
                   {11333444,"Sosa, Cecilia",8,9,8.50}
                  };

    pf=fopen("alumnosmasivo.dat","wb");

    if(pf==NULL)
    {
        printf("Error de escritura");
        getch();
        exit(1);
    }

    fwrite(al,sizeof(Alumnos),2,pf);

    fclose(pf);
    return 0;
}
