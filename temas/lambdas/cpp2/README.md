## Lambdas en C++
Autor: Lucía Caro Barrera

## compilación y ejecución del ejemplo
```
g++ main Acreedor.hpp Acreedor.cpp Deudor.hpp Deudor.cpp main.cpp
./main

```
## Código
```
//Función lambda en main
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

    ...

    CadaUno(acreedores, [](Acreedor *a) -> void{ 
        cout << "Acreedor: " << a->nombre() << "  " << a->apellidos() << "\nDeudores: " <<endl ;
        a->verPrestamos();
    });

    ...
}

//Función lambda en método sort
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
```

## Explicación
En este ejemplo hemos creado dos clases: acreedor y deudor. Cada clase tiene una serie de atributos y métodos, los más destacables serían:
    - En el caso de Deudor: formado por un mapa que almacena una pareja de acreedores y cantidad que les debe; los métodos a destacas son: ver las deudas que éste ha contraido, pedir un prestamo y eliminar un prestamo.
    - En el caso de Acreedor: formado por un mapa que almacena una pareja de deudores y cantidad que éstos le debe; los métodos a destacas son: ver los préstamos que ha ofrecido, facilitar un prestamo y eliminar un prestamo.
En el main hemos creado un vector de acreedores y una serie de deudores. A continuación, describiremos las funciones lambdas realizadas:
    - En el main hemos creado una función cadaUno() que dado el vector de acreedores y una función lambda, describe los datos personales de éstos y los prestamos que ha facilitado.
    - En el archivo Acreedor.cpp, en concreto, la función verPrestamos(), hemos mostrado los préstamos de menor a mayor, realizando una función lambda como parámetro de entrada del método sort. En esta ocasión, la función lambda realiza la operacion menor que(<).

