#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleado.h"
#include <map>
#include <istream>
#include <string>

using namespace std;

class Planilla {

    Empleado *director;

    map<int, Empleado *> indiceEmpleados;

    public:
    Planilla(istream *streamPersonas); //Informacion de la raiz, es decir, el director

    

    void AgregarPagoMensualBruto(istream *streamNomina); //Agregar informacion de empleados de nomina(nomina.txt)
    void AgregarMontoPorHoraYHorasTrabajadas(istream *streamHorasTrabajadas); //Agragar informacion de empleados por hora(horastrabajadas.txt)
    void CrearReporte();

    ~Planilla();
    
    string ObtenerNombre(int id);
    float ObtenerPagoNeto(int id);

};


#endif