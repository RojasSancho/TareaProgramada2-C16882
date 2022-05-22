#ifndef EMPLEADONOMINA_H
#define EMPLEADONOMINA_H

#include "empleado.h"
#include <vector>
#include <string>

using namespace std;

class EmpleadoNomina : public Empleado {
    
    float pagoMensualBruto;
    
    public:
    
    EmpleadoNomina(int id, string nombre, string apellido, string email, int tipoEmpleado, int idSupervisor);

    virtual float CalculoPagoNeto();

    virtual void DarPagoMensualBruto(float pagoMensualBruto);

};

#endif