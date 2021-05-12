#include "ocultacion.hpp"

#include <stdlib.h>
#include <list>
#include <iterator>

using namespace std;


template<typename T> void Lista<T>::addFirst(T value){ //Insert element at beginning

    lista.push_front(value);
}

template<typename T> void Lista<T>::removeFirst(){ //Delete first element 

    lista.pop_front();
}

template<typename T> void Lista<T>::addLast(T value){ //Add element at the end

    lista.push_back(value);
}

template<typename T> void Lista<T>::removeLast(){ //Delete last element

    lista.pop_back();
}

template<typename T> T Lista<T>::first(){ //Access first element

    lista.front();
}

template<typename T> T Lista<T>::last(){ //Access last element

    lista.back();
}

template<typename T>bool Lista<T>::isEmpty(){ //Test whether container is empty

    lista.empty();
}

template<typename T>int Lista<T>::length(){ //Return size

    lista.size();
}

template<typename T>list<T> Lista<T>::clone(){ //Copies all the elements

    list<T> cloneList = lista;

    return cloneList;
}

template<typename T>bool Lista<T>::isEqualTo(Lista<T> newlist){

    return (lista == newlist.returnList());
}

template<typename T> typename Lista<T>::iterator iterator(){

    typename list<T>::iterator iterador;

    return iterador;
}

template<typename E>bool Iterator<E>::hasNext(){

    if(it = it.end()){

        return false;
    
    }else{

        return true;
    }
}

template<typename E> E Iterator<E>::next(){

    it.next();
}

/*
template<typename E> void Iterator<E>::remove(){

    lista.erase(it);
}
*/

template<typename E> void Iterator<E>::remove(Iterator<E> iterator){

    iterator.lista.erase(it);
}