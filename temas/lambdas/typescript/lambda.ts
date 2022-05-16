// LAMBDA ~ ARROW FUNCTION

// Arrow function
const helloArrow = () => console.log('Arrow function')

// Arrow function single argument
const show = (argument: number) => console.log('Arrow function single argument:', argument)

// Arrow function multiple defined arguments
const sum = (arg1: number, arg2: number) => console.log('Arrow function multiple argument:', arg1, arg2)

// Arrow function array argument
const revert = (arr: number[]) => console.log(arr.reverse())

helloArrow()
show(3)
sum(2, 6)
revert([1, 2, 3, 4])

console.log('................................................................')

// Arrow function with undefined number of arguments of any type
const variadic = (...args: any[]) => console.log(...args)

variadic(1, 2, 3)
variadic(1, 2, 3, [5, 4, 3])
variadic(1, 2, 3, [5, 4, 3], 7.2, 8.3, 'numeros...')

console.log('................................................................')

// return arrow function
const x2 = (num: number): number => num*2

const concat = (arg1: string, arg2: string): string =>  arg1 + arg2;

console.log(x2(10));
console.log(concat('hola', ' que pasa'))


// las funciones anonimas no tiene un scope limitado, es decir, pueden acceder al nivel superior
let outside: number = 59;
const add = () => outside + 2;
console.log('Scope superior: ', add())

// lambdas como parametros
const call = (callback) => callback()
console.log('call add: ', call(add))