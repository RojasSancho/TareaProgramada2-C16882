#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoIndependientePorHoras.h"
#include "planilla.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <istream>
#include <string>

using namespace std;

int main () 
{
    /*
    EmpleadoNomina* empleado1 = new EmpleadoNomina(355000.0);
    float pagoNeto = empleado1->CalcularPagoNeto();
    

    EmpleadoIndependientePorHoras* empleado2 = new EmpleadoIndependientePorHoras(1500.5, 192);
    float pagoNeto2 = empleado2->CalcularPagoNeto();

    cout << "El pago del emp1 es: " << pagoNeto << " y el pago del emp2 es: " << pagoNeto2;
    */
    
    
    ifstream ifs("personas.txt", std::ifstream::in);

    if (!ifs.is_open())
    {
        std::cerr << "Error leyendo archivo personas.txt" << std::endl;
        return -1;
    }

    Planilla *planilla = new Planilla(&ifs);

    string nombreDelSegundo = planilla->ObtenerNombre(2);

    cout << nombreDelSegundo;


    


}