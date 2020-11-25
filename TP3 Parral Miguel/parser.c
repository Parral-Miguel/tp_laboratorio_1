#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{

    Employee* empleadoAux;


    int error = 1;
    int r = 0;
    char var1[50],var3[50],var2[50],var4[50];

    if(pFile == NULL)
    {
        printf("El archivo no existe");

    }

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

        if (r == 4)
        {
            empleadoAux = employee_new();

            empleadoAux = employee_new();
            empleadoAux->id = atoi(var1);
            strcpy(empleadoAux->nombre, var2);
            empleadoAux->horasTrabajadas = atoi(var3);
            empleadoAux->sueldo = atoi(var4);

            ll_add(pArrayListEmployee, empleadoAux);

            error = 0;
        }
    }
    while(!feof(pFile));
    fclose(pFile);
    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error = 1;
    Employee* empleadoAux = NULL;

    if (pFile != NULL)
    {
        while(!feof(pFile))
        {
            empleadoAux = employee_new();

            if (empleadoAux != NULL)
            {
                fread(empleadoAux, sizeof(Employee), 1, pFile);
                ll_add(pArrayListEmployee, empleadoAux);
            }
        }
        fclose(pFile);
        error = 0;
    }
    return error;
}
