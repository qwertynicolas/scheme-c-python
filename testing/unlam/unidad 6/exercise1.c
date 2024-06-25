/* Ejercicio 1: Encuesta de Opiniones

Realizar un programa que permita ingresar la opinión de los clientes de un restaurante. Las opiniones deben ser valoradas en una escala del 1 al 5. 
El ingreso de datos finalizará cuando se ingrese un número fuera de la escala (menor a 1 o mayor a 5).

Objetivos:

    Contar la cantidad de opiniones ingresadas.
    Calcular el promedio de las opiniones.
    Determinar la cantidad de opiniones "Excelentes" (valor 5). */

//una funcion que me permita contar las opinions ingresadas, y si el valor se excede del rango que el programa se termine, funcion LeerYContar
// la funcion principal que haga uso de la funcion previamente dicha
// en la funcion principal se llevaran a cabo los objetivos, tales como calcular el promedio y mostrar la cantidad de opiniones excelentes
// la cantidad de opiniones ingresadas, y la cantidad de opiniones excelentes (opiniones cuyo valor sea 5) seran trabajadas en la funcion LeerYContar

// primero debería establecer la libreria de c que quiero usar en el programa, en este caso solo necesito utilizar <stdio.h>

#include <stdio.h>

//ahora deberia trabajar en la funcion LeerYContar

// esta funcion me tiene que devolver un número entero, ya que no puede haber cantidad de opiniones con números decimales

int LeerYValidar() {

    int opinion;
    printf("Ingrese su opinión (1 a 5, otro valor si desea finalizar): ");
    scanf("%d", &opinion);
    return opinion;

}

int main() {

    int opinion;
    int cant_opiniones = 0;
    int cant_excelentes = 0;
    int suma_opiniones = 0;

    while (1) {
        opinion = LeerYValidar();

        if (opinion < 1 || opinion > 5) {
            break;
        }

        ++cant_opiniones;
        suma_opiniones += opinion;
        if (opinion == 5) {
            ++cant_excelentes;
        }

        if (cant_opiniones > 0) {
            double promedio_opiniones = (double)suma_opiniones / cant_opiniones;
            printf("Cantidad de opiniones ingresadas: %d\n", cant_opiniones);
            printf("Promedio de opiniones ingresadas: %.2f\n", promedio_opiniones);
            printf("Cantidad de opiniones excelentes (5): %d\n", cant_excelentes);
        } else {
            printf("No se ingresaron opiniones válidas.\n");
        }
    }

    return 0;
}

