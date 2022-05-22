#ifndef PLANILLA_H
#define PLANILLA_H

#include "empleado.h"
#include <map>

using namespace std;

class Planilla {

    Empleado *director;

    map<int, Empleado *> indiceEmpleados;

    public:
    Planilla();
    ~Planilla();

    void AgregarEmpleado(Empleado *nuevoEmpleado);

    friend istream operator >> (istream &i, Planilla *planilla);

};


















#endif