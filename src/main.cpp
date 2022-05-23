#include "empleado.h"
#include "empleadoNomina.h"
#include "empleadoIndependientePorHoras.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

    }

    std::string linea {};

    while(std::getline(ifs, linea))
    {
        int id{};
        string nombre;
        string apellido;
        string email;
        int tipoEmpleado{};
        int idSupervisor{};

        string stringEntrada = linea;
        istringstream stream(stringEntrada);

        stream >> id >> nombre >> apellido >> email >> tipoEmpleado >>idSupervisor;
 
        if (tipoEmpleado == 1) //Empleado de nomina
        {
            EmpleadoNomina* empleadoNomina = new EmpleadoNomina(id, nombre, apellido, email, tipoEmpleado, idSupervisor);

        } else if (tipoEmpleado == 2) { //Empleado profesional por horas 
            EmpleadoIndependientePorHoras* empleadoPorHoras = new EmpleadoIndependientePorHoras(id, nombre, apellido, email, tipoEmpleado, idSupervisor);
        }
    }


}