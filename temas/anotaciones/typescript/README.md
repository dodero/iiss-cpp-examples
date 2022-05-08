# Anotaciones

## Requisitos
> Debemos tener previamente instalado [NodeJS](https://nodejs.org/en/) y TypeScript `npm install -g typescript`

## Objetivo

### Implementar 

- Implementar el ejemplo de [BankAccount](http://dodero.github.io/iiss/iiss-oop-3/#ejercicio-identificador-de-bankaccount-con-inyeccion-de-dependencias) con diversos atributos comparables, usando los mecanisnmos de anostaciones que el lenguaje proporcione para inyectar como dependencia el comparador a usar.

### Como hacerlo

- La idea es crear un decorador que inyecte a BankAccount una dependencia en los atributos comparadores.
Un decorador para cada comparador tanto de fecha como de id

## Explicación

### Decorador (Definicion)
- Los decoradores (decorators en inglés) son una propuesta para incluir en JavaScript que nos permite añadir anotaciones y metadatos o cambiar el comportamiento de clases, propiedades, métodos, parámetros y accesors. Con TypeScript podemos usarlos activando la propiedad experimentalDecorators del tsconfig.json de nuestro proyecto o si decidimos compilar mediante el comando tsc, colocar siempre la opción de ```--experimentalDecorators```, en caso de que salte algun error probar con ```--experimentalDecorators ---target ES5```.

### Procedimiento aplicado
- Para llevar a cabo esta funcionalidad vamos a usar un **decorador de clase**.
El decorador de clase es aplicado al constructor de la misma y puede ser usado para observar, modificar o reemplazar la definicion inical de la clase. Su único argumento es el ***target*** (objetivo) que vendria siendo
la clase decorada (tipado como Function o any).
A través de ***target*** podemos modificar el contenido de los atributos, en este caso es donde inyectamos las
dependencias.

- Aun asi tenemos disponible otro método de inyección de dependencias con los metodos ***setters***

*NOTA: Cuando inyectamos las dependencias hemos puesto que notifque de ello (solo con el decorador).*

### ¿Como creamos-exportamos modulos o clases en TypeScript?
Para ello debemos crearnos nuestro fichero o ficheros con el módulo/s o clase/s a exportar


**modulo.ts**
```TYPESCRIPT
export module Nombre {
    export class MiClase {
        method: void {
            console.log('soy un metodo de la clase uno')
        }
    }

    export class MiClase2 {
        method: void {
            console.log('soy un metodo de la clase dos')
        }
    }
}
```
**exportar.ts**
```TYPESCRIPT
export class claseExportada {
    method: void {
        console.log('soy un metodo de la clase exportada')
    }
}
```
**main.ts**
```TYPESCRIPT
import { Nombre } from './modulo.ts'
import { claseExportada } from './exportar.ts'

let claseUnoModulo: any = new Nombre.MiClase()
let claseDosModulo: any = new Nombre.MiClase2()
let claseEx: any = new claseExportada()
// ...
```


## Compilar
> `tsc --experimentalDecorators anotaciones.ts`
## Ejecutar
>`node anotaciones.js`