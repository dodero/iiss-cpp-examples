# Bloque 3: Calidad


## Requisitos
> Debemos tener previamente instalado [NodeJS](https://nodejs.org/en/) y TypeScript `npm install -g typescript`

> El usuario debe instalar `npm install --save typescript-optional`

## Undefined en TypeScript
Ejemplo implemetado "MobileTester" del apartado [Optionals](http://dodero.github.io/iiss/iiss-err/#optionals)
usando los mecanismos del lenguaje para resolver el problema de los valores *undefined* 
y el mal uso del `null`
- En TypeScript usaremos un modulo de npm ***typescript-optional***
> *Nos permitirá el uso de ***Optional<T>****

## Explicacion


### Módulo
Este ejemplo lo vamos a desarrollar de dos maneras, la primera haciendo uso del modulo optional que el usuario deberá 
instalar.
Usando el modulo [typescript-optional](https://www.npmjs.com/package/typescript-optional) es muy parecido a como lo hemos visto en clase 
en este caso debemos lo vamos a usar para obtener valores y en caso de que estos sean nulos devolveremos el valor acordado que será 0. No debemos hacer comparaciones usando la palabra *null* o *undefined* ya que no es una buena practica para eso existen este tipo de modulos o los nativos (en caso de que los incorpore el lenguaje)

Métodos

```TYPESCRIPT
Optional.isPresent()
Optional.get()
Optional.ofNullable()
```
*Nota: Esos métodos son mas que suficiente para este problema.*


### Nativa
Typescript ofrece diversos recursos para el control de los null/undefined como lo es el uso "?", "??"...

```TYPESCRIPT

// Sea una clase que tiene un atributo nulo pero no 
// sabemos si el objeto que nos han pasado por parametros
// de esa clase es nulo o está definido, en ese caso 
// usaremos "?" para obtener el dato y sino se le asigna 0
// con "??"
function foo(myClass : Class) {
    let numero = myClass?.num ?? 0
    console.log(numero)
}
```
*Nota: Ambas propuestan se encuentran en el mismo fichero.*