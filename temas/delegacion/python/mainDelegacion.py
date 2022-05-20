from orquesta import *

def main():
	orquesta = Orquesta()

	orquesta.addInstrumento(instrumento = Viento(name = 'trompeta'))
	orquesta.addInstrumento(instrumento = Cuerda(name = "violin"))
	orquesta.addInstrumento(instrumento = Cuerda(name = "viola"))
	orquesta.addInstrumento(instrumento = Percusion(name = "tambor"))
	orquesta.afinarInstrumento()
	orquesta.tocarInstrumento()


if __name__ == "__main__":
	main()