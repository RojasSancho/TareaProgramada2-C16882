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

    ~Planilla();

    void AgregarEmpleado(Empleado *Empleado);

    string ObtenerNombre(int id);
    



};


#endif