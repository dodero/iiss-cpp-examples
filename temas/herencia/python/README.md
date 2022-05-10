## Herencia en Python
Autor: Cristóbal José Velo Huerta

## Ejecución del ejemplo
```
python ./Aventura.py
```

## Código
```
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
```	
# Explicación
Reimplementación del ejemplo Avenura 0.2 visto en las clases de teoría python.
<br>
Se ha intentado mantener la estructura del código original de Java pero cambiando ciertos aspectos para mostrar el funcionamiento propio de la herencia en Python.

En Python, al existir multiherencia, no tenemos los problemas presentes en Java de no poder acceder a los atributos y métodos de una superclase.
<br>
Podemos tener interfaces y clases abstractas de las que tendremos que implementar sus métodos en algún momento en las clases que las heredan.
Pero, ¿qué ocurre si heredamos de mas de una clase y existen métodos que se llaman igual?
<br>
Deberemos decidir cual de ellos tendrá mayor jerarquía. Para ello usaremos super().funcion() para forzar la ajecución de la función de la "root class". Distinguimos a la root class por no tener super().funcion() en el código. En este código hemos decidido que sea SabeLuchar forma arbitraria.

También a la hora de sobreescribir funciones hay que tener el cuenta el orden en el que heredamos porque afecta a que función estamos sobreescribiendo. Esto puede ser un problema importante en el caso de heredar de muchas clases, tener muchos métodos que se llamen igual y no poder editar ese código. Podriamos creer que estamos sobreescribiendo una función y acabar sobreescribiendo otra.

En caso de duda siempre podemos llamar directamente a la funcion de una clase concreta usando su nombre ( A.funcion(self) en vez de super().funcion())

En cuanto al código entregado, realmente es un híbrido de la estructura del programa en Java y algunas de las utilidades presentes en Python. Si quisieramos un código Python mas puro, implementariamos los prints en las clases SabeX porque no nos causaría ningún problema dada la especificación tan sencilla de este ejemplo.
