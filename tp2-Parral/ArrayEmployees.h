#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct //estructura de cada empleado
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

int menu();     //despliega el menu
int modifyMenu (); //despliega el menu de opcion modificar
int ingresarInt ();     //ingresa un entero y valida que sea un numero
float ingresarFloat (); //ingresa un flotante y valida que sea un numero
int checkIfEmpty (Employee* list, int len); //verifica si hay almenos un empleado en el registro
int initEmployees (Employee* list, int len); //inicializa la cadena de estructuras poniendo el flag de vacio (isEmpty) en 1
int printEmployees (Employee* list, int len); //muestra todos los empleados de la lista
void printEmployee (Employee oneEmployee); //muestra un empleado de la lista
void printEmployeeOnce (Employee oneEmployee); //muestra un solo empleado de la lista con la informacion de tabla
int searchEmpty (Employee* list, int len); //busca el primer espacio libre de la lista
int addEmployee (Employee* list, int len, int id, char name[],char lastName[],float salary,int sector); //da de alta un empleado
int removeEmployee (Employee* list, int len, int id);//remueve un empleado de la lista
int findEmployeeById (Employee* list, int len, int id);//encuentra el indice que contiene los datos de un empleado buscado por su ID
int sortEmployees (Employee* list, int len, int order);//organiza empleados por orden alfabetico y por sector, ascendente o descendente.
void averageSalary (Employee* list, int len);//calcula el promedio salarial, la suma de salarios y muestra cuales empleados superan el promedio



