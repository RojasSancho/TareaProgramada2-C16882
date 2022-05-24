#include "planilla.h"
#include "empleadoNomina.h"
#include "empleadoIndependientePorHoras.h"
#include "empleado.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Planilla::Planilla(istream *streamPersonas)
{
    std::string linea {};
    

    while(std::getline(*streamPersonas, linea))
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

        if (id == 1 && tipoEmpleado == 1)     
        {
            EmpleadoNomina* empleadoNomina = new EmpleadoNomina(id, nombre, apellido, email, tipoEmpleado, idSupervisor);
            this->director = empleadoNomina;
            this->indiceEmpleados.insert(std::pair<int, Empleado *> (id, empleadoNomina));
            empleadoNomina->AsigneSupervisor(empleadoNomina);
        } else if (id == 1 && tipoEmpleado == 2) {
            EmpleadoIndependientePorHoras* empleadoPorHoras = new EmpleadoIndependientePorHoras(id, nombre, apellido, email, tipoEmpleado, idSupervisor);
            this->director = empleadoPorHoras;
            this->indiceEmpleados.insert(std::pair<int, Empleado *> (id, empleadoPorHoras));
            empleadoPorHoras->AsigneSupervisor(empleadoPorHoras);
        }

        if (tipoEmpleado == 1 && id != 1) //Empleado de nomina
        {
            EmpleadoNomina* empleadoNomina = new EmpleadoNomina(id, nombre, apellido, email, tipoEmpleado, idSupervisor);
            Empleado *supervisor = this->indiceEmpleados.at(idSupervisor);
            supervisor->InsertarSupervisado(empleadoNomina);
            empleadoNomina->AsigneSupervisor(supervisor);

            this->indiceEmpleados.insert(std::pair<int, Empleado *> (id, empleadoNomina));

        } else if (tipoEmpleado == 2 && id != 1) { //Empleado profesional por horas 
            EmpleadoIndependientePorHoras* empleadoPorHoras = new EmpleadoIndependientePorHoras(id, nombre, apellido, email, tipoEmpleado, idSupervisor);
            Empleado *supervisor = this->indiceEmpleados.at(idSupervisor);
            supervisor->InsertarSupervisado(empleadoPorHoras);
            empleadoPorHoras->AsigneSupervisor(supervisor);

            this->indiceEmpleados.insert(std::pair<int, Empleado *> (id, empleadoPorHoras));
        }
    }
}

void Planilla::AgregarPagoMensualBruto(istream *streamNomina)
{
    std::string linea{};

    while(std::getline(*streamNomina, linea))
    {         
        int id = 0;
        float pagoMensualBruto{};

        string stringEntrada = linea;
        istringstream stream(stringEntrada);

        stream >> id >> pagoMensualBruto;


        if(id <= 450) 
        {
            Empleado *empleadoNomina = this->indiceEmpleados.at(id);
            empleadoNomina->AsignarPagoMensualBruto(pagoMensualBruto);
        }

    }

}

void Planilla::AgregarMontoPorHoraYHorasTrabajadas(istream *streamHorasTrabajadas)
{
    std::string linea{};

    while(std::getline(*streamHorasTrabajadas, linea))
    {         
        int id = 0;
        float montoPorHora{};
        int horasTrabajadas{};

        string stringEntrada = linea;
        istringstream stream(stringEntrada);

        stream >> id >> montoPorHora >> horasTrabajadas;


        if(id > 450) 
        {
            Empleado *empleadoPorHoras = this->indiceEmpleados.at(id);
            empleadoPorHoras->AsignarMontoPorHoraYHorasTrabajadas(montoPorHora, horasTrabajadas);
        }

    }

}

void Planilla::CrearReporte()
{
    ofstream reporte("reporte.csv", std::ifstream::out);
    
    if (!reporte.is_open())
    {
        std::cerr << "Error abriendo reporte.csv" << std::endl;
    }

    for(int i = 1; i <= 600; i++)
    {
        Empleado *empleado = this->indiceEmpleados.at(i);
        reporte << i  << "," << empleado->ObtenerNombre() + " " + empleado->ObtenerApellido() << "," << empleado->ObtenerNombreCompletoSupervisor() << "," << empleado->CalcularPagoNeto() << endl;
    }


    long double subtotal{};
    long double totalImpuestosARetener{};
    long double total{};
    for(int i = 1; i <= 600; i++)
    {
        Empleado *empleado = this->indiceEmpleados.at(i);
        if((empleado->ObtenerTipo()) == 1) 
        {
            subtotal = subtotal + empleado->CalcularPagoNeto();
            totalImpuestosARetener = totalImpuestosARetener + (empleado->ObtenerPagoMensualBruto() * 0.07);
            total = total + empleado->ObtenerPagoMensualBruto();

        } else if((empleado->ObtenerTipo()) == 2 ) {
            subtotal = subtotal + empleado->CalcularPagoNeto();
            total = total + empleado->CalcularPagoNeto();
        }


    }

    reporte << endl << subtotal << "," << totalImpuestosARetener << "," << total << endl;

    reporte.close();
}


Planilla::~Planilla()
{
    delete this->director;
}

string Planilla::ObtenerNombre (int id)
{
    Empleado *empleadoConNombre = this->indiceEmpleados.at(id);
    return empleadoConNombre->ObtenerNombre();
}

float Planilla::ObtenerPagoNeto (int id)
{
    Empleado *empleado = this->indiceEmpleados.at(id);
    return empleado->CalcularPagoNeto();
}