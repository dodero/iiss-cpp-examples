# Bloque 1: Objetos

## Requisitos
> Debemos tener previamente instalado [NodeJS](https://nodejs.org/en/) y TypeScript `npm install -g typescript`
## Compilar
> `tsc herencia.ts`
## Ejecutar
> `node herencia.js`

## Herencia en TypeScript:
Recreacion ejemplo Aventura de [Aventura](http://dodero.github.io/iiss/iiss-oop-1/#ejemplo-aventura-v01)

## Explicacion
En este caso TypeScript en lo que a Herencias e implemetacion de interfaces ser refiere es identico a JAVA

Crear Clase
```TYPESCRIPT
class Coord {
    private x: number;
    private x: number
    constructor(x: number, y: number) {
        this.x = x;
        this.y = y;
    }
}
```

**Crear Interfaz**
```TYPESCRIPT
interface MyInterface {
    method(): any
}
```

**Heredar de una clase e Implementar una interfaz**
```TYPESCRIPT
class myClass extends myOtherClass implements MyInterface {
    // myClass methods...
    method(): any {
        console.log('aqui mi implementacion de este metodo de la interfaz')    
    }
}
```

**Clase abstracta**
```TYPESCRIPT
abstract class ClassA {
    abstract nothing(): void;
}
```

**Clases herederas**
```TYPESCRIPT
class Son extends ClassA {
    nothing(): void {
        console.log('Son: Nothing')
    }
}

class Daughter extends ClassA {
    nothing(): void {
        console.log('Daughter: Nothing')
    }
}
```

**Ejemplo Herencia**
```TYPESCRIPT
class Animal {
    name: string;
    constructor(theName: string) { this.name = theName; }
    move(distanceInMeters: number = 0) {
        console.log(`${this.name} moved ${distanceInMeters}m.`);
    }
}

class Snake extends Animal {
    constructor(name: string) { super(name); }
    move(distanceInMeters = 5) {
        console.log("Slithering...");
        super.move(distanceInMeters);
    }
}

let s : Snake = new Snake('Serpiente')
s.move()
```