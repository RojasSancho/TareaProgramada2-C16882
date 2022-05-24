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

Planilla::~Planilla()
{
    delete this->director;
}

void Planilla::AgregarEmpleado(Empleado *empleado)
{
    

}

string Planilla::ObtenerNombre (int id)
{
    Empleado *empleadoConNombre = this->indiceEmpleados.at(id);
    return empleadoConNombre->ObtenerNombre();
}