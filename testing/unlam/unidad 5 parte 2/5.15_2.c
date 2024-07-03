/*
El  gobierno  de  la  Ciudad  de  Buenos  Aires  realiza  una  encuesta  a  los  estudiantes  de  los  colegios 
secundarios. Los primeros datos a ingresar son la fecha (día, mes y año) y la cantidad de colegios de la ciudad 
en que se realizó la encuesta.  
De cada colegio se conoce: número de escuela, la cantidad de alumnos inscriptos y la especialidad (‘T’: 
técnico, ‘N’: no técnico). 
De cada alumno del colegio que respondió la encuesta se conoce: DNI, fecha de nacimiento (día, mes y 
año), sexo (‘M’ o ‘F’), opinión con respecto a los conocimientos adquiridos (‘B’: buenos, ‘M’: malos). Se 
identifica el fin de ingreso de  datos de los alumnos que  respondieron la encuesta  por cada colegio con 
ingreso 0 en el DNI del estudiante. 
Validar todos los datos que se ingresan por teclado. 
Informar: 
a. Por cada colegio, el porcentaje de alumnos que contestaron la encuesta sobre la cantidad de 
alumnos inscriptos del colegio. 
b. Cantidad de estudiantes de colegio no técnicos que respondieron la encuesta. 
c. Porcentaje de mujeres de escuelas técnicas sobre la cantidad de estudiantes que respondieron 
la encuesta. 
d. Porcentaje  de  estudiantes  que  respondieron  que  los  conocimientos  adquiridos  eran  malos, 
sobre el total de encuestados. 
e. Mayor edad de los estudiantes encuestados. 
f. Número del colegio con mayor opinión buena sobre los conocimientos adquiridos. 
 */

#include <stdio.h>

int main () {

    // datos iniciales (first input)
    int dia, mes, anio;
    int cantidad_colegios_encuesta;
    
    // datos a ingresar sobre la escuela (second input)
    int num_escuela, cant_alumnos;
    char especialidad;

    // datos a ingresar sobre los alumnos (third input)
    int dni, dia_nacimiento, mes_nacimiento, anio_nacimiento;
    char genero, opinion;
    
    // datos a mostrar (output)
    int respondio_total = 0;
    int no_tecnico = 0;
    int mujeres_tecnico = 0;
    int malaOpinionContador = 0;
    int buenaOpinionContador = 0;
    int mayorEdad = -1;
    int colegioOpinionBuena;
    int opinionesBuenas = -1;

    printf("Ingrese la fecha del día de hoy (dia mes año): ");
    scanf("%d %d %d", &dia, &mes, &anio);

    if (dia < 1 || dia > 31) {
        printf("No se ingresó un valor válido.\n");
        return 0;
    }

    if (mes < 1 || mes > 12) {
        printf("No se ingresó un valor válido.\n");
        return 0;
    }

    if (anio < 1900 || anio > 2100) {
        printf("No se ingresó un valor válido.\n");
        return 0;
    }

    printf("Ingrese la cantidad de colegios encuestados: ");
    scanf("%d", &cantidad_colegios_encuesta);

    if (cantidad_colegios_encuesta <= 0) {
        printf("No se realizaron encuestas.\n");
        return 0;
    }

    for (int i = 0; i < cantidad_colegios_encuesta; ++i) {
        printf("Ingrese el número de la escuela Nº%d: ", i + 1);
        scanf("%d", &num_escuela);
        printf("Ingrese la cantidad de alumnos inscriptos: ");
        scanf("%d", &cant_alumnos);
        printf("Ingrese la especialidad del colegio (T o N): ");
        scanf(" %c", &especialidad);
    

    if (cant_alumnos <= 0) {
        printf("Hubo un error en el ingreso de alumnos inscriptos: ");
        return 1;
    }

    int respondio_colegio = 0;
    int buena_opinion_colegio = 0;

    while (cant_alumnos > 0) {
        printf("Ingrese el D.N.I del alumno que respondió la encuesta (0 si desea finalizar): ");
        scanf("%d", &dni);

        if (dni == 0) {
            break;
        } else if (dni < 0) {
            printf("No es un valor válido.\n");
            continue;    
        }

        ++respondio_colegio;
        ++respondio_total;

        printf("Ingrese la fecha de nacimiento del alumno (dia mes año): ");
        scanf("%d %d %d", &dia_nacimiento, &mes_nacimiento, &anio_nacimiento);

        int edad = anio - anio_nacimiento;
        if (mes < mes_nacimiento || (mes == mes_nacimiento && dia < dia_nacimiento)) {
            --edad;
        }

        if (edad > mayorEdad) {
            mayorEdad = edad;
        }

        printf("Ingrese el género del alumno (M o F): ");
        scanf(" %c", &genero);

        if (genero == 'F' || genero == 'f') {
            if (especialidad == 'T' || especialidad == 't') {
                ++mujeres_tecnico;
            }
        }

        printf("Ingrese la opinión del alumno sobre los conocimientos (B o M): ");
        scanf(" %c", &opinion);

        if (opinion == 'B' || opinion == 'b') {
            ++buenaOpinionContador;
            ++buena_opinion_colegio;
        } else if (opinion == 'M' || opinion == 'm') {
            ++malaOpinionContador;
        } else {
            printf("No es un valor válido.\n");
            continue;
        }

        if (especialidad == 'N' || especialidad == 'n') {
            ++no_tecnico;
        }

    }

    float porcentaje_respondio = (float)respondio_colegio / cant_alumnos * 100;

    printf("\nPorcentaje de alumnos que respondieron en la escuela Nº%d: %.2f%%\n", num_escuela, porcentaje_respondio);
    printf("\n");
    
    if (buena_opinion_colegio > opinionesBuenas) {
        opinionesBuenas = buena_opinion_colegio;
        colegioOpinionBuena = num_escuela;
    }
}    

    if (respondio_total > 0) {

    float porcentajeMujeres = (float)mujeres_tecnico / respondio_total * 100;
    float malaOpinionPorcentaje = (float)malaOpinionContador / respondio_total * 100;

    printf("Cantidad de alumnos que respondieron la encuesta de colegios no técnicos: %d\n", no_tecnico); // está bien
    printf("Porcentaje de mujeres de escuelas técnicas que respondieron la encuesta: %.2f%%\n", porcentajeMujeres); // anda mal
    printf("Porcentaje de alumnos que dieron mala opinión sobre los conocimientos: %.2f%%\n", malaOpinionPorcentaje); // anda mal
    printf("Mayor edad de los estudiantes encuestados: %d\n", mayorEdad); // anda mal 
    printf("El colegio con mejor opinión fue el número %d\n", colegioOpinionBuena); // está bien
    } else {
        printf("No hubo respuestas a las encuestas.\n");
    }

    

    return 0;
}