## Contratos en Python
Autor: Cristóbal José Velo Huerta

## Paquete usado
```
PyContracts 1.8.12
https://github.com/AndreaCensi/contracts
```
## Instalación del paquete
```	
pip install PyContracts
```
## Dependencias del paquete
```
pyparsing 2.4.7 o anterior
```
## Instalación de las dependencias
```
pip install pyparsing==2.4.7
```
## Ejecución del ejemplo
```
python ./Aventura.py
```
## Código
```
from contracts import contract

@contract(a='int,>0', b='int') #forma de definir usando decorador @contract
def suma(a, b):
    return a + b 

@contract #forma de definir usando docstring (type para parametros de entrada y rtype para el return). Aqui podemos explicar que hace la funcion y que condiciones debe cumplirse
def resta(a, b):
    """
    Resta dos números enteros (Explicacion de la funcion)
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

```

## Explicación
Pycontracts nos permite establecer contratos en funciones para agilizar el proceso de comprobacion de precondiciones (y postcondiciones si somos exigentes). Si no se respeta una parte del contrato se muestra en que línea no se respeta el contrato, cual es la condión que no se respeta y se detiene la ejecucion.

Para el ejemplo se han implementado 2 funciones sencillas, suma y resta con una serie de condiciones que deben cumplir los parametros de entrada y salida.

suma: Mediante el decorador @contract se puede definir una condicion para los parametros de entrada y salida de la funcion. En este caso "a" debe ser un entero mayor a 0 y "b" debe ser un entero.

resta: Colocamos el decorador @contract en la funcion resta. En este caso colocamos las precondiciones y postcondiciones en un docstring dentro de la función. Con :type definimos las exigencias de los parámetros de entrada y :rtype definimos las exigencias de los parámetros de retorno. Usando el docstring se puede explicar el objetivo de la función para justificar los requisitos.

