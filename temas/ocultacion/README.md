## Encapsulación en Python
Autor: Lucía Caro Barrera

## Entorno utilizado 
```	
Visual Studio Code
```
## Ejecución
```
main_python.py

```
## Código
```
def listToStrinPure( lista):
    cadena = str(lista)
    delet1 = cadena.replace("[","")
    delet2 = delet1.replace("]","")
    aux = delet2.replace("'","")

    return aux + "\n"

class Pelicula:

    def __init__(self,titulo="",reparto=[],descripcion="",generos=[],anno=0):
        self.title = titulo
        self._cast = reparto
        self.description = descripcion
        self.genres = generos
        self.__year = anno
        

    def getCast(self):
       return self._cast
    
    def setCast(self,reparto):
        self._cast = reparto
    
    #def getDescription(self):
     #   return self.description
       
    def setDescription(self,descripcion):
        self.description = descripcion

    def getYear(self):
        return self.__year 
        
    def setYear(self,anno):
       self.__year = anno

    #def getGenres(self):
     #   return self.genres

    def setGenres(self,genero):
       self.genres = genero

    def printFilm(self):
        print("######  Película ######\n")
        cadena0 = "Titulo: " + self.title + "\nSinopsis: " + self.description + "\nAño: " + str(self.__year) 
        cadenaReparto = listToStrinPure(self._cast)
        cadenaGeneros = listToStrinPure(self.genres)
  
        definitiva = cadena0 + "\nReparto:  " + cadenaReparto + "Generos: " + cadenaGeneros
        print(definitiva)



# Creación de objeto pasándole datos
print("######  Creación de objeto con datos estaticos ######\n")
tit = "Avengers: endgame" 
c= ["Robert Downey", "Chris Evans", "Chris Hemsworth", "Jeremy Renner", "Mark Ruffalo", "Brie Larson", "Tom Holland", "Elizabeth Olsen"]
s = "Después de los eventos devastadores de Avengers: Infinity War,el universo está en ruinas debido a las acciones de Thanos, el Titán Loco. Con la ayuda de los aliados que quedaron, los Vengadores deberán reunirse una vez más para intentar detenerlo y restaurar el orden en el universo de una vez por todas."
g = ["Fantasia", "Accion", "Ciencia ficcion", "Aventuras", "Superheroes"]
a = 2019
pelicula1 = Pelicula(tit,c,s,g,a)
pelicula1.printFilm()

print("\n")

print(pelicula1.title) #public
pelicula1.title = "OTRO JEJE" #public
print(pelicula1.title) #public

print(pelicula1._cast)  #protected
pelicula1._cast = ["nose"]  #protected
print(pelicula1._cast)  #protected

#print(pelicula1.__year)
#pelicula1.__year = 1995

print(pelicula1._Pelicula__year)  #private
pelicula1._Pelicula__year = 1995  #private
print(pelicula1._Pelicula__year)


```

## Explicación
Sabemos que la encapsulación es un concepto relacionado con la programación orientada a objetos y consiste en denegar o permitir el acceso a los atributos y métodos internos de una clase desde el exterior. 
En python, este mecanismo como tal no existe. De hecho, en python ni siquiera es necesario la creación de clases para poder crear un programa; sin embargo, permite la creación de éstas con la particularidad de que por defecto no oculta la información de una clase al exterior. En c++, java u otros lenguajes, permitimos o rechazamos el acceso de los atributos de una clase mediante las palabras protected, public o private. En python, se realiza de otra forma: 
	- Si queremos que el atributo sea privado se escribe __: en este caso no podemos acceder al atributo desde fuera de la clase; sin embargo, python realiza una manipulación de nombres en los atributos privados y éstos los cambia a _object._class__variable. que al final permite leer y modificar estos atributos perivados. 
	- Si queremos que el atributo sea protected se escribe_: el protected solo puede ser accedido por su propia clase y las subclases; sin embargo, python no cumple totalmente la funcionalidad de protected pues el atributo es accesible fuera del alcance de la clase y además, se puede modificar por lo que los getter y setter no son necesarias.
	- Si queremos que el atributo sea publico no se escribe nada.
El ejemplo ha consistido en realizar una clase y desde fuera de ésta, intentar acceder y modificar los atributos.

Por lo tanto, podríamos decir que aunque permita la poo, quizás no tiene mucho sentido usarla en él. 

