#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"
#include "controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int error;
    FILE* pFile;
    ll_clear(pArrayListEmployee);
    pFile = fopen(path,"r");
    error = parser_EmployeeFromText(pFile,pArrayListEmployee);
    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error;
    FILE* pFile;

    ll_clear(pArrayListEmployee);
    pFile = fopen(path, "rb");
    error = parser_EmployeeFromBinary(pFile, pArrayListEmployee);


    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int nextId;
    int error;
    Employee newEmployeeAux;
    Employee* newEmployee;
    Employee* nextIdFinder;
    nextId = ll_len(pArrayListEmployee) +1;

    for (int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        nextIdFinder = ll_get(pArrayListEmployee, i);
        while(nextId == nextIdFinder->id)
        {
            nextId++;
        }
    }

    newEmployee = employee_new();

    employee_setId(newEmployee, nextId);

    printf("Ingrese nombre de empleado:\n");
    gets(newEmployeeAux.nombre);
    fflush(stdin);
    employee_setNombre(newEmployee, newEmployeeAux.nombre);

    printf("Ingrese horas trabajadas:\n");
    scanf("%d", &newEmployeeAux.horasTrabajadas);
    fflush(stdin);
    employee_setHorasTrabajadas(newEmployee, newEmployeeAux.horasTrabajadas);

    printf("Ingrese sueldo de empleado:\n");
    scanf("%d", &newEmployeeAux.sueldo);
    fflush(stdin);
    employee_setSueldo(newEmployee, newEmployeeAux.sueldo);

    error = ll_add(pArrayListEmployee, newEmployee);

    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleadoAux;
    int idAux;
    int indice;
    int flag = 0;
    printf("---EDITAR EMPLEADO---\n\n");
    printf("Ingresar la ID del empleado\n");
    controller_ListEmployee(pArrayListEmployee);
    scanf("%d", &idAux);


    for (int i = 0; i<ll_len(pArrayListEmployee); i++)
    {
        empleadoAux = ll_get(pArrayListEmployee,i);
        if (empleadoAux->id == idAux)
        {
            flag = 1;
            indice = i;
        }

    }
    if (flag)
    {
        system("cls");
        empleadoAux = ll_get(pArrayListEmployee,indice);
        employee_listarUno(pArrayListEmployee, empleadoAux, indice);
        switch(menuModificar())
        {
        case 1:
            printf("Ingrese la nueva ID\n");
            scanf("%d", &empleadoAux->id);
            fflush(stdin);
            employee_setId(empleadoAux, empleadoAux->id);
            system("cls");
            employee_listarUno(pArrayListEmployee, empleadoAux, indice);
            break;

        case 2:
            printf("Ingrese el nuevo nombre\n");
            gets(empleadoAux->nombre);
            fflush(stdin);
            employee_setNombre(empleadoAux, empleadoAux->nombre);
            system("cls");
            employee_listarUno(pArrayListEmployee, empleadoAux, indice);
            break;

        case 3:
            printf("Ingrese las nuevas horas\n");
            scanf("%d", &empleadoAux->horasTrabajadas);
            fflush(stdin);
            employee_setId(empleadoAux, empleadoAux->horasTrabajadas);
            system("cls");
            employee_listarUno(pArrayListEmployee, empleadoAux, indice);
            break;

        case 4:
            printf("Ingrese el nuevo sueldo\n");
            scanf("%d", &empleadoAux->sueldo);
            fflush(stdin);
            employee_setId(empleadoAux, empleadoAux->sueldo);
            system("cls");
            employee_listarUno(pArrayListEmployee, empleadoAux, indice);
            break;

        case 5:
            printf("Regresando al menu principal.\n");
            break;
        }
    }
    else
    {
        system("cls");
        printf("no existe empleado con esa ID\n");
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    char confirmar = 'n';
    int error = 0;
    Employee* empleadoAux;
    int idAux;
    int indice;
    int flag = 0;
    printf("Ingresar la ID del empleado\n");
    controller_ListEmployee(pArrayListEmployee);
    scanf("%d", &idAux);
    fflush(stdin);


    for (int i = 0; i<ll_len(pArrayListEmployee); i++)
    {
        empleadoAux = ll_get(pArrayListEmployee,i);
        if (empleadoAux->id == idAux)
        {
            flag = 1;
            indice = i;
        }

    }
    if (flag)
    {
        system("cls");
        empleadoAux = ll_get(pArrayListEmployee,indice);
        employee_listarUno(pArrayListEmployee, empleadoAux, indice);
        printf("Esta seguro de eliminar este empleado? (s/n)\n");
        scanf("%c", &confirmar);
        fflush(stdin);
        while (confirmar != 's' && confirmar != 'n')
        {
            printf("Ingrese un comando valido. Esta seguro de eliminar este empleado? (s/n)\n");
            scanf("%c", &confirmar);
            fflush(stdin);
        }
        if (confirmar == 's')
        {
            ll_remove(pArrayListEmployee, indice);
            employee_delete(empleadoAux);
            error = 1;
        }

    }


    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    printf("ID   NOMBRE   HORAS   SUELDO\n");
    Employee empleadoAux;
    Employee* direccionEmpleado;
    direccionEmpleado = &empleadoAux;
    int tam = ll_len(pArrayListEmployee);
    for (int i = 0; i < tam; i++)
    {
        direccionEmpleado = ll_get(pArrayListEmployee, i);
        if(direccionEmpleado != NULL && direccionEmpleado->id != 0)
        {

            printf("%d, %s, %d, %d\n",
                   direccionEmpleado->id,
                   direccionEmpleado->nombre,
                   direccionEmpleado->horasTrabajadas,
                   direccionEmpleado->sueldo);
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    char confirmar;
    int orden;
    printf("---ORDENAR EMPLEADOS---\n\n");
    switch(menuSort())
    {
    case 1:
        printf("Orden (a)scendete o (d)escendente? (s/n)\n");
        scanf("%c", &confirmar);
        fflush(stdin);
        while (confirmar != 'a' && confirmar != 'd')
        {
            printf("Ingrese un comando valido. Esta seguro de eliminar este empleado? (s/n)\n");
            scanf("%c", &confirmar);
            fflush(stdin);
        }

        if (confirmar == 'a')
        {
            orden = 1;
        }
        else
        {
            orden = 0;
        }
        ll_sort(pArrayListEmployee, employee_sortBy_id, orden);
        break;

    case 2:
        printf("Orden (a)scendete o (d)escendente? (s/n)\n");
        scanf("%c", &confirmar);
        fflush(stdin);
        while (confirmar != 'a' && confirmar != 'd')
        {
            printf("Ingrese un comando valido. Esta seguro de eliminar este empleado? (s/n)\n");
            scanf("%c", &confirmar);
            fflush(stdin);
        }

        if (confirmar == 'a')
        {
            orden = 1;
        }
        else
        {
            orden = 0;
        }
        ll_sort(pArrayListEmployee, employee_sortBy_name, orden);
        break;

    case 3:
        printf("Orden (a)scendete o (d)escendente? (s/n)\n");
        scanf("%c", &confirmar);
        fflush(stdin);
        while (confirmar != 'a' && confirmar != 'd')
        {
            printf("Ingrese un comando valido. Esta seguro de eliminar este empleado? (s/n)\n");
            scanf("%c", &confirmar);
            fflush(stdin);
        }

        if (confirmar == 'a')
        {
            orden = 1;
        }
        else
        {
            orden = 0;
        }
        ll_sort(pArrayListEmployee, employee_sortBy_horasTrabajadas, orden);
        break;

    case 4:

        printf("Orden (a)scendete o (d)escendente? (s/n)\n");
        scanf("%c", &confirmar);
        fflush(stdin);
        while (confirmar != 'a' && confirmar != 'd')
        {
            printf("Ingrese un comando valido. Esta seguro de eliminar este empleado? (s/n)\n");
            scanf("%c", &confirmar);
            fflush(stdin);
        }

        if (confirmar == 'a')
        {
            orden = 1;
        }
        else
        {
            orden = 0;
        }
        ll_sort(pArrayListEmployee, employee_sortBy_sueldo, orden);
        break;

    case 5:
        printf("Regresando al menu principal.\n");
        break;

    default:
        printf("Opcion invalida\n");
        break;
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    char primeraLinea[50]="ID, NOMBRE, HORAS TRABAJADAS, SUELDO\n";
    FILE* pFile;
    Employee* empleadoAux;

    if((pFile=fopen(path,"w"))!=NULL) //Se abre en modo escritura
    {

        fprintf ( pFile,"%s", primeraLinea);    //Se escribe al archivo

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = ll_get(pArrayListEmployee, i);
            fprintf(pFile,"%d, %s, %d, %d\n",
                    empleadoAux->id,
                    empleadoAux->nombre,
                    empleadoAux->horasTrabajadas,
                    empleadoAux->sueldo);

        }
        error = 0;
        fclose(pFile);
    }
    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{

    int error = 1;
    FILE *pFile;
    Employee* empleadoAux;

    if((pFile=fopen(path,"wb"))!=NULL) //Se abre en modo escritura
    {

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = ll_get(pArrayListEmployee, i);
            fwrite (empleadoAux, sizeof(Employee), 1, pFile);

        }
        error = 0;
        fclose(pFile);
    }

    return error;
}

