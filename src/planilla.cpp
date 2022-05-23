#include "planilla.h"
#include "empleadoNomina.h"
#include "empleadoIndependientePorHoras.h"
#include "empleado.h"

Planilla::Planilla(int idDirector, string nombreDirector, string apellidoDirector, string emailDirector, int tipoEmpleadoDirector, int idSupervisorDirector)
{
    this->director = new EmpleadoNomina (idDirector, nombreDirector, apellidoDirector, emailDirector, tipoEmpleadoDirector, idSupervisorDirector);
}

Planilla::~Planilla()
{
    delete this->director;
}

void Planilla::AgregarEmpleado(Empleado *empleado)
{
    

}