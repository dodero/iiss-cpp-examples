#IISS-2021/2022
#Autor: Cristóbal José Velo Huerta
#Paquete usado: PyContracts 1.8.12
#https://github.com/AndreaCensi/contracts
#Instalación: pip install PyContracts
#Dependencia: pyparsing 2.4.7 o anterior
#             pip install pyparsing==2.4.7

#Pycontracts nos permite establecer contratos en funciones para agilizar el proceso de comprobacion de precondiciones (y postcondiciones si somos exigentes).
#Si no se respeta una parte del contrato se muestra en que linea no se respeta el contrato, cual es la condión que no se respeta y se detiene la ejecucion.


from contracts import contract

@contract(a='int,>0', b='int') #forma de definir usando decorador @contract
def suma(a, b):
    return a + b 

@contract #forma de definir usando docstring (type para parametros de entrada y rtype para el return). Aqui podemos explicar que hace la funcion y que condiciones debe cumplirse
def resta(a, b):
    """
    Resta dos números enteros
    :type a: int, >10
    :type b: int, >10
    :rtype: int, >=0
    """
    return a - b

if __name__ == "__main__":
    print(suma(3,4))
    #print(suma(-3,3)) #salta excepcion
    print(resta(100,30))
    #print(resta(99,100)) #salta excepcion
