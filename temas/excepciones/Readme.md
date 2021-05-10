*****************************************************************************************
				 EJECUCIÓN MEDIANTE CLI
*****************************************************************************************
Debemos descargar los archivos:

- excepciones.java
- excepcionesChecked.java
- excepcionesUnchecked.java
- nombreDeNuestraUniversidadErroneo.java
- nombreDeNuestraAsignaturaErroneo.java

Necesitaremos el compilador javac, en Linux lo podemos descargar con el comando:
- sudo apt install openjdk-14-jdk-headless
- sudo apt update

Una vez lo tengamos y, estando en la carpeta donde hemos descargado los 5 archivos mencionados anteriormente, los compilamos con el comando:

- javac excepciones.java

Tras ejecutar el comando se crearan 5 archivos .class (uno por cada clase creada en los ficheros). Ahora para ejecutar el programa hacemos:
- java excepciones

Durante a ejecución se realizan 6 excepciones (3 checked y 3 unchecked) con características diferentes. El único punto del programa en el cual debemos interactuar es durante la segunda excepción Unchecked, cuando nos pide un dividendo para una división el cual, para que salte alguna de las excepciones, debe ser cualquier cosa menos un número distinto de 0 (un string, un 0,...).