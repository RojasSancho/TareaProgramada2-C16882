#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleado.h"
#include <map>

using namespace std;

class Planilla {

    Empleado *director;

    map<int, Empleado *> indiceEmpleados;

    public:
    Planilla(int idDirector, string nombreDirector, string apellidoDirector, string emailDirector, int tipoEmpleadoDirector, int idSupervisorDirector); //Informacion de la raiz, es decir, el director

    ~Planilla();

    void AgregarEmpleado(Empleado *Empleado);



    friend istream operator >> (istream &i, Planilla *planilla);

};


















#endif