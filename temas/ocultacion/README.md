 # OCULTACIÓN DE LA IMPLEMENTACIÓN

## Introducción

En esta carpeta se presenta el ejercicio de clase correspondiente a la Ocultacion de la Implementación en C++. Este fichero contiene una breve explicación de cómo funciona dicho código.

## Breve Explicación

Para la realización de este ejercicio se han usado dos clases de la STL:

    • List
    • Iterator

La primera de ellas contiene funciones que nos harán falta para la implementación de los métodos addFirst, removeFirst, addLast, removeLast, first, last, isEmpty y length de la clase Lista.

```
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
```

Como podemos observar, el método addFirst inserta un elemento al inicio de la lista, removeFirst elimina el primer elemento de la lista, addLast añade un elemento al final de la lista, removeLast elimina el último elemento de la lista, first accede al primer elemento de la lista, last accede al último elemento de la lista, empty comprueba que la lista esté vacía y length devuelve el tamaño de la lista.

Además, la clase lista contiene más métodos que no usan la clase List de la STL como clone, isEqualTo e iterator.

Por otro lado, tenemos una clase Iterator que haremos friend de Lista para que dicha clase pueda acceder a los métodos de Iterator. La clase ITerator tendrá los métodos hasNext, next y remove.

## Compilación y Ejecución

Finalmente, para probar el ejercicio se proporciona un main que llamará a los métodos addFirst, addLast, removeFirst, removeLast y first. Para ejecutar el código introduciremos en nuestra terminal el comando ```g++ main.cpp```.
