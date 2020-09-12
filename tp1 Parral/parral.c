#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "parral.h"


/** \brief ingresa un numero y valida que haya sido un valor int
 *
 * \param
 * \param
 * \return regresa el numero ingresado
 *
 */
int ingresarNum () {
int valido;
int n;

valido = scanf("%d", &n);
while (!valido) {
    fflush(stdin);
    printf("Invalido. Ingrese un numero:");
    valido = scanf("%d", &n);
}
return n;
}


/** \ sumar dos numeros con coma.
 *
 * \param x int
 * \param y int
 * \return int resultado
 *
 */
int sumar(int x, int y) {

    return x + y;
}

/** \ restar dos numeros con coma.
 *
 * \param x int
 * \param y int
 * \return int resultado
 *
 */
int restar(int x, int y) {

    return x - y;
}

/** \ multiplicar dos numeros con coma.
 *
 * \param x int
 * \param y int
 * \return int resultado
 *
 */
int multiplicar(int x, int y) {

    return x * y;
}

/** \brief divide dos numeros y devuelve cero en vez de dividir por cero.
 *
 * \param x int dividendo
 * \param y int divisor
 * \return float
 *
 */
float dividir(float x, float y) {

    if (y == 0) {
        return 0;
    }
    return x/y;
}

/** \brief factoriza un numero
 *
 * \param x int numero a factorizar
 * \return int resultado
 *
 */
int factorizar(int x){
    int i = x-1;
    while (i > 1) {
        x = x * i;
        i--;
    }
    return x;
}

/** \brief despliega el menu de la calculadora y regresa el numero ingresado
 *
 * \param
 * \param
 * \return regresa el entero ingresado
 *
 */
int menu (){
    int opcion;
    printf("Bienvenido. Ingrese una opcion:\n ");
    printf("1 - Ingresar primer operando:\n "); //pide los valores de A y B y almacena en variables x, y.
    printf("2 - Ingresar segundo operando:\n ");
    printf("3 - Calcular todas las operaciones:\n ");   //calcula todas las operaciones
    printf("4 - Informar resultados:\n ");  //informa los resultados
    printf("5 - Salir:\n ");    //sale del menu
    scanf("%d", &opcion);
    system("cls");
    fflush(stdin);
    return opcion;
}

