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
    Planilla(istream *streamPersonas); //Agregar informacion basica de empleados (datos que no tienen que ver con pago)

    

    void AgregarPagoMensualBruto(istream *streamNomina); //Agregar informacion de empleados de nomina(nomina.txt)
    void AgregarMontoPorHoraYHorasTrabajadas(istream *streamHorasTrabajadas); //Agregar informacion de empleados por hora(horastrabajadas.txt)
    void CrearReporte();

    ~Planilla();
    
    string ObtenerNombre(int id);
    float ObtenerPagoNeto(int id);

};


#endif