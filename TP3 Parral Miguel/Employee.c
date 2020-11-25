#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"

Employee* employee_new()
{
    Employee* newEmployee;

    newEmployee = (Employee*) malloc(sizeof(Employee));

    return newEmployee;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    return 0;
}
void employee_delete(Employee* this)

{
    free(this);
}

int employee_setId(Employee* this,int id)
{
    if (this != NULL)
    {
        this->id = id;
    }

    return 0;
}
int employee_getId(Employee* this,int* id)
{

    int error = 0;
    if (this != NULL)
    {
        *id = this->id;
        error = 1;
    }

    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
    }
    return 0;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int error = 0;
    if (this != NULL)
    {
        strcpy(nombre, this->nombre);
        error = 1;
    }

    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if (this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
    }
    return 0;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error = 0;
    if (this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 1;
    }

    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    if (this != NULL)
    {
        this->sueldo = sueldo;
    }

    return 0;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 0;
    if (this != NULL)
    {
        *sueldo = this->sueldo;
        error = 1;
    }

    return error;
}

void employee_listarUno(LinkedList* pArrayEmployees,Employee* this, int index)
{

    this = ll_get(pArrayEmployees, index);

    printf("ID   NOMBRE   HORAS   SUELDO\n");
    printf("%d, %s, %d, %d\n\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
}

int employee_sortBy_name(void* empleadoA, void* empleadoB)
{
    int comparacion = 0;
    char nombreA [50];
    char nombreB [50];

    if ((employee_getNombre((Employee*) empleadoA, nombreA)) &&
            (employee_getNombre((Employee*) empleadoB, nombreB)))
    {
        comparacion = strcmp(nombreA, nombreB);
    }
    return comparacion;
}

int employee_sortBy_id(void* empleadoA, void* empleadoB)
{
    int comparacion = 0;
    int idA;
    int idB;
    if ((employee_getId((Employee*) empleadoA, &idA)) &&
            (employee_getId((Employee*) empleadoB, &idB)))
    {
        comparacion = idA - idB;
    }
    return comparacion;
}

int employee_sortBy_horasTrabajadas(void* empleadoA, void* empleadoB)
{
    int comparacion = 0;
    int horasA;
    int horasB;

    if ((employee_getHorasTrabajadas((Employee*) empleadoA, &horasA)) &&
            (employee_getHorasTrabajadas((Employee*) empleadoB, &horasB)))
    {

        comparacion = horasA - horasB;
    }
    return comparacion;
}

int employee_sortBy_sueldo(void* empleadoA, void* empleadoB)
{
    int comparacion = 0;
    int sueldoA;
    int sueldoB;

    if ((employee_getSueldo((Employee*) empleadoA, &sueldoA)) &&
            (employee_getSueldo((Employee*) empleadoB, &sueldoB)))
    {

        comparacion = sueldoA - sueldoB;
    }
    return comparacion;
}

