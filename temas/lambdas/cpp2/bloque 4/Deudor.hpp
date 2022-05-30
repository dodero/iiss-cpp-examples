#ifndef DEUDOR_H        
#define DEUDOR_H

#include <iostream>
#include <map>
#include <utility> 
#include <iterator>
#include <cassert>
#include "Acreedor.hpp"

class Acreedor;
using namespace std;

class Deudor{
private:
    string nombre_, apellidos_;
    map<Acreedor*, double> deuda;
public:
    Deudor(string n, string a) ;

    string nombre() const;
    string apellidos() const ;
    map<Acreedor*, double>& devolverDeudas();
    
    void pedirPrestamo(Acreedor& a, double dinero) ;

    void eliminarPrestamo(Acreedor& a) ;


    void verDeudas() const;
};

#endif
