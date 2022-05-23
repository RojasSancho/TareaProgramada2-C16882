#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoIndependientePorHoras.h"
#include <iostream>

using namespace std;

int main () 
{

    EmpleadoNomina* empleado1 = new EmpleadoNomina(355000.0);
    float pagoNeto = empleado1->CalcularPagoNeto();
    

    EmpleadoIndependientePorHoras* empleado2 = new EmpleadoIndependientePorHoras(1500.5, 192);
    float pagoNeto2 = empleado2->CalcularPagoNeto();

    cout << "El pago del emp1 es: " << pagoNeto << " y el pago del emp2 es: " << pagoNeto2;
}