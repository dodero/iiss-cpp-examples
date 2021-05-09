# Delegación 
## Instrucciones sobre cómo compilar el ejercicio Delegación

- **Paso 1**. Crear una carpeta en el directorio que se desee, llamada Delegacion
- **Paso 2**. Añadir los ficheros makefile, instrumento.cpp, main.cpp y orquesta.cpp
- **Paso 3**. Abrir la terminal desde el directorio actual, para situarnos justo en la carpeta creada con los ficheros
- **Paso 4**. Escribir en la consola el comando: make all
Este comando hará que el fichero makefile se ejecute y compile el fichero orquesta.cpp
- **Paso 5**. Escribir en la consola el comando: make run
Este comando hará que muestre la salida del programa. (./delegacion)
- **Paso 6**. Para limpiar, y volver a compilar, escribir en la consola el comando: make clean
Este comando eliminará los ficheros que se generaron al realizar el comando make all, dejando la carpeta como se tenía al principio

## Breve explicación del ejercicio Delegación
El ejercicio Orquesta se compone de tres ficheros .cpp: 
- orquesta.cpp
- instrumento.cpp
- main.cpp

### instrumento.cpp
En este fichero están definidas varias clases responsables del funcionamiento del mismo. Tenemos una clase base llamada Instrumento, la cual tiene las subclases: Viento, Cuerda y Percusión, que heredan de la clase Instrumento. Esta clase instrumento es una clase abstracta ya que contiene funciones virtuales puras. ¿Qué implica esto? Que no se puede instanciar directamente objetos de la clase isntrumento, pero sí punteros que apunten a ella, los cuales en un futuro apuntarán a las clases derivadas. Al ser una clase abstracta estamos obligando a que utilice el comportamiento de los métodos de las clases derivadas, dependiendo del tipo de objeto que sea, siempre y cuando estas funciones tengan la misma signatura y valor de retorno que las virtuales puras generadas en la clase base Instrumento. 

En cada clase derivada: Viento, Cuerda y Percusión, tenemos el constructor específico de cada una, la cual recibe el nombre del instrumento en cuestión: trompeta, violín, viola y tambor. Por ejemplo, en viento, recibiría violín y se asignaría al atributo nombreIntrumento el cual también se puede heredar ya que en la clase base está con visibilidad protected. También en estas clases derivadas se definen los métodos con los comportamientos específicos para cada clase derivada: tocar y afinar. 

### orquesta.cpp
Posteriormente, se crea una clase Orquesta, la cual contiene un vector de tipo vector dinámico, es decir, dependiendo de la cantidad de instrumentos que se añadan, va variando su tamaño. En la parte public de la clase está definido un método que añade los instrumentos al vector, y luego otros dos métodos que recorren el vector llamando a la función de tocar y afinar. 

### main.cpp
Finalmente, en la función main, añadimos los instrumentos y llamamos a estos dos métodos, evitando así el acoplamiento con el resto de clases. La salida que devuelve es la que se muestra a continuación.

>Afinando instrumento de Viento: trompeta
>Afinando instrumento de Cuerda: violin
>Afinando instrumento de Cuerda: viola
>Afinando instrumento de Percusión: tambor
>Tocando instrumento de Viento: trompeta
>Tocando instrumento de Cuerda: violin
>Tocando instrumento de Cuerda: viola
>Tocando instrumento de Percusión: tambor

