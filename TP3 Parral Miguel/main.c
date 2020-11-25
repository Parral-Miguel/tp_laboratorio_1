#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "funciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    char confirma = 'n';
    int flag = 0;
    int option = 0;
    int error;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch(menu())
        {
        case 1:
            if (flag)
            {
                printf("Sobreescribir la lista existente? (s/n)\n");
                scanf("%c", &confirma);
                fflush(stdin);
                while (confirma != 's' && confirma != 'n')
                {
                    printf("Ingrese un comando valido. Sobreescribir la lista? (s/n)\n");
                    scanf("%c", &confirma);
                    fflush(stdin);
                }
                if (confirma == 's')
                {
                    flag = 0;
                }
            }
            if (!flag)
            {
                if(controller_loadFromText("data.csv",listaEmpleados))
                {

                    printf("Error al momento de cargar la lista\n");
                }
                else
                {
                    printf("Carga exitosa\n");
                    flag = 1;

                }


            }
            break;

        case 2:
            if (flag)
            {
                printf("Sobreescribir la lista existente? (s/n)\n");
                scanf("%c", &confirma);
                fflush(stdin);
                while (confirma != 's' && confirma != 'n')
                {
                    printf("Ingrese un comando valido. Sobreescribir la lista? (s/n)\n");
                    scanf("%c", &confirma);
                    fflush(stdin);
                }
                if (confirma == 's')
                {
                    flag = 0;
                }
            }
            if (!flag)
            {
                if(controller_loadFromBinary("dataBin.csv",listaEmpleados))
                {

                    printf("Error al momento de cargar la lista\n");
                }
                else
                {
                    printf("Carga exitosa\n");
                    flag = 1;
                }


            }
            break;
        case 3:

            if(!controller_addEmployee(listaEmpleados))
            {

                printf("alta exitosa\n");
                printf("%d", ll_len(listaEmpleados));
            }
            else
            {
                printf("Error al momento de añadir empleado\n");
            }
            break;

        case 4:
            if (flag)
            {
                controller_editEmployee(listaEmpleados);
                break;
            }
            else
            {
                printf("Debe cargar una lista primero\n");

            }
            break;
        case 5:
            if(flag)
            {
                printf("---BAJA DE EMPLEADO---\n");
                error = controller_removeEmployee(listaEmpleados);
                if (error)
                {
                    printf("Baja realizada con exito\n");
                }
                else
                {
                    printf("Baja no realizada\n");
                }

                break;
            }
            else
            {
                printf("Debe cargar una lista primero\n");
            }
            break;
        case 6:
            if (flag)
            {
                printf("---LISTA DE EMPLEADOS---\n");
                controller_ListEmployee(listaEmpleados);
                break;
            }
            else
            {
                printf("Debe cargar una lista primero\n");
            }
            break;
        case 7:
            if (flag)
            {
                controller_sortEmployee(listaEmpleados);
                controller_ListEmployee(listaEmpleados);
                break;
            }
            else
            {
                printf("Debe cargar una lista primero\n");
            }
            break;
        case 8:

            if(controller_saveAsText("data.csv",listaEmpleados))
                {

                    printf("Error al momento de guardar la lista\n");
                }
                else
                {
                    printf("Guardado exitoso\n");
                    flag = 1;
                }

            break;

        case 9:

            if(controller_saveAsBinary("dataBin.csv",listaEmpleados))
                {

                    printf("Error al momento de guardar la lista\n");
                }
                else
                {
                    printf("Guardado exitoso\n");
                    flag = 1;
                }

            break;

        case 10:
            printf("esta seguro de salir? (s/n)");
            scanf("%c", &confirma);
            fflush(stdin);
            if (confirma == 's')
            {
                option = 10;
                ll_deleteLinkedList(listaEmpleados);
                break;
            }
            break;

        default:
            printf("Error. Opcion invalida\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(option != 10);
    return 0;
}
