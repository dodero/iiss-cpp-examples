
class motor:
	__nombre = ""
	__velocidad_maxima = 0
	__combustible = ""


class motor_gasolina(motor):
	def __init__(self):
		self.__nombre = "Pull Start 168F OHV"
		self.__velocidad_maxima = 340
		self.__combustible = "gasolina"
	def arrancar_motor(self):
		print "arrancando: brrrruuuuuummmmmm brrrrruuuuummmmmm" 
	def testeo_velocidad_max(self):
		print "El ferrari de gasolina ha alcanzado ", self.__velocidad_maxima," Km/h"

class motor_diesel(motor):
	def __init__(self):
		self.__nombre = "WM178F-2"
		self.__velocidad_maxima = 320
		self.__combustible = "diesel"
	def arrancar_motor(self):
		print "arrancando: brruumm brruumm bruuumm"
	def testeo_velocidad_max(self):
		print "El ferrari de diesel ha alcanzado ", self.__velocidad_maxima," Km/h"
	

class motor_electrico(motor):
	def __init__(self):
		self.__nombre = "QSMOTOR"
		self.__velocidad_maxima = 290
		self.__combustible = "electricidad"
	def arrancar_motor(self):
		print "arrancando: brrrrrrrrrrruuuuuuuuuuuuuuummmmmmmmmmmmmm" 
	def testeo_velocidad_max(self):
		print "El ferrari electrico ha alcanzado ", self.__velocidad_maxima," Km/h"

class motor_gas_licuado(motor):
	def __init__(self):
		self.__nombre = "188F/190F"
		self.__velocidad_maxima = 300
		self.__combustible = "gas_licuado"
	def arrancar_motor(self):
		print "arrancando: brrrumm bruumm bruumm bruumm" 
	def testeo_velocidad_max(self):
		print "El ferrari de gas licuado ha alcanzado ", self.__velocidad_maxima," Km/h"