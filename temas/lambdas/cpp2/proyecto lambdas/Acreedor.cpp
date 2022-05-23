#include <iostream>
#include <map>
#include <utility> 
#include <iterator>
#include <vector>
#include <cassert>
#include <algorithm>
#include "Deudor.hpp"
#include "Acreedor.hpp"

using namespace std;

Acreedor::Acreedor(string n, string a) : nombre_(n), apellidos_(a){}

string Acreedor::nombre() const {return nombre_; }
string Acreedor::apellidos() const {return apellidos_; }

void Acreedor::prestamo(Deudor& d, double dinero)
{   
    auto it = deudores.find(&d);
    auto it2 = d.devolverDeudas().find(this);
    
    if(it == deudores.end())
    {
        deudores.insert(make_pair(&d,dinero));
        d.devolverDeudas().insert(make_pair(this,dinero));
    }
    else{
        it->second += dinero;
        it2->second += dinero;
    }
}

void Acreedor::eliminarDeuda(Deudor& d) {
    auto it = deudores.find(&d);
    if(it != deudores.end())
        cout << "La persona " << d.nombre() <<" " << d.apellidos() << " no tiene ninguna deuda contigo." << endl;
    else{
        deudores.erase(it);
        cout << "La persona " << d.nombre() <<" " << d.apellidos() << " ha saldado su deuda." << endl;
    }
}

void Acreedor::verPrestamos() const{

    auto it = deudores.begin();

    if(it == deudores.end())
        cout << "Nadie te debe nada" << endl;
    else{
        int id = 0;
        vector<pair_> v;
        copy(deudores.begin(), deudores.end(), back_inserter<vector<pair_>>(v));
        sort(v.begin(), v.end(), [](pair_ s1,pair_ s2){return s1.second<s2.second;});
        auto it2 = v.begin();
        while(it2 != v.end())
        {   
            cout << " ("<< id <<") " << (*it2).first->nombre() << (*it2).first->apellidos() << 
            "                 -               " << (*it2).second << endl;
            ++id;
            it2++;
        }
    }
}
