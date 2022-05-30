#ifndef ACREEDOR_H
#define ACREEDOR_H

#include <iostream>
#include <map>
#include <utility> 
#include <iterator>
#include <cassert>
#include "Deudor.hpp"

class Deudor;
using namespace std;

class Acreedor{
private:
    string nombre_, apellidos_;
    map<Deudor*, double> deudores;
public:
    typedef pair<Deudor*,double> pair_;
    Acreedor(string n, string a);

    string nombre() const;
    string apellidos() const ;

    void prestamo(Deudor& d, double dinero);

    void eliminarDeuda(Deudor& d);


    void verPrestamos() const;

};

#endif
