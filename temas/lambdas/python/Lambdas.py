#IISS-2021/2022
#Autor: Cristóbal José Velo Huerta
#Ejemplo del uso de funciones anonimas en Python

if __name__ == "__main__":
    
    x = (lambda x: x+1) (1) #funcion lambda que suma 1 a un numero
    print(x) 
  
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

    e = lambda x: True if x>10 else False #funcion anonima que devuelve True si x es mayor que 10 y False si no lo es
    d(e(11))
    d(e(9))

    f = lambda x: [i for i in x if i%2==0]  #funcion anonima que devuelve que elimina los numeros impares de una lista
    d(f([1,2,3,4,5,6,7,8,9,10]))

    g = lambda x: sorted(x) #funcion anonima que ordena los elementos de una lista de manera ascendente
    d(g([10,9,8,7,6,5,4,3,2,1]))

    h = lambda x: [i.upper() for i in x]    #funcion anonima que pone a mayusculas una lista de string
    d(h(["hola", "estudiantes", "de IISS"]))

