
from ferrari import *
from motor import *


def main():
	ferrari_gasolina = ferrari("7654 ADS",motor_gasolina());
	ferrari_gasolina.arrancando_motores()
	ferrari_gasolina.testeo_velocidad_max()
	ferrari_diesel = ferrari("8765 KJH",motor_diesel());
	ferrari_diesel.arrancando_motores()
	ferrari_diesel.testeo_velocidad_max()
	ferrari_gas_licuado = ferrari("6547 POL",motor_gas_licuado());
	ferrari_gas_licuado.arrancando_motores()
	ferrari_gas_licuado.testeo_velocidad_max()
	ferrari_electrico = ferrari("6543 GFT",motor_electrico());
	ferrari_electrico.arrancando_motores()
	ferrari_electrico.testeo_velocidad_max()


if __name__ == "__main__":
	main()