import { Optional } from "typescript-optional";

console.log('--------------------------OPTIONALS---------------------------------')

class ScreenResolution {
    private width: number
    private height: number

    constructor(width: number, height: number) {
        this.width = width
        this.height = height
    }

    getWidth(): number {
        return this.width
    }

    getHeight(): number {
        return this.height
    }
}

class DisplayFeatures {
    private size: string
    private resolution: Optional<ScreenResolution>;

    constructor(size: string, resolution: Optional<ScreenResolution>) {
        this.size = size
        this.resolution = resolution
    }

    getSize(): string { return this.size }

    getResolution(): Optional<ScreenResolution> { return this.resolution }

}

class Mobile {
    private id: number
    private brand: string
    private name: string
    private displayFeatures: Optional<DisplayFeatures>

    constructor(id: number, brand: string, name: string, displayFeatures: Optional<DisplayFeatures>) {
        this.id = id
        this.brand = brand
        this.name = name
        this.displayFeatures = displayFeatures
    }

    getId(): number { return this.id }
    getBrand(): string { return this.brand }
    getName(): string { return this.name }
    getDisplayFeatures(): Optional<DisplayFeatures> {
        return this.displayFeatures
    }

}

class MobileService {
    getMobileScreenWidth(mobile: Optional<Mobile>): number {
        let df: Optional<DisplayFeatures> = mobile.get().getDisplayFeatures()
        let res = 0;
        if(df.isPresent()) {
            if(df.get().getResolution().isPresent()) {
                res = df.get().getResolution().get().getWidth()
            }else res = 0;
        }else res = 0;

        return res;
    }
}

let resolution: ScreenResolution = new ScreenResolution(750, 1334)
let dFeatures: DisplayFeatures = new DisplayFeatures('4.7', Optional.ofNullable(resolution))
let mobile = new Mobile(2015001, 'Apple', 'Iphone 6s', Optional.ofNullable(dFeatures))

let mService: MobileService = new MobileService()
let width: number = mService.getMobileScreenWidth(Optional.ofNullable(mobile))
console.log('Apple iPhone 6s screen width is', width)

let mobile2 = new Mobile(2015002, 'Apple', 'Iphone 7', Optional.ofNullable(null)) // Ejemplo de prueba
let width2: number = mService.getMobileScreenWidth(Optional.ofNullable(mobile2))
console.log('Apple iPhone 7 screen width is', width2)


console.log('--------------------------NATIVO---------------------------------')

class ScreenResolutionNativo {
    private width: number
    private height: number

    constructor(width: number, height: number) {
        this.width = width
        this.height = height
    }

    getWidth(): number {
        return this.width
    }

    getHeight(): number {
        return this.height
    }
}

class DisplayFeaturesNativo {
    private size: string
    private resolution: ScreenResolutionNativo

    constructor(size: string, resolution: ScreenResolutionNativo) {
        this.size = size
        this.resolution = resolution
    }

    getSize(): string { return this.size }

    getResolution(): ScreenResolutionNativo { return this.resolution }

}

class MobileNativo {
    private id: number
    private brand: string
    private name: string
    private displayFeatures: DisplayFeaturesNativo

    constructor(id: number, brand: string, name: string, displayFeatures: DisplayFeaturesNativo) {
        this.id = id
        this.brand = brand
        this.name = name
        this.displayFeatures = displayFeatures // ?? new DisplayFeaturesNativo("", new ScreenResolutionNativo(0,0))
    }

    getId(): number { return this.id }
    getBrand(): string { return this.brand }
    getName(): string { return this.name }
    getDisplayFeatures(): DisplayFeaturesNativo {
        return this.displayFeatures
    }

}

class MobileServiceNativo {
    getMobileScreenWidth(mobile: MobileNativo) {
        let df: DisplayFeaturesNativo = mobile?.getDisplayFeatures()
        let sc = df?.getResolution()?.getWidth() ?? 0
        return sc       
    }
}

let resolutionNativo: ScreenResolutionNativo = new ScreenResolutionNativo(750, 1334)
let dFeaturesNativo: DisplayFeaturesNativo = new DisplayFeaturesNativo('4.7', resolutionNativo)
let mobileNativo = new MobileNativo(2015001, 'Apple', 'Iphone 6s', dFeaturesNativo)

let mServiceNativo: MobileServiceNativo = new MobileServiceNativo()
let widthNativo: number = mServiceNativo.getMobileScreenWidth(mobileNativo)
console.log('Apple iPhone 6s screen width is', width )

let mobile2Nativo = new MobileNativo(2015002, 'Apple', 'Iphone 7', null) // Ejemplo de prueba  (donde pone null | undefined, es el objeto no inicializado)
let width2Nativo: number = mServiceNativo.getMobileScreenWidth(mobile2Nativo)
console.log('Apple iPhone 7 screen width is', width2Nativo )