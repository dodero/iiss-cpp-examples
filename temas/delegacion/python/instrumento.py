
class Instrumento:
	def __init__(self,name):
		self._nombreInstrumento = name
	def getNombreInstrumento(self):
		return self._nombreInstrumento

class Viento(Instrumento):
	def __init__(self,name):
		self._nombreInstrumento = name
	def afinar(self):
		print "Afinando instrumento de Viento: ", self.getNombreInstrumento()
	def tocar(self):
		print "Tocando instrumento de Viento: ", self.getNombreInstrumento()

class Cuerda(Instrumento):
	def __init__(self,name):
		self._nombreInstrumento = name
	def afinar(self):
		print "Afinando instrumento de Cuerda: ", self.getNombreInstrumento()
	def tocar(self):
		print "Tocando instrumento de Cuerda: ", self.getNombreInstrumento()


class Percusion(Instrumento):
	def __init__(self,name):
		self._nombreInstrumento = name
	def afinar(self):
		print "Afinando instrumento de Percusion: ", self.getNombreInstrumento()
	def tocar(self):
		print "Tocando instrumento de Percusion: ", self.getNombreInstrumento()