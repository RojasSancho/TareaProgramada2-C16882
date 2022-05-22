#ifndef NODOEMPLEADO_H
#define NODOEMPLEADO_H

#include <vector>

using namespace std;

class NodoEmpleado {

    NodoEmpleado *empleado;
    NodoEmpleado *supervisor;
    vector<NodoEmpleado *> supervisados;

    public:
    NodoEmpleado();


};





















#endif