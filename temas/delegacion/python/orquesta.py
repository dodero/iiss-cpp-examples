from instrumento import *


class Orquesta:
	def __init__(self):
		self.__instrumentos = []

	def addInstrumento(self, instrumento):
		self.__instrumentos.append(instrumento)
	def tocarInstrumento(self):
		for i in range(len(self.__instrumentos)):
			self.__instrumentos[i].tocar()
	def afinarInstrumento(self):
		for j in range(len(self.__instrumentos)):
			self.__instrumentos[j].afinar()
