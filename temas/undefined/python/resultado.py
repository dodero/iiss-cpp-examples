
class resultado():
	def __init__(self,puesto,nombre,vuelta_rapida,puntos,medalla,puntos_total):
		self.__puesto = puesto
		self.__nombre = nombre
		self.__vuelta_rapida = vuelta_rapida
		self.__puntos = puntos
		self.__medalla = medalla
		self.__puntos_total = puntos_total

	def datos(self):
		print self.__puesto, "		", self.__nombre, "		", self.__vuelta_rapida, "		  " ,self.__puntos, "	      " ,self.__medalla

	def datos2(self):
		if (self.__puntos is not None):
			self.__puntos_total = self.__puntos_total + self.__puntos

		print self.__nombre, "		", self.__puntos_total
