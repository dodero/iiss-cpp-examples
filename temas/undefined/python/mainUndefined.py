
from resultado import *

def main():

	class resultado_gp():
		def __init__(self):
			self.__resultado_gran_premio = []
		def addResultado(self,resultado_piloto):
			self.__resultado_gran_premio.append(resultado_piloto)
		def imprimir_resultados_gp(self):
			print ""
			print "                          RESULTADO GRAN PREMIO"
			print ""
			print "PUESTO 		  NOMBRE 		    VUELTA-RAPIDA    PUNTOS-GANADOS 	PREMIO"
			print "--------------------------------------------------------------------------------------------------"
			for i in range(len(self.__resultado_gran_premio)):
				self.__resultado_gran_premio[i].datos()
				print "--------------------------------------------------------------------------------------------------"

		def imprimir_resultados_total(self):
			print ""
			print "	  CLASIFICACION ACTUAL"
			print ""
			print "NOMBRE				PUNTOS TOTALES"
			print "-----------------------------------------------"
			for j in range(len(self.__resultado_gran_premio)):
				self.__resultado_gran_premio[j].datos2()
				print "-----------------------------------------------"



	resultado_gran_premio = resultado_gp()

	resultado_gran_premio.addResultado(resultado(1,"Fernando Alonso",28.458,12,"medalla de oro",105))
	resultado_gran_premio.addResultado(resultado(2,"Carlos Sainz Jr",27.654,10,"medalla de plata",54))
	resultado_gran_premio.addResultado(resultado(3,"Rayo Mc Queen  ",31.765,8,"medalla de bronce",87))
	resultado_gran_premio.addResultado(resultado(4,"Valtteri Bottas",31.421,6,None,88))
	resultado_gran_premio.addResultado(resultado(None,"Kevin Magnussen",32.987,None,None,43))
	resultado_gran_premio.addResultado(resultado(None,"Sebastian Vettel",None,None,None,69))

	resultado_gran_premio.imprimir_resultados_gp()

	resultado_gran_premio.imprimir_resultados_total()





if __name__ == "__main__":
	main()