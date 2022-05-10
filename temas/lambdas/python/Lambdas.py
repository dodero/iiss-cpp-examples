#IISS-2021/2022
#Autor: Cristóbal José Velo Huerta
#Ejemplo del uso de funciones anonimas en Python
#Python dispone de una forma nativa de usar funciones lambdas aunque no podemos decir que sean muy anonimas ya que hay que enlazarla con una variable para poder usarla
#Es mas una forma mas agil de declarar una funcion en python e ideal para operaciones no muy largas de definir y con posible multiuso


if __name__ == "__main__":
    #funcion anonima
    a = lambda x: x*x #funcion anonima del cuadrado de un numero
    print(a(3))
    print(a(4.5))

    b = lambda x,y: x+y #funcion anonima que suma dos cosas o concatena
    print(b(7,7))
    print(b("Hola"," Mundo"))
    
    c = lambda x, y, z: print(x+" "+y+" "+z)  #funcion anonima que imprime la concatenacion de 3 string
    c("Hola", "estudiantes", "de IISS")

   
    d = lambda x: print(x) #funcion anonima que imprime lo que le pases
    d(["Hola", "estudiantes", "de IISS"])
    d([1, 2, 3])
    d(1.5)
    d("hola")
