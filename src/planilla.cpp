#include "planilla.h"
#include <iostream>
#include <sstream>
#include <string>

istream& operator >> (istream &i, Planilla *planilla)
{

    string linea;

    while (std::getline(i, linea)) {

        std::istringstream streamLinea(linea);
        
        int tipo = 0;
        streamLinea >>  >>  >>  >>  >> tipo >> ;
        Empleado *nuevoEmpleado = new Empleado();
        streamLinea >> nuevoEmpleado;
    }
}