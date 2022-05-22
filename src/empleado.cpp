#include "empleado.h"

istream& operator >> (istream &i, Empleado *empleado)
{
    i >> empleado->id >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipoEmpleado >> empleado->idSupervisor;
    return i;
}