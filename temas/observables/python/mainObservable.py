

class Observer():
	_observers = []
	def __init__(self):
		self._observers.append(self)
		self._observables = {}

	def observe(self,event_name,callback):
		self._observables[event_name] = callback


class Event():
	def __init__(self, name, data, autofire = True):
		self.name = name
		self.data = data
		if autofire:
			self.fire()

	def fire(self):
		for observer in Observer._observers:
			if self.name in observer._observables:
				observer._observables[self.name](self.data)


class Cocina(Observer):
	def __init__(self):
		print "Que desea de primero"
		Observer.__init__(self)

	def que_comemos(self,comida):
		print ("Aqui tiene su " + comida)

class Cocina2(Observer):
	def __init__(self):
		print "Y de segundo"
		Observer.__init__(self)

	def que_comemos(self,comida):
		print ("su " + comida + " listo")

def main():
	cocina = Cocina()
	cocina2 = Cocina2()
	cocina.observe("Que comemos de primero", cocina.que_comemos)
	cocina2.observe("Y de segundo", cocina2.que_comemos)
	Event("Que comemos de primero", "salmorejo")
	Event("Y de segundo", "filetito con patatas")

if __name__=="__main__":
	main()
