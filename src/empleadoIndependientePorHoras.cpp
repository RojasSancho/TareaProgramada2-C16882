#include "empleadoIndependientePorHoras.h"

using namespace std;

EmpleadoIndependientePorHoras::EmpleadoIndependientePorHoras(int id, string nombre, string apellido, string email, int tipoEmpleado, int idSupervisor) {

    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
    this->tipoEmpleado = tipoEmpleado;
    this->idSupervisor = idSupervisor;

}

EmpleadoIndependientePorHoras::EmpleadoIndependientePorHoras(float montoPorHora, int horasTrabajadasEnMes)
{
    this->montoPorHora = montoPorHora;
    this->horasTrabajadasEnMes = horasTrabajadasEnMes;
}

float EmpleadoIndependientePorHoras::CalcularPagoNeto()
{
    float pagoNeto = 0;
    pagoNeto = this->horasTrabajadasEnMes * this->montoPorHora;
    return pagoNeto;
}