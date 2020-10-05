#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayEmployees.h"

/** \brief despliega el menu del programa y regresa la opcion ingresada como int
 *
 * \param
 * \param
 * \return regresa el entero ingresado
 *
 */
int menu ()
{
    int option;
    printf("Bienvenido. Ingrese una opcion:\n ");
    printf("1 - ALTAS:\n "); //Permite ingresar un empleado calculando el ID automaticamente. El resto es ingresado por usuario
    printf("2 - MODIFICAR:\n "); // Permite cambiar informacion del empleado ingresando su ID
    printf("3 - BAJA:\n ");   //Dar de baja un empleado ingresando su numero de ID
    printf("4 - INFORMAR\n ");  //informa listado de empleados o salario y promedios
    printf("5 - Salir:\n ");    //sale del menu
    scanf("%d", &option);
    system("cls");
    fflush(stdin);
    return option;
}

/** \brief despliega y valida el menu para modificar registro de empleado
 *
 * \param
 * \param
 * \return int opcion seleccionada
 *
 */
int modifyMenu ()
{
    int option;
    printf("Ingrese lo que desea cambiar: \n");
    printf("1 - NOMBRE:\n ");
    printf("2 - APELLIDO:\n ");
    printf("3 - SALARIO:\n ");
    printf("4 - SECTOR\n ");
    scanf("%d", &option);
    system("cls");
    fflush(stdin);
    while (option <1 || option > 4 )
    {
        printf("ingrese una opcion valida:\n");
        scanf("%d", &option);
        fflush (stdin);
    }
    return option;
}
/** \brief ingresa un numero y valida que haya sido un int
 *
 * \param
 * \param
 * \return regresa el numero ingresado
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

/** \brief ingresa un numero y valida que haya sido un float
 *
 * \param
 * \param
 * \return regresa el numero ingresado
 *
 */
float ingresarFloat ()
{
    float valido;
    float n =0;

    valido = scanf("%f", &n);
    fflush(stdin);

    while (!valido)
    {
        fflush(stdin);
        printf("Invalido. Ingrese un numero:");
        valido = scanf("%f", &n);
    }
    return n;
}


/** \brief inicializa el programa poniendo el valor de isEmpty en 1 (vacio) en todos los campos
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int initEmployees(Employee* list, int len)
{

    int error = 1;
    if (list!=NULL && len > 0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

/** \brief imprime la informacion de tabla y la data de todos los empleados de la lista
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int printEmployees(Employee* list, int len)
{

    int error = 1;
    int flag = 0;

    if( list != NULL && len > 0)
    {
        printf(" ID   Last Name    Name      Salary     Sector \n");
        printf("------------------------------------------------\n");

        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                printEmployee(list[i]);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay empleados en la lista");
        }
        printf("\n\n");

        error = 0;

    }
    return error;

}

/** \brief imprime la data de un empleado
 *
 * \param oneEmployee Employee
 * \return void
 *
 */
void printEmployee(Employee oneEmployee)
{
    printf(" %4d    %s    %s    %.2f    %d\n", oneEmployee.id, oneEmployee.lastName, oneEmployee.name, oneEmployee.salary, oneEmployee.sector);

}


/** \brief imprime la data de un empleado y la informacion de tabla para cuando hay que mostrar solo un empleado
 *
 * \param oneEmployee Employee
 * \return void
 *
 */
void printEmployeeOnce(Employee oneEmployee)
{
    system("cls");
    printf(" ID   Last Name    Name     Salary    Sector \n");
    printf("----------------------------------------------\n");
    printf(" %4d    %s      %s    %.2f    %d\n", oneEmployee.id, oneEmployee.lastName, oneEmployee.name, oneEmployee.salary, oneEmployee.sector);
}

/** \brief busca el primer indice de lista con valor isEmpty = 1.
 *
 * \param list Employee*
 * \param len int
 * \return int  devuelve el indice o un valor de error
 *
 */
int searchEmpty(Employee* list, int len)
{
    int index = -1;

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}


/** \brief da de alta a un empleado a la lista pasandole todos los valores a la funcion. Esta pone en 0 el valor de isEmpty y asigna valores a la estructura
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int  devuelve error = 0 si se realizo correctamente el alta
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int error = 1;
    int index;
    index =  searchEmpty(list, len);
    if (index != -1)
    {
        list[index].id = id;
        list[index].isEmpty = 0;
        if (name[0] > 90)       //pone primera letra de nombre y apellido en mayuscula
        {
            name[0] = toupper(name[0]);
        }
        strcpy (list[index].name, name);
        if (lastName[0] > 90)
        {
            lastName[0] = toupper(lastName[0]);
        }
        strcpy (list[index].lastName, lastName);
        list[index].salary = salary;
        list[index].sector = sector;
        printEmployeeOnce(list[index]);
        error = 0;
    }

    return error;
}

/** \brief encuentra un empleado con su numero de ID
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int el indice del empleado que se encontro o un valor de error
 *
 */
int findEmployeeById(Employee* list, int len, int id)
{
    int index = -1;

    for(int i = 0; i < len; i++)
    {

        if(list[i].id == id && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}

/** \brief Da de baja un empleado de la lista poniendo el valor de isEmpty en 1.
 *
 * \param list Employee*
 * \param len int
 * \param id int ID del empleado a dar de baja
 * \return int valor de error que define si se dio de baja o si no se realizo la misma
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int error = 1;
    int index;
    char confirm;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("  --- BAJA DE PERSONA ---\n");
        printEmployees(list, len);
        printf("Ingrese el legajo: ");
        id = ingresarInt();
        index = findEmployeeById(list, len, id);

        if( index == -1)
        {
            printf("No existe una persona con ese legajo.\n");
        }
        else
        {
            printEmployeeOnce(list[index]);
            printf("Confirma baja: (s/n)\n");
            scanf("%c", &confirm);
            fflush(stdin);
            while (confirm != 's' && confirm != 'n')
            {
                printf("Invalido. Confirme baja: (s/n)\n");
                scanf("%c", &confirm);
                fflush(stdin);
            }
            if(confirm == 's')
            {
                list[index].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }

    }

    return error;

}


/** \brief ordena los empleados para poder imprimirlos en un cierto orden por sector y alfabeticamente
 *
 * \param list Employee*
 * \param len int
 * \param order int sentido ascendente o descendente
 * \return int
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int error = 1;
    Employee auxEmployee;

    if(list != NULL && len > 0 && order >= 0 && order <= 1)
    {


        for(int i=0; i-len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {

                if (list[i].sector > list[j].sector && order == 1)
                {

                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;

                }

                else if(list[i].sector < list[j].sector && order == 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }

                else if(list[i].sector == list[j].sector && order == 1 && strcmp(list[i].lastName, list[j].lastName) > 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }

                else if(list[i].sector == list[j].sector && order == 0 && strcmp(list[i].lastName, list[j].lastName) > 0)
                {
                    auxEmployee = list[i];
                    list[i] = list[j];
                    list[j] = auxEmployee;
                }
            }
        }
        error = 0;
    }

    return error;

}

/** \brief calcula y muestra el promedio salarial, el salario total y cuales empleados superan el promedio
 *
 * \param list Employee*
 * \param len int
 * \return void
 *
 */

void averageSalary(Employee* list,int len)
{
    int counter = 0;
    int flag = 0;
    float add = 0;
    float average;

    for (int i = 0; i < len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            add += list[i].salary;
            counter++;
        }
    }
    average = add / counter;
    printf("El total de los salarios es $ %.2f \n", add);
    printf("El promedio salarial es de $ %.2f \n", average);
    printf("Los empleados que superan ese promedio son:\n\n");
    printf(" ID   Last Name    Name   Salary  Sector \n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < len; i++)
    {
        if (list[i].isEmpty == 0 && list[i].salary > average)
        {
            printEmployee(list[i]);
            flag = 1;
        }
    }
    if (!flag) {
        printf("\nNingun empleado supera ese promedio\n\n");
    }
    return;
}

/** \brief  verifica si hay almenos un empleado en el registro recorriendo los valores de isEmpty (para validacion)
 *
 * \param list Employee*
 * \param len int
 * \return int error = 1 si esta llena lista, error = 0 si encontro al menos algun empleado en la lista
 *
 */
int checkIfEmpty(Employee* list, int len)
{
    int error = 1;

    for (int i = 0; i < len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            error = 0;
        }
    }
    return error;
}
