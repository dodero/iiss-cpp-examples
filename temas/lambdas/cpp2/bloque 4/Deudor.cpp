
#include <iostream>
#include <map>
#include <utility> 
#include <iterator>
#include <cassert>
#include "Acreedor.hpp"
#include "Deudor.hpp"

    Deudor::Deudor(string n, string a) : nombre_(n), apellidos_(a){}

    string Deudor::nombre() const {return nombre_; }
    string Deudor::apellidos() const {return apellidos_; }
    map<Acreedor*, double>& Deudor::devolverDeudas(){ return deuda; }
    
    void Deudor::pedirPrestamo(Acreedor& a, double dinero)
    {
       a.prestamo(*this,dinero);
    }

    void Deudor::eliminarPrestamo(Acreedor& a) {
        a.eliminarDeuda(*this);
    }


    void Deudor::verDeudas() const{
        auto it = deuda.begin();

        if(it == deuda.end())
            cout << "Nooooo tiene ninguna deuda" <<endl;
        else{
            int id = 0;

            while(it != deuda.end())
            {
                cout << " ("<< id <<") " << (*it).first->nombre() <<"  " << (*it).first->apellidos() << 
                "                 -               " << (*it).second << endl;
                id++;
                it++;
            }
        }
    }

