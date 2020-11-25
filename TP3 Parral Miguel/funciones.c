#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief ingreso un int y valida que sea int
 *
 * \param
 * \param
 * \return
 *
 */
int ingresarInt ()
{
    int valido;
    int n;

    valido = scanf("%d", &n);
    fflush(stdin);

    while (!valido)
    {
        fflush(stdin);
        printf("Invalido. Ingrese un numero:");
        valido = scanf("%d", &n);
    }
    return n;
}

/** \brief menu principal
 *
 * \param
 * \param
 * \return
 *
 */
int menu ()
{
    int option;
    printf("Bienvenido. Ingrese una opcion:\n ");
    printf("1 - CARGAR DATOS DE EMPLEADOS (ARCHIVO CSV):\n "); //Permite ingresar calculando el ID automaticamente. El resto es ingresado por usuario
    printf("2 - CARGAR DATOS DE EMPLEADOS (ARCHIVO BINARIO):\n "); // Permite cambiar informacion ID
    printf("3 - ALTA DE EMPLEADO:\n ");   //Dar de baja ingresando numero de ID
    printf("4 - MODIFCIAR DATOS DE EMPLEADO\n ");  //listar
    printf("5 - BAJA DE EMPLEADO\n "); //listar
    printf("6 - LISTAR EMPLEADOS\n "); //listar
    printf("7 - ORDENAR EMPELADOS\n "); //listar
    printf("8 - GUARDAR DATOS DE EMPLEADOS (ARCHIVO CSV)\n ");  //Permite ingresar calculando el ID automaticamente. El resto es ingresado por usuario
    printf("9 - GUARDAR DATOS DE EMPLEADOS (ARCHIVO BINARIO)\n ");    //listar
    printf("10 - SALIR   :\n ");    //sale del menu
    scanf("%d", &option);
    system("cls");
    fflush(stdin);
    return option;
}

/** \brief menu para opcion modificar
 *
 * \param
 * \param
 * \return
 *
 */
int menuModificar ()
{
    int opcion;
    printf("Ingrese lo que desea cambiar: \n");
    printf("1 - ID:\n ");
    printf("2 - NOMBRE:\n ");
    printf("3 - HORAS TRABAJADAS:\n ");
    printf("4 - SUELDO:\n ");
    printf("5 - VOLVER AL MENU:\n ");
    scanf("%d", &opcion);
    system("cls");
    fflush(stdin);
    while (opcion <1 && opcion > 5 )
    {
        printf("ingrese una opcion valida:\n");
        scanf("%d", &opcion);
        fflush (stdin);
    }
    return opcion;
}

int menuSort ()
{
    int opcion;
    printf("Ordenar de acuerdo a: \n");
    printf("1 - ID:\n ");
    printf("2 - NOMBRE:\n ");
    printf("3 - HORAS TRABAJADAS:\n ");
    printf("4 - SUELDO:\n ");
    printf("5 - VOLVER AL MENU:\n ");
    scanf("%d", &opcion);
    system("cls");
    fflush(stdin);
    while (opcion <1 && opcion > 5 )
    {
        printf("ingrese una opcion valida:\n");
        scanf("%d", &opcion);
        fflush (stdin);
    }
    return opcion;
}


