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

string Empleado::ObtenerApellido()
{
    return this->apellido;
}

string Empleado::ObtenerNombreCompletoSupervisor()
{
    return this->supervisor->nombre + " " + this->supervisor->apellido;
}

int Empleado::ObtenerTipo()
{
    return this->tipoEmpleado;
}

void Empleado::AsignarPagoMensualBruto(float a)
{

}

float Empleado::ObtenerPagoMensualBruto()
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

