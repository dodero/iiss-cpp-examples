---
title: Anotaciones en Java
created: '2021-04-22T09:58:52.807Z'
modified: '2021-04-22T10:49:59.315Z'
---

# Anotaciones en Java

## Índice

- Introducción
- Compilación y ejecución
- Explicación del ejercicio

## Introducción

En esta carpeta se presenta el ejercicio de clase correspondiente al uso de anotaciones en Java para especificar inyecciones de dependencias en el código. En este fichero se explicará cómo compilar y ejecutar el código del ejercicio, así como una breve explicación sobre cómo funciona dicho código

## Compilación y ejecución

La estructura del directorio tras descargarlo del github es la siguiente:

carpeta codigos -> aquí encontraremos todos los ficheros .java y la librería de javax.inject necesaria para las anotaciones

README.md -> Este fichero markdown con la explicación sobre cómo compilar y ejecutar

### Compilación

Para compilar el ejercicio, abrimos a terminal de nuestro ordenador y nos situamos en el directorio donde se haya descargado la carpeta del git:
![La imagen no se ha podido cargar](/home/usuario/Música/anotaciones/img/1.png)

Como se puede observar, dentro de la carpeta Música de mi ordenador, está a carpeta anotaciones, donde dentro de la misma tenemos el código del ejercicio. Para poder compilar y ejecutar el código, debemos de estar en el directorio raiz de git. En este caso dicho directorio raíz se llama anotaciones.

Para compilar el código, una vez que nos hayamos situado en anotaciones, ejecutamos el siguiente comando:

- javac -cp codigo/javax.inject-1.jar codigo/*.java

En la siguiente imagen podemos observar que cuando se ejecuta este comando, se generan los ficheros .class resultantes de la compilación de los ficheros:

![La imagen no se ha podido cargar](/home/usuario/Música/anotaciones/img/2.png)

### Ejecución

Finalmente, para ejecutar el ejercicio una vez que los ficheros hayan sido compilados, se ejecuta el siguiente comando:

- java codigo.Main

En la siguiente imagen, se observa que se ejecuta correctamente:

![La imagen no se ha podido cargar](/home/usuario/Música/anotaciones/img/3.png)

## Explicación del ejercicio

Para la realización de este ejercicio se han usado dos anotaciones: 
- Inject
- Anotación personalizada @compareWithSomething

La primera de estas, le indica al compilador cuando hay algo que debe de inyectarse. Por ejemplo, en la clase BankAccount observamos esto en varias ocasiones:

![La imagen no se ha podido cargar](/home/usuario/Música/anotaciones/img/4.png)

Se observa que se ha indicado que los atributos comparator y creationDate son dependencias que deberán de inyectarse en el constructor.

La segunda anotación nos sirve para representar qué tipo de servicio estamos usando en la anotación:

![La imagen no se ha podido cargar](/home/usuario/Música/anotaciones/img/5.png)

Esta anotación solo tendrá un valor que es el valor "tipo" y por defecto será de tipo id (es decir, por defecto, usamos el servicio de comparación por id). En el caso de la comparación por fechas, se obseva que se ha especificado un valor diferente:

![La imagen no se ha podido cargar](/home/usuario/Música/anotaciones/img/6.png)



