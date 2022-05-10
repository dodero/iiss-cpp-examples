#IISS-2021/2022
#Autor: Cristóbal José Velo Huerta
#Remplementacion de la clase Aventura v0.2 vista en las clases de teoria a python con un par de cambios
#En python no tenemos el problema de que una clase herede de otra clase y no se pueda acceder a los atributos y metodos de la clase padre
#Pero si los métodos se llaman igual hay que extablecer un mecanismo para diferenciar sobre a cual queremos que se llame en el caso de que haya implementaciones en las superclases
#En el siguiente ejemplo PersonajeDeAccion no hereda de SabeLuchar y hemos decidido porque sí que Heroe llame al metodo luchar de SabeLuchar en vez de al de PersonajeDeAccion
#Para ello hay que poner super().luchar() en el método luchar de PersonajeDeAccion para que ejecute el método de la "root class"
#Esto sin embargo tambien tiene ciertos problemas porque el código de la clase no root tambien se ejecutará. Para resolver esto hay que tener en cuenta
#el orden de la herencia en la clase hija lo cual puede ser un verdadero problema en caso de que se quiera heredar de varias clases que no podemos tocar pero siempre podemos
#hacer una llamada directa a los metodos de la clase padre mediante A.function(self) siendo A una de las clases de las que se hereda.

#"Interfaces"
class SabeLuchar:   #root class
    def luchar(self):
        print("Luchando Sabiendo")

class SabeNadar:
    def nadar(self):
        pass

class SabeVolar:
    def volar(self):
        pass

class PersonajeDeAccion: #not root class
    def luchar(self):
        super().luchar()
        #print("Luchando con Accion")
        pass


#Clase que hereda de las "interfaces".
#El orden de la herencia afecta al metodo que llame super()
class Heroe(PersonajeDeAccion,SabeLuchar,SabeNadar, SabeVolar):
    def nadar(self):
        print("Nadando")

    def volar(self):
        print("Volando")

    def luchar(self):
        super().luchar()
        #PersonajeDeAccion.luchar(self)
        #print("Luchando")
    
#Class Aventura
class Aventura:

    #main
    def main(self):
        i = Heroe()
        i.luchar()
        i.nadar()
        i.volar()

#execute main
if __name__ == "__main__":
    Aventura().main()
    


    

