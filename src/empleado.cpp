#include "empleado.h"
#include <string>

void Empleado::InsertarSupervisado(Empleado *supervisado)
{
    this->supervisados.push_back(supervisado);
}

void Empleado::AsigneSupervisor(Empleado *supervisor) 
{
    this->supervisor = supervisor;
}

Empleado::~Empleado()
{
    
}

string Empleado::ObtenerNombre()
{
    return this->nombre;
}

void Empleado::AsignarPagoMensualBruto(float a)
{

}

void Empleado::AsignarMontoPorHoraYHorasTrabajadas(float a, int b)
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

