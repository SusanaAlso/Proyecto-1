#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    int tipoCliente, tipoTiquete, cantidad;
    float montoPorTiquete, montoVenta, descuento, subtotal, impuesto, total;
    int cantidadGaleria = 0, cantidadPalco = 0;
    float acumuladoGaleria = 0, acumuladoPalco = 0, acumuladoGeneral = 0;
    int numeroFactura = 1;
    char continuar;

    do {
        
        char cedula[20];
        char nombre[50];

        printf("Ingrese la cedula del cliente: ");
        scanf("%s", cedula);
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", nombre);
        printf("Tipo de cliente (1=infante/Adulto Mayor, 2=Adulto): ");
        scanf("%d", &tipoCliente);
        printf("Tipo de tiquete (1=Tiquete Galeria, 2=Tiquete Palco): ");
        scanf("%d", &tipoTiquete);
        printf("Cantidad de tiquetes a comprar: ");
        scanf("%d", &cantidad);

        if (tipoTiquete == 1) {
            montoPorTiquete = 6000;
            cantidadGaleria += cantidad;
        } else {
            montoPorTiquete = 12000;
            cantidadPalco += cantidad;
        }

        montoVenta = cantidad * montoPorTiquete;

        if (tipoCliente == 1) { 
            descuento = montoVenta * 0.30;
        } else { 
            descuento = 0;
        }

        subtotal = montoVenta - descuento;
        impuesto = subtotal * 0.13; 
        total = subtotal + impuesto;

        printf("\nFactura No: %d\n", numeroFactura);
        printf("Cedula: %s\n", cedula);
        printf("Nombre: %s\n", nombre);
        printf("Tipo de cliente: %s\n", tipoCliente == 1 ? "infante/Adulto Mayor" : "Adulto");
        printf("Tipo de tiquete: %s\n", tipoTiquete == 1 ? "Galeria" : "Palco");
        printf("Cantidad de tiquetes: %d\n", cantidad);
        printf("Monto unitario: %.2f\n", montoPorTiquete);
        printf("Monto de venta: %.2f\n", montoVenta);
        printf("Descuento: %.2f\n", descuento);
        printf("Subtotal: %.2f\n", subtotal);
        printf("Impuesto: %.2f\n", impuesto);
        printf("Total a pagar: %.2f\n\n", total);

        acumuladoGeneral += total;
        if (tipoTiquete == 1) {
            acumuladoGaleria += total;
        } else {
            acumuladoPalco += total;
        }

        numeroFactura++;

        printf("¿Desea ingresar otra venta? (s/n): ");
        continuar = getch();
        printf("\n");

    } while (continuar == 's' || continuar == 'S');

    printf("\nEstadísticas finales:\n");
    printf("Cantidad de entradas Tiquetes Galeria: %d\n", cantidadGaleria);
    printf("Acumulado Dinero por Tiquetes Galeria: %.2f\n", acumuladoGaleria);
    printf("Cantidad de entradas Tiquetes Palco: %d\n", cantidadPalco);
    printf("Acumulado Dinero por Tiquetes Palco: %.2f\n", acumuladoPalco);
    printf("Cantidad General de Entradas: %d\n", cantidadGaleria + cantidadPalco);
    printf("Acumulado General Dinero por Entradas: %.2f\n", acumuladoGeneral);
    printf("Promedio General por Ventas: %.2f\n", (numeroFactura > 1) ? (acumuladoGeneral / (numeroFactura - 1)) : 0);

    return 0; 
}

