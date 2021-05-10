#ifndef OCULTACION_HPP_
#define OCULTACION_HPP_

#include <stdlib.h>
#include <list>
#include <iterator>

using namespace std;

template<typename T>

class Lista{

    public:

        Lista() {}; //Contructor por defecto

        void addFirst(T value);
        void removeFirst();
        void  addLast(T value);
        void removeLast();
        T first();
        T last();                                   
        bool isEmpty();
        int length();
        list<T> clone();
        bool isEqualTo(Lista <T>);
        //iterator<T> iterator();

    private:

        std::list<T> lista;
};



template<typename E>

class Iterator{

    public:

        friend class Lista<E>;
        bool hasNext();
        E next();
    
    private:

        typename std::list<E>::iterator it;
        void remove();
};

#endif