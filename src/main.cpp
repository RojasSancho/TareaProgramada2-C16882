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

    ifstream ifs("personas.txt", std::ifstream::in);

    if (!ifs.is_open())
    {
        std::cerr << "Error leyendo archivo personas.txt" << std::endl;
        return -1;
    }

    ifstream ifs2("nomina.txt", std::ifstream::in);

    if (!ifs.is_open())
    {
        std::cerr << "Error leyendo archivo nomina.txt" << std::endl;
        return -1;
    }

    ifstream ifs3("horastrabajadas.txt", std::ifstream::in);

    if (!ifs.is_open())
    {
        std::cerr << "Error leyendo archivo horastrabajdas.txt" << std::endl;
        return -1;
    }

    Planilla *planilla = new Planilla(&ifs);
    planilla->AgregarPagoMensualBruto(&ifs2);
    planilla->AgregarMontoPorHoraYHorasTrabajadas(&ifs3);
    planilla->CrearReporte();
    
    


}