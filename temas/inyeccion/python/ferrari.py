
from motor import *

class ferrari:
	# @injection
	def __init__(self,matricula, motor):
		self.__matricula_ferrari = matricula
		self.__motor_ferrari = motor
	def arrancando_motores(self):
		self.__motor_ferrari.arrancar_motor()
	def testeo_velocidad_max(self):
		self.__motor_ferrari.testeo_velocidad_max()

