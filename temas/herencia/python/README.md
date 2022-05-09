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
