#include "empleadoIndependientePorHoras.h"

using namespace std;

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