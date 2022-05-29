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
print("\n")








'''
# Creación de objetos con parámetros predeterminados
print("######  Creación de objetos con parámetros predeterminados ######\n")
pelicula2 = Pelicula()
pelicula2.printFilm()

print("\n")


# Modificar pelicula 1
print("######  Modificar datos de la pelicula ######\n")
print("Introduce el titulo de la pelicula")
nombre = input()
pelicula2.setTitle(nombre)

print("Introduce la sinopsis de la pelicula")
sinopsis = input()
pelicula2.setDescription(sinopsis)

print("Introduce el reparto de la pelicula")
reparto = input()
pelicula2.setCast(reparto)

print("Introduce el genero de la pelicula")
genero = input()
pelicula2.setGenres(genero)

print("Introduce el anno de la pelicula")
anno = input()
pelicula2.setYear(anno)

print("\n")
pelicula2.printFilm()'''