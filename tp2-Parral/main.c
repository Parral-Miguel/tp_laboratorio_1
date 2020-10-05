#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TAM 1000

int main()
{
    int id = 1000;
    int error;// variables que reciben valores de error
    int check;
    int option; //variable para determinar accion de informar
    int order; //variable para determinar orden ascendente o descendente
    int index; //variable para indice determinado en lista[]
    int findId; //variable para id determinada
    char confirm = 'n'; // confirmacion de salida del do while
    Employee auxEmployee; // estructura auxiliar para recopilacion de datos
    Employee list [TAM]; //array de estructuras
    initEmployees (list, TAM);  // inicializo el programa con valores isEmpty = 1

    do
    {
        switch (menu())     //menu del programa
        {
        case 1:
            printf("  --- ALTA DE EMPLEADO ---\n\n");
            auxEmployee.id = id;
            printf("Ingrese nombre: \n");       //pido datos y los pongo en auxiliar para pasar por funcion
            gets(auxEmployee.name);
            printf("Ingrese apellido: \n");
            gets(auxEmployee.lastName);
            printf("Ingrese salario en $: \n");
            auxEmployee.salary = ingresarFloat();
            printf("Ingrese sector: \n");
            auxEmployee.sector = ingresarInt();
            error = addEmployee(list, TAM, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);
            if (error == 1) // si la funcion devuelve error la base de datos esta llena y el alta no se realizo
            {
                printf("Error: Base de datos llena\n");
                printf("No se realizo el alta\n");
                system("pause");
                break;
            }
            printf("\nAlta finalizada con exito \n"); // si no devuelve error se cargaron los datos correctamente
            system("pause");
            id++;
            break;

        case 2:
            check = checkIfEmpty(list, TAM);    // checkea si hay almenos un empleado en registro antes de operar
            if (check == 1)
            {
                printf("Error. No hay empleados en el registro.\n");
                system("pause");
                break;
            }
            printf("  --- MODIFICAR REGISTRO ---\n\n");
            printEmployees(list, TAM);
            printf("Ingrese la id del empleado: \n");
            findId = ingresarInt();
            index = findEmployeeById(list, TAM, findId);    //busca si la id del empleado existe devuelve valor -1 si no se enncontro la id
            if (index == -1)
            {
                printf("Error. No se encontro esa id en el registro.\n");
                system("pause");
                break;
            }
            printf("\n\n");
            switch (modifyMenu())   //menu para las opciones de modificar
            {
            case 1:
                printf("Ingrese nuevo nombre: \n");  //sobreescribe el campo en la estructura con lo que ingrese el usuario
                gets(list[index].name);     // sobre el indice que se busco previamente
                if (list[index].name[0] > 90)
                {
                    list[index].name[0] = toupper(list[index].name[0]);     //pone primera letra de nombre y apellido en mayuscula
                }
                printEmployeeOnce(list[index]);
                break;

            case 2:
                printf("Ingrese nuevo apellido: \n");
                gets(list[index].lastName);
                if (list[index].lastName[0] > 90)
                {
                    list[index].lastName[0] = toupper(list[index].lastName[0]);     //pone primera letra de nombre y apellido en mayuscula
                }
                printEmployeeOnce(list[index]);
                break;

            case 3:
                printf("Ingrese nuevo salario: \n");
                list[index].salary = ingresarFloat();
                printEmployeeOnce(list[index]);
                break;

            case 4:
                printf("Ingrese nuevo sector: \n");
                list[index].sector = ingresarInt();
                printEmployeeOnce(list[index]);
                break;
            }
            printf("\n");
            printf("Modificado correctamente\n");
            system("pause");
            break;
        case 3:
            check = checkIfEmpty(list, TAM);
            if (check == 1)
            {
                printf("Error. No hay empleados en el registro.\n");
                system("pause");
                break;
            }
            error = removeEmployee (list, TAM, findId);     //con la id, la funcion busca el indice del empleado y pone isEmpty en 1
            if (error == 1)     //devuelve distintos errores por distintas circunstancias
            {
                printf ("No se realizo la baja \n");    //la id no existe
                system("pause");
            }
            else if (error == 2)
            {
                printf ("No se realizo la baja: cancelada por el usuario\n");   //el usuario cancelo
                system("pause");
            }
            else
            {
                printf ("Baja realizada con exito \n");
                system("pause");
            }

            break;
        case 4:

            check = checkIfEmpty(list, TAM);
            if (check == 1)
            {
                printf("Error. No hay empleados en el registro.\n");
                system("pause");
                break;
            }
            printf("Informar:\n");
            printf("1 - Listado de empleados por sector:\n");
            printf("2 - Salario promedio:\n");
            option = ingresarInt();
            while (option != 1 && option != 2)      // elijo cual opcion quiero usar y compruebo que sea una opcion valida
            {
                printf("Ingrese una opcion valida\n");
                option = ingresarInt();
            }
            if (option == 1)
            {
                printf("Mostrar por orden ascendente o descendente? 1 (Asc) - 0 (DESC): \n");
                order = ingresarInt();  // ingreso el valor dependiendo de que modo quiera ver la informacion
                while (order != 0 && order != 1)
                {
                    printf("Ingrese una opcion valida: (Asc) - 0 (DESC): \n");
                    order = ingresarInt();
                }
                system("cls");
                sortEmployees(list, TAM, order);
                printEmployees(list, TAM);
                system("pause");
                break;
            }
            if (option == 2)
            {
                system("cls");
                averageSalary(list, TAM);   // la funcion calcula el total, promedio e imprime esos valores y los empleados que superan el promedio
                printf("\n");
                system("pause");
                break;
            }
        case 5:
            printf ("esta seguro de salir?: (s/n)\n");  //confirmo si quiero salir y valido el dato ingresado
            scanf ("%c", &confirm); // sobreescribo el valor de cornfirm, permitiendo salir del do while
            fflush (stdin);
            while (confirm != 's' && confirm != 'n')
            {
                printf ("opcion invalida, ingrese un caracter (s/n).\n");
                scanf ("%c", &confirm);
                fflush (stdin);
            }
            break;
        default:
            printf ("Opcion invalida, ingrese nuevamente\n");
            system("pause");
            break;
        }
        system ("cls");
    }
    while (confirm == 'n');
    return 0;
}

