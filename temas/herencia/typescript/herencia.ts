interface SabeLuchar {
    luchar(): void
}

interface SabeNadar {
    nadar(): void
}

interface SabeVolar {
    volar(): void
}

class PersonajeDeAccion {
    luchar(): void {
        console.log('Personaje de accion luchar')
    }
}

class Heroe extends PersonajeDeAccion implements SabeLuchar, SabeNadar, SabeVolar {
    nadar(): void {
        console.log('Heroe: Personaje de accion - nadar')
    }

    volar(): void {
        console.log('Heroe: Personaje de accion - volar')
    }
}

class Aventura {
    t(x: SabeLuchar): void {
        x.luchar()
    }

    u(x: SabeVolar): void {
        x.volar()
    }

    v(x: SabeNadar): void {
        x.nadar()
    }

    w(x: PersonajeDeAccion): void {
        x.luchar()
    }
    
    main(): void {
        let i: Heroe = new Heroe();
        this.t(i); // Tratar como un SabeLuchar
        this.u(i); // Tratar como un SabeNadar
        this.v(i); // Tratar como un SabeVolar
        this.w(i); // Tratar como un PersonajeDeAccion
    }
}

let test: Aventura = new Aventura()
test.main()