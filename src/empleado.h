#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Empleado {

    protected:
    
    int id;
    string nombre;
    string apellido;
    string email;
    int tipoEmpleado;
    int idSupervisor;
    Empleado *supervisor;
    vector<Empleado *> supervisados;

    public:
    virtual ~Empleado();

    virtual float CalcularPagoNeto() = 0;

    void InsertarSupervisado(Empleado *supervisado);


    friend istream& operator >> (istream &i, Empleado *empleado);
    friend ostream& operator << (ostream &o, const Empleado *empleado);

    void AsigneSupervisor(Empleado *supervisor);

    string ObtenerNombre();

};

#endif