*****************************************************************************************
				 MEDIANTE CLI
*****************************************************************************************
Debemos descargar los archivos excepciones.java, excepcionesChecked.java y
excepcionesUnchecked.java situados en /BASE/excepciones/src/ (siendo BASE el directorio en
el que nos encontramos).

Necesitaremos el compilador javac, en Linux lo podemos descargar con el comando:
- sudo apt-get isntall openjdk-14-jdk-headless
- sudo apt update

Una vez lo tengamos y, estando en la carpeta donde hemos descargado los 3 archivos mencio-
nados anteriormente, los compilamos con el comando:
- javac excepciones.java

Tras ejecutar el comando se crearan 5 archivos .class (uno por cada clase creada en los
ficheros). Ahora para ejecutar el programa hacemos:
- java excepciones

Durante a ejecución se realizan 6 excepciones (3 checked y 3 unchecked) con característi-
cas diferentes. El único punto del programa en el cual debemos interactuar es durante 
la segunda excepción Unchecked, cuando nos pide un dividendo para una división el cual, 
para que salte alguna de las excepciones, debe ser cualquier cosa menos un número distin-
to de 0 (un string, un 0,...).

*****************************************************************************************
				CON IDE ECLIPSE
*****************************************************************************************
La carpeta excepciones contenida en este mismo directorio (donde se encuentra este Readme)
es un proyecto que puede importarse y ejecutarse directamente a Eclipse. Debemos descargar
la carpeta BASE/excepciones (siendo BASE el directorio en el que nos encontramos) y colo-
carla en el workspace de Eclipse. Acto seguido la abrimos de ésta forma:
File->Open Projects from File System->Directory->Seleccionar carpeta excepciones->Finish

Durante a ejecución se realizan 6 excepciones (3 checked y 3 unchecked) con característi-
cas diferentes. El único punto del programa en el cual debemos interactuar es durante 
la segunda excepción Unchecked, cuando nos pide un dividendo para una división el cual, 
para que salte alguna de las excepciones, debe ser cualquier cosa menos un número distin-
to de 0 (un string, un 0,...).