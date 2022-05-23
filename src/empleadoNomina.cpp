#include "empleadoNomina.h"

using namespace std;

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