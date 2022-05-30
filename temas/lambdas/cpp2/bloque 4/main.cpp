#include <iostream> 
#include <cctype>
#include <vector>
#include "Acreedor.hpp"
#include "Deudor.hpp"

using namespace std;

void CadaUno(const vector<Acreedor*>& acreedors, void(*func)(Acreedor*))
{
    for(Acreedor* a : acreedors)
    {
        func(a);
    }
}

int main(){
    Acreedor *a1 = new Acreedor("Lucia", "Caro"),
            *a2 = new Acreedor("Carmen", "Duqmac"),
            *a3 = new Acreedor("Davinia", "Barrera"),
            *a4 = new Acreedor("Jose Luis", "Romero"),
            *a5 = new Acreedor("Hugo", "Diosdado"),
            *a6 = new Acreedor("Juan Antonio", "Montaño");

    vector<Acreedor*> acreedores = {a1,a2,a3,a4,a6};
    

    Deudor *d1 = new Deudor("Dario", "Velazquez"),
            *d2 = new Deudor("Manuel", " Castañeda"),
            *d3 = new Deudor("Cristina", " Ramirez"),
            *d4 = new Deudor("Aitor", " Menacho"),
            *d5 = new Deudor("Daniel", " Gómez"),
            *d6 = new Deudor("Juan Luis", " Ramirez"),
            *d7 = new Deudor("Nadia", " Benitez");


//  ####### ACCIONES DEL ACREEDOR
    a6->prestamo(*d2, 5000);
    a6->prestamo(*d3, 2000);
    a6->prestamo(*d4, 54000);
    a6->prestamo(*d5, 6000);
    a6->prestamo(*d7, 8000);

    CadaUno(acreedores, [](Acreedor *a) -> void{ 
        cout << "Acreedor: " << a->nombre() << "  " << a->apellidos() << "\nDeudores: " <<endl ;
        a->verPrestamos();
    });

    a6->eliminarDeuda(*d2);
    

//  ###### ACCIONES DEL DEUDOR
    d4->pedirPrestamo(*a5,3000);
    d4->pedirPrestamo(*a3,2000);
    d4->pedirPrestamo(*a6,1);
    //d4->verDeudas();

}