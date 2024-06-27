#include <stdio.h>

// Prototipos de funciones
void cargarVentas(float facturacion[], int vendedor[], int maxVendedores);
float calcularTotalFacturacion(float facturacion[], int cantidad);
int vendedorMaximaFacturacion(float facturacion[], int cantidad);
void vendedoresSinVentas(int vendedor[], int cantidad);
void vendedoresSobrePromedio(float facturacion[], int cantidad, float promedioTotal);

int main() {
    const int MAX_VENDEDORES = 50;
    float facturacion[MAX_VENDEDORES] = {0};
    int vendedor[MAX_VENDEDORES] = {0};

    // Cargar ventas
    cargarVentas(facturacion, vendedor, MAX_VENDEDORES);

    // Calcular total de facturación para cada vendedor
    printf("\nTotal de facturación por vendedor:\n");
    for (int i = 0; i < MAX_VENDEDORES; i++) {
        if (facturacion[i] > 0) {
            printf("Vendedor %d: $%.2f\n", vendedor[i], facturacion[i]);
        }
    }

    // Calcular el vendedor con mayor facturación
    int vendedorMax = vendedorMaximaFacturacion(facturacion, MAX_VENDEDORES);
    printf("\nVendedor con mayor facturación: %d\n", vendedorMax);

    // Encontrar vendedores sin ventas
    printf("\nVendedores que no realizaron ventas:\n");
    vendedoresSinVentas(vendedor, MAX_VENDEDORES);

    // Calcular promedio total de facturación
    float totalFacturacion = calcularTotalFacturacion(facturacion, MAX_VENDEDORES);
    float promedioTotal = totalFacturacion / MAX_VENDEDORES;

    // Encontrar vendedores que superaron el promedio total de facturación
    printf("\nVendedores que superaron el promedio total de facturación ($%.2f):\n", promedioTotal);
    vendedoresSobrePromedio(facturacion, MAX_VENDEDORES, promedioTotal);

    return 0;
}

// Función para cargar las ventas y vendedores
void cargarVentas(float facturacion[], int vendedor[], int maxVendedores) {
    int codigoVendedor;
    float importeVenta;

    printf("Ingrese código de vendedor (0 para finalizar):\n");
    scanf("%d", &codigoVendedor);

    while (codigoVendedor != 0) {
        printf("Ingrese importe de la venta:\n");
        scanf("%f", &importeVenta);

        // Validar importe de venta mayor que cero
        if (importeVenta <= 0) {
            printf("Importe de venta inválido. Ingrese nuevamente:\n");
            continue;
        }

        // Agregar importe a la facturación del vendedor
        if (codigoVendedor >= 1 && codigoVendedor <= maxVendedores) {
            facturacion[codigoVendedor - 1] += importeVenta;
            vendedor[codigoVendedor - 1] = codigoVendedor;
        } else {
            printf("Código de vendedor fuera de rango. Ingrese nuevamente:\n");
            continue;
        }

        // Siguiente vendedor
        printf("Ingrese código de vendedor (0 para finalizar):\n");
        scanf("%d", &codigoVendedor);
    }
}

// Función para calcular el total de facturación
float calcularTotalFacturacion(float facturacion[], int cantidad) {
    float total = 0;
    for (int i = 0; i < cantidad; i++) {
        total += facturacion[i];
    }
    return total;
}

// Función para encontrar el vendedor con mayor facturación
int vendedorMaximaFacturacion(float facturacion[], int cantidad) {
    int codigoVendedorMax = 0;
    float maxFacturacion = 0;

    for (int i = 0; i < cantidad; i++) {
        if (facturacion[i] > maxFacturacion) {
            maxFacturacion = facturacion[i];
            codigoVendedorMax = i + 1;
        }
    }

    return codigoVendedorMax;
}

// Función para encontrar vendedores que no realizaron ventas
void vendedoresSinVentas(int vendedor[], int cantidad) {
    int sinVentas = 1;

    for (int i = 0; i < cantidad; i++) {
        if (vendedor[i] != 0) {
            sinVentas = 0;
        } else {
            printf("Vendedor %d\n", i + 1);
        }
    }

    if (sinVentas) {
        printf("Todos los vendedores realizaron ventas.\n");
    }
}

// Función para encontrar vendedores que superaron el promedio total de facturación
void vendedoresSobrePromedio(float facturacion[], int cantidad, float promedioTotal) {
    for (int i = 0; i < cantidad; i++) {
        if (facturacion[i] > promedioTotal) {
            printf("Vendedor %d\n", i + 1);
        }
    }
}
