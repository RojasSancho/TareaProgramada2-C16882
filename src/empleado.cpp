#include "empleado.h"

Empleado::~Empleado()
{
    
}

ostream& operator << (ostream &o, const Empleado *empleado)
{
    o << empleado->id << "," << empleado->nombre << "," << empleado->apellido << "," << empleado->email << "," << empleado->tipoEmpleado <<  "," << empleado->idSupervisor;
    return o;
}

istream& operator >> (istream &i, Empleado *empleado)
{
    i >> empleado->id >> empleado->nombre >> empleado->apellido >> empleado->email >> empleado->tipoEmpleado >> empleado->idSupervisor;
    return i;
}

