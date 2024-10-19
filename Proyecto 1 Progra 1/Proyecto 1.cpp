#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int esPrimo(int numero) {
    if (numero <= 1) return 0; 
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) return 0; 
    }
    return 1; // Primo
}

int main() {
    int numeros[100]; 
    int cantidad = 0;
    int numero;

    while (1) {
        printf("Ingresa un numero entero (o escribe -1 para terminar): ");
        scanf("%d", &numero);

        if (numero == -1) 
		break; 

        numeros[cantidad++] = numero; 

        if (esPrimo(numero)) {
            printf("El numero %d es un numero primo \n", numero);
        } else {
            printf("El numero %d No es un numero primo \n", numero);
        }
    }

    if (cantidad == 0) {
        printf("No se ingresaron numeros \n");
        return 0;
    }

    int maxNum = numeros[0];
    int posMax = 0;
    int sumaPrimos = 0, cantidadPrimos = 0;
    int sumaNoPrimos = 0, cantidadNoPrimos = 0;

    for (int i = 0; i < cantidad; i++) {
        if (numeros[i] > maxNum) {
            maxNum = numeros[i];
            posMax = i;
        }

        if (esPrimo(numeros[i])) {
            sumaPrimos += numeros[i];
            cantidadPrimos++;
        } else {
            sumaNoPrimos += numeros[i];
            cantidadNoPrimos++;
        }
    }

    double promedioPrimos = cantidadPrimos > 0 ? (double)sumaPrimos / cantidadPrimos : 0;
    double promedioNoPrimos = cantidadNoPrimos > 0 ? (double)sumaNoPrimos / cantidadNoPrimos : 0;

    printf("Numero Mayor Ingresado: %d en la posicion %d\n", maxNum, posMax + 1);
    printf("Cantidad de Numeros Primos: %d\n", cantidadPrimos);
    printf("Sumatoria de los Numeros Primos: %d\n", sumaPrimos);
    printf("Promedio de los Numeros Primos: %.2f\n", promedioPrimos);
    printf("Cantidad de Numeros No Primos: %d\n", cantidadNoPrimos);
    printf("Sumatoria de Numeros No Primos: %d\n", sumaNoPrimos);
    printf("Promedio de Numeros No Primos: %.2f\n", promedioNoPrimos);

    return 0;
}

