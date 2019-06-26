#include <stdio.h>
#include <stdlib.h>

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

/** \brief muestra en pantalla un menu de opciones
 *
 * \return un entero correspondiente a la opcion que eligio el usuario
 *
 */
int menuPrincipal( char* buildInfo);

int menuOrdenamiento( char* buildInfo );

int menuModificarEmpleado( employee* employeeToModify, char* buildInfo );

int main()
{
    int opcionMenu = 0;
    employee* employeeAux = NULL;
    char buildInfo [] = "Version: 3.0.0";
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaFiltrada = NULL;

    do
    {
        opcionMenu = 0;
        system("cls");

        switch ( menuPrincipal(buildInfo) )
        {
            case 1:
                if ( employee_altaEmpleado(lista) )
                {
                     printf("||\n|| //ERROR// No se pudo realizar el alta... \n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se realizo esta operacion satisfactoriamente!\n\n");
                }
                system("pause");
                break;

            case 2:
                if ( employee_removerEmpleado(lista) )
                {
                     printf("||\n|| //ERROR// No existe ese ID en la lista... \n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se realizo esta operacion satisfactoriamente!\n\n");
                }
                system("pause");
                break;

            case 3:
                employeeAux = employee_findEmployeeById(lista, "||\n|| Ingrese el ID (legajo) del empleado que desea modificar: ");
                do
                {
                    if ( employeeAux != NULL )
                    {
                        switch ( menuModificarEmpleado( employeeAux, buildInfo ) )
                        {
                            case 1:
                                input_getName(employeeAux->name, "||\n|| Ingrese el nuevo nombre: ", "||\n|| //ERROR// El nombre debe tener mas de 2 letras y menos de 25", 2, 25);
                                printf("\n");
                                break;

                            case 2:
                                input_getName(employeeAux->surname, "||\n|| Ingrese el nuevo apellido: ", "||\n|| //ERROR// El apellido debe tener mas de 2 letras y menos de 25", 2, 25);
                                printf("\n");
                                break;

                            case 3:
                                input_getFloat(&employeeAux->salary, "||\n|| Ingrese el nuevo salario: ", "||\n|| //ERROR// El salario no cumple con los rangos minimos/maximos", 8000, 100000);
                                printf("\n");
                                break;

                            case 4:
                                input_getInt(&employeeAux->eDate.day, "||\n|| Ingrese el nuevo dia de ingreso: ", "||\n|| //ERROR// Lo ingresado no es un dato valido...", 1, 32);
                                input_getInt(&employeeAux->eDate.month, "||\n|| Ingrese el nuevo mes de ingreso: ", "||\n|| //ERROR// Lo ingresado no es un dato valido...", 1, 12);
                                input_getInt(&employeeAux->eDate.year, "||\n|| Ingrese el nuevo year de ingreso: ", "||\n|| //ERROR// Lo ingresado no es un dato valido...", 2018, 2019);
                                printf("\n");
                                break;

                            case 5:
                                opcionMenu = 3;
                                break;

                            default:
                                printf("||\n|| //ERROR// Numero de opcion invalido...\n");
                                printf("||\n|| //Sugerencia// Intenta utilizando NUMEROS correspondientes a los del menu.\n\n");
                                break;
                        }
                    }
                    else
                    {
                        printf("||\n|| //ERROR// No existe ese ID en la lista... \n\n");
                        opcionMenu = 3;
                    }

                    system("pause");
                } while ( opcionMenu != 3 );
                break;

            case 4:
                do
                {
                    system("cls");
                    switch ( menuOrdenamiento(buildInfo) )
                    {
                        case 1:
                            printf("||\n|| //ATENCION// Realizando el ordenado... ( puede tardar unos segundos )\n");

                            if ( employee_ordenarLista(lista, 1) )
                            {
                                printf("||\n|| //ERROR// No hay elementos que ordenar // no se pudo ordenar la lista\n\n");
                            }
                            else
                            {
                                printf("||\n|| //EXITO// Se realizo esta operacion satisfactoriamente!\n\n");
                            }
                            break;

                        case 2:
                            printf("||\n|| //ATENCION// Realizando el ordenado... ( puede tardar unos segundos )\n");

                            if ( employee_ordenarLista(lista, 2) )
                            {
                                printf("||\n|| //ERROR// No hay elementos que ordenar // no se pudo ordenar la lista\n\n");
                            }
                            else
                            {
                                printf("||\n|| //EXITO// Se realizo esta operacion satisfactoriamente!\n\n");
                            }
                            break;

                        case 3:
                            printf("||\n|| //ATENCION// Realizando el ordenado... ( puede tardar unos segundos )\n");

                            if ( employee_ordenarLista(lista, 3) )
                            {
                                printf("||\n|| //ERROR// No hay elementos que ordenar // no se pudo ordenar la lista\n\n");
                            }
                            else
                            {
                                printf("||\n|| //EXITO// Se realizo esta operacion satisfactoriamente!\n\n");
                            }
                            break;

                        case 4:
                            printf("||\n|| Volviendo...\n\n");
                            opcionMenu = 2;
                            break;

                        default:
                            printf("||\n|| //ERROR// Numero de opcion invalido...\n");
                            printf("||\n|| //Sugerencia// Intenta utilizando NUMEROS correspondientes a los del menu.\n\n");
                            break;
                    }
                    system("pause");
                } while ( opcionMenu != 2 );
                break;

            case 5:
                if ( listarEmpleados(lista) )
                {
                    printf("||\n|| //ERROR// No existen elementos que listar // lista NULA...\n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se realizo esta operacion satisfactoriamente!\n\n");
                }
                system("pause");
                break;

            case 6:
                if ( employee_removeList(lista) )
                {
                    printf("||\n|| //ERROR// No hay ninguna lista que eliminar...\n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se realizo esta operacion satisfactoriamente!\n\n");
                }
                system("pause");
                break;


            case 7:
                if ( employee_cargarListaBin(lista, "data.bin") )
                {
                     printf("||\n|| //ERROR// no se encontro el archivo - data.bin - // lista NULA. \n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se cargaron los datos correctamente!\n\n");
                }
                system("pause");
                break;

            case 8:
                if ( employee_guardarListaBin(lista, "data.bin") )
                {
                    printf("||\n|| //ERROR// puede que lo siguiente este causando este problema...\n");
                    printf("||\n|| // 1) // no hay elementos que guardar\n");
                    printf("|| // 2) // no hay espacio para realizar el guardado\n");
                    printf("|| // 3) // Lista NULA\n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se guardaron los datos correctamente!\n\n");
                }
                system("pause");
                break;

            case 9:
                if ( employee_cargarListaAImprimir(lista, "data.csv") )
                {
                    printf("||\n|| //ERROR// no se encontro el archivo - data.csv - // lista NULA \n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se cargaron los datos correctamente!\n\n");
                }
                system("pause");
                break;

            case 10:

                if ( employee_guardarListaAImprimir(lista, "data.csv") )
                {
                    printf("||\n|| //ERROR// puede que lo siguiente este causando este problema...\n");
                    printf("||\n|| // 1) // no hay elementos que guardar\n");
                    printf("|| // 2) // no hay espacio para realizar el guardado\n");
                    printf("|| // 3) // Lista NULA\n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se guardaron los datos correctamente!\n\n");
                }
                system("pause");
                break;

            case 11:

                listaFiltrada = employee_filter(lista);

                listarEmpleados(listaFiltrada);


                if ( employee_guardarListaAImprimir(listaFiltrada, "out.csv") )
                {
                    printf("||\n|| //ERROR// puede que lo siguiente este causando este problema...\n");
                    printf("||\n|| // 1) // no hay elementos que guardar\n");
                    printf("|| // 2) // no hay espacio para realizar el guardado\n");
                    printf("|| // 3) // Lista NULA\n\n");
                }
                else
                {
                    printf("||\n|| //EXITO// Se guardaron los datos correctamente!\n\n");
                }
                system("pause");
                break;

            case 12:
                opcionMenu = 1;
                break;

            default:
                printf("||\n|| //ERROR// Numero de opcion invalido...\n");
                printf("||\n|| //Sugerencia// Intenta utilizando NUMEROS correspondientes a los del menu.\n\n");
                system("pause");
                break;
        }

    } while (opcionMenu != 1);

    return 0;
}

// ------------------------------------------------------------ //

int menuPrincipal( char* buildInfo )
{
    int opcion;
    char solapaActual [] = "Menu principal";

    fflush(stdin);

    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||  %-14s  || ABM Empleaditos ||  %-15s  ||\n", buildInfo, solapaActual);
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");

    printf("||- - - - - - - - - - - - - - - - - - - - \n");
    printf("|| 1) Alta de empleado\n");
    printf("|| 2) Baja de empleado\n");
    printf("|| 3) Modificacion de empleado\n");
    printf("||- - - - - - - - - - - - - - - - - - - - \n");
    printf("|| 4) Ordenar lista actual\n");
    printf("|| 5) Mostrar lista actual \n");
    printf("|| 6) Eliminar lista actual\n");
    printf("||- - - - - - - - - - - - - - - - - - - - \n");
    printf("|| 7) Cargar lista de empleados (bin)\n");
    printf("|| 8) Guardar lista de empleados (bin)\n");
    printf("|| 9) Cargar lista de empleados a imprimir (csv)\n");
    printf("|| 10) Crear/Guardar lista de empleados a imprimir(csv)\n");
    printf("||- - - - - - - - - - - - - - - - - - - - \n");
    printf("|| 11) Informes\n");
    printf("|| 12) Salir... \n");

    printf("||\n|| Que desea hacer?: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuOrdenamiento( char* buildInfo )
{
    int opcion;

    char solapaActual [] = "Ordenamiento";

    fflush(stdin);

    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("||  %-14s  || ABM Empleaditos ||  %-15s  ||\n", buildInfo, solapaActual);
    printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");

    printf("||- - - - - - - - - - - - - - - - - - - - \n");
    printf("|| 1) Ordenar alfabeticamente por nombre y apellido\n");
    printf("|| 2) Ordenar por salario\n");
    printf("|| 3) Ordenar por fecha de ingreso\n");
    printf("||- - - - - - - - - - - - - - - - - - - - \n");
    printf("|| 4) Atras...\n");

    printf("||\n|| Que desea hacer?: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuModificarEmpleado( employee* employeeToModify, char* buildInfo )
{
    char solapaActual [] = "Modificar Empleado";

    int opcion = -1;

    if ( employeeToModify != NULL )
    {
        system("cls");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||  %-14s  || ABM Empleaditos ||  %-15s  ||\n", buildInfo, solapaActual);
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");

        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||  ID  | NOMBRE                    | APELLIDO                  | SALARIO   | INGRESO    ||\n");
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|| %04d | %-25s | %-25s | $%-8.2f | %.2d/%.2d/%.4d ||\n", employeeToModify->id, employeeToModify->name, employeeToModify->surname, employeeToModify->salary, employeeToModify->eDate.day, employeeToModify->eDate.month, employeeToModify->eDate.year);
        printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");

        printf("||- - - - - - - - - - - - - - - - - - - - \n");
        printf("|| 1) Modificar Nombre\n");
        printf("|| 2) Modificar Apellido\n");
        printf("|| 3) Modificar Salario\n");
        printf("|| 4) Modificar Fecha de ingreso\n");
        printf("||- - - - - - - - - - - - - - - - - - - - \n");
        printf("|| 5) Atras...\n");

        fflush(stdin);
        printf("||\n|| Que desea hacer?: ");
        scanf("%d", &opcion);
    }

    return opcion;
}
