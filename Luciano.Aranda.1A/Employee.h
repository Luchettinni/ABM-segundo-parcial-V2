typedef struct
{
    int day;
    int month;
    int year;

} date;

typedef struct
{
    int id;
    char name[25];
    char surname[25];
    float salary;
    date eDate;

} employee;

//---------------------------------------------------------------//

employee* employee_newEmployee();
employee* employee_setEmployee ( char* id, char* name, char* surName, char* salary, char* day, char* month, char* year);

int employee_cargarListaAImprimir(LinkedList* lista, char path[]);
int employee_guardarListaAImprimir ( LinkedList* lista, char* path );

int employee_cargarListaBin ( LinkedList* lista, char* path );
int employee_guardarListaBin( LinkedList* lista, char* path );

int listarEmpleados( LinkedList* lista );

int ordenarListaSalario ( void* employeeA, void* employeeB );
int ordenarListaFechaDeIngreso ( void* employeeA, void* employeeB );
int ordenarListaNombreYApellido ( void* employeeA, void* employeeB );

int employee_ordenarLista ( LinkedList* lista, int opcion );
int employee_removeList( LinkedList* lista );

employee* employee_findEmployeeById( LinkedList* lista, char* mensaje );
int employee_removerEmpleado( LinkedList* lista );
int employee_altaEmpleado( LinkedList* lista );

LinkedList* employee_filter(LinkedList* lista);

int FiltradoPorSalario(void* elemento);
