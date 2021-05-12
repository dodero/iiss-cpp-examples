#include <stdlib.h>
#include <iostream>
#include "ocultacion.hpp"
#include "ocultacion.cpp"
#include <list>
#include <iterator>

using namespace std;

int main(){

    Lista<int> l;
    l.addFirst(200);
    l.addLast(15);
    l.addFirst(300);
    Lista<int> listAux = l;
    
    while (!listAux.isEmpty()) {

        std::cout << ' '<< listAux.first();
        listAux.removeFirst();
    }

    l.removeFirst();
    l.removeLast();
    std::cout << l.first();

    return 0;
}