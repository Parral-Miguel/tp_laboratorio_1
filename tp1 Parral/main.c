#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "parral.h"


int main()
{
    int salir = 0;
    int ingresoA = 0;   // flags para las operaciones de switch
    int ingresoB = 0;
    int calculos = 0;
    int x;              //valores A y B
    int y;
    int resultados[5]; // resultados de la suma, resta, multiplicacion y factorizacion en ese orden
    float resultadoDivision;
    char confirmar; // caracter que confirma salida

    do {
    switch (menu()) {       //operacion de la funcion menu
        case 1:
            printf("Ingrese el valor de A: ");  //pide valor de A y lo almacena en variable x
            x = ingresarNum();
            ingresoA = 1;
            break;

        case 2:
            printf("Ingrese el valor de B: ");  //pide valor de B y lo almacena en variable y
            y = ingresarNum();
            ingresoB = 1;
            break;

        case 3:
            if(ingresoA == 0 || ingresoB == 0) {
                printf("Operando no ingresado. Ingrese con 1 o 2 en el menu\n");
                break;
            } else {
                printf("A: %d -- B: %d\n\n", x, y);
                resultados[0] = sumar(x, y);
                resultados[1] = restar(x, y);
                resultados[2] = multiplicar(x, y);     // realiza las operaciones
                resultados[3] = factorizar(x);
                resultados[4] = factorizar(y);
                resultadoDivision = dividir(x, y);
                calculos = 1;
                printf("Calculos realizados. Mostrar resultado con 4 en el menu\n");
                break;
            }
        case 4:
            if(!calculos) {
                printf("Calculos aun no realizados. Usar la opcion 3.\n");  // despliega mensaje si se muestra antes de calcular
                break;
            }
            printf("A: %d -- B: %d\n\n", x, y);
            printf("El resultado de A+B es: %d\n ", resultados[0]);
            printf("El resultado de A-B es: %d\n ", resultados[1]);   //despliega los resultados
            if (y == 0) {
                printf("No es posible dividir por cero\n ");
            } else {
                printf("El resultado de A/B es: %.2f\n ", resultadoDivision);
            }
            printf("El resultado de A*B es: %d\n ", resultados[2]);
            printf("El factorial de A es: %d y El factorial de B es: %d\n", resultados[3], resultados[4]);
            break;

        case 5:
            printf("Esta seguro de salir? - s/n\n");        // confirmacion y validacion de salida
            scanf("%c", &confirmar);
            fflush(stdin);
            while( confirmar != 's' && confirmar != 'n') {
                printf("Opcion invalida. Esta seguro de salir? - s/n\n");
                scanf("%c", &confirmar);
                fflush(stdin);
                }
            if(confirmar == 's') {
                salir = 1;
                break;
            } else {
                break;
            }
        default:
            printf("Opcion invalida\n");    // mensaje de ingreso invalido
            break;
    }
    system("pause");
    system("cls");
    }while (salir == 0);    // comienza de nuevo a menos que el flag salir haya cambiado
    return 0;
}
