#ifndef EMPLEADOINDEPENDIENTEPORHORAS_H
#define EMPLEADOINDEPENDIENTEPORHORAS_H

#include "empleado.h"
#include <vector>
#include <string>

using namespace std;

class EmpleadoIndependientePorHoras : public Empleado {
    
    float montoPorHora;
    int horasTrabajadasEnMes;
    
    public:

    EmpleadoIndependientePorHoras(int id, string nombre, string apellido, string email, int tipoEmpleado, int idSupervisor);
    EmpleadoIndependientePorHoras(float montoPorHora, int horasTrabajadasEnMes);
    virtual float CalcularPagoNeto();

    void AsignarMontoPorHoraYHorasTrabajadas(float montoPorHora, int horasTrabajadas);


};

#endif