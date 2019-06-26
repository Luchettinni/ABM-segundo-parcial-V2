#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include "LinkedList.h"

#endif // LINKEDLIST_H_INCLUDED

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED

employee* employee_newEmployee()
{
    employee* newEmployee = (employee*) malloc(sizeof(employee));

    if ( newEmployee != NULL )
    {
        newEmployee->id = 0;
        strcpy( newEmployee->name, " " );
        strcpy( newEmployee->surname, " " );
        newEmployee->salary = 0;
        newEmployee->eDate.day = 0;
        newEmployee->eDate.month = 0;
        newEmployee->eDate.year = 0;

    }

    return newEmployee;
}

employee* employee_setEmployee( char* id, char* name, char* surName, char* salary, char* day, char* month, char* year)
{
    int todoOK = -1;

    employee* employeeToSet = employee_newEmployee();

    if ( employeeToSet != NULL )
    {
        employeeToSet->id = atoi(id);
        strcpy( employeeToSet->name, name );
        strcpy( employeeToSet->surname, surName );
        employeeToSet->salary = atof(salary);
        employeeToSet->eDate.day = atoi(day);
        employeeToSet->eDate.month = atoi(month);
        employeeToSet->eDate.year = atoi(year);
        todoOK = 0;
    }

    if (todoOK == -1)
    {
        free(employeeToSet);
        employeeToSet = NULL;
    }

    return employeeToSet;


}

int employee_cargarListaAImprimir( LinkedList* lista, char* path )
{
    int auxReturn = -1;
    int cant;
    char buffer [7][25];

    employee* employeeToLoad;

    FILE* file;

    file = fopen(path, "r");

    if ( file != NULL && lista != NULL)
    {
        fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4] );
        ll_clear(lista);

        while( !feof(file) )
        {
            cant = fscanf(file, "%[^,],%[^,],%[^,],$%[^,],%[^/]/%[^/]/%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
            if ( cant < 7 )
            {
                if ( feof(file) )
                {
                    break;
                }
                else
                {
                    system("cls");
                    printf("//ERROR// no se pudo leer el ultimo registro");
                    break;
                }
            }

            employeeToLoad = employee_newEmployee();

            if ( employeeToLoad != NULL )
            {
                employeeToLoad = employee_setEmployee( buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
                ll_add(lista, employeeToLoad);
            }
            else
            {
                printf("algo salio para el tuje...");
                ll_clear(lista);
                break;
            }
            auxReturn = 0;
        }
    }

    fclose(file);
    return auxReturn;
}

int employee_guardarListaAImprimir ( LinkedList* lista, char* path )
{
    int len;
    int auxReturn = -1;

    employee* employeeToSave = employee_newEmployee();
    FILE* file;

    if ( ll_len(lista) > 0 )
    {
        file = fopen(path, "w");
    }
    else
    {
        file = NULL;
    }


    if ( lista != NULL && file != NULL )
    {
        len = ll_len(lista);

        fprintf(file, "id,name,surname,salary,date\n" );
        for ( int i = 0; i < len; i++ )
        {
            employeeToSave = ll_get(lista, i);
            fprintf(file, "%d,%s,%s,$%8.2f,%.2d/%.2d/%.4d\n", employeeToSave->id, employeeToSave->name, employeeToSave->surname, employeeToSave->salary, employeeToSave->eDate.day, employeeToSave->eDate.month, employeeToSave->eDate.year);
        }

        auxReturn = 0;
    }

    fclose(file);
    return auxReturn;
}

int employee_cargarListaBin ( LinkedList* lista, char* path )
{
    int cant;
    int auxReturn = -1;

    employee* employeeToLoad = NULL;
    FILE* file;

    file = fopen(path, "rb");

    if ( lista != NULL && file != NULL )
    {
        ll_clear(lista);

        while( !feof(file) )
        {
            employeeToLoad = employee_newEmployee();

            cant = fread(employeeToLoad,sizeof(employee),1,file);

            if ( cant != 1 )
            {
               if(feof(file))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro");
                    break;
                }
            }

            if (employeeToLoad != NULL)
            {
                ll_add(lista, employeeToLoad);
            }
            else
            {
                printf("ERROR: no se pudo conseguir espacio para realizar el cargado\n\n");
                ll_clear(lista);
                break;
            }
        }
        auxReturn = 0;
    }

    fclose(file);
    return auxReturn;
}

int employee_guardarListaBin ( LinkedList* lista, char* path )
{
    int len;
    int auxReturn = -1;

    employee* employeeToSave = employee_newEmployee();
    FILE* file;

    if ( ll_len(lista) > 0 )
    {
        file = fopen(path, "wb");
    }
    else
    {
        file = NULL;
    }

    if ( lista != NULL && file != NULL )
    {
        len = ll_len(lista);
        for ( int i = 0; i < len; i++ )
        {
            employeeToSave = ll_get(lista, i);
            fwrite(employeeToSave, sizeof(employee), 1, file );
        }

        auxReturn = 0;
    }

    fclose(file);
    return auxReturn;
}

int listarEmpleados( LinkedList* lista )
{
    int len;
    int auxReturn = -1;
    employee* employeeToList = employee_newEmployee();

    if ( ll_isEmpty(lista) == 0 )
    {
        if ( lista != NULL && employeeToList != NULL )
        {
            system("cls");
            len = ll_len(lista);
            printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||  ID  | NOMBRE                    | APELLIDO                  | SALARIO   | INGRESO    ||\n");
            printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            for ( int i = 0; i < len; i++ )
            {
                employeeToList = ll_get(lista, i);
                printf("|| %04d | %-25s | %-25s | $%-8.2f | %.2d/%.2d/%.4d ||\n", employeeToList->id, employeeToList->name, employeeToList->surname, employeeToList->salary, employeeToList->eDate.day, employeeToList->eDate.month, employeeToList->eDate.year);
            }

            auxReturn = 0;
        }
    }

    return auxReturn;
}

int ordenarListaSalario ( void* employeeA, void* employeeB )
{
    int auxReturn = 0;

    if( ((employee*) employeeA)->salary > ((employee*) employeeB)->salary )
    {
        auxReturn = 1;
    }

    if( ((employee*) employeeA)->salary < ((employee*) employeeB)->salary )
    {
        auxReturn = -1;
    }

    return auxReturn;
}

int ordenarListaFechaDeIngreso ( void* employeeA, void* employeeB )
{
    int auxReturn = 0;

    if ( ((employee*) employeeA)->eDate.year == ((employee*) employeeB)->eDate.year )
    {
        if ( ((employee*) employeeA)->eDate.month > ((employee*) employeeB)->eDate.month )
        {
            auxReturn = 1;
        }
        else if ( ((employee*) employeeA)->eDate.month == ((employee*) employeeB)->eDate.month )
        {
            if ( ((employee*) employeeA)->eDate.day > ((employee*) employeeB)->eDate.day )
            {
                 auxReturn = 1;
            }
        }
    }
    else if ( ((employee*) employeeA)->eDate.year > ((employee*) employeeB)->eDate.year )
    {
        auxReturn = 1;
    }

    if ( ((employee*) employeeA)->eDate.year == ((employee*) employeeB)->eDate.year )
    {
        if ( ((employee*) employeeA)->eDate.month < ((employee*) employeeB)->eDate.month )
        {
            auxReturn = -1;
        }
        else if ( ((employee*) employeeA)->eDate.month == ((employee*) employeeB)->eDate.month )
        {
            if ( ((employee*) employeeA)->eDate.day < ((employee*) employeeB)->eDate.day )
            {
                 auxReturn = -1;
            }
        }
    }
    else if ( ((employee*) employeeA)->eDate.year < ((employee*) employeeB)->eDate.year )
    {
        auxReturn = -1;
    }

    return auxReturn;
}

int ordenarListaNombreYApellido ( void* employeeA, void* employeeB )
{
    int auxReturn = 0;
    int compareNames;
    int compareSurnames;

    compareNames = stricmp( ((employee*) employeeA)->name,((employee*) employeeB)->name );
    compareSurnames = stricmp( ((employee*) employeeA)->surname,((employee*) employeeB)->surname );

    if(  compareNames > 0 )
    {
        auxReturn = 1;
    }

    if( compareNames == 0 && compareSurnames > 0 )
    {
        auxReturn = 1;
    }

    if( compareNames < 0 )
    {
        auxReturn = -1;
    }

    if( compareNames == 0 && compareSurnames < 0 )
    {
        auxReturn = -1;
    }

    return auxReturn;
}

int employee_ordenarLista ( LinkedList* lista, int opcion )
{
    int auxReturn = ll_isEmpty(lista);

    if ( auxReturn == 0 )
    {
        if ( opcion == 1 )
        {
            auxReturn = ll_sort( lista, ordenarListaNombreYApellido, 1 );
        }
        else if ( opcion == 2 )
        {
            auxReturn = ll_sort( lista, ordenarListaSalario, 1 );
        }
        else if ( opcion == 3 )
        {
            auxReturn = ll_sort( lista, ordenarListaFechaDeIngreso, 1 );
        }
    }

    return auxReturn;
}

int employee_removeList( LinkedList* lista )
{
    int auxReturn = -1;

    if ( lista != NULL && ll_isEmpty(lista) == 0 )
    {
        auxReturn = ll_clear(lista);
    }

    return auxReturn;
}

employee* employee_findEmployeeById( LinkedList* lista, char* mensaje )
{
    int id;

    fflush(stdin);
    printf("%s", mensaje);
    scanf("%d", &id);

    employee* employeeToFind = NULL;

    for ( int i = 0; i < ll_len(lista); i++ )
    {
        employeeToFind  = ll_get(lista, i);
        if ( employeeToFind->id == id )
        {
            break;
        }
        else
        {
            employeeToFind = NULL;
        }
    }

    return employeeToFind;
}

int employee_removerEmpleado( LinkedList* lista )
{
    int returnAux = -1;

    employee* employeeToRemove = NULL;
    employeeToRemove = employee_findEmployeeById(lista, "||\n|| Ingrese el ID (legajo) del empleado que desea eliminar: ");

    if ( employeeToRemove != NULL )
    {
        for ( int i = 0; i < ll_len(lista); i++ )
        {
            if ( employeeToRemove == ll_get(lista, i) )
            {
                ll_remove(lista, i);
                returnAux = 0;
                break;
            }

        }
    }
    return returnAux;
}

int employee_altaEmpleado( LinkedList* lista )
{
    int returnAux = 0 ;
    int max = 0;
    employee* newEmployee = NULL;

    if ( lista != NULL )
    {

        for ( int i = 0; i < ll_len(lista); i++ )
        {
            newEmployee  = ll_get(lista, i);

            if ( newEmployee->id > max )
            {
                max = newEmployee->id;
            }
        }

        max++;

        newEmployee = employee_newEmployee();

        if ( newEmployee != NULL )
        {
            newEmployee->id = max;
            input_getName(newEmployee->name, "||\n|| Ingrese el nombre del empleado: ", "||\n|| //ERROR// El nombre debe tener mas de 2 letras y menos de 25", 2, 25);
            input_getName(newEmployee->surname, "||\n|| Ingrese el apellido del empleado: ", "||\n|| //ERROR// El apellido debe tener mas de 2 letras y menos de 25", 2, 25);
            input_getFloat(&newEmployee->salary, "||\n|| Ingrese el salario del empleado: ", "||\n|| //ERROR// El salario no cumple con los rangos minimos/maximos", 8000, 100000);

            input_getInt(&newEmployee->eDate.day, "||\n|| Ingrese el dia de ingreso: ", "||\n|| //ERROR// Lo ingresado no es un dato valido...", 1, 32);
            input_getInt(&newEmployee->eDate.month, "||\n|| Ingrese el mes de ingreso: ", "||\n|| //ERROR// Lo ingresado no es un dato valido...", 1, 12);
            input_getInt(&newEmployee->eDate.year, "||\n|| Ingrese el year de ingreso: ", "||\n|| //ERROR// Lo ingresado no es un dato valido...", 2018, 2019);
            returnAux = 0;

            ll_add(lista, newEmployee);
        }
    }

    return returnAux;
}

LinkedList* employee_filter(LinkedList* lista)
{

    int len;
    LinkedList* newLinkedList = ll_newLinkedList();
    employee* auxEmployee = employee_newEmployee();

    if ( lista != NULL && newLinkedList != NULL && auxEmployee != NULL )
    {
        if ( ll_isEmpty(lista) == 0 )
        {
            system("cls");
            len = ll_len(lista);

            for ( int i = 0; i < len; i++ )
            {
                auxEmployee = ll_get(lista, i);

                if ( FiltradoPorSalario( &(auxEmployee)->salary ) )
                {
                    ll_add(newLinkedList, auxEmployee);
                }
            }
        }
    }
    return newLinkedList;
}

int FiltradoPorSalario(void* elemento)
{
    int returnAux = 0;

    if ( *((float*) elemento)> 60000.00 )
    {
        returnAux = 1;
    }

    return returnAux;
}
