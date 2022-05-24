#include "empleadoNomina.h"
#include <string>

using namespace std;

EmpleadoNomina::EmpleadoNomina(int id, string nombre, string apellido, string email, int tipoEmpleado, int idSupervisor) {

    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
    this->tipoEmpleado = tipoEmpleado;
    this->idSupervisor = idSupervisor;

}

EmpleadoNomina::EmpleadoNomina(float pagoMensualBruto)
{
    this->pagoMensualBruto = pagoMensualBruto;
}

float EmpleadoNomina::CalcularPagoNeto()
{

    float pagoNeto = 0;
    float retencionPorImpuestos = this->pagoMensualBruto * (0.07);
    pagoNeto = pagoMensualBruto - retencionPorImpuestos;

    return pagoNeto;

}

void EmpleadoNomina::AsignarPagoMensualBruto(float pagoMensualBruto)
{
    this->pagoMensualBruto = pagoMensualBruto;
}

float EmpleadoNomina::ObtenerPagoMensualBruto() 
{
    return this->pagoMensualBruto;
}