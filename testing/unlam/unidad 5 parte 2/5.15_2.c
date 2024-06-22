/* 
El gobierno de la Ciudad de Buenos Aires realiza una encuesta a los estudiantes de los colegios
secundarios. Los primeros datos a ingresar son la fecha (día, mes y año) y la cantidad de colegios de la ciudad
en que se realizó la encuesta.
De cada colegio se conoce: número de escuela, la cantidad de alumnos inscriptos y la especialidad (‘T’:
técnico, ‘N’: no técnico).
De cada alumno del colegio que respondió la encuesta se conoce: DNI, fecha de nacimiento (día, mes y
año), sexo (‘M’ o ‘F’), opinión con respecto a los conocimientos adquiridos (‘B’: buenos, ‘M’: malos). Se
identifica el fin de ingreso de datos de los alumnos que respondieron la encuesta por cada colegio con
ingreso 0 en el DNI del estudiante.
Validar todos los datos que se ingresan por teclado.
Informar:
a. Por cada colegio, el porcentaje de alumnos que contestaron la encuesta sobre la cantidad de
alumnos inscriptos del colegio.
b. Cantidad de estudiantes de colegio no técnicos que respondieron la encuesta.
c. Porcentaje de mujeres de escuelas técnicas sobre la cantidad de estudiantes que respondieron
la encuesta.
d. Porcentaje de estudiantes que respondieron que los conocimientos adquiridos eran malos,
sobre el total de encuestados.
e. Mayor edad de los estudiantes encuestados.
f. Número del colegio con mayor opinión buena sobre los conocimientos adquiridos.
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    int dia, mes, anio, cant_colegios;
    do {
        printf("Ingrese la fecha (dia mes año): ");
        scanf("%d %d %d", &dia, &mes, &anio);
    } while ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (anio < 1900 || anio > 2100));

    do {
        printf("Ingrese la cantidad de colegios encuestados: ");
        scanf("%d", &cant_colegios);
    } while (cant_colegios <= 0); // se rompe cuando ingreso un 0
    
    int colegio, inscriptos, dni;  // sobre el colegio y el dni del alumno que respondio la encuesta
    char especialidad, sexo, opinion; // tecnico o no tecnico y datos del alumno sobre la encuesta
    int total_alumnos_no_tecnicos = 0; // variables para el output final, todas inicializadas en 0
    int total_mujeres_tecnicas = 0, total_respondieron_tecnicas = 0;
    int total_malos = 0, total_encuestados = 0;
    int mayor_edad = 0, mayor_anio_nac = 0;
    int colegio_mayor_opinion_buena = 0, max_buenas = 0;

    for (int i = 0; i < cant_colegios; ++i) { // deberia terminar cuando vaya por el colegio nº'cant_colegios' y arrojar el output final
        int total_respondieron = 0, total_buenas = 0;

        printf ("Ingrese el número de la escuela: ");
        scanf("%d", &colegio);

        do {

            printf("Ingrese la cantidad de alumnos inscriptos: ");
            scanf("%d", &inscriptos);
        } while (inscriptos <= 0);

        do {
            printf("Ingrese la especialidad. 'T' técnico / 'N' no técnico: ");
            scanf(" %c", &especialidad);
        } while (especialidad != 'T' && especialidad != 'N');
        
        do {
            printf("Ingrese el D.N.I del alumno. Ingrese 0 si desea finalizar: ");
            scanf("%d", &dni);
            if (dni == 0) break;

            int dia_nac, mes_nac, anio_nac;
            do {
                printf("Ingrese la fecha de nacimiento del alumno (dia mes año): ");
                scanf("%d %d %d", &dia_nac, &mes_nac, &anio_nac);
            } while ((dia <= 0 || dia > 31) || (mes <= 0 || mes > 12) || (anio < 1900 || anio > 2100));

            do {
                printf("Ingrese el sexo del alumno (M masculino F femenino): ");
                scanf(" %c", &sexo);
            } while (sexo != 'M' && sexo != 'F');

            do {
                printf("Ingrese la opinión del alumno sobre los conocimientos adquiridos. (M malos B buenos): ");
                scanf(" %c", &opinion);
            } while (opinion != 'M' && opinion != 'B');

            ++total_encuestados;
            ++total_respondieron;
            if (opinion == 'B') ++total_buenas;
            if (opinion == 'M') ++total_malos;

            if (especialidad == 'N') ++total_alumnos_no_tecnicos;
            if (especialidad == 'T') {
                if (sexo == 'F') ++total_mujeres_tecnicas;
                ++total_respondieron_tecnicas;
            }

            int edad = anio - anio_nac;
            if (edad > mayor_edad) {
                mayor_edad = edad;
                mayor_anio_nac = anio_nac;
            }


        } while (dni != 0);

        if (total_buenas > max_buenas) { // no tiene mucha dificultad a comparación de otros ejercicios de aritmética pero si es bastante largo y puede llegar a ser extenuante en un exámen
            max_buenas = total_buenas; // es bastante fácil perderse con las variables ya que son bastantes
            colegio_mayor_opinion_buena = colegio;
        }

        printf("Porcentaje de alumnos que contestaron en el colegio %d: %.2f%%.\n", colegio, (double)total_respondieron / inscriptos);
    }

    printf("Cantidad de estudiantes de colegio no técnico que respondieron la encuesta: %d\n", total_alumnos_no_tecnicos);
    printf("Porcentaje de mujeres de escuelas técnicas: %.2f%%\n", (double)total_mujeres_tecnicas / total_respondieron_tecnicas);
    printf("Porcentaje de alumnos que dieron una mala opinión sobre los conocimientos adquiridos: %.2f%%\n", (double)total_malos / total_encuestados);
    printf("Mayor edad de los colegios encuestados: %d\n", mayor_edad);
    printf("El colegio con mayor opinión buena fue el colegio número %d\n", colegio_mayor_opinion_buena);

    return 0;
}